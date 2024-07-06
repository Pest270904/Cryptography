//C internal library 
#include <iostream>
using std::endl;
#include <string>
using std::string;
using std::string;
#include <cstdlib>
using std::exit;
#include <fstream>
#include <utility>
#include "assert.h"

//Cryptopp Library
#include <cryptopp/files.h>
using CryptoPP::FileSource;
using CryptoPP::FileSink;
using CryptoPP::BufferedTransformation;
#include "cryptopp/filters.h"
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::StreamTransformationFilter;
using CryptoPP::Redirector;
#include "cryptopp/osrng.h"
using CryptoPP::AutoSeededRandomPool;
using CryptoPP::byte;
#include "cryptopp/cryptlib.h"
using CryptoPP::Exception;
#include "cryptopp/hex.h"
using CryptoPP::HexEncoder;
using CryptoPP::HexDecoder;
#include "cryptopp/base64.h"
using CryptoPP::Base64Encoder;
using CryptoPP::Base64Decoder;
#include "cryptopp/des.h"
using CryptoPP::DES;
#include "cryptopp/aes.h"
using CryptoPP::AES;
#include "cryptopp/modes.h" //ECB, CBC, CBC-CTS, CFB, OFB, CTR
using CryptoPP::ECB_Mode;
using CryptoPP::CBC_Mode;
using CryptoPP::CFB_Mode;
using CryptoPP::OFB_Mode;
using CryptoPP::CTR_Mode;
#include "cryptopp/xts.h"
using CryptoPP::XTS;
#include <cryptopp/ccm.h>
using CryptoPP::CCM;
#include "cryptopp/gcm.h"
using CryptoPP::GCM;

/* Set utf8 support for windows*/ 
#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#include <windows.h>
#else
#endif

/* Convert string <--> utf8*/ 
#include <locale>
#include <codecvt>
using  std::codecvt_utf8;

#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#endif

using namespace std;
using namespace CryptoPP;
CryptoPP::byte key[AES::MAX_KEYLENGTH];
CryptoPP::byte iv[AES::BLOCKSIZE];

// -------------------------------------------- Decrypt --------------------------------------------
string ECB_decrypt(string &cipher);
string CBC_decrypt(string &cipher);
string OFB_decrypt(string &ciphertext);
string CFB_decrypt(string &ciphertext);
string CTR_decrypt(string &ciphertext);
string XTS_decrypt(string &ciphertext);
string CCM_decrypt(string &cipher, CryptoPP::byte* iv_);
pair<string, string> GCM_decrypt(string &cipher, string &adata);

// -------------------------------------------- Encrypt --------------------------------------------
string base64_decode(string enc);
string base64_encode(string text);
string ECB_encrypt(string &plain);
string CBC_encrypt(string &plain);
string OFB_encrypt(string &plain);
string CFB_encrypt(string &plain);
string CTR_encrypt(string &plain);
string XTS_encrypt(string &plain);
string CCM_encrypt(string &pdata, CryptoPP::byte* truncatedIV);
string GCM_encrypt(string pdata, string adata);

// -------------------------------------------- Other functions --------------------------------------------
void get_keyboard_key_iv();
void get_key_iv_from_file(string fileKey, string fileIV);
string getPlainFromFile(string filename);
string enter(string kindOfText);
int enc_dec_Menu();
int display_Menu();
int main_Menu();
int genkey_Menu();
void write2File(string text);

// -------------------------------------------- Main function --------------------------------------------
int main(int argc, char* argv[])
{
    #ifdef __linux__
    std::locale::global(std::locale("C.utf8"));
    #endif
  
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    #endif

    while(true)
    {
        int select = main_Menu();

        switch (select) 
        {
            case 1: // Key & Iv gen
            {
                int keygen = genkey_Menu();

                switch (keygen)
                {
                    case 1: // random key va iv
                    {
                        // random key
                        AutoSeededRandomPool prng;
                        prng.GenerateBlock(key, sizeof(key));
                        string encodedKey;
                        StringSource(key, sizeof(key), true,
                            new HexEncoder(new StringSink(encodedKey)));        
                        cout << "Generated Key: " << encodedKey << endl;
                        
                        // random IV
                        string encodedIV;
                        prng.GenerateBlock(iv, sizeof(iv));
                        StringSource(iv, sizeof(iv), true, 
                            new HexEncoder(new StringSink(encodedIV)));
                        
                        cout << "Generated IV: " << encodedIV << endl;
                        break;
                    }
                    case 2:
                    {
                        get_keyboard_key_iv(); // hex
                        break;
                    }
                    case 3:
                    {
                        string filenameKey;
                        cout<<"-> Enter key file name: ";
                        cin >> filenameKey;

                        string filenameIV;
                        cout<<"-> Enter IV file name: ";
                        cin >> filenameIV;
                        get_key_iv_from_file(filenameKey, filenameIV); // hex

                        break;
                    }
                    default:
                    {
                        cout<<"Invalid option";
                        return 0;
                    }
                }
                break;
            }
            case 2: // Encrypt
            {
                int mode = enc_dec_Menu();

                string plaintext;
                plaintext = enter("plaintext"); 

                int display = display_Menu();

                switch (mode)
                {
                    case 1: // ECB encrypt
                    {
                        string cipher;

                        auto start = std::chrono::high_resolution_clock::now();
                        for (int i = 0; i < 10000; ++i) 
                        {
                            cipher = ECB_encrypt(plaintext); 
                        }
                        auto end = std::chrono::high_resolution_clock::now();
                        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                        double averageTime = static_cast<double>(duration) / 10000.0;
                        cout << "Average time for encryption over 10000 rounds: " << averageTime << " ms" << std::endl;

                        string cipherb64 = base64_encode(cipher);
                        if (display == 1)
                            cout<<"Ciphertext(base 64):" << cipherb64 << endl;
                        else if (display == 2)
                            write2File(cipherb64);
                        else
                        {
                            cout << "Invalid cipher";
                            return 0;
                        }
                        break;
                    }
                    case 2: // CBC encrypt
                    {
                        string cipher;

                        auto start = std::chrono::high_resolution_clock::now();
                        for (int i = 0; i < 10000; ++i) 
                        {
                            cipher = CBC_encrypt(plaintext); 
                        }
                        auto end = std::chrono::high_resolution_clock::now();
                        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                        double averageTime = static_cast<double>(duration) / 10000.0;
                        cout << "Average time for encryption over 10000 rounds: " << averageTime << " ms" << std::endl;

                        string ciphertext = base64_encode(cipher);
                        if (display == 1)
                            cout<<"Ciphertext(base 64):" << ciphertext << endl;
                        else if (display == 2)
                            write2File(ciphertext);
                        else
                        {
                            cout << "Invalid cipher";
                            return 0;
                        }
                        break;
                    }
                    case 3: // OFB encrypt
                    {
                        string cipher;

                        auto start = std::chrono::high_resolution_clock::now();
                        for (int i = 0; i < 10000; ++i) 
                        {
                            cipher = OFB_encrypt(plaintext); 
                        }
                        auto end = std::chrono::high_resolution_clock::now();
                        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                        double averageTime = static_cast<double>(duration) / 10000.0;
                        cout << "Average time for encryption over 10000 rounds: " << averageTime << " ms" << std::endl;

                        string ciphertext = base64_encode(cipher);
                        if (display == 1)
                            cout<<"Ciphertext(base 64):" << ciphertext << endl;
                        else if (display == 2)
                            write2File(ciphertext);
                        else
                        {
                            cout << "Invalid cipher";
                            return 0;
                        }
                        break;
                    }
                    case 4: // CFB encrypt
                    {
                        string cipher;

                        auto start = std::chrono::high_resolution_clock::now();
                        for (int i = 0; i < 10000; ++i) 
                        {
                            cipher = CFB_encrypt(plaintext); 
                        }
                        auto end = std::chrono::high_resolution_clock::now();
                        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                        double averageTime = static_cast<double>(duration) / 10000.0;
                        cout << "Average time for encryption over 10000 rounds: " << averageTime << " ms" << std::endl;

                        string ciphertext = base64_encode(cipher);
                        if (display == 1)
                            cout<<"Ciphertext(base 64):" << ciphertext << endl;
                        else if (display == 2)
                            write2File(ciphertext);
                        else
                        {
                            cout << "Invalid cipher";
                            return 0;
                        }
                        break;
                    }
                    case 5: // CTR encrypt
                    {
                        string cipher;

                        auto start = std::chrono::high_resolution_clock::now();
                        for (int i = 0; i < 10000; ++i) 
                        {
                            cipher = CTR_encrypt(plaintext); 
                        }
                        auto end = std::chrono::high_resolution_clock::now();
                        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                        double averageTime = static_cast<double>(duration) / 10000.0;
                        cout << "Average time for encryption over 10000 rounds: " << averageTime << " ms" << std::endl;

                        string ciphertext = base64_encode(cipher);
                        if (display == 1)
                            cout<<"Ciphertext(base 64):" << ciphertext << endl;
                        else if (display == 2)
                            write2File(ciphertext);
                        else
                        {
                            cout << "Invalid cipher";
                            return 0;
                        }
                        break;
                    }
                    case 6: // XTS encrypt
                    {
                        string cipher;

                        auto start = std::chrono::high_resolution_clock::now();
                        for (int i = 0; i < 10000; ++i) 
                        {
                            cipher = XTS_encrypt(plaintext); 
                        }
                        auto end = std::chrono::high_resolution_clock::now();
                        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                        double averageTime = static_cast<double>(duration) / 10000.0;
                        cout << "Average time for encryption over 10000 rounds: " << averageTime << " ms" << std::endl;

                        string ciphertext = base64_encode(cipher);
                        if (display == 1)
                            cout<<"Ciphertext(base 64):" << ciphertext << endl;
                        else if (display == 2)
                            write2File(ciphertext);
                        else
                        {
                            cout << "Invalid cipher";
                            return 0;
                        }
                        break;
                    }
                    case 7: // CCM encrypt
                    {       
                        string cipher;

                        auto start = std::chrono::high_resolution_clock::now();
                        CryptoPP::byte truncatedIV[13];
	                    memcpy(truncatedIV, iv, 13);
                        for (int i = 0; i < 10000; ++i) 
                        {
                            cipher = CCM_encrypt(plaintext, truncatedIV); 
                        }
                        auto end = std::chrono::high_resolution_clock::now();
                        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                        double averageTime = static_cast<double>(duration) / 10000.0;
                        std::cout << "Average time for encryption over 10000 rounds: " << averageTime << " ms" << std::endl;

                        string ciphertext = base64_encode(cipher);
                        if (display == 1)
                            cout << "Ciphertext base64 (enc + tag):" << ciphertext << endl;
                        else if (display == 2)
                            write2File(ciphertext);
                        else
                        {
                            cout << "Invalid cipher";
                            return 0;
                        }
                        break;
                        
                    }
                    case 8: // GCM encrypt
                    {
                        string AAD;
                        cout << "Enter Additional Authenticated Data(AAD): "; 
                        cin >> AAD;
                        
                        string cipher;

                        auto start = std::chrono::high_resolution_clock::now();
                        for (int i = 0; i < 10000; ++i) 
                        {
                            cipher = GCM_encrypt(plaintext, AAD); 
                        }
                        auto end = std::chrono::high_resolution_clock::now();
                        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                        double averageTime = static_cast<double>(duration) / 10000.0;
                        std::cout << "Average time for encryption over 10000 rounds: " << averageTime << " ms" << std::endl;

                        string ciphertext = base64_encode(cipher);
                        if (display == 1)
                            cout << "Ciphertext base64 (enc + tag):" << ciphertext << endl;
                        else if (display == 2)
                            write2File(ciphertext);
                        else
                        {
                            cout << "Invalid cipher";
                            return 0;
                        }
                        break;
                    }
                    default:
                    {
                        cout << "Invalid option";
                        return 0;
                    }
                }
                break;
            }
            case 3: // Decrypt
            {
                int mode = enc_dec_Menu();

                string cipher = base64_decode(enter("ciphertext(base 64)"));

                int display = display_Menu();

                switch (mode)
                {
                    case 1: // ECB decrypt
                    {
                        string plaintext;

                        auto start = std::chrono::high_resolution_clock::now();
                        for (int i = 0; i < 10000; ++i) 
                        {
                            plaintext = ECB_decrypt(cipher); 
                        }
                        auto end = std::chrono::high_resolution_clock::now();
                        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                        double averageTime = static_cast<double>(duration) / 10000.0;
                        std::cout << "Average time for decryption over 10000 rounds: " << averageTime << " ms" << std::endl;
                        if (display == 1)
                            cout << "Recovered text: " << plaintext << endl;
                        else if (display == 2)
                            write2File(plaintext);
                        else
                        {
                            cout << "Invalid option";
                            return 0;
                        }
                        break;
                    }
                    case 2: // CBC decrypt
                    {
                        string plaintext;

                        auto start = std::chrono::high_resolution_clock::now();
                        for (int i = 0; i < 10000; ++i) 
                        {
                            plaintext = CBC_decrypt(cipher); 
                        }
                        auto end = std::chrono::high_resolution_clock::now();
                        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                        double averageTime = static_cast<double>(duration) / 10000.0;
                        std::cout << "Average time for decryption over 10000 rounds: " << averageTime << " ms" << std::endl;
                        if (display == 1)
                            cout << "Recovered text: " << plaintext << endl;
                        else if (display == 2)
                            write2File(plaintext);
                        else
                        {
                            cout << "Invalid option";
                            return 0;
                        }
                        break;                 
                    }
                    case 3: // OFB decrypt
                    {
                        string plaintext;

                        auto start = std::chrono::high_resolution_clock::now();
                        for (int i = 0; i < 10000; ++i) 
                        {
                            plaintext = OFB_decrypt(cipher); 
                        }
                        auto end = std::chrono::high_resolution_clock::now();
                        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                        double averageTime = static_cast<double>(duration) / 10000.0;
                        std::cout << "Average time for decryption over 10000 rounds: " << averageTime << " ms" << std::endl;
                        if (display == 1)
                            cout << "Recovered text: " << plaintext << endl;
                        else if (display == 2)
                            write2File(plaintext);
                        else
                        {
                            cout << "Invalid option";
                            return 0;
                        }
                        break;
                    }
                    case 4: // CFB decrypt
                    {
                        string plaintext;

                        auto start = std::chrono::high_resolution_clock::now();
                        for (int i = 0; i < 10000; ++i) 
                        {
                            plaintext = CFB_decrypt(cipher); 
                        }
                        auto end = std::chrono::high_resolution_clock::now();
                        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                        double averageTime = static_cast<double>(duration) / 10000.0;
                        std::cout << "Average time for decryption over 10000 rounds: " << averageTime << " ms" << std::endl;
                        if (display == 1)
                            cout << "Recovered text: " << plaintext << endl;
                        else if (display == 2)
                            write2File(plaintext);
                        else
                        {
                            cout << "Invalid option";
                            return 0;
                        }
                        break;
                    }
                    case 5: // CTR decrypt
                    {
                        string plaintext;

                        auto start = std::chrono::high_resolution_clock::now();
                        for (int i = 0; i < 10000; ++i) 
                        {
                            plaintext = CTR_decrypt(cipher); 
                        }
                        auto end = std::chrono::high_resolution_clock::now();
                        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                        double averageTime = static_cast<double>(duration) / 10000.0;
                        std::cout << "Average time for decryption over 10000 rounds: " << averageTime << " ms" << std::endl;
                        if (display == 1)
                            cout << "Recovered text: " << plaintext << endl;
                        else if (display == 2)
                            write2File(plaintext);
                        else
                        {
                            cout << "Invalid option";
                            return 0;
                        }
                        break;
                    }
                    case 6: // XTS decrypt
                    {
                        string plaintext;

                        auto start = std::chrono::high_resolution_clock::now();
                        for (int i = 0; i < 10000; ++i) 
                        {
                            plaintext = XTS_decrypt(cipher); 
                        }
                        auto end = std::chrono::high_resolution_clock::now();
                        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                        double averageTime = static_cast<double>(duration) / 10000.0;
                        std::cout << "Average time for decryption over 10000 rounds: " << averageTime << " ms" << std::endl;
                        if (display == 1)
                            cout << "Recovered text: " << plaintext << endl;
                        else if (display == 2)
                            write2File(plaintext);
                        else
                        {
                            cout << "Invalid option";
                            return 0;
                        }
                        break;
                    }
                    case 7: // CCM decrypt
                    {
                        auto start = std::chrono::high_resolution_clock::now();
                        string rpdata;
                        CryptoPP::byte truncatedIV[13];
	                    memcpy(truncatedIV, iv, 13);
                        for (int i = 0; i < 10000; ++i) 
                        {
                            rpdata = CCM_decrypt(cipher, truncatedIV);
                        }
                        auto end = std::chrono::high_resolution_clock::now();
                        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                        double averageTime = static_cast<double>(duration) / 10000.0;
                        std::cout << "Average time for decryption over 10000 rounds: " << averageTime << " ms" << std::endl;
                        if (display == 1)
                            cout << "Recovered pdata: " << rpdata << endl;
                        else if (display == 2)
                            write2File(rpdata);
                        else
                        {
                            cout << "Invalid option";
                            return 0;
                        }
                        break;
                    }
                    case 8: // GCM decrypt
                    {
                        string AAD;
                        cout << "Enter Additional Authenticated Data(AAD): ";
                        cin >> AAD;

                        auto start = std::chrono::high_resolution_clock::now();
                        pair<string, string> out;
                        for (int i = 0; i < 10000; ++i) 
                        {
                            out = GCM_decrypt(cipher, AAD);
                        }
                        string radata = out.first, rpdata = out.second;
                        auto end = std::chrono::high_resolution_clock::now();
                        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                        double averageTime = static_cast<double>(duration) / 10000.0;
                        std::cout << "Average time for decryption over 10000 rounds: " << averageTime << " ms" << std::endl;
                        if (display == 1)
                            cout << "Recovered pdata: " << rpdata << endl;
                        else if (display == 2)
                            write2File(rpdata);
                        else
                        {
                            cout << "Invalid option";
                            return 0;
                        }
                        cout << "Recovered adata: " << radata << endl;
                        break;
                    }
                    default:
                    {
                        cout << "Invalid option";
                        return 0;
                    }
                }
                break;
            }
            default:
            {
                cout << "Invalid input\n";
                return 0;
            }    
        }
    }
    return 0;
}

// -------------------------------------------- Decrypt --------------------------------------------

string ECB_decrypt(string &cipher)
{
    string recovered;
    ECB_Mode< AES >::Decryption d;
    d.SetKey(key, sizeof(key));
    StringSource s(cipher, true, 
        new StreamTransformationFilter(d, new StringSink(recovered)));
    return recovered;
}

string CBC_decrypt(string &cipher)
{
    string recovered;

    CBC_Mode< AES >::Decryption d;
    d.SetKeyWithIV(key, sizeof(key), iv);
    StringSource s(cipher, true, 
        new StreamTransformationFilter(d, new StringSink(recovered)));
    return recovered;
}

string OFB_decrypt(string &ciphertext)
{
    string recovered;
    OFB_Mode< AES >::Decryption d;
    d.SetKeyWithIV(key, sizeof(key), iv);
    StringSource s(ciphertext, true, 
        new StreamTransformationFilter(d, new StringSink(recovered)));
    return recovered;
}

string CFB_decrypt(string &ciphertext)
{
    string recovered;
   
    CFB_Mode< AES >::Decryption d;
    d.SetKeyWithIV(key, sizeof(key), iv);
    StringSource s(ciphertext, true, 
        new StreamTransformationFilter(d, new StringSink(recovered)));
    return recovered;
}

string CTR_decrypt(string &ciphertext)
{
    string recovered;

    CTR_Mode< AES >::Decryption d;
    d.SetKeyWithIV(key, sizeof(key), iv);
    StringSource s(ciphertext, true, 
        new StreamTransformationFilter(d, new StringSink(recovered)));
    return recovered;
}

string XTS_decrypt(string &ciphertext)
{
    string recovered;

    XTS_Mode< AES >::Decryption dec;
    dec.SetKeyWithIV( key, sizeof(key), iv );
    StringSource ss( ciphertext, true, 
        new StreamTransformationFilter(dec, new StringSink( recovered ), StreamTransformationFilter::NO_PADDING));       
	return recovered;
}

string CCM_decrypt(string &cipher, CryptoPP::byte* iv_)
{
	const int TAG_SIZE = 8;
	string rpdata;
    CCM< AES, TAG_SIZE >::Decryption d;
    d.SetKeyWithIV( key, sizeof(key), iv_, sizeof(iv_));
    d.SpecifyDataLengths( 0, cipher.size() - TAG_SIZE, 0 );

    AuthenticatedDecryptionFilter df(d, new StringSink( rpdata ));

    StringSource ss2( cipher, true, new Redirector( df )); 
    return rpdata;
}

pair<string, string> GCM_decrypt(string &cipher, string &adata)
{
	string radata, rpdata;
	const int TAG_SIZE = 16;
	try
    {
        GCM< AES >::Decryption d;
        d.SetKeyWithIV( key, sizeof(key), iv, sizeof(iv) );

        // Break the cipher text out into it's
        //  components: Encrypted Data and MAC Value
        string enc = cipher.substr( 0, cipher.length()-TAG_SIZE );
        string mac = cipher.substr( cipher.length()-TAG_SIZE );

        // Sanity checks
        assert( cipher.size() == enc.size() + mac.size() );
        assert( TAG_SIZE == mac.size() );

        // Not recovered - sent via clear channel
        radata = adata;     

        AuthenticatedDecryptionFilter df( d, NULL,
            AuthenticatedDecryptionFilter::MAC_AT_BEGIN |
            AuthenticatedDecryptionFilter::THROW_EXCEPTION, TAG_SIZE );

        // The order of the following calls are important
        df.ChannelPut( "", (const CryptoPP::byte*)mac.data(), mac.size() );
        df.ChannelPut( "AAD", (const CryptoPP::byte*)adata.data(), adata.size() ); 
        df.ChannelPut( "", (const CryptoPP::byte*)enc.data(), enc.size() );               

        // If the object throws, it will most likely occur
        //  during ChannelMessageEnd()
        df.ChannelMessageEnd( "AAD" );
        df.ChannelMessageEnd( "" );

        // Remove data from channel
        string retrieved;
        size_t n = (size_t)-1;

        // Plain text recovered from enc.data()
        df.SetRetrievalChannel( "" );
        n = (size_t)df.MaxRetrievable();
        retrieved.resize( n );

        if( n > 0 ) { df.Get( (CryptoPP::byte*)retrieved.data(), n ); }
        rpdata = retrieved;
    }
    catch( CryptoPP::InvalidArgument& e )
    {
        cerr << "Caught InvalidArgument..." << endl;
        cerr << e.what() << endl;
        cerr << endl;
    }
    catch( CryptoPP::AuthenticatedSymmetricCipher::BadState& e )
    {
        cerr << "Caught BadState..." << endl;
        cerr << e.what() << endl;
        cerr << endl;
    }
    catch( CryptoPP::HashVerificationFilter::HashVerificationFailed& e )
    {
        cerr << "Caught HashVerificationFailed..." << endl;
        cerr << e.what() << endl;
        cerr << endl;
    }
    return make_pair(radata,rpdata);
}

// -------------------------------------------- Encrypt --------------------------------------------

string base64_decode(string enc)
{
    string out;
    StringSource(enc, true, 
        new Base64Decoder(new StringSink(out)));
    return out;
}

string base64_encode(string text)
{
    string encoded;
    StringSource(text, true, 
        new Base64Encoder(new StringSink(encoded), true));
    return encoded;
}

string ECB_encrypt(string &plain)
{
    string cipher;

    ECB_Mode< AES >::Encryption e;
	e.SetKey(key, AES::MAX_KEYLENGTH);
	StringSource(plain, true, 
		new StreamTransformationFilter(e, new StringSink(cipher)));
    return cipher;
}

string CBC_encrypt(string &plain)
{
    string cipher;

    CBC_Mode< AES >::Encryption e;
    e.SetKeyWithIV(key, sizeof(key), iv);
    StringSource s(plain, true, 
        new StreamTransformationFilter(e, new StringSink(cipher)));
    return cipher;
}

string OFB_encrypt(string &plain)
{
    string cipher;

    OFB_Mode< AES >::Encryption e;
    e.SetKeyWithIV(key, sizeof(key), iv);
    StringSource(plain, true, 
        new StreamTransformationFilter(e, new StringSink(cipher)));
    return cipher;
}

string CFB_encrypt(string &plain)
{
    string cipher;

    CFB_Mode< AES >::Encryption e;
    e.SetKeyWithIV(key, sizeof(key), iv);
    StringSource(plain, true, 
        new StreamTransformationFilter(e, new StringSink(cipher)));
    return cipher;
}

string CTR_encrypt(string &plain)
{
    string cipher;

    CTR_Mode< AES >::Encryption e;
    e.SetKeyWithIV(key, sizeof(key), iv);
    StringSource(plain, true, 
        new StreamTransformationFilter(e, new StringSink(cipher)));
    return cipher;
}

string XTS_encrypt(string &plain)
{
    string cipher;

    XTS_Mode< AES >::Encryption enc;
    enc.SetKeyWithIV( key, sizeof(key), iv );
    StringSource ss( plain, true, 
        new StreamTransformationFilter(enc, new StringSink( cipher ), StreamTransformationFilter::NO_PADDING));
    return cipher;
}

string CCM_encrypt(string &pdata, CryptoPP::byte* truncatedIV)
{
	string cipher;

	const int TAG_SIZE = 8;
	CCM< AES, TAG_SIZE >::Encryption e;
    e.SetKeyWithIV( key, sizeof(key), truncatedIV, sizeof(truncatedIV));
    e.SpecifyDataLengths( 0, pdata.size(), 0);
    StringSource( pdata, true,
        new AuthenticatedEncryptionFilter(e, new StringSink( cipher )));
    return cipher;
}

string GCM_encrypt(string pdata, string adata)
{
	const int TAG_SIZE = 16;
	string cipher;

    GCM< AES >::Encryption e;
    e.SetKeyWithIV( key, sizeof(key), iv, sizeof(iv) );

    AuthenticatedEncryptionFilter ef( e,
        new StringSink( cipher ), false, TAG_SIZE
    );

    ef.ChannelPut( "AAD", (const CryptoPP::byte*)adata.data(), adata.size() );
    ef.ChannelMessageEnd("AAD");

    ef.ChannelPut( "", (const CryptoPP::byte*)pdata.data(), pdata.size() );
    ef.ChannelMessageEnd("");
    return cipher;
}

// -------------------------------------------- Other functions --------------------------------------------

void get_keyboard_key_iv()
{
    string keyHex;
    cout<<"Enter key (in hex):";
    cin >> keyHex;
    // decode key from hex -> byte
    StringSource(keyHex, true, 
        new HexDecoder(new ArraySink(key, sizeof(key))));

    string ivHex;
    cout<<"Enter IV (in hex):";
    cin >> ivHex;
    
    // decode iv from hex -> byte
    StringSource(ivHex, true, 
        new HexDecoder(new ArraySink(iv, sizeof(iv))));
}

void get_key_iv_from_file(string fileKey, string fileIV)
{
    // key file
    FileSource(fileKey.data(), true, 
        new HexDecoder(new ArraySink(key, sizeof(key))));
    // iv file
    FileSource(fileIV.data(), true, 
        new HexDecoder(new ArraySink(iv, sizeof(iv))));
}

string getPlainFromFile(string filename)
{
    string file_data;
    FileSource(filename.data(), true, 
        new StringSink(file_data));
    return file_data;
}

string enter(string kindOfText)
{
    int selection;
    string text;

    cout << "\n--- How do you want to enter " << kindOfText << ":";
    cout << "\n1. From keyboard";
    cout << "\n2. From file";
    cout << "\n-> Please enter a number (1-2): ";

    cin >> selection;
    switch (selection)
    {
        case 1:
        {
            cout <<"-> Enter " << kindOfText<< ": ";
            cin.ignore();
            getline(cin, text);
            break;  
        }
        case 2:
        {
            string filename;
            cout<<"-> Enter filename: ";
            cin >> filename;
            text = getPlainFromFile(filename);
        }
        default:
            break;
    }
    return text;
}

void write2File(string text)
{
    string filename;
    cout << "-> Enter filename: ";
    cin >> filename;
    StringSource(text, true, 
        new FileSink(filename.data()));

    cout << "(!) Complete writing to file " << filename << endl;
}

int enc_dec_Menu() 
{
    int mode;
    cout << "\n--- Choose your mode:\n"
    << "1.ECB, 2.CBC, 3.OFB, 4.CFB, 5.CTR, 6.XTS, 7.CCM, 8.GCM\n";

    cout << "-> Your mode (1-8): ";
    cin >> mode;

    return mode;
}

int display_Menu() 
{
    int display;

    cout << "\n---How do you want to display output:";
    cout << "\n1. Display in screen";
    cout << "\n2. Write on file";
    cout << "\n-> Please enter your number (1-2): ";

    cin >> display;
    
    return display;
}

int main_Menu()
{
    int select;

    cout << "\n--- Would you like to generate Key & IV, encrypt or decrypt message:";
    cout << "\n1. Generate key and iv";
    cout << "\n2. Encrypt";
    cout << "\n3. Decrypt";
    cout << "\n-> Please enter your number (1-3): ";
    
    cin >> select;
    return select;
}

int genkey_Menu()
{
    int keygen;
    
    cout << "\n--- How do you want to gen key:";
    cout << "\n1. Random";
    cout << "\n2. Input from screen";
    cout << "\n3. Input from file";
    cout << "\n-> Please enter your number (1-3): ";

    cin >> keygen;
    return keygen;
}
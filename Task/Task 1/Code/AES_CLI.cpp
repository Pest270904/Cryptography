#include "pch.h"

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
#include "cryptopp/modes.h"
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

// Define DLL export macro
#ifndef DLL_EXPORT
#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif
#endif

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

extern "C" {
    DLL_EXPORT void keyGen(char *keyFileName, char *ivFileName);
    DLL_EXPORT void AES_Encrypt(int choice, int mode, char *keyFileName, char *ivFileName, char *plain, char *cipherFileName, char *auth);
    DLL_EXPORT void AES_Decrypt(int choice, int mode, char *keyFileName, char *ivFileName, char *cipher, char *recoveredFileName, char *auth);
}

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
void write2File(string text, string file);

void keyGen(char *keyFileName, char *ivFileName)
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

    StringSource(key, sizeof(key), true,
        new HexEncoder(new FileSink(keyFileName)));

    StringSource(iv, sizeof(iv), true,
        new HexEncoder(new FileSink(ivFileName)));
}

void AES_Encrypt(int choice, int mode, char *keyFileName, char *ivFileName, char *plain, char *cipherFileName, char *auth)
{
    string plaintext, cipher, AAD;

    // key file
    FileSource(string(keyFileName).data(), true, 
        new HexDecoder(new ArraySink(key, sizeof(key))));
    // iv file
    FileSource(string(ivFileName).data(), true, 
        new HexDecoder(new ArraySink(iv, sizeof(iv))));

    if (choice == 0)
    {
        plaintext = string(plain);
    }
    else 
    {
        plaintext = getPlainFromFile(plain);
    }

    switch (mode)
    {
        case 1: // ECB encrypt
        {
            for (int i = 0; i < 10000; ++i) 
            {
                cipher = ECB_encrypt(plaintext); 
            }
            string cipherb64 = base64_encode(cipher);
            cout<<"Ciphertext(base 64): " << cipherb64 << endl;
            write2File(cipherb64, cipherFileName);
            break;
        }
        case 2: // CBC encrypt
        {
            for (int i = 0; i < 10000; ++i) 
            {
                cipher = CBC_encrypt(plaintext); 
            }
            string cipherb64 = base64_encode(cipher);
            cout<<"Ciphertext(base 64): " << cipherb64 << endl;
            write2File(cipherb64, cipherFileName);
            break;
        }
        case 3: // OFB encrypt
        {
            for (int i = 0; i < 10000; ++i) 
            {
                cipher = OFB_encrypt(plaintext); 
            }
            string cipherb64 = base64_encode(cipher);
            cout<<"Ciphertext(base 64): " << cipherb64 << endl;
            write2File(cipherb64, cipherFileName);
            break;
        }
        case 4: // CFB encrypt
        {
            for (int i = 0; i < 10000; ++i) 
            {
                cipher = CFB_encrypt(plaintext); 
            }
            string cipherb64 = base64_encode(cipher);
            cout<<"Ciphertext(base 64): " << cipherb64 << endl;
            write2File(cipherb64, cipherFileName);
            break;
        }
        case 5: // CTR encrypt
        {
            for (int i = 0; i < 10000; ++i) 
            {
                cipher = CTR_encrypt(plaintext); 
            }
            string cipherb64 = base64_encode(cipher);
            cout<<"Ciphertext(base 64): " << cipherb64 << endl;
            write2File(cipherb64, cipherFileName);
            break;
        }
        case 6: // XTS encrypt
        {
            for (int i = 0; i < 10000; ++i) 
            {
                cipher = XTS_encrypt(plaintext); 
            }
            string cipherb64 = base64_encode(cipher);
            cout<<"Ciphertext(base 64): " << cipherb64 << endl;
            write2File(cipherb64, cipherFileName);
            break;
        }
        case 7: // CCM encrypt
        {       
            CryptoPP::byte truncatedIV[13];
            memcpy(truncatedIV, iv, 13);
            for (int i = 0; i < 10000; ++i) 
            {
                cipher = CCM_encrypt(plaintext, truncatedIV); 
            }
            string cipherb64 = base64_encode(cipher);
            cout<<"Ciphertext(base 64): " << cipherb64 << endl;
            write2File(cipherb64, cipherFileName);
            break;
        }
        case 8: // GCM encrypt
        {
            AAD = string(auth);
            
            for (int i = 0; i < 10000; ++i) 
            {
                cipher = GCM_encrypt(plaintext, AAD); 
            }
            string cipherb64 = base64_encode(cipher);
            cout<<"Ciphertext(base 64): " << cipherb64 << endl;
            write2File(cipherb64, cipherFileName);
            break;
        }
    }
}

void AES_Decrypt(int choice, int mode, char *keyFileName, char *ivFileName, char *cipher, char *recoveredFileName, char *auth)
{
    string ciphertext, recovered, AAD;

    // key file
    FileSource(string(keyFileName).data(), true, 
        new HexDecoder(new ArraySink(key, sizeof(key))));
    // iv file
    FileSource(string(ivFileName).data(), true, 
        new HexDecoder(new ArraySink(iv, sizeof(iv))));

    if (choice == 0)
    {
        ciphertext = base64_decode(cipher);
    }
    else if (choice == 1)
    {
        ciphertext = base64_decode(getPlainFromFile(cipher));
    }

    switch (mode)
    {
        case 1: // ECB decrypt
        {
            for (int i = 0; i < 10000; ++i) 
            {
                recovered = ECB_decrypt(ciphertext); 
            }
            cout << "Recovered text: " << recovered << endl;
            write2File(recovered, recoveredFileName);
            break;
        }
        case 2: // CBC decrypt
        {
            for (int i = 0; i < 10000; ++i) 
            {
                recovered = CBC_decrypt(ciphertext); 
            }
            cout << "Recovered text: " << recovered << endl;
            write2File(recovered, recoveredFileName);
            break;                 
        }
        case 3: // OFB decrypt
        {
            for (int i = 0; i < 10000; ++i) 
            {
                recovered = OFB_decrypt(ciphertext); 
            }
            cout << "Recovered text: " << recovered << endl;
            write2File(recovered, recoveredFileName);
            break;
        }
        case 4: // CFB decrypt
        {
            for (int i = 0; i < 10000; ++i) 
            {
                recovered = CFB_decrypt(ciphertext); 
            }
            cout << "Recovered text: " << recovered << endl;
            write2File(recovered, recoveredFileName);
            break;
        }
        case 5: // CTR decrypt
        {
            for (int i = 0; i < 10000; ++i) 
            {
                recovered = CTR_decrypt(ciphertext); 
            }
            cout << "Recovered text: " << recovered << endl;
            write2File(recovered, recoveredFileName);
            break;
        }
        case 6: // XTS decrypt
        {
            for (int i = 0; i < 10000; ++i) 
            {
                recovered = XTS_decrypt(ciphertext); 
            }
            cout << "Recovered text: " << recovered << endl;
            write2File(recovered, recoveredFileName);
            break;
        }
        case 7: // CCM decrypt
        {
            string rpdata;
            CryptoPP::byte truncatedIV[13];
            memcpy(truncatedIV, iv, 13);
            for (int i = 0; i < 10000; ++i) 
            {
                rpdata = CCM_decrypt(ciphertext, truncatedIV);
            }
            cout << "Recovered text: " << rpdata << endl;
            write2File(rpdata, recoveredFileName);
            break;
        }
        case 8: // GCM decrypt
        {
            AAD = string(auth);

            pair<string, string> out;
            for (int i = 0; i < 10000; ++i) 
            {
                out = GCM_decrypt(ciphertext, AAD);
            }
            string radata = out.first, rpdata = out.second;
            cout << "Recovered text: " << rpdata << endl;
            write2File(rpdata, recoveredFileName);
            cout << "Recovered adata: " << radata << endl;
            break;
        }
        default:
        {
            cout << "Invalid option";
            return ;
        }
    }    
}

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

    if (argc == 1)
    {
        cerr << "Usage: aes <mode>" << endl;
        cerr << "Mode: keygen, enc, dec" << endl;
        return 1;
    }

    int choose;
    if (string(argv[1]) == "keygen")
        choose = 1;
    else if (string(argv[1]) == "enc")
        choose = 2;
    else if (string(argv[1]) == "dec")
        choose = 3;
    else 
    {
        cerr << "Invalid mode:" << argv[1] << endl;
        return 1;
    }

    int mode = 0;
    switch (choose) 
    {
        case 1: 
        {
            if (argc != 4)
            {
                cerr << "Usage: aes keygen <keyFileName> <ivFileName>" << endl;
                return 1;
            }

            keyGen(argv[2], argv[3]);
            return 1;
        }
        case 2:
        {
            if (argc < 7)
            {
                cerr << "Usage: aes enc <choice> <mode> <keyFileName> <ivFileName> <plain_text/file> <cipherFileName>\n";
                cerr << "   + mode: ECB, CBC, OFB, CFB, CTR, XTS, CCM, GCM\n";
                cerr << "   + choice: 0 if you want input from keyboard, 1 if you want to input from file\n";
                return 1;
            }

            if (strcmp(argv[3], "ECB") == 0)
                mode = 1;
            else if (strcmp(argv[3], "CBC") == 0)
                mode = 2;
            else if (strcmp(argv[3], "OFB") == 0)
                mode = 3;
            else if (strcmp(argv[3], "CFB") == 0)
                mode = 4;
            else if (strcmp(argv[3], "CTR") == 0)
                mode = 5;
            else if (strcmp(argv[3], "XTS") == 0)
                mode = 6;
            else if (strcmp(argv[3], "CCM") == 0)
                mode = 7;
            else if (strcmp(argv[3], "GCM") == 0)
                {
                    if(argc != 9)
                    {
                        cerr << "Usage: aes enc <choice> GCM <keyFileName> <ivFileName> <plain_text/file> <cipherFileName> <AAD>\n";
                        return 1;
                    }
                    mode = 8;
                }

            AES_Encrypt(stoi(argv[2]), mode, argv[4], argv[5], argv[6], argv[7], argv[8]);
            break;
        }
        case 3:
        {
            if (argc < 7)
            {
                cerr << "Usage: aes dec <choice> <mode> <keyFileName> <ivFileName> <cipher_text/file> <recoveredFileName>";
                return 1;
            }

            if (strcmp(argv[3], "ECB") == 0)
                mode = 1;
            else if (strcmp(argv[3], "CBC") == 0)
                mode = 2;
            else if (strcmp(argv[3], "OFB") == 0)
                mode = 3;
            else if (strcmp(argv[3], "CFB") == 0)
                mode = 4;
            else if (strcmp(argv[3], "CTR") == 0)
                mode = 5;
            else if (strcmp(argv[3], "XTS") == 0)
                mode = 6;
            else if (strcmp(argv[3], "CCM") == 0)
                mode = 7;
            else if (strcmp(argv[3], "GCM") == 0)
                {
                    if(argc != 9)
                    {
                        cerr << "Usage: aes dec <choice> GCM <keyFileName> <ivFileName> <cipher_text/file> <recoveredFileName> <AAD>\n";
                        return 1;
                    }
                    mode = 8;
                }

            AES_Decrypt(stoi(argv[2]), mode, argv[4], argv[5], argv[6], argv[7], argv[8]);
            break;
        }
        default:
        {
            cerr << "Invalid option!!" << endl;
            return 0;
        }
    }
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

void write2File(string text, string file)
{
    string filename = string(file);
    StringSource(text, true, 
        new FileSink(filename.data()));

    cout << "(!) Complete writing to file " << filename << endl;
}
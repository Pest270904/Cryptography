//#include "pch.h"

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
    DLL_EXPORT void DES_Encrypt(int choice, int mode, char *keyFileName, char *ivFileName, char *plain, char *cipherFileName);
    DLL_EXPORT void DES_Decrypt(int choice, int mode, char *keyFileName, char *ivFileName, char *cipher, char *recoveredFileName);
}

using namespace std;
using namespace CryptoPP;
CryptoPP::byte key[DES::DEFAULT_KEYLENGTH];
CryptoPP::byte iv[DES::BLOCKSIZE];

// -------------------------------------------- Decrypt --------------------------------------------
string DES_ECB_decrypt(string &cipher);
string DES_CBC_decrypt(string &cipher);
string DES_OFB_decrypt(string &ciphertext);
string DES_CFB_decrypt(string &ciphertext);
string DES_CTR_decrypt(string &ciphertext);

// -------------------------------------------- Encrypt --------------------------------------------
string base64_decode(string enc);
string base64_encode(string text);
string DES_ECB_encrypt(string &plain);
string DES_CBC_encrypt(string &plain);
string DES_OFB_encrypt(string &plain);
string DES_CFB_encrypt(string &plain);
string DES_CTR_encrypt(string &plain);

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

void DES_Encrypt(int choice, int mode, char *keyFileName, char *ivFileName, char *plain, char *cipherFileName)
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
                cipher = DES_ECB_encrypt(plaintext); 
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
                cipher = DES_CBC_encrypt(plaintext); 
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
                cipher = DES_OFB_encrypt(plaintext); 
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
                cipher = DES_CFB_encrypt(plaintext); 
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
                cipher = DES_CTR_encrypt(plaintext); 
            }
            string cipherb64 = base64_encode(cipher);
            cout<<"Ciphertext(base 64): " << cipherb64 << endl;
            write2File(cipherb64, cipherFileName);
            break;
        }
    }
}

void DES_Decrypt(int choice, int mode, char *keyFileName, char *ivFileName, char *cipher, char *recoveredFileName)
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
                recovered = DES_ECB_decrypt(ciphertext); 
            }
            cout << "Recovered text: " << recovered << endl;
            write2File(recovered, recoveredFileName);
            break;
        }
        case 2: // CBC decrypt
        {
            for (int i = 0; i < 10000; ++i) 
            {
                recovered = DES_CBC_decrypt(ciphertext); 
            }
            cout << "Recovered text: " << recovered << endl;
            write2File(recovered, recoveredFileName);
            break;                 
        }
        case 3: // OFB decrypt
        {
            for (int i = 0; i < 10000; ++i) 
            {
                recovered = DES_OFB_decrypt(ciphertext); 
            }
            cout << "Recovered text: " << recovered << endl;
            write2File(recovered, recoveredFileName);
            break;
        }
        case 4: // CFB decrypt
        {
            for (int i = 0; i < 10000; ++i) 
            {
                recovered = DES_CFB_decrypt(ciphertext); 
            }
            cout << "Recovered text: " << recovered << endl;
            write2File(recovered, recoveredFileName);
            break;
        }
        case 5: // CTR decrypt
        {
            for (int i = 0; i < 10000; ++i) 
            {
                recovered = DES_CTR_decrypt(ciphertext); 
            }
            cout << "Recovered text: " << recovered << endl;
            write2File(recovered, recoveredFileName);
            break;
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
        cerr << "Usage: des <mode>" << endl;
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
                cerr << "Usage: des keygen <keyFileName> <ivFileName>" << endl;
                return 1;
            }

            keyGen(argv[2], argv[3]);
            return 1;
        }
        case 2:
        {
            if (argc < 7)
            {
                cerr << "Usage: des enc <choice> <mode> <keyFileName> <ivFileName> <plain_text/file> <cipherFileName>\n";
                cerr << "   + mode: ECB, CBC, OFB, CFB, CTR\n";
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

            DES_Encrypt(stoi(argv[2]), mode, argv[4], argv[5], argv[6], argv[7]);
            break;
        }
        case 3:
        {
            if (argc < 7)
            {
                cerr << "Usage: des dec <choice> <mode> <keyFileName> <ivFileName> <cipher_text/file> <recoveredFileName>";
                cerr << "   + mode: ECB, CBC, OFB, CFB, CTR\n";
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

            DES_Decrypt(stoi(argv[2]), mode, argv[4], argv[5], argv[6], argv[7]);
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

string DES_ECB_decrypt(string &cipher){
    string recovered;
    ECB_Mode<CryptoPP::DES>::Decryption d;
    d.SetKey(key, sizeof(key));
    StringSource s(cipher, true, 
        new StreamTransformationFilter(d, new StringSink(recovered)));
    return recovered;
}

string DES_CBC_decrypt(string &cipher){
    string recovered;
    CBC_Mode<DES>::Decryption d;
    d.SetKeyWithIV(key, sizeof(key), iv);
    StringSource s(cipher, true, 
        new StreamTransformationFilter(d, new StringSink(recovered)));
    return recovered;
}

string DES_OFB_decrypt(string &cipher){
    string recovered;
    OFB_Mode<DES>::Decryption d;
    d.SetKeyWithIV(key, sizeof(key), iv);
    StringSource s(cipher, true, 
        new StreamTransformationFilter(d, new StringSink(recovered)));
    return recovered;
}

string DES_CFB_decrypt(string &cipher){
    string recovered;
    CFB_Mode< DES >::Decryption d;
    d.SetKeyWithIV(key, sizeof(key), iv);
    StringSource s(cipher, true, 
        new StreamTransformationFilter(d, new StringSink(recovered)));
    return recovered;
}

string DES_CTR_decrypt(string &cipher){
    string recovered;
    CTR_Mode< DES >::Decryption d;
    d.SetKeyWithIV(key, sizeof(key), iv);
    StringSource s(cipher, true, 
        new StreamTransformationFilter(d, new StringSink(recovered)));
    return recovered;
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

string DES_ECB_encrypt(string &plain){
    string cipher;

    ECB_Mode< DES >::Encryption e;
	e.SetKey(key, DES::DEFAULT_KEYLENGTH);
	StringSource(plain, true, 
		new StreamTransformationFilter(e, new StringSink(cipher)));
    return cipher;
}
string DES_CBC_encrypt(string &plain){
    string cipher;

    CBC_Mode< DES >::Encryption e;
    e.SetKeyWithIV(key, sizeof(key), iv);
    StringSource s(plain, true, 
        new StreamTransformationFilter(e, new StringSink(cipher)));
    return cipher;
}
string DES_OFB_encrypt(string &plain){
    string cipher;

    OFB_Mode< DES >::Encryption e;
    e.SetKeyWithIV(key, sizeof(key), iv);
    StringSource s(plain, true, 
        new StreamTransformationFilter(e, new StringSink(cipher)));
    return cipher;
}

string DES_CFB_encrypt(string &plain){
    string cipher;

    CFB_Mode< DES >::Encryption e;
    e.SetKeyWithIV(key, sizeof(key), iv);
    StringSource s(plain, true, 
        new StreamTransformationFilter(e, new StringSink(cipher)));
    return cipher;
}

string DES_CTR_encrypt(string &plain){
    string cipher;

    CTR_Mode< DES >::Encryption e;
    e.SetKeyWithIV(key, sizeof(key), iv);
    StringSource s(plain, true, 
        new StreamTransformationFilter(e, new StringSink(cipher)));
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
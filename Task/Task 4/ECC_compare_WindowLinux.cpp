#include <assert.h>
#include <windows.h>
#include <fstream>
#include <chrono>

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "cryptopp/osrng.h"
using CryptoPP::AutoSeededRandomPool;

#include "cryptopp/aes.h"
using CryptoPP::AES;

#include "cryptopp/integer.h"
using CryptoPP::Integer;

#include "cryptopp/sha.h"
using CryptoPP::SHA1;
#include "cryptopp/pem.h"
#include "cryptopp/pem_common.h"
#include "cryptopp/filters.h"
using CryptoPP::StringSource;
using CryptoPP::StringSink;
using CryptoPP::ArraySink;
using CryptoPP::SignerFilter;
using CryptoPP::SignatureVerificationFilter;

#include <cryptopp/hex.h>

#include "cryptopp/files.h"
using CryptoPP::FileSource;
using CryptoPP::FileSink;

#include "cryptopp/eccrypto.h"
using CryptoPP::ECDSA;
using CryptoPP::ECP;
using CryptoPP::DL_GroupParameters_EC;
using CryptoPP::HexEncoder;
using CryptoPP::HexDecoder;

#include "cryptopp/oids.h"
using CryptoPP::OID;

// Define DLL export macro 
#ifndef DLL_EXPORT 
#ifdef _WIN32 
#define DLL_EXPORT __declspec(dllexport)  //declspec = define class specipher
#else 
#define DLL_EXPORT 
#endif 
#endif

// Declare functions with extern "C" to prevent name mangling in C++ 
extern "C" {
    DLL_EXPORT bool key_gen(const char* filePriv, const char* filePub, const char* format);
    DLL_EXPORT void SignMessage(int choice, const char* filekey, const char* messageText, const char* outputFileName);
    DLL_EXPORT int VerifyMessage(int choice, const char* filePub, const char* messageText, const char* signFileName);
}

bool GeneratePrivateKey(const OID& oid, ECDSA<ECP, SHA1>::PrivateKey& key);
bool GeneratePublicKey(const ECDSA<ECP, SHA1>::PrivateKey& privateKey, ECDSA<ECP, SHA1>::PublicKey& publicKey);
void SavePrivateKey(const string& filename, const ECDSA<ECP, SHA1>::PrivateKey& key);
void SavePublicKey(const string& filename, const ECDSA<ECP, SHA1>::PublicKey& key);

int detect_pem_pri(const char* filename);
int detect_pem_pub(const char* filename);

void LoadPrivateKey(const char* filename, ECDSA<ECP, SHA1>::PrivateKey& key);
void LoadPublicKey(const string& filename, ECDSA<ECP, SHA1>::PublicKey& key);

bool key_gen(const char* filePriv, const char* filePub, const char* format)
{
    bool result = false;
    // Private and Public keys
    ECDSA<ECP, SHA1>::PrivateKey privateKey;
    ECDSA<ECP, SHA1>::PublicKey publicKey;

    // Generate Keys
    result = GeneratePrivateKey(CryptoPP::ASN1::secp160r1(), privateKey);
    assert(true == result);
    if (!result) { return 0; }

    result = GeneratePublicKey(privateKey, publicKey);
    assert(true == result);
    if (!result) { return 0; }

    string strFormat = string(format);
    if (strFormat == "DER")
    {
        SavePrivateKey(filePriv, privateKey);
        SavePublicKey(filePub, publicKey);
    }
    else if (strFormat == "PEM")
    {
        FileSink pub(filePub, true);
        PEM_Save(pub, publicKey);
        FileSink priv(filePriv, true);
        PEM_Save(priv, privateKey);
    }
    else {
        cout << "Please choose format: DER or PEM\n";
        return 0;
    }

    cout << "Key generated succesfully!\n";
    return 1;
}

void SignMessage(int choice, const char* filekey, const char* messageText, const char* outputFileName)  
{
    int MAXLENGTH = 3072;
    AutoSeededRandomPool prng;
    ECDSA<ECP, SHA1>::PrivateKey key;
    try
    {
        int fileType = detect_pem_pri(filekey);
        if (fileType == 1)
        {
            FileSource fs(filekey, true);
            PEM_Load(fs, key);
        }
        else if (fileType == 0)
            LoadPrivateKey(filekey, key);
        else
        {
            cout << "Can't open private key file\n";
            return;
        }
    }
    catch (const std::exception&)
    {
        cout << "Fail to load ECDSA key!!!\n";
        return;
    }
        
    string m;
    if (choice == 1) // from file
        FileSource(messageText, true, new StringSink(m));
    else if (choice == 2) // from keyboard
        m = string(messageText);
    else
    {
        cout << "Invalid option !!!\n";
        return;
    }

    string sign;
    StringSource(m, true,
        new SignerFilter(prng,
            ECDSA<ECP, SHA1>::Signer(key),
            new StringSink(sign)
        ) // SignerFilter
    ); // StringSource

    //  + print out signature to terminal in hex
    // string signHex;
    // StringSource(sign, true, new HexEncoder(new StringSink(signHex)));
    // cout << "Signature: " << signHex;

    CryptoPP::StringSource(sign, true,
        new CryptoPP::HexEncoder(new CryptoPP::FileSink(outputFileName)));
}

int VerifyMessage(int choice, const char* filePub, const char* messageText, const char* signFileName)
{
    int MAXLENGTH = 3072;
    bool result = false;
    ECDSA<ECP, SHA1>::PublicKey key;
    try
    {
        int fileType = detect_pem_pub(filePub);
        if (fileType == 1)
        {
            FileSource fs(filePub, true);
            PEM_Load(fs, key);
        }
        else if (fileType == 0)
            LoadPublicKey(filePub, key);
        else
        {
            cout << "Can't open file key!!!\n";
            return 0;
        }
    }
    catch (const std::exception&)
    {
        cout << "Fail to load ECDSA key!!\n";
        return 0;
    }
    
    string m;
    if (choice == 1) // from file
        FileSource(messageText, true, new StringSink(m));
    else if (choice == 2) // from keyboard
        m = string(messageText);
    else
    {
        cout << "Invalid option !!\n";
        return 0;
    }

    string strSignHex;
    FileSource file(signFileName, true, new StringSink(strSignHex));

    string signature;
    StringSource(strSignHex, true, new HexDecoder(new StringSink(signature)));

    ECDSA<ECP, SHA1>::Verifier verifier(key);
    StringSource ss(signature + m, true,
        new SignatureVerificationFilter(
            verifier,
            new ArraySink( (byte*)&result, sizeof(result))
        ) // SignatureVerificationFilter
    );

    if (result)
        return 1;
    return 0;
}

int main(int argc, char* argv[]) {
    #ifdef __linux__
        std::locale::global(std::locale("C.UTF-8"));
    #endif
    #ifdef _WIN32
        // Set console code page to UTF-8 on Windows
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #endif

    if (argc == 1) {
        std::cerr << "Usage: " + string(argv[0]) + " <keygen|sign|verify> <other arguments>\n";
        return 1;
    }

    string mode = string(argv[1]);
    if (mode == "keygen") {
        if (argc != 5) {
            std::cerr << "Usage: " + string(argv[0]) + " keygen <privateFileName> <publicFileName> <format>\n";
            std::cerr << "      + format: DER or PEM\n";
            return 1;
        }

        auto start = std::chrono::high_resolution_clock::now();

        key_gen(argv[2], argv[3], argv[4]);

        auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		cout << "Time for key generation: " << static_cast<double>(duration) << " ms" << endl;
    }
    else if (mode == "sign") {
        if (argc != 6) {
            std::cerr << "Usage: " + string(argv[0]) + " sign <choice> <privateKeyFile> <message/messageFileName> <ouputFileName>\n";
            std::cerr << "      + choice: '1' if msg from file, '2' if msg from keyboard\n";
            return 1;
        }

        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < 100; i++)
            SignMessage(std::stoi(argv[2]), argv[3], argv[4], argv[5]);

        auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		cout << "Average time for signing message over 100 times: " << static_cast<double>(duration) / 100 << " ms" << endl;
    }
    else if (mode == "verify") {
        if (argc != 6) {
            std::cerr << "Usage: " + string(argv[0]) + " verify <choice> <publicKeyFile> <message/messageFileName> <signatureFileName>\n";
            std::cerr << "      + choice: '1' if msg from file, '2' if msg from keyboard\n";
            return 1;
        }

        auto start = std::chrono::high_resolution_clock::now();

        int success = 0;

        for (int i = 0; i < 100; i++)
            success = VerifyMessage(std::stoi(argv[2]), argv[3], argv[4], argv[5]);

        if(success == 1) 
            cout << "Verify succesfully!\n";
        else
            cout << "Failed to verify!\n";

        auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		cout << "Average time for verifying message over 100 times: " << static_cast<double>(duration) / 100 << " ms" << endl;
    }
    else {
        std::cerr << "Invalid mode!!\n";
        return 1;
    }
}

bool GeneratePrivateKey(const OID& oid, ECDSA<ECP, SHA1>::PrivateKey& key)
{
    AutoSeededRandomPool prng;

    key.Initialize(prng, oid);
    assert(key.Validate(prng, 3));

    return key.Validate(prng, 3);
}

bool GeneratePublicKey(const ECDSA<ECP, SHA1>::PrivateKey& privateKey, ECDSA<ECP, SHA1>::PublicKey& publicKey)
{
    AutoSeededRandomPool prng;

    // Sanity check
    assert(privateKey.Validate(prng, 3));

    privateKey.MakePublicKey(publicKey);
    assert(publicKey.Validate(prng, 3));

    return publicKey.Validate(prng, 3);
}

void SavePrivateKey(const string& filename, const ECDSA<ECP, SHA1>::PrivateKey& key)
{
    key.Save(FileSink(filename.c_str(), true /*binary*/).Ref());
}

void SavePublicKey(const string& filename, const ECDSA<ECP, SHA1>::PublicKey& key)
{
    key.Save(FileSink(filename.c_str(), true /*binary*/).Ref());
}

int detect_pem_pri(const char* filename) 
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        return 2; // error 
    }
    string line;
    getline(file, line);
    if (line != "-----BEGIN EC PRIVATE KEY-----")
    {
        return 0;
    }
    while (getline(file, line)) {
        if (line == "-----END EC PRIVATE KEY-----") {
            return 1; // is PEM
        }
    }
    return 0; // is BER
}

int detect_pem_pub(const char* filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        return 2; // error 
    }
    string line;
    getline(file, line);
    if (line != "-----BEGIN PUBLIC KEY-----")
    {
        return 0;
    }
    while (getline(file, line)) {
        if (line == "-----END PUBLIC KEY-----") {
            return 1; // is PEM
        }
    }
    return 0; // is BER
}

void LoadPrivateKey(const char* filename, ECDSA<ECP, SHA1>::PrivateKey& key)
{
    key.Load(FileSource(filename, true /*pump all*/).Ref());
}

void LoadPublicKey(const string& filename, ECDSA<ECP, SHA1>::PublicKey& key)
{
    key.Load(FileSource(filename.c_str(), true /*pump all*/).Ref());
}
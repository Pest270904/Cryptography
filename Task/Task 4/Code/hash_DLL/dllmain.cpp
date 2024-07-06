// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::ifstream;

#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#include <windows.h>
#endif
#include <chrono>
#include <clocale>

#include "cryptopp/cryptlib.h"
#include "cryptopp/sha3.h"
#include "cryptopp/sha.h"
#include "cryptopp/shake.h"
#include "cryptopp/hex.h"
#include "cryptopp/files.h"
using CryptoPP::FileSink;

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
    DLL_EXPORT void hash(int choice, char* algo, char* plainText, char* outputFileName, int digestLength);
}

void hash(int choice, char* algo, char* plainText, char* outputFileName, int digestLength)
{
    string msg;
    if (choice == 0)
        msg = string(plainText);
    else {
        ifstream file(plainText, std::ios::binary);
        string mess((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        msg = mess;
    }

    std::unique_ptr<CryptoPP::HashTransformation> hash;
    string hashAlgo = string(algo);
    transform(hashAlgo.begin(), hashAlgo.end(), hashAlgo.begin(), ::toupper);
    if (hashAlgo == "SHA3_224")
        hash.reset(new CryptoPP::SHA3_224);
    else if (hashAlgo == "SHA3_256")
        hash.reset(new CryptoPP::SHA3_256);
    else if (hashAlgo == "SHA3_384")
        hash.reset(new CryptoPP::SHA3_384);
    else if (hashAlgo == "SHA3_512")
        hash.reset(new CryptoPP::SHA3_512);
    else if (hashAlgo == "SHA224")
        hash.reset(new CryptoPP::SHA224);
    else if (hashAlgo == "SHA256")
        hash.reset(new CryptoPP::SHA256);
    else if (hashAlgo == "SHA384")
        hash.reset(new CryptoPP::SHA384);
    else if (hashAlgo == "SHA512")
        hash.reset(new CryptoPP::SHA512);
    else if (hashAlgo == "SHAKE128")
        hash.reset(new CryptoPP::SHAKE128(digestLength));
    else if (hashAlgo == "SHAKE256")
        hash.reset(new CryptoPP::SHAKE256(digestLength));
    else {
        cerr << "Invalid option";
        return;
    }

    string digest;
    string encoded;

    hash->Update((const CryptoPP::byte*)msg.data(), msg.size());
    digest.resize(hash->DigestSize());
    hash->Final((CryptoPP::byte*)&digest[0]);

    // Print out digest on screen in hex
    // CryptoPP::StringSource(digest, true,
    //     new CryptoPP::HexEncoder(new CryptoPP::StringSink(encoded)));
    // std::cout << "Digest: " << encoded << std::endl;

    CryptoPP::StringSource(digest, true,
        new CryptoPP::HexEncoder(new CryptoPP::FileSink(outputFileName)));
}

int main(int argc, char* argv[])
{
#ifdef linux
    std::locale::global(std::locale("C.UTF-8"));
#endif

#ifdef _WIN32
    // Set console code page to UTF-8 on Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    if (argc == 1)
    {
        cerr << "Usage: " + string(argv[0]) + " <choice> <Hash algo> <plainText> <outputFileName> (<hash's length>) " << endl;
        cerr << "   + Choice: '0' if plainText from keyboard, '1' if plainText from file" << endl;
        cerr << "   + Hash algo: SHA224, SHA256, SHA384, SHA512, SHA3_224, SHA3_256, SHA3_384, SHA3_512, SHAKE128, SHAKE256" << endl;
        cerr << "   + hash's length: even number which is a length of digest when hash_algo is 'SHAKE128' or 'SHAKE256'" << endl;
        return 1;
    }

    if (string(argv[2]) == "SHAKE128" || string(argv[2]) == "SHAKE256") {
        if (argc != 6) {
            cerr << "Usage: " + string(argv[0]) + " <choice> <SHAKE128 | SHAKE256> <plainText> <outputFileName> <hash's length> " << endl;
            cerr << "   + Choice: '0' if plainText from keyboard, '1' if plainText from file" << endl;
            cerr << "   + Hash algo: SHA224, SHA256, SHA384, SHA512, SHA3_224, SHA3_256, SHA3_384, SHA3_512, SHAKE128, SHAKE256" << endl;
            cerr << "   + hash's length: even number which is a length of digest when hash_algo is 'SHAKE128' or 'SHAKE256'" << endl;
            return 1;
        }

        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < 1000; i++)
            hash(std::stoi(argv[1]), argv[2], argv[3], argv[4], std::stoi(argv[5]));

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        double time = static_cast<double>(duration) / 1000;
        cout << "Average time for hashing over 1000 times: " << time << " ms" << std::endl;
    }
    else {
        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < 1000; i++)
            hash(std::stoi(argv[1]), argv[2], argv[3], argv[4], 0);

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        double time = static_cast<double>(duration) / 1000;
        cout << "Average time for hashing over 1000 times: " << time << " ms" << std::endl;
    }

    return 0;
}


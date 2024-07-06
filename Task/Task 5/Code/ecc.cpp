// OpenSSL library
#include "openssl/evp.h"
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/sha.h> // Include for SHA256
#include <openssl/ecdsa.h>

// Cryptopp library
#include "cryptopp/files.h"
#include "cryptopp/rsa.h"
#include "cryptopp/osrng.h"
#include "cryptopp/eccrypto.h"
#include "cryptopp/oids.h"
#include "cryptopp/hex.h"
#include "cryptopp/files.h"
#include "cryptopp/filters.h"
#include "cryptopp/queue.h"
#include "cryptopp/oids.h"
using CryptoPP::ByteQueue;
using CryptoPP::BufferedTransformation;
#include "cryptopp/base64.h"

// C++ library
#include <fstream>
#include <iterator> // Include for std::istreambuf_iterator
#include <vector> // Include for std::vector
#include <iostream>
#include <assert.h>
#include <string>
#include <iomanip>
using std::string;
#ifdef _WIN32
#include <windows.h>
#endif

#ifndef DLL_EXPORT 
#ifdef _WIN32 
#define DLL_EXPORT __declspec(dllexport) 
#else 
#define DLL_EXPORT 
#endif 
#endif

extern "C" {
    DLL_EXPORT int keygen(const char* filePrivate, const char* filePublic, const char* format);
    DLL_EXPORT int sign(int choice, const char* filePrivate, const char* filename, const char* signFile);
    DLL_EXPORT int verify(const char* filePublic, const char* filename, const char* signFile);
}

bool IsPemEncoded_Pub(const string& filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
	{
		return 2;
	}
	string line;
	std::getline(file, line);
	if (line != "-----BEGIN PUBLIC KEY-----")
	{
		return 0;
	}
	while (std::getline(file, line)) {
		if (line == "-----END PUBLIC KEY-----") {
			return 1;
		}
	}
	return 0;
}

bool IsPemEncoded_Pri(const string& filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
	{
		return 2;
	}
	string line;
	std::getline(file, line);
	if (line != "-----BEGIN PRIVATE KEY-----")
	{
		return 0;
	}
	while (std::getline(file, line)) {
		if (line == "-----END PRIVATE KEY-----") {
			return 1;
		}
	}
	return 0;
}

int keygen(const char* filePrivate, const char* filePublic, const char* format) {
    int result = 0;
    EVP_PKEY* pkey = nullptr;
    EVP_PKEY_CTX* pctx = nullptr;
    FILE* privFile = nullptr;
    FILE* pubFile = nullptr;

    // Initialize OpenSSL library
    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();

    try {
        pctx = EVP_PKEY_CTX_new_id(EVP_PKEY_EC, nullptr);
        EVP_PKEY_keygen_init(pctx);
        EVP_PKEY_CTX_set_ec_paramgen_curve_nid(pctx, NID_X9_62_prime256v1);
        EVP_PKEY_keygen(pctx, &pkey);

        if (string(format) == "DER") {
            // Save the private key to a file in DER format
            privFile = fopen(filePrivate, "wb");
            i2d_PrivateKey_fp(privFile, pkey);
            fclose(privFile);

            // Save the public key to a file in DER format
            pubFile = fopen(filePublic, "wb");
            i2d_PUBKEY_fp(pubFile, pkey);
            fclose(pubFile);

            privFile = nullptr;
            pubFile = nullptr;

        } else if (string(format) == "PEM") {
            // Save the private key to a file in PEM format
            privFile = fopen(filePrivate, "wb");
            PEM_write_PrivateKey(privFile, pkey, nullptr, nullptr, 0, nullptr, nullptr);
            fclose(privFile);

            // Save the public key to a file in PEM format
            pubFile = fopen(filePublic, "wb");
            PEM_write_PUBKEY(pubFile, pkey);
            fclose(pubFile);

            privFile = nullptr;
            pubFile = nullptr;
        }
        else {
            std::cerr << "Unsupported format, please choose PEM or DER";
            return 0;
        }

        result = 1;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        if (privFile) fclose(privFile);
        if (pubFile) fclose(pubFile);
    }

    if (pkey) EVP_PKEY_free(pkey);
    if (pctx) EVP_PKEY_CTX_free(pctx);
    ERR_free_strings();

    return result;
}

int sign(int choice, const char* filePrivate, const char* filename, const char* signFile) {
    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();
    BIO* bio = BIO_new(BIO_s_file());
    BIO_read_filename(bio, filePrivate);
    EVP_PKEY* privateKey = nullptr;

    // Load file private key
    try {
        if (IsPemEncoded_Pri(filePrivate)) {
            privateKey = PEM_read_bio_PrivateKey(bio, NULL, NULL, NULL);
            BIO_free(bio);
        }
        else {
            privateKey = d2i_PrivateKey_bio(bio, nullptr);
            BIO_free(bio);
        }
    }
    catch (std::exception& ex) {
        return 1;
    }

    unsigned char hash[SHA256_DIGEST_LENGTH];

    try {
        if (choice == 0)
        {
            std::ifstream pdfFile(filename, std::ios::binary);
            std::vector<unsigned char> pdfContents((std::istreambuf_iterator<char>(pdfFile)), std::istreambuf_iterator<char>());
            SHA256(&pdfContents[0], pdfContents.size(), hash);
            pdfFile.close();
        }
        else 
        {
            std::string content = string(filename);
            std::vector<unsigned char> pdfContents(content.begin(), content.end());
            SHA256(&pdfContents[0], pdfContents.size(), hash);
        }
    }
    catch (std::exception& ex) {
        return 2;
    }

    EVP_MD_CTX* mdCtx = EVP_MD_CTX_new();
    EVP_SignInit(mdCtx, EVP_sha256());
    EVP_SignUpdate(mdCtx, hash, SHA256_DIGEST_LENGTH);

    unsigned int signatureLen = EVP_PKEY_size(privateKey);
    std::vector<unsigned char> signature(signatureLen);

    if (!EVP_SignFinal(mdCtx, &signature[0], &signatureLen, privateKey)) {
        EVP_MD_CTX_free(mdCtx);
        EVP_PKEY_free(privateKey);
        return 3;
    }
    
    std::ofstream signaturefile(signFile, std::ios::binary);
    signaturefile.write(reinterpret_cast<const char*>(&signature[0]), signatureLen);
    signaturefile.close();

    EVP_MD_CTX_free(mdCtx);
    EVP_PKEY_free(privateKey);
    EVP_cleanup();
    ERR_free_strings();
    return 0;
}

int verify(const char* filePublic, const char* filename, const char* signFile) {
    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();
    BIO* bio = BIO_new(BIO_s_file());
    BIO_read_filename(bio, filePublic);
    EVP_PKEY* publicKey = nullptr;

    if (IsPemEncoded_Pub(filePublic)) {
        
        publicKey = PEM_read_bio_PUBKEY(bio, NULL, NULL, NULL);
        BIO_free(bio);
    }
    else {
        publicKey = d2i_PUBKEY_bio(bio, nullptr);
        BIO_free(bio);
    }

    if (!publicKey) {
        return 1;
    }

    std::ifstream signatureFile(signFile, std::ios::binary);
    if (!signatureFile.is_open()) {
        return 2;
    }
    std::vector<unsigned char> signature((std::istreambuf_iterator<char>(signatureFile)), std::istreambuf_iterator<char>());
    signatureFile.close();
    std::ifstream originalFile(filename, std::ios::binary);
    if (!originalFile.is_open()) {
        return 3;
    }

    std::vector<unsigned char> originalContents((std::istreambuf_iterator<char>(originalFile)), std::istreambuf_iterator<char>());
    originalFile.close();
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(&originalContents[0], originalContents.size(), hash);
    EVP_MD_CTX* mdCtx = EVP_MD_CTX_new();
    EVP_VerifyInit(mdCtx, EVP_sha256());
    EVP_VerifyUpdate(mdCtx, hash, SHA256_DIGEST_LENGTH);
    if (EVP_VerifyFinal(mdCtx, &signature[0], signature.size(), publicKey) != 1) {
        EVP_MD_CTX_free(mdCtx);
        EVP_PKEY_free(publicKey);
        return 4;
    }

    EVP_MD_CTX_free(mdCtx);
    EVP_PKEY_free(publicKey);
    EVP_cleanup();
    ERR_free_strings();
    return 0;
}

int main(int argc, char *argv[])
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    if (argc == 1) {
        std::cerr << "Usage: " + string(argv[0]) + " <keygen|sign|verify> <other arguments>\n";
        return 1;
    }

    string mode = string(argv[1]);

    string module = argv[1];
    if (mode == "keygen") {
        if (argc != 5) {
            std::cerr << "Usage: " + string(argv[0]) + " keygen <privateFileName> <publicFileName> <format>\n";
            std::cerr << "      + format: DER or PEM\n";
            return 1;
        }

        auto start = std::chrono::high_resolution_clock::now();

        for(int i = 0; i < 1000; i++)
            keygen(argv[2], argv[3], argv[4]);

        auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		std::cout << "Time for key generation for 1000 rounds: " << static_cast<double>(duration) / 1000 << " ms" << std::endl;
    }
    else if (mode == "sign") {
        if (argc != 6) {
            std::cerr << "Usage: " + string(argv[0]) + " sign <choice> <privateKeyFile> <message/messageFileName> <ouputFileName>\n";
            std::cerr << "      + choice: '0' if msg from file, '1' if msg from keyboard\n";
            return 1;
        }

        int check;
        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < 1000; i++)
            check = sign(std::stoi(argv[2]), argv[3], argv[4], argv[5]);

        auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

        if (check == 0)
        {
            std::cout << "Sign succesfully\n";
            std::cout << "Average time for signing message over 1000 times: " << static_cast<double>(duration) / 1000 << " ms" << std::endl;
        }
        else
            std::cout << "Failed to sign";
    }
    else if (mode == "verify") {
        if (argc != 5) {
            std::cerr << "Usage: " + string(argv[0]) + " verify <publicKeyFile> <messageFileName> <signatureFileName>\n";
            return 1;
        }

        auto start = std::chrono::high_resolution_clock::now();

        int success = 0;

        for (int i = 0; i < 1000; i++)
            success = verify(argv[2], argv[3], argv[4]);

        if(success == 0) 
            std::cout << "Verify succesfully!\n";
        else
            std::cout << "Failed to verify!\n";

        auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		std::cout << "Average time for verifying message over 1000 times: " << static_cast<double>(duration) / 1000 << " ms" << std::endl;
    }
    else {
        std::cerr << "Invalid mode!!\n";
        return 1;
    }
}
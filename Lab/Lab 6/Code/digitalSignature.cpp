//#include "pch.h" // Uncomment this line when generate DLL in MSVC

//digital-sign-1.cpp
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/sha.h> // Include for SHA256
#include <iostream>
#include <fstream>
#include <vector> // Include for std::vector
#include <iterator> // Include for std::istreambuf_iterator
#include <assert.h>

// for pem file format
#include "cryptopp/pem.h"
#include "cryptopp/pem_common.h"

#include "cryptopp/sha.h"
#include "cryptopp/osrng.h"
using CryptoPP::AutoSeededRandomPool;
#include "cryptopp/eccrypto.h"
using CryptoPP::ECDSA;
using CryptoPP::ECP;
using CryptoPP::DL_GroupParameters_EC;
#include "cryptopp/filters.h"
using CryptoPP::StringSource;
using CryptoPP::StringSink;
using CryptoPP::ArraySink;
using CryptoPP::SignerFilter;
using CryptoPP::SignatureVerificationFilter;
#include "cryptopp/integer.h"
using CryptoPP::Integer;
#include "cryptopp/files.h"
using CryptoPP::FileSource;
using CryptoPP::FileSink;
#include "cryptopp/oids.h"
using CryptoPP::OID;

#include <string>
using std::string;

// Define DLL export macro
#ifndef DLL_EXPORT
#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif
#endif

extern "C" {
    DLL_EXPORT bool signPdf(const char* chr_privateKeyPath, const char* chr_pdfPath, const char* chr_signaturePath);
    DLL_EXPORT int verifySignature(const char* chr_publicKeyPath, const char* chr_pdfPath, const char* chr_signaturePath);
    DLL_EXPORT bool keyGen(const char* privateKeyFile, const char* publicKeyFile);
}

bool GeneratePrivateKey(const OID& oid, ECDSA<ECP, CryptoPP::SHA1>::PrivateKey& key);
bool GeneratePublicKey(const ECDSA<ECP, CryptoPP::SHA1>::PrivateKey& privateKey, ECDSA<ECP, CryptoPP::SHA1>::PublicKey& publicKey);
void SavePrivateKey(const string& filename, const ECDSA<ECP, CryptoPP::SHA1>::PrivateKey& key);
void SavePublicKey(const string& filename, const ECDSA<ECP, CryptoPP::SHA1>::PublicKey& key);

// https://www.openssl.org/docs/man3.3/man3/EVP_SignInit.html
bool signPdf(const char* chr_privateKeyPath, const char* chr_pdfPath, const char* chr_signaturePath)
{
    // Convert *char to string
    std::string privateKeyPath(chr_privateKeyPath), pdfPath(chr_pdfPath), signaturePath(chr_signaturePath);

    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();
    // Read the private key from file
    BIO* keyData = BIO_new(BIO_s_file());
    BIO_read_filename(keyData, privateKeyPath.c_str());
    EVP_PKEY* privateKey = PEM_read_bio_PrivateKey(keyData, NULL, NULL, NULL);
    BIO_free(keyData);
    if (!privateKey) {
        std::cerr << "Error reading private key." << std::endl;
        ERR_print_errors_fp(stderr);
        return false;
    }

    // Create a buffer to hold the document hash
    unsigned char hashSize[SHA512_DIGEST_LENGTH]; //output size for hash function
    // Read input message (binary)
    std::ifstream pdfFile(pdfPath, std::ios::binary); // Read for all file types
    if (!pdfFile.is_open()) {
        std::cerr << "Error opening PDF file." << std::endl;
        return false;
    }
    std::vector<unsigned char> pdfContents((std::istreambuf_iterator<char>(pdfFile)), std::istreambuf_iterator<char>());
    pdfFile.close();

    // Hash the PDF
    std::cout << "Hashing the PDF" << std::endl;
    SHA512(&pdfContents[0], pdfContents.size(), hashSize);

    // Initalize hash function
    std::cout << "Signing the hash" << std::endl;
    EVP_MD_CTX* hash = EVP_MD_CTX_new();
    EVP_SignInit(hash, EVP_sha512()); //Initilize sing function void EVP_SignInit(EVP_MD_CTX *ctx, const EVP_MD *type);
    EVP_SignUpdate(hash, hashSize, SHA512_DIGEST_LENGTH);

    //Convert key to bytes
    unsigned int signatureLen = EVP_PKEY_size(privateKey);
    std::vector<unsigned char> signature(signatureLen);

    if (!EVP_SignFinal(hash, &signature[0], &signatureLen, privateKey)) {
        std::cerr << "Error signing PDF." << std::endl;
        EVP_MD_CTX_free(hash);
        EVP_PKEY_free(privateKey);
        return false;
    }
    // Write the signature to a file
    std::cout << "Writing the signature to file: " << signaturePath << std::endl;
    std::ofstream signatureFile(signaturePath, std::ios::binary);
    if (!signatureFile.is_open()) {
        std::cerr << "Error opening signature file." << std::endl;
        return false;
    }
    // Save signature to file
    signatureFile.write(reinterpret_cast<const char*>(&signature[0]), signatureLen);
    signatureFile.close();
    // Clean up
    EVP_MD_CTX_free(hash);
    EVP_PKEY_free(privateKey);
    EVP_cleanup();
    ERR_free_strings();
    return true;
}

int verifySignature(const char* chr_publicKeyPath, const char* chr_pdfPath, const char* chr_signaturePath)
{
    // Convert *char to string
    std::string publicKeyPath(chr_publicKeyPath), pdfPath(chr_pdfPath), signaturePath(chr_signaturePath);

    // Load the public key (PEM) using BIO
    BIO* pubData = BIO_new(BIO_s_file());
    if (BIO_read_filename(pubData, publicKeyPath.c_str()) <= 0) {
        std::cerr << "Error opening public key file." << std::endl;
        BIO_free(pubData);
        return false;
    }
    EVP_PKEY* publicKey = PEM_read_bio_PUBKEY(pubData, NULL, NULL, NULL);
    BIO_free(pubData);

    if (!publicKey) {
        std::cerr << "Error loading public key." << std::endl;
        return false;
    }

    // Load the PDF
    std::ifstream pdfFile(pdfPath, std::ios::binary);
    std::vector<unsigned char> pdfContents((std::istreambuf_iterator<char>(pdfFile)), std::istreambuf_iterator<char>());
    pdfFile.close();

    // Create a buffer to hold the document hash
    unsigned char hash[SHA512_DIGEST_LENGTH];
    SHA512(&pdfContents[0], pdfContents.size(), hash);

    // Load the signature
    std::ifstream signatureFile(signaturePath, std::ios::binary);
    std::vector<unsigned char> signature(std::istreambuf_iterator<char>(signatureFile), {});
    signatureFile.close();

    // Verify the signature
    EVP_MD_CTX* mesData = EVP_MD_CTX_new();
    EVP_DigestVerifyInit(mesData, NULL, EVP_sha512(), NULL, publicKey);
    EVP_DigestVerifyUpdate(mesData, hash, SHA512_DIGEST_LENGTH);
    int result = EVP_DigestVerifyFinal(mesData, &signature[0], signature.size());

    // Clean up
    EVP_MD_CTX_free(mesData);
    EVP_PKEY_free(publicKey);

    return result;
}

bool keyGen(const char* privateKeyFile, const char* publicKeyFile)
{
    bool result = false;
    // Private and Public keys
    ECDSA<ECP, CryptoPP::SHA1>::PrivateKey privateKey;
    ECDSA<ECP, CryptoPP::SHA1>::PublicKey publicKey;

    // Generate Keys
    result = GeneratePrivateKey(CryptoPP::ASN1::secp160r1(), privateKey);
    assert(true == result);
    if (!result) { return false; }

    result = GeneratePublicKey(privateKey, publicKey);
    assert(true == result);
    if (!result) { return false; }

    // Binary Format
    // SavePrivateKey(privateKeyFile, privateKey);
    // SavePublicKey(publicKeyFile, publicKey);

    // PEM Format
    FileSink pub(publicKeyFile, true);
    PEM_Save(pub, publicKey);
    FileSink priv(privateKeyFile, true);
    PEM_Save(priv, privateKey);

    return true;
}

// Main function
int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cerr << "Usage: " << argv[0] << " [keygen|sign|verify] <other parameters>" << std::endl;
        return 1;
    }

    std::string mode(argv[1]);

    if (mode == "keygen")
    {
        if (argc != 4) {
            std::cerr << "Usage: " << argv[0] << " keygen <private key file> <public key file>" << std::endl;
            return 1;
        }

        keyGen(argv[2], argv[3]);
        std::cout << "Key generated succesfully.";
    }
    else if (mode == "sign")
    {
        if (argc != 5) {
            std::cerr << "Usage: " << argv[0] << " sign <private key file> <PDF file> <signature output file>" << std::endl;
            return 1;
        }

        if (signPdf(argv[2], argv[3], argv[4])) {
            std::cout << "PDF signed successfully." << std::endl;
        }
        else {
            std::cout << "Failed to sign PDF." << std::endl;
        }
    }
    else if (mode == "verify")
    {
        if (argc != 5) {
            std::cerr << "Usage: " << argv[0] << " verify <public key file> <PDF file> <signature file>" << std::endl;
            return 1;
        }

        if (verifySignature(argv[2], argv[3], argv[4]) == 1) {
            std::cout << "PDF verified successfully." << std::endl;
        }
        else {
            std::cout << "Failed to verify PDF." << std::endl;
        }
    }
    else
    {
        std::cerr << "Invalid option";
        return 1;
    }

    return 0;
}

// Individual functions
bool GeneratePrivateKey(const OID& oid, ECDSA<ECP, CryptoPP::SHA1>::PrivateKey& key)
{
    AutoSeededRandomPool prng;

    key.Initialize(prng, oid);
    assert(key.Validate(prng, 3));

    return key.Validate(prng, 3);
}

bool GeneratePublicKey(const ECDSA<ECP, CryptoPP::SHA1>::PrivateKey& privateKey, ECDSA<ECP, CryptoPP::SHA1>::PublicKey& publicKey)
{
    AutoSeededRandomPool prng;

    // Sanity check
    assert(privateKey.Validate(prng, 3));

    privateKey.MakePublicKey(publicKey);
    assert(publicKey.Validate(prng, 3));

    return publicKey.Validate(prng, 3);
}

void SavePrivateKey(const string& filename, const ECDSA<ECP, CryptoPP::SHA1>::PrivateKey& key)
{
    key.Save(FileSink(filename.c_str(), true /*binary*/).Ref());
}

void SavePublicKey(const string& filename, const ECDSA<ECP, CryptoPP::SHA1>::PublicKey& key)
{
    key.Save(FileSink(filename.c_str(), true /*binary*/).Ref());
}
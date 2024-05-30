//digital-sign-1.cpp
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/sha.h> // Include for SHA256
#include <iostream>
#include <fstream>
#include <vector> // Include for std::vector
#include <iterator> // Include for std::istreambuf_iterator

// https://www.openssl.org/docs/man3.3/man3/EVP_SignInit.html
bool signPdf(const std::string& privateKeyPath, const std::string& pdfPath, const std::string& signaturePath) 
{
    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();
    // Read the private key from file
    BIO *keyData = BIO_new(BIO_s_file());
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
    EVP_MD_CTX *hash = EVP_MD_CTX_new();
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

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <private key file> <PDF file> <signature output file>" << std::endl;
        return 1;
    }
    const std::string privateKeyPath = argv[1];
    const std::string pdfPath = argv[2];
    const std::string signaturePath= argv[3];
    if (signPdf(privateKeyPath, pdfPath, signaturePath)) {
        std::cout << "PDF signed successfully." << std::endl;
    } else {
        std::cout << "Failed to sign PDF." << std::endl;
    }
    return 0;
}

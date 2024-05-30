#include <openssl/evp.h>
#include <openssl/pem.h>
#include <iostream>
#include <fstream>
#include <vector>

bool verifySignature(const std::string& publicKeyPath, const std::string& pdfPath, const std::string& signaturePath) {
    // Load the public key (PEM) using BIO
    BIO *pubData = BIO_new(BIO_s_file());
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
    EVP_MD_CTX *mesData = EVP_MD_CTX_new();
    EVP_DigestVerifyInit(mesData, NULL, EVP_sha512(), NULL, publicKey);
    EVP_DigestVerifyUpdate(mesData, hash, SHA512_DIGEST_LENGTH);
    int result = EVP_DigestVerifyFinal(mesData, &signature[0], signature.size());

    // Clean up
    EVP_MD_CTX_free(mesData);
    EVP_PKEY_free(publicKey);

    return result == 1;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <public key file> <PDF file> <signature file>" << std::endl;
        return 1;
    }
    const std::string publicKeyPath = argv[1];
    const std::string pdfPath = argv[2];
    const std::string signaturePath= argv[3];
    if (verifySignature(publicKeyPath, pdfPath, signaturePath)) {
        std::cout << "PDF verified successfully." << std::endl;
    } else {
        std::cout << "Failed to verify PDF." << std::endl;
    }
    return 0;
}

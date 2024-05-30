#include "pch.h" 

#include <openssl/evp.h>
#include <openssl/evperr.h>
#include <openssl/bio.h>


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef DLL_EXPORT 
#ifdef _WIN32 
#define DLL_EXPORT __declspec(dllexport) 
#else 
#define DLL_EXPORT 
#endif 
#endif 

extern "C" {
    DLL_EXPORT void hashes(const char* algo, const char* input_filename, const char* output_filename);
}

void hashes(const char* algo, const char* input_filename, const char* output_filename)
{
    EVP_MD_CTX* hashes;
    const EVP_MD* hasl_algo = EVP_get_digestbyname(algo);

    // basic input output
    FILE* f_in = fopen(input_filename, "rb");
    if (!f_in)
    {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }

    FILE* f_out = fopen(output_filename, "w");
    if (!f_out)
    {
        perror("Failed to open output file");
        fclose(f_in);
        exit(EXIT_FAILURE);
    }

    // check input argument
    if (!hasl_algo)
    {
        fprintf(stderr, "Unknown message digest %s\n", algo);
        fclose(f_in);
        fclose(f_out);
        exit(EXIT_FAILURE);
    }

    // Setting hashes function (create instances)
    hashes = EVP_MD_CTX_new();
    EVP_DigestInit_ex(hashes, hasl_algo, NULL);

    unsigned char buffer[4096]; // may be larger 1024
    size_t read_bytes;
    while ((read_bytes = fread(buffer, 1, sizeof(buffer), f_in)) != 0)
    {
        if (hashes && read_bytes > 0)
            EVP_DigestUpdate(hashes, buffer, read_bytes); // set input for hash
    }

    unsigned char md_value[EVP_MAX_MD_SIZE]; // max output 512 bits
    unsigned int md_len; // real output size
    EVP_DigestFinal_ex(hashes, md_value, &md_len); // set actual output length
    EVP_MD_CTX_free(hashes); // closed hashed

    // write digest to the output (bio)
    for (unsigned int i = 0; i < md_len; i++)
    {
        fprintf(f_out, "%02x", md_value[i]);
    }
    fprintf(f_out, "/n");
    // close files
    fclose(f_in);
    fclose(f_out);
}

int main(int argc, char** argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <algo> <input fileName> <output fileName>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char* algo = argv[1];
    const char* input_filename = argv[2];
    const char* output_filename = argv[3];
    hashes(algo, input_filename, output_filename);
    printf("hashed save to %s", output_filename);
    return 0;
}
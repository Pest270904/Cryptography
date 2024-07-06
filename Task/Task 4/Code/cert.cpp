#include <openssl/bio.h>
#include <openssl/err.h>
#include <openssl/pem.h>
#include <openssl/x509.h>
#include <openssl/x509v3.h>

#include <string>
#include <iostream>
#include <fstream>
#include <cstdint>

using namespace std;

int detect_pem(const char* filename) {
    ifstream file(filename);
    if (!file.is_open())
    {
        return 2;
    }
    string line;
    getline(file, line);
    if (line != "-----BEGIN CERTIFICATE-----")
    {
        return 0;
    }
    while (getline(file, line)) {
        if (line == "-----END CERTIFICATE-----") {
            return 1;
        }
    }
    return 0;
}

int sig_verify(X509* intermediate ,X509* cert)
{
    EVP_PKEY *signing_key=X509_get_pubkey(intermediate);
    int result = X509_verify(cert, signing_key);
    EVP_PKEY_free(signing_key);
    return result;
}

void readCert(const char* filename, X509** cert)
{
    BIO* cert_file = BIO_new(BIO_s_file());
    if (BIO_read_filename(cert_file, filename) <= 0) 
    {
        cerr << "Error opening certificate file.\n";
        *cert = NULL;
    }
    int fileType = detect_pem(filename);
    if (fileType == 0)
    {
        *cert = d2i_X509_bio(cert_file, NULL);
        if (*cert == NULL)
        {
            cerr << "Error reading certificate.\n";
            *cert = NULL;
        }
    }
    else if (fileType == 1)
    {
        *cert = PEM_read_bio_X509(cert_file, NULL, 0, NULL);
        if (*cert == NULL) {
            cerr << "Error reading certificate.\n";
            *cert = NULL;
        }
    }
    BIO_free_all(cert_file);
}

void printInFormat(string hex)
{
    cout <<'\t';
    for(int i = 0; i < hex.length(); i++)
    {
        cout << hex[i];
        if (i%2 && (i + 1 != hex.length())) cout << ':';
        if ((i+1) % 30 == 0) cout <<"\n\t";
    }
    cout << endl;
}

string printDateTime(const ASN1_TIME* time)
{
    BIO *bio = BIO_new(BIO_s_mem());
    ASN1_TIME_print(bio, time);
    char* printTime = new char[BIO_number_written(bio) + 1];
    memset(printTime, 0, BIO_number_written(bio) + 1);
    BIO_read(bio, printTime, BIO_number_written(bio));
    string time_str = string(printTime);
    delete[] printTime;
    BIO_free(bio);
    return time_str;
}

void validateCertificate(const char* fileCert, const char* intermediateCert)
{
    X509* cert = NULL;
    X509* inter = NULL;
    
    readCert(fileCert, &cert);
    if (cert == NULL)
        return;
    
    readCert(intermediateCert, &inter);
    if (inter == NULL)
        return;
    
    if (sig_verify(inter, cert))
    {
        cout << "Validate certificate successfully!!!\n";

        char* subject_name = X509_NAME_oneline(X509_get_subject_name(cert), NULL, 0);
        char* issuer_name = X509_NAME_oneline(X509_get_issuer_name(cert), NULL, 0);
        //subject
        cout << "Subject: " << string(subject_name) << endl;
        // issuer
        cout << "Issuer: " << string(issuer_name) << endl;
        // subject public key
        EVP_PKEY* pubkey = X509_get_pubkey(cert);
        if (pubkey == NULL) 
        {
            cerr << "Error reading public key.\n";
            return;
        } 
        else
        {
            int type = EVP_PKEY_base_id(pubkey);
            const char* name = OBJ_nid2ln(type);
            cout << "Subject Public Key Info: \n";
            if (EVP_PKEY_id(pubkey) == EVP_PKEY_EC) 
            {
                EC_KEY* ec_key = EVP_PKEY_get1_EC_KEY(pubkey);
                const EC_GROUP* ec_group = EC_KEY_get0_group(ec_key);
                int curve_nid = EC_GROUP_get_curve_name(ec_group);
                const char* curve_name = OBJ_nid2sn(curve_nid);
                std::cout << "\tPublic Key Algorithm: " << name << "\n";
                cout << "\tPublic-Key: (" << EVP_PKEY_bits(pubkey) << " bit)\n";
                const EC_POINT* pub_point = EC_KEY_get0_public_key(ec_key);
                BIGNUM* bn = EC_POINT_point2bn(ec_group, pub_point, EC_KEY_get_conv_form(ec_key), NULL, NULL);
                char* hex = BN_bn2hex(bn);
                printInFormat(string(hex));
                OPENSSL_free(hex);
                BN_free(bn);
                EC_KEY_free(ec_key);
                cout << "\tASN1 OID: " << curve_name << "\n";
                std::cout << "NIST CURVE: " << curve_name << "\n";
                EC_KEY_free(ec_key);
            }
            else if (EVP_PKEY_id(pubkey) == EVP_PKEY_RSA) 
            {
                RSA* rsa_key = EVP_PKEY_get1_RSA(pubkey);

                // Print Public Key Algorithm
                cout << "\tPublic Key Algorithm: " << name << "\n";

                // Print Public Key Length
                std::cout << "\tPublic-Key: (" << RSA_bits(rsa_key) << " bit)\n";

                // Print Modulus
                const BIGNUM* n = NULL;
                const BIGNUM* e = NULL;
                RSA_get0_key(rsa_key, &n, &e, NULL);
                char* hex_n = BN_bn2hex(n);
                std::cout << "\tModulus:\n";
                printInFormat(hex_n);
                OPENSSL_free(hex_n);
                char* hex_e = BN_bn2hex(e);
                std::cout << "\tExponent: " << hex_e << "\n";
                OPENSSL_free(hex_e);
                RSA_free(rsa_key);
            }
            else
            {
                cerr <<"Unsupported subject public key algorithm!!!";
                return;
            }
        
            // Signature
            const ASN1_BIT_STRING* signature;
            X509_get0_signature(&signature, NULL, cert);
            if (signature == NULL) 
            {
                std::cerr << "Error reading signature.\n";
                return;
            } 
            else 
            {
                BIO *bio = BIO_new(BIO_s_mem());
                i2a_ASN1_STRING(bio, signature, V_ASN1_OCTET_STRING);
                BUF_MEM *bptr;
                BIO_get_mem_ptr(bio, &bptr);

                // bptr->data contains the hex string
                string hex_str(bptr->data, bptr->length);
                cout << "Signature: " << endl;
                cout << hex_str << endl;
                BIO_free_all(bio);
            }

            // Signature Algorithm and its param
            const X509_ALGOR* sig_alg;
            X509_get0_signature(NULL, &sig_alg, cert);
            if (sig_alg == NULL) {
                std::cerr << "Error reading signature algorithm.\n";
            } else {
                int pkey_nid = OBJ_obj2nid(sig_alg->algorithm);
                string ln = string(OBJ_nid2ln(pkey_nid));
                std::cout << "Signature algorithm: " << ln << "\n";
            }
            
            // Validity Dates
            const ASN1_TIME* not_before = X509_get0_notBefore(cert);
            const ASN1_TIME* not_after = X509_get0_notAfter(cert);
            cout << "Validity: \n";
            cout << "\tNot before: " << printDateTime(not_before) << endl;
            cout << "\tNot after: " << printDateTime(not_after) << endl;

            // Purposes
            cout << "Purpose: ";
            for (int i = 0; i < X509_PURPOSE_get_count(); i++) 
            {
                X509_PURPOSE* purpose = X509_PURPOSE_get0(i);
                int id = X509_PURPOSE_get_id(purpose);
                if (X509_check_purpose(cert, id, 0)) cout << X509_PURPOSE_get0_name(purpose);
            }
        } 
        OPENSSL_free(subject_name);
        OPENSSL_free(issuer_name);    
    }
    else 
    {
        cout << "Fail to validate certificate!!!" << endl;
    }
    X509_free(cert);
    X509_free(inter);
}

int main(int argc, char* argv[]) 
{
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <certificate_file> <intermediate_certificate>\n";
        return 1;
    }

    const char* fileCert = argv[1];
    const char* intermediate = argv[2];

    validateCertificate(fileCert, intermediate);

    return 0;
}

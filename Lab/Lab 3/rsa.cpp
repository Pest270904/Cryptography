#include "pch.h"

#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <stdexcept>
using std::runtime_error;

#include <cryptopp/queue.h>
using CryptoPP::ByteQueue;

#include <cryptopp/files.h>
using CryptoPP::FileSink;
using CryptoPP::FileSource;

// #include "cryptopp/dsa.h"
// using CryptoPP::DSA;

#include "cryptopp/rsa.h"
using CryptoPP::RSA;

#include "cryptopp/base64.h"
using CryptoPP::Base64Decoder;
using CryptoPP::Base64Encoder;

#include <cryptopp/cryptlib.h>
using CryptoPP::BufferedTransformation;
using CryptoPP::PrivateKey;
using CryptoPP::PublicKey;

#include "cryptopp/osrng.h"
using CryptoPP::AutoSeededRandomPool;

#include <cryptopp/integer.h>
using CryptoPP::Integer;

#include <cryptopp/nbtheory.h>
using CryptoPP::ModularSquareRoot;

#include <cryptopp/modarith.h>
using CryptoPP::ModularArithmetic;


#include "cryptopp/rsa.h"
using CryptoPP::RSA;
using CryptoPP::InvertibleRSAFunction;
using CryptoPP::RSAES_OAEP_SHA_Encryptor;
using CryptoPP::RSAES_OAEP_SHA_Decryptor;

#include "cryptopp/files.h"
using CryptoPP::FileSource;
using CryptoPP::FileSink;

#include "cryptopp/filters.h"
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::PK_EncryptorFilter;
using CryptoPP::PK_DecryptorFilter;

// header part
#ifdef _WIN32
#include <windows.h>
#endif
#include <cstdlib>
#include <locale>
#include <cctype>

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
	DLL_EXPORT void GenerateAndSaveRSAKeys(int keySize, const char* format, const char* privateKeyFile, const char* publicKeyFile);
	DLL_EXPORT void RSAEncrypt(const char* format, const char* publicKeyFile, const char* plainTextFile, const char* cipherFile);
	DLL_EXPORT void RSADecrypt(const char* format, const char* privateKeyFile, const char* cipherFile, const char* recoveredFile);
}

// Save Keys (Binary)
void Save(const string &filename, const BufferedTransformation &bt);
void SavePrivateKey(const string &filename, const PrivateKey &key);
void SavePublicKey(const string &filename, const PublicKey &key);

// Save Keys (Base 64 text)
void SaveBase64(const string &filename, const BufferedTransformation &bt);
void SaveBase64PrivateKey(const string &filename, const PrivateKey &key);
void SaveBase64PublicKey(const string &filename, const PublicKey &key);

// Load Keys (Binary)
void Load(const string &filename, BufferedTransformation &bt);
void LoadPrivateKey(const string &filename, PrivateKey &key);
void LoadPublicKey(const string &filename, PublicKey &key);

// Load Keys (Base 64 text)
void LoadBase64(const string &filename, BufferedTransformation &bt);
void LoadBase64PrivateKey(const string &filename, PrivateKey &key);
void LoadBase64PublicKey(const string &filename, PublicKey &key);

// Key generation function
void GenerateAndSaveRSAKeys(int keySize, const char *format, const char *privateKeyFile, const char *publicKeyFile)
{

	string strFormat(format);
	string strPrivateKeyFile(privateKeyFile);
	string strPublicKeyFile(publicKeyFile);

	// Keys generation
	AutoSeededRandomPool rnd;
	RSA::PrivateKey rsaPrivate;
	rsaPrivate.GenerateRandomWithKeySize(rnd, keySize);
	RSA::PublicKey rsaPublic(rsaPrivate);

	// Save key
	if (strFormat == "DER")
	{
		SavePrivateKey(strPrivateKeyFile, rsaPrivate);
		SavePublicKey(strPublicKeyFile, rsaPublic);
	}
	else if (strFormat == "Base64")
	{
		SaveBase64PrivateKey(strPrivateKeyFile, rsaPrivate);
		SaveBase64PublicKey(strPublicKeyFile, rsaPublic);
	}
	else
	{
		cerr << "Unsupported format. Please choose 'DER." << endl;
		exit(1); // Exit with error
	}

	RSA::PrivateKey r1, r2;
	r1.GenerateRandomWithKeySize(rnd, keySize);
	SavePrivateKey("rsa-roundtrip.key", r1);
	LoadPrivateKey("rsa-roundtrip.key", r2);
	r1.Validate(rnd, 3);
	r2.Validate(rnd, 3);
	if (r1.GetModulus() != r2.GetModulus() ||
		r1.GetPublicExponent() != r2.GetPublicExponent() ||
		r1.GetPrivateExponent() != r2.GetPrivateExponent())
	{
		throw runtime_error("key data did not round trip");
	}

	cout << "Successfully generated and saved RSA key" << endl;

	// Load key and read parameters
	RSA::PrivateKey rsaPrivate1;
	RSA::PublicKey rsaPublic1;
	if (strFormat == "DER")
	{
		LoadPrivateKey(strPrivateKeyFile, rsaPrivate1);
		LoadPublicKey(strPublicKeyFile, rsaPublic1);
	}
	else if (strFormat == "Base64")
	{
		LoadBase64PrivateKey(strPrivateKeyFile, rsaPrivate1);
		LoadBase64PublicKey(strPublicKeyFile, rsaPublic1);
	}
	else
	{
		cerr << "Unsupported format. Please choose DER or Base64" << endl;
		exit(1); // Exit with error
	}

	Integer modul1 = rsaPrivate1.GetModulus();	   // modul n (from private)
	Integer prime1 = rsaPrivate1.GetPrime1();	   // prime p
	Integer prime2 = rsaPrivate1.GetPrime2();	   // prime p
	Integer SK = rsaPrivate1.GetPrivateExponent(); // secret exponent d;

	/* Secret exponent d; public exponent e */
	Integer modul2 = rsaPublic1.GetModulus();	 // modul n (from public)
	Integer PK = rsaPublic1.GetPublicExponent(); // public exponent e;

	cout << "modul(private) n = " << modul1 << '\n';
	cout << "modul(public) n = " << modul2 << '\n';
	cout << "Prime number p = " << std::hex << prime1 << std::dec << '\n';
	cout << "Prime number q = " << prime2 << '\n';
	cout << "Public exponent e = " << PK << '\n';
	cout << "Secret exponent e = " << SK << '\n';
}

// RSA Encrypt
void RSAEncrypt(const char *format, const char *publicKeyFile, const char *plainTextFile, const char *cipherFile)
{
	string strFormat(format);
	string plain, cipher, pub;
	AutoSeededRandomPool rng;
	RSA::PublicKey rsaPublic;

	if (strFormat == "DER")
	{
		LoadPublicKey(publicKeyFile, rsaPublic);
	}
	else if (strFormat == "Base64")
	{
		LoadBase64PublicKey(publicKeyFile, rsaPublic);
	}
	else
	{
		cerr << "Unsupported format. Please choose 'DER." << endl;
		exit(1); // Exit with error
	}

	FileSource(plainTextFile, true, 
		new StringSink(plain), false);
	
	RSAES_OAEP_SHA_Encryptor e( rsaPublic );

	StringSource( plain, true,
		new PK_EncryptorFilter( rng, e,
			new FileSink( cipherFile, true )
		) // PK_EncryptorFilter
	); // StringSource
}

// RSA Decrypt
void RSADecrypt(const char *format, const char *privateKeyFile, const char *cipherFile, const char *recoveredFile)
{
	string strFormat(format);
	string cipher, pub;
	AutoSeededRandomPool rng;
	RSA::PrivateKey rsaPrivate;

	if (strFormat == "DER")
	{
		LoadPrivateKey(privateKeyFile, rsaPrivate);
	}
	else if (strFormat == "Base64")
	{
		LoadBase64PrivateKey(privateKeyFile, rsaPrivate);
	}
	else
	{
		cerr << "Unsupported format. Please choose 'DER." << endl;
		exit(1); // Exit with error
	}

	FileSource(cipherFile, true, 
		new StringSink(cipher));
	
	RSAES_OAEP_SHA_Decryptor d( rsaPrivate );

	StringSource( cipher, true,
		new PK_DecryptorFilter( rng, d,
			new FileSink( recoveredFile, true )
		) // PK_DecryptorFilter
	); // StringSource
}

int main(int argc, char **argv)
{
	// main part
	// Set locale to support UTF-8
	#ifdef __linux__
	std::locale::global(std::locale("C.utf8"));
	#endif
	#ifdef _WIN32
	// Set console code page to UTF-8 on Windows C.utf8, CP_UTF8
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	#endif
	std::ios_base::sync_with_stdio(false);
	if (argc != 6)
	{
		cerr << "Usage: \n";
		cerr << argv[0] << " keygen <keysize> <format> <privateKeyFile> <publicKeyFile>\n";
		cerr << argv[0] << " encrypt <format> <publicKeyFile> <plainTextFile> <cipherFile>\n";
		cerr << argv[0] << " decrypt <format> <privateKeyFile> <cipherFile> <recoveredFile>\n";
		exit(1);
	}

	string mode = argv[1];
	
	if(mode == "keygen")
	{
		int keysize = std::stoi(argv[2]);
		GenerateAndSaveRSAKeys(keysize, argv[3], argv[4], argv[5]);
	}
	else if (mode == "encrypt")
	{	
		RSAEncrypt(argv[2], argv[3], argv[4], argv[5]);
	}
	else if (mode == "decrypt")
	{
		RSADecrypt(argv[2], argv[3], argv[4], argv[5]);
	}
	else 
	{
		cerr << "Invalid option.";
		exit(1);
	}


	return 0;
}

// Def functions

void SavePrivateKey(const string &filename, const PrivateKey &key)
{
	// http://www.cryptopp.com/docs/ref/class_byte_queue.html
	ByteQueue queue;
	key.Save(queue);

	Save(filename, queue);
}

void SavePublicKey(const string &filename, const PublicKey &key)
{
	// http://www.cryptopp.com/docs/ref/class_byte_queue.html
	ByteQueue queue;
	key.Save(queue);

	Save(filename, queue);
}

void Save(const string &filename, const BufferedTransformation &bt)
{
	// http://www.cryptopp.com/docs/ref/class_file_sink.html
	FileSink file(filename.c_str());

	bt.CopyTo(file);
	file.MessageEnd();
}

void SaveBase64PrivateKey(const string &filename, const PrivateKey &key)
{
	// http://www.cryptopp.com/docs/ref/class_byte_queue.html
	ByteQueue queue;
	key.Save(queue);

	SaveBase64(filename, queue);
}

void SaveBase64PublicKey(const string &filename, const PublicKey &key)
{
	// http://www.cryptopp.com/docs/ref/class_byte_queue.html
	ByteQueue queue;
	key.Save(queue);

	SaveBase64(filename, queue);
}

void SaveBase64(const string &filename, const BufferedTransformation &bt)
{
	// http://www.cryptopp.com/docs/ref/class_base64_encoder.html
	Base64Encoder encoder;

	bt.CopyTo(encoder);
	encoder.MessageEnd();

	Save(filename, encoder);
}

void LoadPrivateKey(const string &filename, PrivateKey &key)
{
	// http://www.cryptopp.com/docs/ref/class_byte_queue.html
	ByteQueue queue;

	Load(filename, queue);
	key.Load(queue);
}

void LoadPublicKey(const string &filename, PublicKey &key)
{
	// http://www.cryptopp.com/docs/ref/class_byte_queue.html
	ByteQueue queue;

	Load(filename, queue);
	key.Load(queue);
}

void Load(const string &filename, BufferedTransformation &bt)
{
	// http://www.cryptopp.com/docs/ref/class_file_source.html
	FileSource file(filename.c_str(), true /*pumpAll*/);

	file.TransferTo(bt);
	bt.MessageEnd();
}

void LoadBase64PrivateKey(const string& filename, PrivateKey& key)
{
	// Create a FileSource that automatically decodes Base64 data from the file
    CryptoPP::FileSource file(filename.c_str(), true, new CryptoPP::Base64Decoder);
 
    // Load the decoded data into a ByteQueue
    CryptoPP::ByteQueue queue;
    file.TransferTo(queue);
    queue.MessageEnd();
 
    // Load the private key from the ByteQueue
    key.Load(queue);
 
    // Optionally, check the validity of the loaded key
    CryptoPP::AutoSeededRandomPool prng;
    if (!key.Validate(prng, 3)) {
        throw std::runtime_error("Loaded private key is invalid.");
    }
}

void LoadBase64PublicKey(const string& filename, PublicKey& key)
{
    // Create a FileSource that automatically decodes Base64 data from the file
    CryptoPP::FileSource file(filename.c_str(), true, new CryptoPP::Base64Decoder);
 
    // Load the decoded data into a ByteQueue
    CryptoPP::ByteQueue queue;
    file.TransferTo(queue);
    queue.MessageEnd();
 
    // Load the public key from the ByteQueue
    key.Load(queue);
    // Optionally, check the validity of the loaded key
    AutoSeededRandomPool prng;
    if (!key.Validate(prng, 3)) {
        throw std::runtime_error("Loaded public key is invalid.");
    }
}

void LoadBase64(const string &filename, BufferedTransformation &bt)
{
	throw runtime_error("Not implemented");
}


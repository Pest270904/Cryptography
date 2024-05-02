// g++ -g3 -ggdb -O0 -DDEBUG -I/usr/include/cryptopp Driver.cpp -o Driver.exe -lcryptopp -lpthread
// g++ -g -O2 -DNDEBUG -I/usr/include/cryptopp Driver.cpp -o Driver.exe -lcryptopp -lpthread



#include <iostream>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

#include <string>
using std::string;

#include <cstdlib>
using std::exit;

#include "cryptopp/osrng.h"
using CryptoPP::AutoSeededRandomPool;

#include "cryptopp/cryptlib.h"
using CryptoPP::Exception;

#include "cryptopp/hex.h"
using CryptoPP::HexEncoder;
using CryptoPP::HexDecoder;

#include "cryptopp/filters.h"
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::StreamTransformationFilter;
using CryptoPP::ArraySource;
using CryptoPP::ArraySink;

#include "cryptopp/files.h"
using CryptoPP::FileSource;
using CryptoPP::FileSink;

#include "cryptopp/aes.h"
using CryptoPP::AES;

#include "cryptopp/ccm.h"
#include "cryptopp/modes.h"
using CryptoPP::OFB_Mode;
using CryptoPP::CBC_Mode;

#include "assert.h"

 // header part
#ifdef _WIN32
#endif
#include <cstdlib>
#include <locale>
#include <cctype>

int main(int argc, char* argv[])
{
    #ifdef __linux__
    std::locale::global(std::locale("C.utf8"));
    #endif

	AutoSeededRandomPool prng;
    string encoded;
    cout << "What do you like to choose?\n";
    cout << "1. Key generation\n";
    cout << "2. Encryption data\n";
    cout << "3. Decryption data\n";
    cout << "Your task?: ";

    int actions;
    cin >> actions;

    switch (actions)
    {
        case 1:
        {
            CryptoPP::byte key[AES::DEFAULT_KEYLENGTH];
            prng.GenerateBlock(key, sizeof(key));

            CryptoPP::byte iv[AES::BLOCKSIZE];
            prng.GenerateBlock(iv, sizeof(iv));

            // Save key to file (binaries)
            StringSource(key, sizeof(key), true,
                    new FileSink("key.bin", true)
            ); // StringSource

            // Save key to file (hex)
            StringSource(key, sizeof(key), true,
                    new HexEncoder(new FileSink("key.tex"))
            ); // StringSource

            // Save iv to file (binaries)
            StringSource(iv, sizeof(iv), true,
                    new FileSink("iv.bin", true)
            ); // StringSource

            // Save iv to file (hex)
            StringSource(iv, sizeof(iv), true,
                    new HexEncoder(new FileSink("iv.tex"))
            ); // StringSource

            // Pretty print key (hex)
            encoded.clear();
            StringSource(key, sizeof(key), true,
                new HexEncoder(
                    new StringSink(encoded)
                ) // HexEncoder
            ); // StringSource
            cout << "key: " << encoded << endl;

            // Pretty print iv (hex)
            encoded.clear();
            StringSource(iv, sizeof(iv), true,
                new HexEncoder(
                    new StringSink(encoded)
                ) // HexEncoder
            ); // StringSource
            cout << "iv: " << encoded << endl;
            break;
        }
        case 2:
        {
            string plain = "Buổi 2 - Nguyễn Tuấn Phát";
            string cipher;
            cout << "plain text: " << plain << endl;

            CryptoPP::byte key[AES::DEFAULT_KEYLENGTH];
            //prng.GenerateBlock(key, sizeof(key));

            // Load key (binaries)
            FileSource("key.bin", true,
                new ArraySink(key, sizeof(key))
            ); // StringSource

            CryptoPP::byte iv[AES::BLOCKSIZE];
            //prng.GenerateBlock(iv, sizeof(iv));
            // Load key (binaries)
            FileSource("iv.bin", true,
                new ArraySink(iv, sizeof(iv))
            ); // StringSource
            

            OFB_Mode< AES >::Encryption e;
            e.SetKeyWithIV(key, sizeof(key), iv);

            // The StreamTransformationFilter removes
            //  padding as required.
            StringSource (plain, true, 
                new StreamTransformationFilter(e,
                    new StringSink(cipher)
                ) // StreamTransformationFilter
            ); // StringSource

            /*********************************\
            \*********************************/

            // Pretty print
            encoded.clear();
            StringSource(cipher, true,
                new HexEncoder(
                    new StringSink(encoded)
                ) // HexEncoder
            ); // StringSource
            cout << "cipher text (hex): " << encoded << endl;
            break;
        }
        case 3:
        {
            string plain = "Buổi 2 - Nguyễn Tuấn Phát";
            string cipher, recovered;
            
            CryptoPP::byte key[AES::DEFAULT_KEYLENGTH];
            prng.GenerateBlock(key, sizeof(key));

            CryptoPP::byte iv[AES::BLOCKSIZE];
            prng.GenerateBlock(iv, sizeof(iv));

            OFB_Mode< AES >::Encryption e;
            e.SetKeyWithIV(key, sizeof(key), iv);

                        StringSource (plain, true, 
                new StreamTransformationFilter(e,
                    new StringSink(cipher)
                ) // StreamTransformationFilter
            ); // StringSource

            OFB_Mode< AES >::Decryption d;
            d.SetKeyWithIV(key, sizeof(key), iv);

            // The StreamTransformationFilter removes
            //  padding as required.
            StringSource (cipher, true, 
                new StreamTransformationFilter(d,
                    new StringSink(recovered)
                ) // StreamTransformationFilter
            ); // StringSource
            cout << "recovered text: " << recovered << endl;
            break;
        }
        default:
        {
            cout << "idk what you typed in... please type in 1 or 2 or 3\n";
        }
    }

	return 0;
}


/* Integer arithmatics*/
#include <cryptopp/integer.h>
using CryptoPP::Integer;

#include <cryptopp/nbtheory.h>
using CryptoPP::ModularSquareRoot;

#include <cryptopp/modarith.h>
using CryptoPP::ModularArithmetic;


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
#include <windows.h>
#endif
#include <cstdlib>
#include <locale>
#include <cctype>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>

int main()
{
    // main part
    // Set locale to support UTF-8
    // #ifdef __linux__
    // std::locale::global(std::locale("C.utf8"));
    // #endif

    #ifdef _WIN32
    // Set console code page to UTF-8 on Windows C.utf8, CP_UTF8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    #endif

    #ifdef __linux__
        setlocale(LC_ALL, "");
    #elif _WIN32
        _setmode(_fileno(stdin), _O_U16TEXT);
        _setmode(_fileno(stdout), _O_U16TEXT);
    #endif

    AutoSeededRandomPool prng;

    Integer p("01FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFH");
    Integer x("123456789012345678901234567890.");
    Integer y(prng, 1, p); // random integer
    cout << "p= " << p << endl;
    cout << "x= " << x << endl;
    cout << "y= " << y << endl;
    ModularArithmetic ma(p); // mod p

    cout << "x+y mod p: " << ma.Add(x, y) << endl;
    cout << "x-y mod p: " << ma.Subtract(x, y) << endl;
    cout << "x*y mod p: " << ma.Multiply(x, y) << endl;
    cout << "x/y mod p: " << ma.Divide(x, y) << endl;
    cout << "x%y mod p: " << ma.Reduce(x, y) << endl;
    cout << "x^y mod p: " << ma.Exponentiate(x, y) << endl;
    // Validation x.x^-1 = 1;
    Integer x1 = ma.Divide(1, x);
    cout << "x*x1 mod p: " << ma.Multiply(x, x1) << endl;
    
    string mes, hexmes;
    cout << "Input message to convert to integer: ";
    getline(cin, mes);
    StringSource(mes, true, new HexEncoder(new StringSink(hexmes)));
    hexmes=hexmes+"H";
    Integer u(hexmes.data());
    cout << "Message to Integer: " << u << '\n';
    cout << "Message to Integer (mod p): " << u%p << '\n';
}
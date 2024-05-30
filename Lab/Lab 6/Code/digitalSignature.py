import ctypes
from ctypes import c_char_p
import sys
import os

# .so path
sopath=os.path.join(os.getcwd(),"digitalSignature.so")
 
# Load the shared libraryc
signature = ctypes.CDLL(sopath, winmode=ctypes.DEFAULT_MODE) # winmode = [0,1,2,3]
 
# Set up the prototype of the function
# All of them are strings (char*)
sign = signature.signPdf # call signPdf funtion from digitalSignature.so;
sign.argtypes = [c_char_p, c_char_p, c_char_p]
sign.restype = bool  # The function returns bool

verify = signature.verifySignature # call verifySignature funtion from digitalSignature.so;
verify.argtypes = [c_char_p, c_char_p, c_char_p]
verify.restype = int  # The function returns bool

# Wrapped funtions
def call_sign(privateKeyPath, filePath, signaturePath):
    # Convert Python strings to bytes, as ctypes works with bytes
    privateKeyPath = privateKeyPath.encode('utf-8')
    filePath = filePath.encode('utf-8')
    signaturePath = signaturePath.encode('utf-8')
   
    # Call the C function
    return sign(privateKeyPath, filePath, signaturePath)

def call_verify(publicKeyPath, filePath, signaturePath):
    # Convert Python strings to bytes, as ctypes works with bytes
    publicKeyPath = publicKeyPath.encode('utf-8')
    filePath = filePath.encode('utf-8')
    signaturePath = signaturePath.encode('utf-8')

    # Call the C function
    return verify(publicKeyPath, filePath, signaturePath) == 1

if __name__ == "__main__":
    if len(sys.argv) == 1:
        print(f"Usage: python {sys.argv[0]} [sign|verify] <other parameters>")
        sys.exit(1)

    mode = sys.argv[1]

    if mode == "sign":
        if len(sys.argv) != 5:
            print(f"Usage: python {sys.argv[0]} sign <private key file> <PDF file> <signature output file>")
            sys.exit(1)
        
        if call_sign(sys.argv[2], sys.argv[3], sys.argv[4]):
            print("File signed succesfully.")
        else:
            print("Failed to sign File.")

    elif mode == "verify":
        if len(sys.argv) != 5:
            print(f"Usage: python {sys.argv[0]} verify <public key file> <PDF file> <signature output file>")
            sys.exit(1)
        
        if call_verify(sys.argv[2], sys.argv[3], sys.argv[4]):
            print("File verified succesfully.")
        else:
            print("Failed to verify File.")

    else:
        print("Invalid option")
        sys.exit(1)
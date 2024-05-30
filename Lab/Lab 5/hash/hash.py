import ctypes
from ctypes import c_char_p
import sys
import os

# .so path
sopath=os.path.join(os.getcwd(),"hash.dll")
 
# Load the shared libraryc
SHA = ctypes.CDLL(sopath)
 
# Set up the prototype of the function
# All of them are strings (char*)
hashes = SHA.hashes # call hashes funtion from hash.so;
hashes.argtypes = [c_char_p, c_char_p, c_char_p]
hashes.restype = None  # The function returns void

# Wrapped funtions
def call_hashes( algo, input_filename, output_filename):
    # Convert Python strings to bytes, as ctypes works with bytes
    algo = algo.encode('utf-8')
    input_filename = input_filename.encode('utf-8')
    output_filename = output_filename.encode('utf-8')
   
   
    # Call the C function
    hashes(algo, input_filename, output_filename)

if __name__ == "__main__":
    # Check if the correct number of arguments have been passed (3 arguments + 1 for the script name)
    if len(sys.argv) != 4:
        print(f"Usage: python {sys.argv[0]} <<algorithm>, <input filename> <output filename>")
        sys.exit(1)
 
    # Extract arguments
    algo = sys.argv[1]
    input_filename = sys.argv[2]
    output_filename = sys.argv[3]
 
 
    # Call the function with command-line arguments
    call_hashes(algo, input_filename, output_filename)
    print(f"Hashed output save to {sys.argv[3]}")
using System;
using System.Text;
using System.Runtime.InteropServices;//import dll 

namespace RSA_CS
{
    internal class RSA_CS
    {
        [DllImport("RSA_DLL.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "GenerateAndSaveRSAKeys")]
        public static extern void GenerateAndSaveRSAKeys(int keySize, string format, string privateKeyFile, string publicKeyFile);


        [DllImport("RSA_DLL.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "RSAEncrypt")]
        public static extern void RSAEncrypt(string format, string publicKeyFile, string plainTextFile, string cipherFile);

        [DllImport("RSA_DLL.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "RSADecrypt")]
        public static extern void RSADecrypt(string format, string privateKeyFile, string cipherFile, string recoveredFile);
        
        static void Main(string[] args)
        {
            try
            {
                if (Environment.OSVersion.Platform == PlatformID.Win32NT)
                {
                    Console.OutputEncoding = System.Text.Encoding.UTF8;
                    Console.InputEncoding = System.Text.Encoding.UTF8;
                }

                if (args.Length != 5)
                {
                    Console.Error.WriteLine("Usage:");
                    Console.Error.WriteLine(" {0} keygen <keysize> <format> <privateKeyFile> <publicKeyFile>", Environment.GetCommandLineArgs()[0]);
                    Console.Error.WriteLine(" {0} encrypt <format> <publicKeyFile> <plainTextFile> <cipherFile>", Environment.GetCommandLineArgs()[0]);
                    Console.Error.WriteLine(" {0} decrypt <format> <privateKeyFile> <cipherFile> <recoveredFile>", Environment.GetCommandLineArgs()[0]);
                    Environment.Exit(1);
                }

                string mode = args[0];

                if (mode == "keygen")
                {
                    int keysize = int.Parse(args[1]);
                    GenerateAndSaveRSAKeys(keysize, args[2], args[3], args[4]);
                }
                else if (mode == "encrypt")
                {
                    RSAEncrypt(args[1], args[2], args[3], args[4]);
                }
                else if (mode == "decrypt")
                {
                    RSADecrypt(args[1], args[2], args[3], args[4]);
                }
                else
                {
                    Console.Error.WriteLine("Invalid option.");
                    Environment.Exit(1);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                Environment.Exit(1);
            }

            Console.WriteLine("Operation completed succesfully");
        }
    }
}

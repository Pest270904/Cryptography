using System;
using System.Text;
using System.Runtime.InteropServices;//import dll 

namespace hash_CLI
{
    internal class Program
    {
        [DllImport("hash.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "hashes")]
        public static extern void hashes(string algo, string input_filemame, string output_filename);

        static void Main(string[] args)
        {
            try
            {
                if (Environment.OSVersion.Platform == PlatformID.Win32NT)
                {
                    Console.OutputEncoding = System.Text.Encoding.UTF8;
                    Console.InputEncoding = System.Text.Encoding.UTF8;
                }

                if (args.Length != 3)
                {
                    Console.Error.WriteLine("Usage:");
                    Console.Error.WriteLine(" {0} <algo> <inputFileName> <outputFileName>", Environment.GetCommandLineArgs()[0]);
                    Environment.Exit(1);
                }

                string algo = args[0], inputFileName = args[1], outputFileName = args[2];

                hashes(algo, inputFileName, outputFileName);
            }
            catch (Exception e)
            {
                Console.Error.WriteLine(e.Message);
                Environment.Exit(1);
            }

            Console.WriteLine("Operation completed succesfully");
        }
    }
}

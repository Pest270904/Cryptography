using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace RSA_GUI
{
    public partial class Form1 : Form
    {
        [DllImport("RSA_DLL.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "GenerateAndSaveRSAKeys")]
        public static extern void GenerateAndSaveRSAKeys(int keySize, string format, string privateKeyFile, string publicKeyFile);


        [DllImport("RSA_DLL.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "RSAEncrypt")]
        public static extern void RSAEncrypt(string format, string publicKeyFile, string plainTextFile, string cipherFile);

        [DllImport("RSA_DLL.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "RSADecrypt")]
        public static extern void RSADecrypt(string format, string privateKeyFile, string cipherFile, string recoveredFile);

        public Form1()
        {
            InitializeComponent();
        }

        private void key_generate_Btn_Click(object sender, EventArgs e)
        {
            try
            {
                int key_Length = int.Parse(keyLength.Text);
                GenerateAndSaveRSAKeys(key_Length, keyFormat.Text, private_keygen.Text, public_keygen.Text);
                MessageBox.Show("Operation completed successfully");
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void encrypt_Btn_Click(object sender, EventArgs e)
        {
            try
            {
                RSAEncrypt(pub_format.Text, public_enc.Text, plaintext.Text, cipher_enc.Text);
                MessageBox.Show("Operation completed successfully");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void decrypt_Btn_Click(object sender, EventArgs e)
        {
            try
            {
                RSADecrypt(pri_format.Text, private_dec.Text, cipher_dec.Text, recovered.Text);
                MessageBox.Show("Operation completed successfully");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}

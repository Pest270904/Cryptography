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
        public Form1()
        {
            InitializeComponent();
        }

        [DllImport("RSA_DLL.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "GenerateAndSaveRSAKeys")]
        public static extern void GenerateAndSaveRSAKeys(int keySize, string format, string privateKeyFile, string publicKeyFile);

        [DllImport("RSA_DLL.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "RSAEncrypt")]
        public static extern void RSAEncrypt(string choice, string publicKeyFile, string plainText, string cipherFile);

        [DllImport("RSA_DLL.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "RSADecrypt")]
        public static extern void RSADecrypt(string choice, string privateKeyFile, string cipherText, string recoveredFile);

        private void enc_choice_CheckedChanged(object sender, EventArgs e)
        {
            if(enc_choice.Checked )
            {
                plainTextLabel.Text = "Plain text file name:";
            }
            else
            {
                plainTextLabel.Text = "Plain text:";
            }
        }

        private void dec_choice_CheckedChanged(object sender, EventArgs e)
        {
            if (dec_choice.Checked)
            {
                cipherLabel.Text = "Cipher text file name:";
            }
            else
            {
                cipherLabel.Text = "Cipher text:";
            }
        }

        private void keyGenBtn_Click(object sender, EventArgs e)
        {
            try
            {
                GenerateAndSaveRSAKeys(Int32.Parse(keySizeTB.Text), keyFormatCB.Text, genKey_privateTB.Text, genKey_publicTB.Text);
                MessageBox.Show("Key generated succesfully and save to " + genKey_privateTB.Text + " and " + genKey_publicTB.Text);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void encryptBtn_Click(object sender, EventArgs e)
        {
            try
            {
                string choice = enc_choice.Checked ? "0" : "1";
                RSAEncrypt(choice, pub_enc.Text, plainText.Text, enc_cipher.Text);
                MessageBox.Show("Encrypt succesfully, cipher save to file: \"" + enc_cipher.Text + "\".");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void decryptBtn_Click(object sender, EventArgs e)
        {
            try
            {
                string choice = dec_choice.Checked ? "0" : "1";
                RSADecrypt(choice, pri_dec.Text, cipherTextTB.Text, dec_rec.Text);
                MessageBox.Show("Decrypt succesfully, recovered text save to file: \"" + dec_rec.Text + "\".");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}

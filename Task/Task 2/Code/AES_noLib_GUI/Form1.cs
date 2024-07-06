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

namespace AES_noLib_GUI
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }


        [DllImport("AES_noLib_DLL.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "AES_Encrypt")]
        public static extern void AES_Encrypt(string key, string iv, string choice, string plaintext, string cipherFileName);

        [DllImport("AES_noLib_DLL.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "AES_Decrypt")]
        public static extern void AES_Decrypt(string key, string iv, string choice, string ciphertext, string recoveredFileName);

        private void ENC_checkbox_CheckedChanged(object sender, EventArgs e)
        {
            if (enc_checkbox.Checked)
            {
                plainLabel.Text = "Plain text:";
            }
            else
            {
                plainLabel.Text = "Plaintext file name:";
            }
        }

        private void DEC_checkbox_CheckedChanged(object sender, EventArgs e)
        {
            if (dec_checkbox.Checked)
            {
                dec_label.Text = "Cipher text:";
            }
            else
            {
                dec_label.Text = "Ciphertext file name:";
            }
        }

        private void encryptBtn_Click(object sender, EventArgs e)
        {
            try
            {
                string choice = enc_checkbox.Checked ? "keyboard" : "file";
                AES_Encrypt(enc_key.Text, enc_iv.Text, choice, enc_plain.Text, enc_cipher.Text);

                MessageBox.Show("Operation succesfully");
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
                string choice = dec_checkbox.Checked ? "keyboard" : "file";
                AES_Decrypt(dec_key.Text, dec_iv.Text, choice, dec_cipher.Text, dec_recovered.Text);

                MessageBox.Show("Operation succesfully");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}

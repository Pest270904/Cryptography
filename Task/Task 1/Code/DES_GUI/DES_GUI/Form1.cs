using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace DES_GUI
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        [DllImport("DES.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "keyGen")]
        public static extern void keyGen(string keyFileName, string ivFileName);

        [DllImport("DES.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "DES_Encrypt")]
        public static extern void DES_Encrypt(int choice, int mode, string keyFileName, string ivFileName, string plain, string cipherFileName);

        [DllImport("DES.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "DES_Decrypt")]
        public static extern void DES_Decrypt(int choice, int mode, string keyFileName, string ivFileName, string cipher, string recoveredFileName);

        private void Form1_Load(object sender, EventArgs e)
        {

        }
        private void ENC_checkbox_CheckedChanged(object sender, EventArgs e)
        {
            if (ENC_checkbox.Checked)
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
            if (DEC_checkbox.Checked)
            {
                cipherLabel.Text = "Cipher text:";
            }
            else
            {
                cipherLabel.Text = "Ciphertext file name:";
            }
        }

        private void genKeyBTN_Click(object sender, EventArgs e)
        {
            try
            {
                keyGen(KG_keyTB.Text, KG_ivTB.Text);

                MessageBox.Show("Operation succesfully");
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
                int mode = 0, choice = 0;
                if (ENC_mode.Text == "ECB")
                    mode = 1;
                else if (ENC_mode.Text == "CBC")
                    mode = 2;
                else if (ENC_mode.Text == "OFB")
                    mode = 3;
                else if (ENC_mode.Text == "CFB")
                    mode = 4;
                else if (ENC_mode.Text == "CTR")
                    mode = 5;

                if (ENC_checkbox.Checked)
                    choice = 0;
                else choice = 1;

                DES_Encrypt(choice, mode, ENC_key.Text, ENC_iv.Text,
                    ENC_plain.Text, ENC_cipher.Text);

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
                int mode = 0, choice = 0;
                if (DEC_mode.Text == "ECB")
                    mode = 1;
                else if (DEC_mode.Text == "CBC")
                    mode = 2;
                else if (DEC_mode.Text == "OFB")
                    mode = 3;
                else if (DEC_mode.Text == "CFB")
                    mode = 4;
                else if (DEC_mode.Text == "CTR")
                    mode = 5;

                if (DEC_checkbox.Checked)
                    choice = 0;
                else choice = 1;

                DES_Decrypt(choice, mode, DEC_key.Text, DEC_iv.Text,
                    DEC_cipher.Text, DEC_rec.Text);

                MessageBox.Show("Operation succesfully");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void ENC_mode_TextChanged(object sender, EventArgs e)
        {

        }

        private void DEC_mode_TextChanged(object sender, EventArgs e)
        {

        }
    }
}

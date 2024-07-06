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

namespace AES_GUI
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }


        [DllImport("AES.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "keyGen")]
        public static extern void keyGen(string keyFileName, string ivFileName);

        [DllImport("AES.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "AES_Encrypt")]
        public static extern void AES_Encrypt(int choice, int mode, string keyFileName, string ivFileName, string plain, string cipherFileName, string auth);

        [DllImport("AES.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "AES_Decrypt")]
        public static extern void AES_Decrypt(int choice, int mode, string keyFileName, string ivFileName, string cipher, string recoveredFileName, string auth);

        private void ENC_checkbox_CheckedChanged(object sender, EventArgs e)
        {
            if(ENC_checkbox.Checked)
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
                else if (ENC_mode.Text == "XTS")
                    mode = 6;
                else if (ENC_mode.Text == "CCN")
                    mode = 7;
                else if (ENC_mode.Text == "GCM")
                    mode = 8;

                if (ENC_checkbox.Checked)
                    choice = 0;
                else choice = 1;

                AES_Encrypt(choice, mode, ENC_key.Text, ENC_iv.Text,
                    ENC_plain.Text, ENC_cipher.Text, ENC_aad.Text);

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
                else if (DEC_mode.Text == "XTS")
                    mode = 6;
                else if (DEC_mode.Text == "CCN")
                    mode = 7;
                else if (DEC_mode.Text == "GCM")
                    mode = 8;

                if (DEC_checkbox.Checked)
                    choice = 0;
                else choice = 1;

                AES_Decrypt(choice, mode, DEC_key.Text, DEC_iv.Text,
                    DEC_cipher.Text, DEC_rec.Text, DEC_aad.Text);

                MessageBox.Show("Operation succesfully");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void ENC_mode_TextChanged(object sender, EventArgs e)
        {
            if (ENC_mode.Text == "GCM")
            {
                aad_enc_label.Visible = true;
                ENC_aad.Visible = true;
            }
            else
            {
                aad_enc_label.Visible = false;
                ENC_aad.Visible = false;
            }
        }

        private void DEC_mode_TextChanged(object sender, EventArgs e)
        {
            if (DEC_mode.Text == "GCM")
            {
                aad_dec_label.Visible = true;
                DEC_aad.Visible = true;
            }
            else
            {
                aad_dec_label.Visible = false;
                DEC_aad.Visible = false;
            }
        }
    }
}

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

namespace DS
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        [DllImport("digital_signature.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "signPdf")]
        public static extern bool signPdf(string privateKeyFileName, string pdfPath, string signaturePath);

        [DllImport("digital_signature.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "verifySignature")]
        public static extern int verifySignature(string publicKeyFileName, string pdfPath, string signaturePath);

        [DllImport("digital_signature.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "keyGen")]
        public static extern bool keyGen(string privateKeyFileName, string publicKeyFileName);

        private void keygenBtn_Click(object sender, EventArgs e)
        {
            try
            {
                keyGen(kg_priTB.Text, kg_pubTB.Text);
                MessageBox.Show("Operation perform succesfully.");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void signBtn_Click(object sender, EventArgs e)
        {
            try
            {
                signPdf(sign_priTB.Text, sign_fileTB.Text, sign_sigTB.Text);
                MessageBox.Show("Operation perform succesfully.");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void verifyBtn_Click(object sender, EventArgs e)
        {
            try
            {
                if (verifySignature(verify_pubTB.Text, verify_fileTB.Text, verify_sigTB.Text) == 1)
                { 
                    status.Text = "File verified successfully.";
                    status.ForeColor = Color.Green;
                }
                else {
                    status.Text = "Failed to verify PDF.";
                    status.ForeColor = Color.Red;
                }
                MessageBox.Show("Operation perform succesfully.");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}

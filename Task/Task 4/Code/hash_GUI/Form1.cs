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

namespace hash_GUI
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        [DllImport("Hash_DLL.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "hash")]
        public static extern void hash(int choice, string algo, string plainText, string outputFileName, int digestLength);

        private void executeBtn_Click(object sender, EventArgs e)
        {
            try
            {
                string algo = algoCBB.Text, plain = inputFileNameTB.Text, output = outputFileNameTB.Text;
                int length = 0;

                if (algoCBB.Text == "SHAKE128" || algoCBB.Text == "SHAKE256")
                    length = int.Parse(lengthTB.Text);

                int choice = checkBox1.Checked ? 0 :1;

                hash(choice, algo, plain, output, length);


                MessageBox.Show("Operation completed succesfully");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void algoCBB_TextChanged(object sender, EventArgs e)
        {
            if (algoCBB.Text == "SHAKE128" || algoCBB.Text == "SHAKE256")
            {
                lengthLabel.Visible = true;
                lengthTB.Visible = true;
            }
            else
            {
                lengthLabel.Visible = false;
                lengthTB.Visible = false;
            }
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked)
            {
                plainLabel.Text = "Plaintext";
            }
            else
            {
                plainLabel.Text = "Plain text file name";
            }
        }
    }
}

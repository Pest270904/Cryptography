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

        [DllImport("hash.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "hashes")]
        public static extern void hashes(string algo, string input_filemame, string output_filename);

        private void executeBtn_Click(object sender, EventArgs e)
        {
            try
            {
                string algo = algoCBB.Text, inputFileName = inputFileNameTB.Text, outputFileName = outputFileNameTB.Text;

                hashes(algo, inputFileName, outputFileName);


                MessageBox.Show("Operation completed succesfully");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}

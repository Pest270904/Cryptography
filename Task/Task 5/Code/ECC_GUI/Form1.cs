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
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Button;

namespace ECC_GUI
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        [DllImport("ECC_DLL.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "keygen")]
        public static extern int keygen(string privateFileName, string publicFileName, string format);
        [DllImport("ECC_DLL.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "sign")]
        public static extern int sign(int choice, string privateFileName, string message, string signatureFileName);
        [DllImport("ECC_DLL.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "verify")]
        public static extern int verify(string publicFileName, string messageFileName, string signatureFileName);

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                keygen(GK_pri.Text, GK_pub.Text, GK_format.Text);
                MessageBox.Show("Key generated succesfully");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                int choice = S_checkbox.Checked ? 1 : 0;
                int result = sign(choice, S_pri.Text, S_msg.Text, S_sig.Text);

                if (result == 0)
                {
                    MessageBox.Show("Sign succesfully");
                }
                else
                {
                    MessageBox.Show("Fail to sign");
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            try
            {
                int result = verify(V_pub.Text, V_msg.Text, V_sig.Text);

                if (result == 0)
                {
                    MessageBox.Show("Verify succesfully");
                }
                else
                {
                    MessageBox.Show("Fail to verify");
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void S_checkbox_CheckedChanged(object sender, EventArgs e)
        {
            if (S_checkbox.Checked)
            {
                S_label.Text = "Message: ";
            }
            else
            {
                S_label.Text = "Message file: ";
            }
        }
    }
}

namespace ECC_GUI
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.GK_pri = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.GK_pub = new System.Windows.Forms.TextBox();
            this.button2 = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.S_pri = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.S_sig = new System.Windows.Forms.TextBox();
            this.S_checkbox = new System.Windows.Forms.CheckBox();
            this.S_label = new System.Windows.Forms.Label();
            this.S_msg = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.V_msg = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.V_sig = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.V_pub = new System.Windows.Forms.TextBox();
            this.button3 = new System.Windows.Forms.Button();
            this.GK_format = new System.Windows.Forms.ComboBox();
            this.label8 = new System.Windows.Forms.Label();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.tabPage2.SuspendLayout();
            this.tabPage3.SuspendLayout();
            this.SuspendLayout();
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Controls.Add(this.tabPage3);
            this.tabControl1.Location = new System.Drawing.Point(49, 26);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(522, 249);
            this.tabControl1.TabIndex = 0;
            // 
            // tabPage1
            // 
            this.tabPage1.BackColor = System.Drawing.Color.Silver;
            this.tabPage1.Controls.Add(this.label8);
            this.tabPage1.Controls.Add(this.GK_format);
            this.tabPage1.Controls.Add(this.label2);
            this.tabPage1.Controls.Add(this.GK_pub);
            this.tabPage1.Controls.Add(this.label1);
            this.tabPage1.Controls.Add(this.button1);
            this.tabPage1.Controls.Add(this.GK_pri);
            this.tabPage1.Location = new System.Drawing.Point(4, 25);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(514, 220);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "KeyGen";
            // 
            // tabPage2
            // 
            this.tabPage2.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.tabPage2.Controls.Add(this.S_checkbox);
            this.tabPage2.Controls.Add(this.S_label);
            this.tabPage2.Controls.Add(this.S_msg);
            this.tabPage2.Controls.Add(this.label5);
            this.tabPage2.Controls.Add(this.S_sig);
            this.tabPage2.Controls.Add(this.label4);
            this.tabPage2.Controls.Add(this.S_pri);
            this.tabPage2.Controls.Add(this.button2);
            this.tabPage2.Location = new System.Drawing.Point(4, 25);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(514, 220);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Sign";
            // 
            // tabPage3
            // 
            this.tabPage3.BackColor = System.Drawing.Color.DarkGray;
            this.tabPage3.Controls.Add(this.label3);
            this.tabPage3.Controls.Add(this.V_msg);
            this.tabPage3.Controls.Add(this.label6);
            this.tabPage3.Controls.Add(this.V_sig);
            this.tabPage3.Controls.Add(this.label7);
            this.tabPage3.Controls.Add(this.V_pub);
            this.tabPage3.Controls.Add(this.button3);
            this.tabPage3.Location = new System.Drawing.Point(4, 25);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage3.Size = new System.Drawing.Size(514, 220);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "Verify";
            // 
            // GK_pri
            // 
            this.GK_pri.Location = new System.Drawing.Point(131, 49);
            this.GK_pri.Name = "GK_pri";
            this.GK_pri.Size = new System.Drawing.Size(149, 22);
            this.GK_pri.TabIndex = 0;
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.button1.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.button1.Location = new System.Drawing.Point(332, 88);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(146, 49);
            this.button1.TabIndex = 1;
            this.button1.Text = "Generate";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(28, 52);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(97, 16);
            this.label1.TabIndex = 2;
            this.label1.Text = "Private key file:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(28, 104);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(92, 16);
            this.label2.TabIndex = 4;
            this.label2.Text = "Public key file:";
            // 
            // GK_pub
            // 
            this.GK_pub.Location = new System.Drawing.Point(131, 101);
            this.GK_pub.Name = "GK_pub";
            this.GK_pub.Size = new System.Drawing.Size(149, 22);
            this.GK_pub.TabIndex = 3;
            // 
            // button2
            // 
            this.button2.BackColor = System.Drawing.Color.LightCoral;
            this.button2.ForeColor = System.Drawing.Color.Black;
            this.button2.Location = new System.Drawing.Point(337, 131);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(146, 49);
            this.button2.TabIndex = 4;
            this.button2.Text = "Sign";
            this.button2.UseVisualStyleBackColor = false;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(19, 126);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(97, 16);
            this.label4.TabIndex = 7;
            this.label4.Text = "Private key file:";
            // 
            // S_pri
            // 
            this.S_pri.Location = new System.Drawing.Point(122, 123);
            this.S_pri.Name = "S_pri";
            this.S_pri.Size = new System.Drawing.Size(149, 22);
            this.S_pri.TabIndex = 6;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(19, 173);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(87, 16);
            this.label5.TabIndex = 9;
            this.label5.Text = "Signature file:";
            // 
            // S_sig
            // 
            this.S_sig.Location = new System.Drawing.Point(122, 170);
            this.S_sig.Name = "S_sig";
            this.S_sig.Size = new System.Drawing.Size(149, 22);
            this.S_sig.TabIndex = 8;
            // 
            // S_checkbox
            // 
            this.S_checkbox.AutoSize = true;
            this.S_checkbox.Location = new System.Drawing.Point(22, 31);
            this.S_checkbox.Name = "S_checkbox";
            this.S_checkbox.Size = new System.Drawing.Size(179, 20);
            this.S_checkbox.TabIndex = 13;
            this.S_checkbox.Text = "Message from keyboard:";
            this.S_checkbox.UseVisualStyleBackColor = true;
            this.S_checkbox.CheckedChanged += new System.EventHandler(this.S_checkbox_CheckedChanged);
            // 
            // S_label
            // 
            this.S_label.AutoSize = true;
            this.S_label.Location = new System.Drawing.Point(19, 79);
            this.S_label.Name = "S_label";
            this.S_label.Size = new System.Drawing.Size(87, 16);
            this.S_label.TabIndex = 12;
            this.S_label.Text = "Message file:";
            // 
            // S_msg
            // 
            this.S_msg.Location = new System.Drawing.Point(122, 76);
            this.S_msg.Name = "S_msg";
            this.S_msg.Size = new System.Drawing.Size(363, 22);
            this.S_msg.TabIndex = 11;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(25, 54);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(87, 16);
            this.label3.TabIndex = 19;
            this.label3.Text = "Message file:";
            // 
            // V_msg
            // 
            this.V_msg.Location = new System.Drawing.Point(128, 51);
            this.V_msg.Name = "V_msg";
            this.V_msg.Size = new System.Drawing.Size(149, 22);
            this.V_msg.TabIndex = 18;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(25, 148);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(87, 16);
            this.label6.TabIndex = 17;
            this.label6.Text = "Signature file:";
            // 
            // V_sig
            // 
            this.V_sig.Location = new System.Drawing.Point(128, 145);
            this.V_sig.Name = "V_sig";
            this.V_sig.Size = new System.Drawing.Size(149, 22);
            this.V_sig.TabIndex = 16;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(25, 101);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(92, 16);
            this.label7.TabIndex = 15;
            this.label7.Text = "Public key file:";
            // 
            // V_pub
            // 
            this.V_pub.Location = new System.Drawing.Point(128, 98);
            this.V_pub.Name = "V_pub";
            this.V_pub.Size = new System.Drawing.Size(149, 22);
            this.V_pub.TabIndex = 14;
            // 
            // button3
            // 
            this.button3.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(128)))), ((int)(((byte)(255)))), ((int)(((byte)(128)))));
            this.button3.ForeColor = System.Drawing.Color.Black;
            this.button3.Location = new System.Drawing.Point(341, 85);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(146, 49);
            this.button3.TabIndex = 13;
            this.button3.Text = "Verify";
            this.button3.UseVisualStyleBackColor = false;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // GK_format
            // 
            this.GK_format.FormattingEnabled = true;
            this.GK_format.Items.AddRange(new object[] {
            "DER",
            "PEM"});
            this.GK_format.Location = new System.Drawing.Point(131, 155);
            this.GK_format.Name = "GK_format";
            this.GK_format.Size = new System.Drawing.Size(149, 24);
            this.GK_format.TabIndex = 5;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(28, 158);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(52, 16);
            this.label8.TabIndex = 6;
            this.label8.Text = "Format:";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.ClientSize = new System.Drawing.Size(652, 334);
            this.Controls.Add(this.tabControl1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            this.tabPage3.ResumeLayout(false);
            this.tabPage3.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox GK_pub;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox GK_pri;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.CheckBox S_checkbox;
        private System.Windows.Forms.Label S_label;
        private System.Windows.Forms.TextBox S_msg;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox S_sig;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox S_pri;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox V_msg;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox V_sig;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox V_pub;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.ComboBox GK_format;
    }
}


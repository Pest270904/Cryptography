namespace RSA_GUI
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
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.public_keygen = new System.Windows.Forms.TextBox();
            this.private_keygen = new System.Windows.Forms.TextBox();
            this.keyFormat = new System.Windows.Forms.ComboBox();
            this.label4 = new System.Windows.Forms.Label();
            this.keyLength = new System.Windows.Forms.ComboBox();
            this.key_generate_Btn = new System.Windows.Forms.Button();
            this.tabPage5 = new System.Windows.Forms.TabPage();
            this.encrypt_Btn = new System.Windows.Forms.Button();
            this.pub_format = new System.Windows.Forms.ComboBox();
            this.label5 = new System.Windows.Forms.Label();
            this.public_enc = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.cipher_enc = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.plaintext = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.cipher_dec = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.recovered = new System.Windows.Forms.TextBox();
            this.label12 = new System.Windows.Forms.Label();
            this.private_dec = new System.Windows.Forms.TextBox();
            this.label13 = new System.Windows.Forms.Label();
            this.decrypt_Btn = new System.Windows.Forms.Button();
            this.pri_format = new System.Windows.Forms.ComboBox();
            this.label14 = new System.Windows.Forms.Label();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.tabPage2.SuspendLayout();
            this.tabPage5.SuspendLayout();
            this.SuspendLayout();
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Controls.Add(this.tabPage5);
            this.tabControl1.Location = new System.Drawing.Point(12, 12);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(632, 309);
            this.tabControl1.TabIndex = 0;
            // 
            // tabPage1
            // 
            this.tabPage1.BackColor = System.Drawing.Color.LightGray;
            this.tabPage1.Controls.Add(this.key_generate_Btn);
            this.tabPage1.Controls.Add(this.keyLength);
            this.tabPage1.Controls.Add(this.label4);
            this.tabPage1.Controls.Add(this.keyFormat);
            this.tabPage1.Controls.Add(this.private_keygen);
            this.tabPage1.Controls.Add(this.public_keygen);
            this.tabPage1.Controls.Add(this.label3);
            this.tabPage1.Controls.Add(this.label2);
            this.tabPage1.Controls.Add(this.label1);
            this.tabPage1.Location = new System.Drawing.Point(4, 25);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(624, 280);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "KeyGen";
            // 
            // tabPage2
            // 
            this.tabPage2.BackColor = System.Drawing.Color.LightGray;
            this.tabPage2.Controls.Add(this.plaintext);
            this.tabPage2.Controls.Add(this.label9);
            this.tabPage2.Controls.Add(this.label8);
            this.tabPage2.Controls.Add(this.cipher_enc);
            this.tabPage2.Controls.Add(this.label7);
            this.tabPage2.Controls.Add(this.public_enc);
            this.tabPage2.Controls.Add(this.label6);
            this.tabPage2.Controls.Add(this.encrypt_Btn);
            this.tabPage2.Controls.Add(this.pub_format);
            this.tabPage2.Controls.Add(this.label5);
            this.tabPage2.Location = new System.Drawing.Point(4, 25);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(624, 280);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Encrypt";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(38, 34);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(116, 16);
            this.label1.TabIndex = 1;
            this.label1.Text = "Key length (bytes):";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(428, 172);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(134, 16);
            this.label2.TabIndex = 2;
            this.label2.Text = "Private key file name:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(428, 32);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(129, 16);
            this.label3.TabIndex = 3;
            this.label3.Text = "Public key file name:";
            // 
            // public_keygen
            // 
            this.public_keygen.Location = new System.Drawing.Point(431, 51);
            this.public_keygen.Name = "public_keygen";
            this.public_keygen.Size = new System.Drawing.Size(154, 22);
            this.public_keygen.TabIndex = 4;
            // 
            // private_keygen
            // 
            this.private_keygen.Location = new System.Drawing.Point(431, 191);
            this.private_keygen.Name = "private_keygen";
            this.private_keygen.Size = new System.Drawing.Size(154, 22);
            this.private_keygen.TabIndex = 5;
            // 
            // keyFormat
            // 
            this.keyFormat.FormattingEnabled = true;
            this.keyFormat.Items.AddRange(new object[] {
            "DER",
            "Base64"});
            this.keyFormat.Location = new System.Drawing.Point(41, 191);
            this.keyFormat.Name = "keyFormat";
            this.keyFormat.Size = new System.Drawing.Size(121, 24);
            this.keyFormat.TabIndex = 7;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(38, 163);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(52, 16);
            this.label4.TabIndex = 8;
            this.label4.Text = "Format:";
            // 
            // keyLength
            // 
            this.keyLength.FormattingEnabled = true;
            this.keyLength.Items.AddRange(new object[] {
            "1028",
            "2056",
            "3072"});
            this.keyLength.Location = new System.Drawing.Point(41, 51);
            this.keyLength.Name = "keyLength";
            this.keyLength.Size = new System.Drawing.Size(121, 24);
            this.keyLength.TabIndex = 9;
            // 
            // key_generate_Btn
            // 
            this.key_generate_Btn.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.key_generate_Btn.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.key_generate_Btn.Location = new System.Drawing.Point(230, 101);
            this.key_generate_Btn.Name = "key_generate_Btn";
            this.key_generate_Btn.Size = new System.Drawing.Size(139, 44);
            this.key_generate_Btn.TabIndex = 10;
            this.key_generate_Btn.Text = "GENERATE";
            this.key_generate_Btn.UseVisualStyleBackColor = false;
            this.key_generate_Btn.Click += new System.EventHandler(this.key_generate_Btn_Click);
            // 
            // tabPage5
            // 
            this.tabPage5.BackColor = System.Drawing.Color.LightGray;
            this.tabPage5.Controls.Add(this.cipher_dec);
            this.tabPage5.Controls.Add(this.label10);
            this.tabPage5.Controls.Add(this.label11);
            this.tabPage5.Controls.Add(this.recovered);
            this.tabPage5.Controls.Add(this.label12);
            this.tabPage5.Controls.Add(this.private_dec);
            this.tabPage5.Controls.Add(this.label13);
            this.tabPage5.Controls.Add(this.decrypt_Btn);
            this.tabPage5.Controls.Add(this.pri_format);
            this.tabPage5.Controls.Add(this.label14);
            this.tabPage5.Location = new System.Drawing.Point(4, 25);
            this.tabPage5.Name = "tabPage5";
            this.tabPage5.Size = new System.Drawing.Size(624, 280);
            this.tabPage5.TabIndex = 2;
            this.tabPage5.Text = "Decrypt";
            // 
            // encrypt_Btn
            // 
            this.encrypt_Btn.BackColor = System.Drawing.Color.IndianRed;
            this.encrypt_Btn.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.encrypt_Btn.Location = new System.Drawing.Point(208, 165);
            this.encrypt_Btn.Name = "encrypt_Btn";
            this.encrypt_Btn.Size = new System.Drawing.Size(139, 44);
            this.encrypt_Btn.TabIndex = 13;
            this.encrypt_Btn.Text = "ENCRYPT";
            this.encrypt_Btn.UseVisualStyleBackColor = false;
            this.encrypt_Btn.Click += new System.EventHandler(this.encrypt_Btn_Click);
            // 
            // pub_format
            // 
            this.pub_format.FormattingEnabled = true;
            this.pub_format.Items.AddRange(new object[] {
            "DER",
            "Base64"});
            this.pub_format.Location = new System.Drawing.Point(51, 34);
            this.pub_format.Name = "pub_format";
            this.pub_format.Size = new System.Drawing.Size(154, 24);
            this.pub_format.TabIndex = 12;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(48, 17);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(112, 16);
            this.label5.TabIndex = 11;
            this.label5.Text = "Public key format:";
            // 
            // public_enc
            // 
            this.public_enc.Location = new System.Drawing.Point(51, 92);
            this.public_enc.Name = "public_enc";
            this.public_enc.Size = new System.Drawing.Size(154, 22);
            this.public_enc.TabIndex = 15;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(48, 73);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(0, 16);
            this.label6.TabIndex = 14;
            // 
            // cipher_enc
            // 
            this.cipher_enc.Location = new System.Drawing.Point(347, 92);
            this.cipher_enc.Name = "cipher_enc";
            this.cipher_enc.Size = new System.Drawing.Size(154, 22);
            this.cipher_enc.TabIndex = 17;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(344, 73);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(208, 16);
            this.label7.TabIndex = 16;
            this.label7.Text = "Cipher file\'s name after encrypted:";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(48, 73);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(129, 16);
            this.label8.TabIndex = 18;
            this.label8.Text = "Public key file name:";
            // 
            // plaintext
            // 
            this.plaintext.Location = new System.Drawing.Point(347, 36);
            this.plaintext.Name = "plaintext";
            this.plaintext.Size = new System.Drawing.Size(154, 22);
            this.plaintext.TabIndex = 20;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(344, 17);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(127, 16);
            this.label9.TabIndex = 19;
            this.label9.Text = "Plaintext file\'s name:";
            // 
            // cipher_dec
            // 
            this.cipher_dec.Location = new System.Drawing.Point(343, 38);
            this.cipher_dec.Name = "cipher_dec";
            this.cipher_dec.Size = new System.Drawing.Size(154, 22);
            this.cipher_dec.TabIndex = 30;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(340, 19);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(116, 16);
            this.label10.TabIndex = 29;
            this.label10.Text = "Cipher file\'s name:";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(44, 75);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(134, 16);
            this.label11.TabIndex = 28;
            this.label11.Text = "Private key file name:";
            // 
            // recovered
            // 
            this.recovered.Location = new System.Drawing.Point(343, 94);
            this.recovered.Name = "recovered";
            this.recovered.Size = new System.Drawing.Size(154, 22);
            this.recovered.TabIndex = 27;
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(340, 75);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(238, 16);
            this.label12.TabIndex = 26;
            this.label12.Text = "Recovered file\'s name after decrypted:";
            // 
            // private_dec
            // 
            this.private_dec.Location = new System.Drawing.Point(47, 94);
            this.private_dec.Name = "private_dec";
            this.private_dec.Size = new System.Drawing.Size(154, 22);
            this.private_dec.TabIndex = 25;
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(44, 75);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(0, 16);
            this.label13.TabIndex = 24;
            // 
            // decrypt_Btn
            // 
            this.decrypt_Btn.BackColor = System.Drawing.Color.IndianRed;
            this.decrypt_Btn.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.decrypt_Btn.Location = new System.Drawing.Point(204, 167);
            this.decrypt_Btn.Name = "decrypt_Btn";
            this.decrypt_Btn.Size = new System.Drawing.Size(139, 44);
            this.decrypt_Btn.TabIndex = 23;
            this.decrypt_Btn.Text = "DECRYPT";
            this.decrypt_Btn.UseVisualStyleBackColor = false;
            this.decrypt_Btn.Click += new System.EventHandler(this.decrypt_Btn_Click);
            // 
            // pri_format
            // 
            this.pri_format.FormattingEnabled = true;
            this.pri_format.Items.AddRange(new object[] {
            "DER",
            "Base64"});
            this.pri_format.Location = new System.Drawing.Point(47, 36);
            this.pri_format.Name = "pri_format";
            this.pri_format.Size = new System.Drawing.Size(154, 24);
            this.pri_format.TabIndex = 22;
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Location = new System.Drawing.Point(44, 19);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(117, 16);
            this.label14.TabIndex = 21;
            this.label14.Text = "Private key format:";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(120F, 120F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Dpi;
            this.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.ClientSize = new System.Drawing.Size(659, 343);
            this.Controls.Add(this.tabControl1);
            this.Name = "Form1";
            this.Text = "RSA - Keygen_Encrypt_Decrypt";
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            this.tabPage5.ResumeLayout(false);
            this.tabPage5.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button key_generate_Btn;
        private System.Windows.Forms.ComboBox keyLength;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.ComboBox keyFormat;
        private System.Windows.Forms.TextBox private_keygen;
        private System.Windows.Forms.TextBox public_keygen;
        private System.Windows.Forms.TextBox plaintext;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.TextBox cipher_enc;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox public_enc;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Button encrypt_Btn;
        private System.Windows.Forms.ComboBox pub_format;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TabPage tabPage5;
        private System.Windows.Forms.TextBox cipher_dec;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.TextBox recovered;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.TextBox private_dec;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.Button decrypt_Btn;
        private System.Windows.Forms.ComboBox pri_format;
        private System.Windows.Forms.Label label14;
    }
}


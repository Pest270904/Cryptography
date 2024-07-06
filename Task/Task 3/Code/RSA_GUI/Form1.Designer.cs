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
            this.label4 = new System.Windows.Forms.Label();
            this.genKey_publicTB = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.genKey_privateTB = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.keyFormatCB = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.keyGenBtn = new System.Windows.Forms.Button();
            this.keySizeTB = new System.Windows.Forms.TextBox();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.label8 = new System.Windows.Forms.Label();
            this.enc_cipher = new System.Windows.Forms.TextBox();
            this.encryptBtn = new System.Windows.Forms.Button();
            this.label6 = new System.Windows.Forms.Label();
            this.pub_enc = new System.Windows.Forms.TextBox();
            this.plainTextLabel = new System.Windows.Forms.Label();
            this.plainText = new System.Windows.Forms.TextBox();
            this.enc_choice = new System.Windows.Forms.CheckBox();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.label9 = new System.Windows.Forms.Label();
            this.dec_rec = new System.Windows.Forms.TextBox();
            this.decryptBtn = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            this.pri_dec = new System.Windows.Forms.TextBox();
            this.cipherLabel = new System.Windows.Forms.Label();
            this.cipherTextTB = new System.Windows.Forms.TextBox();
            this.dec_choice = new System.Windows.Forms.CheckBox();
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
            this.tabControl1.Location = new System.Drawing.Point(32, 23);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(657, 330);
            this.tabControl1.TabIndex = 0;
            // 
            // tabPage1
            // 
            this.tabPage1.BackColor = System.Drawing.SystemColors.ButtonShadow;
            this.tabPage1.Controls.Add(this.label4);
            this.tabPage1.Controls.Add(this.genKey_publicTB);
            this.tabPage1.Controls.Add(this.label3);
            this.tabPage1.Controls.Add(this.genKey_privateTB);
            this.tabPage1.Controls.Add(this.label2);
            this.tabPage1.Controls.Add(this.keyFormatCB);
            this.tabPage1.Controls.Add(this.label1);
            this.tabPage1.Controls.Add(this.keyGenBtn);
            this.tabPage1.Controls.Add(this.keySizeTB);
            this.tabPage1.Location = new System.Drawing.Point(4, 25);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(649, 301);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "GenKey";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(358, 128);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(129, 16);
            this.label4.TabIndex = 8;
            this.label4.Text = "Public key file name:";
            // 
            // genKey_publicTB
            // 
            this.genKey_publicTB.Location = new System.Drawing.Point(361, 147);
            this.genKey_publicTB.Name = "genKey_publicTB";
            this.genKey_publicTB.Size = new System.Drawing.Size(209, 22);
            this.genKey_publicTB.TabIndex = 7;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(358, 48);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(134, 16);
            this.label3.TabIndex = 6;
            this.label3.Text = "Private key file name:";
            // 
            // genKey_privateTB
            // 
            this.genKey_privateTB.Location = new System.Drawing.Point(361, 67);
            this.genKey_privateTB.Name = "genKey_privateTB";
            this.genKey_privateTB.Size = new System.Drawing.Size(209, 22);
            this.genKey_privateTB.TabIndex = 5;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(83, 128);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(73, 16);
            this.label2.TabIndex = 4;
            this.label2.Text = "Key format:";
            // 
            // keyFormatCB
            // 
            this.keyFormatCB.FormattingEnabled = true;
            this.keyFormatCB.Items.AddRange(new object[] {
            "DER",
            "Base64",
            "PEM"});
            this.keyFormatCB.Location = new System.Drawing.Point(86, 147);
            this.keyFormatCB.Name = "keyFormatCB";
            this.keyFormatCB.Size = new System.Drawing.Size(129, 24);
            this.keyFormatCB.TabIndex = 3;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(80, 48);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(60, 16);
            this.label1.TabIndex = 2;
            this.label1.Text = "Key size:";
            // 
            // keyGenBtn
            // 
            this.keyGenBtn.BackColor = System.Drawing.Color.DarkGray;
            this.keyGenBtn.Location = new System.Drawing.Point(254, 220);
            this.keyGenBtn.Name = "keyGenBtn";
            this.keyGenBtn.Size = new System.Drawing.Size(124, 54);
            this.keyGenBtn.TabIndex = 1;
            this.keyGenBtn.Text = "Gen key";
            this.keyGenBtn.UseVisualStyleBackColor = false;
            this.keyGenBtn.Click += new System.EventHandler(this.keyGenBtn_Click);
            // 
            // keySizeTB
            // 
            this.keySizeTB.Location = new System.Drawing.Point(83, 67);
            this.keySizeTB.Name = "keySizeTB";
            this.keySizeTB.Size = new System.Drawing.Size(132, 22);
            this.keySizeTB.TabIndex = 0;
            // 
            // tabPage2
            // 
            this.tabPage2.BackColor = System.Drawing.Color.Silver;
            this.tabPage2.Controls.Add(this.label8);
            this.tabPage2.Controls.Add(this.enc_cipher);
            this.tabPage2.Controls.Add(this.encryptBtn);
            this.tabPage2.Controls.Add(this.label6);
            this.tabPage2.Controls.Add(this.pub_enc);
            this.tabPage2.Controls.Add(this.plainTextLabel);
            this.tabPage2.Controls.Add(this.plainText);
            this.tabPage2.Controls.Add(this.enc_choice);
            this.tabPage2.Location = new System.Drawing.Point(4, 25);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(649, 301);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Encrypt";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(60, 209);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(126, 16);
            this.label8.TabIndex = 8;
            this.label8.Text = "Ciphertext file name:";
            // 
            // enc_cipher
            // 
            this.enc_cipher.Location = new System.Drawing.Point(63, 228);
            this.enc_cipher.Name = "enc_cipher";
            this.enc_cipher.Size = new System.Drawing.Size(236, 22);
            this.enc_cipher.TabIndex = 7;
            // 
            // encryptBtn
            // 
            this.encryptBtn.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.encryptBtn.Location = new System.Drawing.Point(431, 171);
            this.encryptBtn.Name = "encryptBtn";
            this.encryptBtn.Size = new System.Drawing.Size(124, 54);
            this.encryptBtn.TabIndex = 6;
            this.encryptBtn.Text = "Encrypt";
            this.encryptBtn.UseVisualStyleBackColor = false;
            this.encryptBtn.Click += new System.EventHandler(this.encryptBtn_Click);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(60, 134);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(129, 16);
            this.label6.TabIndex = 5;
            this.label6.Text = "Public key file name:";
            // 
            // pub_enc
            // 
            this.pub_enc.Location = new System.Drawing.Point(63, 153);
            this.pub_enc.Name = "pub_enc";
            this.pub_enc.Size = new System.Drawing.Size(236, 22);
            this.pub_enc.TabIndex = 4;
            // 
            // plainTextLabel
            // 
            this.plainTextLabel.AutoSize = true;
            this.plainTextLabel.Location = new System.Drawing.Point(60, 66);
            this.plainTextLabel.Name = "plainTextLabel";
            this.plainTextLabel.Size = new System.Drawing.Size(63, 16);
            this.plainTextLabel.TabIndex = 2;
            this.plainTextLabel.Text = "Plain text:";
            // 
            // plainText
            // 
            this.plainText.Location = new System.Drawing.Point(63, 85);
            this.plainText.Name = "plainText";
            this.plainText.Size = new System.Drawing.Size(548, 22);
            this.plainText.TabIndex = 1;
            // 
            // enc_choice
            // 
            this.enc_choice.AutoSize = true;
            this.enc_choice.Location = new System.Drawing.Point(63, 28);
            this.enc_choice.Name = "enc_choice";
            this.enc_choice.Size = new System.Drawing.Size(131, 20);
            this.enc_choice.TabIndex = 0;
            this.enc_choice.Text = "Plain text from file";
            this.enc_choice.UseVisualStyleBackColor = true;
            this.enc_choice.CheckedChanged += new System.EventHandler(this.enc_choice_CheckedChanged);
            // 
            // tabPage3
            // 
            this.tabPage3.BackColor = System.Drawing.Color.Silver;
            this.tabPage3.Controls.Add(this.label9);
            this.tabPage3.Controls.Add(this.dec_rec);
            this.tabPage3.Controls.Add(this.decryptBtn);
            this.tabPage3.Controls.Add(this.label5);
            this.tabPage3.Controls.Add(this.pri_dec);
            this.tabPage3.Controls.Add(this.cipherLabel);
            this.tabPage3.Controls.Add(this.cipherTextTB);
            this.tabPage3.Controls.Add(this.dec_choice);
            this.tabPage3.Location = new System.Drawing.Point(4, 25);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage3.Size = new System.Drawing.Size(649, 301);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "Decrypt";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(49, 215);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(135, 16);
            this.label9.TabIndex = 14;
            this.label9.Text = "Recovered file name:";
            // 
            // dec_rec
            // 
            this.dec_rec.Location = new System.Drawing.Point(52, 234);
            this.dec_rec.Name = "dec_rec";
            this.dec_rec.Size = new System.Drawing.Size(236, 22);
            this.dec_rec.TabIndex = 13;
            // 
            // decryptBtn
            // 
            this.decryptBtn.BackColor = System.Drawing.Color.Salmon;
            this.decryptBtn.Location = new System.Drawing.Point(438, 191);
            this.decryptBtn.Name = "decryptBtn";
            this.decryptBtn.Size = new System.Drawing.Size(124, 54);
            this.decryptBtn.TabIndex = 12;
            this.decryptBtn.Text = "Decrypt";
            this.decryptBtn.UseVisualStyleBackColor = false;
            this.decryptBtn.Click += new System.EventHandler(this.decryptBtn_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(49, 138);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(134, 16);
            this.label5.TabIndex = 11;
            this.label5.Text = "Private key file name:";
            // 
            // pri_dec
            // 
            this.pri_dec.Location = new System.Drawing.Point(52, 157);
            this.pri_dec.Name = "pri_dec";
            this.pri_dec.Size = new System.Drawing.Size(236, 22);
            this.pri_dec.TabIndex = 10;
            // 
            // cipherLabel
            // 
            this.cipherLabel.AutoSize = true;
            this.cipherLabel.Location = new System.Drawing.Point(49, 70);
            this.cipherLabel.Name = "cipherLabel";
            this.cipherLabel.Size = new System.Drawing.Size(72, 16);
            this.cipherLabel.TabIndex = 9;
            this.cipherLabel.Text = "Cipher text:";
            // 
            // cipherTextTB
            // 
            this.cipherTextTB.Location = new System.Drawing.Point(52, 89);
            this.cipherTextTB.Name = "cipherTextTB";
            this.cipherTextTB.Size = new System.Drawing.Size(548, 22);
            this.cipherTextTB.TabIndex = 8;
            // 
            // dec_choice
            // 
            this.dec_choice.AutoSize = true;
            this.dec_choice.Location = new System.Drawing.Point(52, 32);
            this.dec_choice.Name = "dec_choice";
            this.dec_choice.Size = new System.Drawing.Size(140, 20);
            this.dec_choice.TabIndex = 7;
            this.dec_choice.Text = "Cipher text from file";
            this.dec_choice.UseVisualStyleBackColor = true;
            this.dec_choice.CheckedChanged += new System.EventHandler(this.dec_choice_CheckedChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.ClientSize = new System.Drawing.Size(743, 394);
            this.Controls.Add(this.tabControl1);
            this.Name = "Form1";
            this.Text = "RSA GUI";
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
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox keyFormatCB;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button keyGenBtn;
        private System.Windows.Forms.TextBox keySizeTB;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox genKey_publicTB;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox genKey_privateTB;
        private System.Windows.Forms.Button encryptBtn;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox pub_enc;
        private System.Windows.Forms.Label plainTextLabel;
        private System.Windows.Forms.TextBox plainText;
        private System.Windows.Forms.CheckBox enc_choice;
        private System.Windows.Forms.Button decryptBtn;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox pri_dec;
        private System.Windows.Forms.Label cipherLabel;
        private System.Windows.Forms.TextBox cipherTextTB;
        private System.Windows.Forms.CheckBox dec_choice;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.TextBox enc_cipher;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox dec_rec;
    }
}


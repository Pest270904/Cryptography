namespace AES_GUI
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
            this.genKeyBTN = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.KG_keyTB = new System.Windows.Forms.TextBox();
            this.KG_ivTB = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.ENC_iv = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.ENC_key = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.encryptBtn = new System.Windows.Forms.Button();
            this.ENC_checkbox = new System.Windows.Forms.CheckBox();
            this.ENC_mode = new System.Windows.Forms.ComboBox();
            this.ENC_plain = new System.Windows.Forms.TextBox();
            this.plainLabel = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.ENC_cipher = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.DEC_rec = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.DEC_cipher = new System.Windows.Forms.TextBox();
            this.cipherLabel = new System.Windows.Forms.Label();
            this.DEC_mode = new System.Windows.Forms.ComboBox();
            this.DEC_checkbox = new System.Windows.Forms.CheckBox();
            this.DEC_iv = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.DEC_key = new System.Windows.Forms.TextBox();
            this.label11 = new System.Windows.Forms.Label();
            this.decryptBtn = new System.Windows.Forms.Button();
            this.aad_enc_label = new System.Windows.Forms.Label();
            this.ENC_aad = new System.Windows.Forms.TextBox();
            this.DEC_aad = new System.Windows.Forms.TextBox();
            this.aad_dec_label = new System.Windows.Forms.Label();
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
            this.tabControl1.Location = new System.Drawing.Point(22, 26);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(718, 339);
            this.tabControl1.TabIndex = 0;
            // 
            // tabPage1
            // 
            this.tabPage1.BackColor = System.Drawing.Color.Silver;
            this.tabPage1.Controls.Add(this.KG_ivTB);
            this.tabPage1.Controls.Add(this.label2);
            this.tabPage1.Controls.Add(this.KG_keyTB);
            this.tabPage1.Controls.Add(this.label1);
            this.tabPage1.Controls.Add(this.genKeyBTN);
            this.tabPage1.Location = new System.Drawing.Point(4, 25);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(710, 310);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "KeyGen";
            // 
            // tabPage2
            // 
            this.tabPage2.BackColor = System.Drawing.Color.Silver;
            this.tabPage2.Controls.Add(this.ENC_aad);
            this.tabPage2.Controls.Add(this.aad_enc_label);
            this.tabPage2.Controls.Add(this.ENC_cipher);
            this.tabPage2.Controls.Add(this.label6);
            this.tabPage2.Controls.Add(this.label5);
            this.tabPage2.Controls.Add(this.ENC_plain);
            this.tabPage2.Controls.Add(this.plainLabel);
            this.tabPage2.Controls.Add(this.ENC_mode);
            this.tabPage2.Controls.Add(this.ENC_checkbox);
            this.tabPage2.Controls.Add(this.ENC_iv);
            this.tabPage2.Controls.Add(this.label3);
            this.tabPage2.Controls.Add(this.ENC_key);
            this.tabPage2.Controls.Add(this.label4);
            this.tabPage2.Controls.Add(this.encryptBtn);
            this.tabPage2.Location = new System.Drawing.Point(4, 25);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(710, 310);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Encrypt";
            // 
            // tabPage3
            // 
            this.tabPage3.BackColor = System.Drawing.Color.Silver;
            this.tabPage3.Controls.Add(this.DEC_aad);
            this.tabPage3.Controls.Add(this.aad_dec_label);
            this.tabPage3.Controls.Add(this.DEC_rec);
            this.tabPage3.Controls.Add(this.label7);
            this.tabPage3.Controls.Add(this.label8);
            this.tabPage3.Controls.Add(this.DEC_cipher);
            this.tabPage3.Controls.Add(this.cipherLabel);
            this.tabPage3.Controls.Add(this.DEC_mode);
            this.tabPage3.Controls.Add(this.DEC_checkbox);
            this.tabPage3.Controls.Add(this.DEC_iv);
            this.tabPage3.Controls.Add(this.label10);
            this.tabPage3.Controls.Add(this.DEC_key);
            this.tabPage3.Controls.Add(this.label11);
            this.tabPage3.Controls.Add(this.decryptBtn);
            this.tabPage3.Location = new System.Drawing.Point(4, 25);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage3.Size = new System.Drawing.Size(710, 310);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "Decrypt";
            // 
            // genKeyBTN
            // 
            this.genKeyBTN.BackColor = System.Drawing.Color.RosyBrown;
            this.genKeyBTN.Location = new System.Drawing.Point(278, 188);
            this.genKeyBTN.Name = "genKeyBTN";
            this.genKeyBTN.Size = new System.Drawing.Size(153, 48);
            this.genKeyBTN.TabIndex = 0;
            this.genKeyBTN.Text = "Generate Key - IV";
            this.genKeyBTN.UseVisualStyleBackColor = false;
            this.genKeyBTN.Click += new System.EventHandler(this.genKeyBTN_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(125, 53);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(90, 16);
            this.label1.TabIndex = 1;
            this.label1.Text = "Key file name:";
            // 
            // KG_keyTB
            // 
            this.KG_keyTB.Location = new System.Drawing.Point(128, 72);
            this.KG_keyTB.Name = "KG_keyTB";
            this.KG_keyTB.Size = new System.Drawing.Size(143, 22);
            this.KG_keyTB.TabIndex = 2;
            // 
            // KG_ivTB
            // 
            this.KG_ivTB.Location = new System.Drawing.Point(417, 72);
            this.KG_ivTB.Name = "KG_ivTB";
            this.KG_ivTB.Size = new System.Drawing.Size(143, 22);
            this.KG_ivTB.TabIndex = 4;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(414, 53);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(79, 16);
            this.label2.TabIndex = 3;
            this.label2.Text = "IV file name:";
            // 
            // ENC_iv
            // 
            this.ENC_iv.Location = new System.Drawing.Point(115, 161);
            this.ENC_iv.Name = "ENC_iv";
            this.ENC_iv.Size = new System.Drawing.Size(190, 22);
            this.ENC_iv.TabIndex = 9;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(112, 142);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(79, 16);
            this.label3.TabIndex = 8;
            this.label3.Text = "IV file name:";
            // 
            // ENC_key
            // 
            this.ENC_key.Location = new System.Drawing.Point(115, 101);
            this.ENC_key.Name = "ENC_key";
            this.ENC_key.Size = new System.Drawing.Size(190, 22);
            this.ENC_key.TabIndex = 7;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(112, 77);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(90, 16);
            this.label4.TabIndex = 6;
            this.label4.Text = "Key file name:";
            // 
            // encryptBtn
            // 
            this.encryptBtn.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.encryptBtn.Location = new System.Drawing.Point(415, 217);
            this.encryptBtn.Name = "encryptBtn";
            this.encryptBtn.Size = new System.Drawing.Size(153, 48);
            this.encryptBtn.TabIndex = 5;
            this.encryptBtn.Text = "Encrypt";
            this.encryptBtn.UseVisualStyleBackColor = false;
            this.encryptBtn.Click += new System.EventHandler(this.encryptBtn_Click);
            // 
            // ENC_checkbox
            // 
            this.ENC_checkbox.AutoSize = true;
            this.ENC_checkbox.Location = new System.Drawing.Point(115, 28);
            this.ENC_checkbox.Name = "ENC_checkbox";
            this.ENC_checkbox.Size = new System.Drawing.Size(169, 20);
            this.ENC_checkbox.TabIndex = 10;
            this.ENC_checkbox.Text = "Plaintext from keyboard";
            this.ENC_checkbox.UseVisualStyleBackColor = true;
            this.ENC_checkbox.CheckedChanged += new System.EventHandler(this.ENC_checkbox_CheckedChanged);
            // 
            // ENC_mode
            // 
            this.ENC_mode.FormattingEnabled = true;
            this.ENC_mode.Items.AddRange(new object[] {
            "ECB",
            "CBC",
            "OFB",
            "CFB",
            "CTR",
            "XTS",
            "CCM",
            "GCM"});
            this.ENC_mode.Location = new System.Drawing.Point(115, 230);
            this.ENC_mode.Name = "ENC_mode";
            this.ENC_mode.Size = new System.Drawing.Size(190, 24);
            this.ENC_mode.TabIndex = 11;
            this.ENC_mode.TextChanged += new System.EventHandler(this.ENC_mode_TextChanged);
            // 
            // ENC_plain
            // 
            this.ENC_plain.Location = new System.Drawing.Point(378, 101);
            this.ENC_plain.Name = "ENC_plain";
            this.ENC_plain.Size = new System.Drawing.Size(190, 22);
            this.ENC_plain.TabIndex = 13;
            // 
            // plainLabel
            // 
            this.plainLabel.AutoSize = true;
            this.plainLabel.Location = new System.Drawing.Point(375, 77);
            this.plainLabel.Name = "plainLabel";
            this.plainLabel.Size = new System.Drawing.Size(117, 16);
            this.plainLabel.TabIndex = 12;
            this.plainLabel.Text = "Plaintext file name:";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(112, 211);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(45, 16);
            this.label5.TabIndex = 14;
            this.label5.Text = "Mode:";
            // 
            // ENC_cipher
            // 
            this.ENC_cipher.Location = new System.Drawing.Point(378, 161);
            this.ENC_cipher.Name = "ENC_cipher";
            this.ENC_cipher.Size = new System.Drawing.Size(190, 22);
            this.ENC_cipher.TabIndex = 16;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(375, 137);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(126, 16);
            this.label6.TabIndex = 15;
            this.label6.Text = "Ciphertext file name:";
            // 
            // DEC_rec
            // 
            this.DEC_rec.Location = new System.Drawing.Point(393, 157);
            this.DEC_rec.Name = "DEC_rec";
            this.DEC_rec.Size = new System.Drawing.Size(190, 22);
            this.DEC_rec.TabIndex = 28;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(390, 133);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(135, 16);
            this.label7.TabIndex = 27;
            this.label7.Text = "Recovered file name:";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(115, 207);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(45, 16);
            this.label8.TabIndex = 26;
            this.label8.Text = "Mode:";
            // 
            // DEC_cipher
            // 
            this.DEC_cipher.Location = new System.Drawing.Point(393, 97);
            this.DEC_cipher.Name = "DEC_cipher";
            this.DEC_cipher.Size = new System.Drawing.Size(190, 22);
            this.DEC_cipher.TabIndex = 25;
            // 
            // cipherLabel
            // 
            this.cipherLabel.AutoSize = true;
            this.cipherLabel.Location = new System.Drawing.Point(390, 73);
            this.cipherLabel.Name = "cipherLabel";
            this.cipherLabel.Size = new System.Drawing.Size(126, 16);
            this.cipherLabel.TabIndex = 24;
            this.cipherLabel.Text = "Ciphertext file name:";
            // 
            // DEC_mode
            // 
            this.DEC_mode.FormattingEnabled = true;
            this.DEC_mode.Items.AddRange(new object[] {
            "ECB",
            "CBC",
            "OFB",
            "CFB",
            "CTR",
            "XTS",
            "CCM",
            "GCM"});
            this.DEC_mode.Location = new System.Drawing.Point(118, 226);
            this.DEC_mode.Name = "DEC_mode";
            this.DEC_mode.Size = new System.Drawing.Size(190, 24);
            this.DEC_mode.TabIndex = 23;
            this.DEC_mode.TextChanged += new System.EventHandler(this.DEC_mode_TextChanged);
            // 
            // DEC_checkbox
            // 
            this.DEC_checkbox.AutoSize = true;
            this.DEC_checkbox.Location = new System.Drawing.Point(118, 24);
            this.DEC_checkbox.Name = "DEC_checkbox";
            this.DEC_checkbox.Size = new System.Drawing.Size(178, 20);
            this.DEC_checkbox.TabIndex = 22;
            this.DEC_checkbox.Text = "Ciphertext from keyboard";
            this.DEC_checkbox.UseVisualStyleBackColor = true;
            this.DEC_checkbox.CheckedChanged += new System.EventHandler(this.DEC_checkbox_CheckedChanged);
            // 
            // DEC_iv
            // 
            this.DEC_iv.Location = new System.Drawing.Point(118, 157);
            this.DEC_iv.Name = "DEC_iv";
            this.DEC_iv.Size = new System.Drawing.Size(190, 22);
            this.DEC_iv.TabIndex = 21;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(115, 138);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(79, 16);
            this.label10.TabIndex = 20;
            this.label10.Text = "IV file name:";
            // 
            // DEC_key
            // 
            this.DEC_key.Location = new System.Drawing.Point(118, 97);
            this.DEC_key.Name = "DEC_key";
            this.DEC_key.Size = new System.Drawing.Size(190, 22);
            this.DEC_key.TabIndex = 19;
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(115, 73);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(90, 16);
            this.label11.TabIndex = 18;
            this.label11.Text = "Key file name:";
            // 
            // decryptBtn
            // 
            this.decryptBtn.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(128)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
            this.decryptBtn.Location = new System.Drawing.Point(414, 213);
            this.decryptBtn.Name = "decryptBtn";
            this.decryptBtn.Size = new System.Drawing.Size(153, 48);
            this.decryptBtn.TabIndex = 17;
            this.decryptBtn.Text = "Decrypt";
            this.decryptBtn.UseVisualStyleBackColor = false;
            this.decryptBtn.Click += new System.EventHandler(this.decryptBtn_Click);
            // 
            // aad_enc_label
            // 
            this.aad_enc_label.AutoSize = true;
            this.aad_enc_label.Location = new System.Drawing.Point(375, 16);
            this.aad_enc_label.Name = "aad_enc_label";
            this.aad_enc_label.Size = new System.Drawing.Size(38, 16);
            this.aad_enc_label.TabIndex = 18;
            this.aad_enc_label.Text = "AAD:";
            this.aad_enc_label.Visible = false;
            // 
            // ENC_aad
            // 
            this.ENC_aad.Location = new System.Drawing.Point(378, 37);
            this.ENC_aad.Name = "ENC_aad";
            this.ENC_aad.Size = new System.Drawing.Size(190, 22);
            this.ENC_aad.TabIndex = 19;
            this.ENC_aad.Visible = false;
            // 
            // DEC_aad
            // 
            this.DEC_aad.Location = new System.Drawing.Point(393, 34);
            this.DEC_aad.Name = "DEC_aad";
            this.DEC_aad.Size = new System.Drawing.Size(190, 22);
            this.DEC_aad.TabIndex = 30;
            this.DEC_aad.Visible = false;
            // 
            // aad_dec_label
            // 
            this.aad_dec_label.AutoSize = true;
            this.aad_dec_label.Location = new System.Drawing.Point(390, 13);
            this.aad_dec_label.Name = "aad_dec_label";
            this.aad_dec_label.Size = new System.Drawing.Size(38, 16);
            this.aad_dec_label.TabIndex = 29;
            this.aad_dec_label.Text = "AAD:";
            this.aad_dec_label.Visible = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.ClientSize = new System.Drawing.Size(766, 398);
            this.Controls.Add(this.tabControl1);
            this.Name = "Form1";
            this.Text = "AES";
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
        private System.Windows.Forms.TextBox KG_ivTB;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox KG_keyTB;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button genKeyBTN;
        private System.Windows.Forms.TextBox ENC_plain;
        private System.Windows.Forms.Label plainLabel;
        private System.Windows.Forms.ComboBox ENC_mode;
        private System.Windows.Forms.CheckBox ENC_checkbox;
        private System.Windows.Forms.TextBox ENC_iv;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox ENC_key;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button encryptBtn;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.TextBox ENC_cipher;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox DEC_rec;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.TextBox DEC_cipher;
        private System.Windows.Forms.Label cipherLabel;
        private System.Windows.Forms.ComboBox DEC_mode;
        private System.Windows.Forms.CheckBox DEC_checkbox;
        private System.Windows.Forms.TextBox DEC_iv;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.TextBox DEC_key;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Button decryptBtn;
        private System.Windows.Forms.TextBox ENC_aad;
        private System.Windows.Forms.Label aad_enc_label;
        private System.Windows.Forms.TextBox DEC_aad;
        private System.Windows.Forms.Label aad_dec_label;
    }
}


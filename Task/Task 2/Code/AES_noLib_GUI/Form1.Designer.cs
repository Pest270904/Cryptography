namespace AES_noLib_GUI
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
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.encryptBtn = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.enc_key = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.enc_iv = new System.Windows.Forms.TextBox();
            this.enc_checkbox = new System.Windows.Forms.CheckBox();
            this.plainLabel = new System.Windows.Forms.Label();
            this.enc_plain = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.enc_cipher = new System.Windows.Forms.TextBox();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.dec_recovered = new System.Windows.Forms.TextBox();
            this.dec_cipher = new System.Windows.Forms.TextBox();
            this.dec_iv = new System.Windows.Forms.TextBox();
            this.dec_key = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.dec_label = new System.Windows.Forms.Label();
            this.dec_checkbox = new System.Windows.Forms.CheckBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.decryptBtn = new System.Windows.Forms.Button();
            this.tabPage3.SuspendLayout();
            this.tabPage2.SuspendLayout();
            this.tabControl1.SuspendLayout();
            this.SuspendLayout();
            // 
            // tabPage3
            // 
            this.tabPage3.BackColor = System.Drawing.Color.Silver;
            this.tabPage3.Controls.Add(this.dec_recovered);
            this.tabPage3.Controls.Add(this.dec_cipher);
            this.tabPage3.Controls.Add(this.dec_iv);
            this.tabPage3.Controls.Add(this.dec_key);
            this.tabPage3.Controls.Add(this.label1);
            this.tabPage3.Controls.Add(this.dec_label);
            this.tabPage3.Controls.Add(this.dec_checkbox);
            this.tabPage3.Controls.Add(this.label5);
            this.tabPage3.Controls.Add(this.label7);
            this.tabPage3.Controls.Add(this.decryptBtn);
            this.tabPage3.Location = new System.Drawing.Point(4, 25);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage3.Size = new System.Drawing.Size(801, 387);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "Decrypt";
            // 
            // tabPage2
            // 
            this.tabPage2.BackColor = System.Drawing.Color.Silver;
            this.tabPage2.Controls.Add(this.enc_cipher);
            this.tabPage2.Controls.Add(this.enc_plain);
            this.tabPage2.Controls.Add(this.enc_iv);
            this.tabPage2.Controls.Add(this.enc_key);
            this.tabPage2.Controls.Add(this.label6);
            this.tabPage2.Controls.Add(this.plainLabel);
            this.tabPage2.Controls.Add(this.enc_checkbox);
            this.tabPage2.Controls.Add(this.label3);
            this.tabPage2.Controls.Add(this.label4);
            this.tabPage2.Controls.Add(this.encryptBtn);
            this.tabPage2.Location = new System.Drawing.Point(4, 25);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(801, 387);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Encrypt";
            // 
            // encryptBtn
            // 
            this.encryptBtn.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.encryptBtn.Location = new System.Drawing.Point(543, 296);
            this.encryptBtn.Name = "encryptBtn";
            this.encryptBtn.Size = new System.Drawing.Size(153, 48);
            this.encryptBtn.TabIndex = 5;
            this.encryptBtn.Text = "Encrypt";
            this.encryptBtn.UseVisualStyleBackColor = false;
            this.encryptBtn.Click += new System.EventHandler(this.encryptBtn_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(80, 29);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(143, 16);
            this.label4.TabIndex = 6;
            this.label4.Text = "Key (128, 192, 256 bits):";
            // 
            // enc_key
            // 
            this.enc_key.Location = new System.Drawing.Point(83, 53);
            this.enc_key.Name = "enc_key";
            this.enc_key.Size = new System.Drawing.Size(613, 22);
            this.enc_key.TabIndex = 7;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(80, 91);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(103, 16);
            this.label3.TabIndex = 8;
            this.label3.Text = "Initial vector (IV):";
            // 
            // enc_iv
            // 
            this.enc_iv.Location = new System.Drawing.Point(83, 110);
            this.enc_iv.Name = "enc_iv";
            this.enc_iv.Size = new System.Drawing.Size(613, 22);
            this.enc_iv.TabIndex = 9;
            // 
            // enc_checkbox
            // 
            this.enc_checkbox.AutoSize = true;
            this.enc_checkbox.Location = new System.Drawing.Point(83, 200);
            this.enc_checkbox.Name = "enc_checkbox";
            this.enc_checkbox.Size = new System.Drawing.Size(169, 20);
            this.enc_checkbox.TabIndex = 10;
            this.enc_checkbox.Text = "Plaintext from keyboard";
            this.enc_checkbox.UseVisualStyleBackColor = true;
            this.enc_checkbox.CheckedChanged += new System.EventHandler(this.ENC_checkbox_CheckedChanged);
            // 
            // plainLabel
            // 
            this.plainLabel.AutoSize = true;
            this.plainLabel.Location = new System.Drawing.Point(280, 159);
            this.plainLabel.Name = "plainLabel";
            this.plainLabel.Size = new System.Drawing.Size(117, 16);
            this.plainLabel.TabIndex = 12;
            this.plainLabel.Text = "Plaintext file name:";
            // 
            // enc_plain
            // 
            this.enc_plain.Location = new System.Drawing.Point(283, 178);
            this.enc_plain.Multiline = true;
            this.enc_plain.Name = "enc_plain";
            this.enc_plain.Size = new System.Drawing.Size(413, 88);
            this.enc_plain.TabIndex = 13;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(280, 285);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(126, 16);
            this.label6.TabIndex = 15;
            this.label6.Text = "Ciphertext file name:";
            // 
            // enc_cipher
            // 
            this.enc_cipher.Location = new System.Drawing.Point(283, 309);
            this.enc_cipher.Name = "enc_cipher";
            this.enc_cipher.Size = new System.Drawing.Size(190, 22);
            this.enc_cipher.TabIndex = 16;
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Controls.Add(this.tabPage3);
            this.tabControl1.Location = new System.Drawing.Point(22, 26);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(809, 416);
            this.tabControl1.TabIndex = 0;
            // 
            // dec_recovered
            // 
            this.dec_recovered.Location = new System.Drawing.Point(295, 316);
            this.dec_recovered.Name = "dec_recovered";
            this.dec_recovered.Size = new System.Drawing.Size(190, 22);
            this.dec_recovered.TabIndex = 26;
            // 
            // dec_cipher
            // 
            this.dec_cipher.Location = new System.Drawing.Point(295, 185);
            this.dec_cipher.Multiline = true;
            this.dec_cipher.Name = "dec_cipher";
            this.dec_cipher.Size = new System.Drawing.Size(413, 88);
            this.dec_cipher.TabIndex = 24;
            // 
            // dec_iv
            // 
            this.dec_iv.Location = new System.Drawing.Point(95, 117);
            this.dec_iv.Name = "dec_iv";
            this.dec_iv.Size = new System.Drawing.Size(613, 22);
            this.dec_iv.TabIndex = 21;
            // 
            // dec_key
            // 
            this.dec_key.Location = new System.Drawing.Point(95, 60);
            this.dec_key.Name = "dec_key";
            this.dec_key.Size = new System.Drawing.Size(613, 22);
            this.dec_key.TabIndex = 19;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(292, 292);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(135, 16);
            this.label1.TabIndex = 25;
            this.label1.Text = "Recovered file name:";
            // 
            // dec_label
            // 
            this.dec_label.AutoSize = true;
            this.dec_label.Location = new System.Drawing.Point(292, 166);
            this.dec_label.Name = "dec_label";
            this.dec_label.Size = new System.Drawing.Size(126, 16);
            this.dec_label.TabIndex = 23;
            this.dec_label.Text = "Ciphertext file name:";
            // 
            // dec_checkbox
            // 
            this.dec_checkbox.AutoSize = true;
            this.dec_checkbox.Location = new System.Drawing.Point(95, 207);
            this.dec_checkbox.Name = "dec_checkbox";
            this.dec_checkbox.Size = new System.Drawing.Size(178, 20);
            this.dec_checkbox.TabIndex = 22;
            this.dec_checkbox.Text = "Ciphertext from keyboard";
            this.dec_checkbox.UseVisualStyleBackColor = true;
            this.dec_checkbox.CheckedChanged += new System.EventHandler(this.DEC_checkbox_CheckedChanged);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(92, 98);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(103, 16);
            this.label5.TabIndex = 20;
            this.label5.Text = "Initial vector (IV):";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(92, 36);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(143, 16);
            this.label7.TabIndex = 18;
            this.label7.Text = "Key (128, 192, 256 bits):";
            // 
            // decryptBtn
            // 
            this.decryptBtn.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
            this.decryptBtn.Location = new System.Drawing.Point(555, 303);
            this.decryptBtn.Name = "decryptBtn";
            this.decryptBtn.Size = new System.Drawing.Size(153, 48);
            this.decryptBtn.TabIndex = 17;
            this.decryptBtn.Text = "Decrypt";
            this.decryptBtn.UseVisualStyleBackColor = false;
            this.decryptBtn.Click += new System.EventHandler(this.decryptBtn_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.ClientSize = new System.Drawing.Size(863, 480);
            this.Controls.Add(this.tabControl1);
            this.Name = "Form1";
            this.Text = "AES";
            this.tabPage3.ResumeLayout(false);
            this.tabPage3.PerformLayout();
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            this.tabControl1.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.TextBox enc_cipher;
        private System.Windows.Forms.TextBox enc_plain;
        private System.Windows.Forms.TextBox enc_iv;
        private System.Windows.Forms.TextBox enc_key;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label plainLabel;
        private System.Windows.Forms.CheckBox enc_checkbox;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button encryptBtn;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TextBox dec_recovered;
        private System.Windows.Forms.TextBox dec_cipher;
        private System.Windows.Forms.TextBox dec_iv;
        private System.Windows.Forms.TextBox dec_key;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label dec_label;
        private System.Windows.Forms.CheckBox dec_checkbox;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Button decryptBtn;
    }
}


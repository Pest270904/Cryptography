namespace DS
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
            this.label2 = new System.Windows.Forms.Label();
            this.kg_pubTB = new System.Windows.Forms.TextBox();
            this.keygenBtn = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.kg_priTB = new System.Windows.Forms.TextBox();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.label5 = new System.Windows.Forms.Label();
            this.sign_priTB = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.sign_sigTB = new System.Windows.Forms.TextBox();
            this.signBtn = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.sign_fileTB = new System.Windows.Forms.TextBox();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.label6 = new System.Windows.Forms.Label();
            this.verify_pubTB = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.verify_sigTB = new System.Windows.Forms.TextBox();
            this.verifyBtn = new System.Windows.Forms.Button();
            this.label8 = new System.Windows.Forms.Label();
            this.verify_fileTB = new System.Windows.Forms.TextBox();
            this.status = new System.Windows.Forms.Label();
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
            this.tabControl1.Location = new System.Drawing.Point(42, 26);
            this.tabControl1.Margin = new System.Windows.Forms.Padding(4);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(721, 356);
            this.tabControl1.TabIndex = 0;
            // 
            // tabPage1
            // 
            this.tabPage1.BackColor = System.Drawing.Color.Silver;
            this.tabPage1.Controls.Add(this.label2);
            this.tabPage1.Controls.Add(this.kg_pubTB);
            this.tabPage1.Controls.Add(this.keygenBtn);
            this.tabPage1.Controls.Add(this.label1);
            this.tabPage1.Controls.Add(this.kg_priTB);
            this.tabPage1.Location = new System.Drawing.Point(4, 29);
            this.tabPage1.Margin = new System.Windows.Forms.Padding(4);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(4);
            this.tabPage1.Size = new System.Drawing.Size(713, 323);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Keygen";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(423, 52);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(163, 20);
            this.label2.TabIndex = 4;
            this.label2.Text = "Public key file name:";
            // 
            // kg_pubTB
            // 
            this.kg_pubTB.Location = new System.Drawing.Point(399, 89);
            this.kg_pubTB.Margin = new System.Windows.Forms.Padding(4);
            this.kg_pubTB.Name = "kg_pubTB";
            this.kg_pubTB.Size = new System.Drawing.Size(232, 26);
            this.kg_pubTB.TabIndex = 3;
            // 
            // keygenBtn
            // 
            this.keygenBtn.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.keygenBtn.Location = new System.Drawing.Point(257, 190);
            this.keygenBtn.Margin = new System.Windows.Forms.Padding(4);
            this.keygenBtn.Name = "keygenBtn";
            this.keygenBtn.Size = new System.Drawing.Size(182, 66);
            this.keygenBtn.TabIndex = 2;
            this.keygenBtn.Text = "Generate key";
            this.keygenBtn.UseVisualStyleBackColor = false;
            this.keygenBtn.Click += new System.EventHandler(this.keygenBtn_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(106, 52);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(169, 20);
            this.label1.TabIndex = 1;
            this.label1.Text = "Private key file name:";
            // 
            // kg_priTB
            // 
            this.kg_priTB.Location = new System.Drawing.Point(80, 89);
            this.kg_priTB.Margin = new System.Windows.Forms.Padding(4);
            this.kg_priTB.Name = "kg_priTB";
            this.kg_priTB.Size = new System.Drawing.Size(232, 26);
            this.kg_priTB.TabIndex = 0;
            // 
            // tabPage2
            // 
            this.tabPage2.BackColor = System.Drawing.SystemColors.AppWorkspace;
            this.tabPage2.Controls.Add(this.label5);
            this.tabPage2.Controls.Add(this.sign_priTB);
            this.tabPage2.Controls.Add(this.label3);
            this.tabPage2.Controls.Add(this.sign_sigTB);
            this.tabPage2.Controls.Add(this.signBtn);
            this.tabPage2.Controls.Add(this.label4);
            this.tabPage2.Controls.Add(this.sign_fileTB);
            this.tabPage2.Location = new System.Drawing.Point(4, 29);
            this.tabPage2.Margin = new System.Windows.Forms.Padding(4);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(4);
            this.tabPage2.Size = new System.Drawing.Size(713, 323);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Sign";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(410, 51);
            this.label5.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(169, 20);
            this.label5.TabIndex = 11;
            this.label5.Text = "Private key file name:";
            // 
            // sign_priTB
            // 
            this.sign_priTB.Location = new System.Drawing.Point(413, 87);
            this.sign_priTB.Margin = new System.Windows.Forms.Padding(4);
            this.sign_priTB.Name = "sign_priTB";
            this.sign_priTB.Size = new System.Drawing.Size(223, 26);
            this.sign_priTB.TabIndex = 10;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(100, 176);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(158, 20);
            this.label3.TabIndex = 9;
            this.label3.Text = "Signature file name:";
            // 
            // sign_sigTB
            // 
            this.sign_sigTB.Location = new System.Drawing.Point(103, 212);
            this.sign_sigTB.Margin = new System.Windows.Forms.Padding(4);
            this.sign_sigTB.Name = "sign_sigTB";
            this.sign_sigTB.Size = new System.Drawing.Size(223, 26);
            this.sign_sigTB.TabIndex = 8;
            // 
            // signBtn
            // 
            this.signBtn.BackColor = System.Drawing.Color.Salmon;
            this.signBtn.Location = new System.Drawing.Point(434, 192);
            this.signBtn.Margin = new System.Windows.Forms.Padding(4);
            this.signBtn.Name = "signBtn";
            this.signBtn.Size = new System.Drawing.Size(182, 66);
            this.signBtn.TabIndex = 7;
            this.signBtn.Text = "Sign";
            this.signBtn.UseVisualStyleBackColor = false;
            this.signBtn.Click += new System.EventHandler(this.signBtn_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(95, 51);
            this.label4.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(136, 20);
            this.label4.TabIndex = 6;
            this.label4.Text = "File want to sign:";
            // 
            // sign_fileTB
            // 
            this.sign_fileTB.Location = new System.Drawing.Point(99, 87);
            this.sign_fileTB.Margin = new System.Windows.Forms.Padding(4);
            this.sign_fileTB.Name = "sign_fileTB";
            this.sign_fileTB.Size = new System.Drawing.Size(223, 26);
            this.sign_fileTB.TabIndex = 5;
            // 
            // tabPage3
            // 
            this.tabPage3.BackColor = System.Drawing.Color.Silver;
            this.tabPage3.Controls.Add(this.status);
            this.tabPage3.Controls.Add(this.label6);
            this.tabPage3.Controls.Add(this.verify_pubTB);
            this.tabPage3.Controls.Add(this.label7);
            this.tabPage3.Controls.Add(this.verify_sigTB);
            this.tabPage3.Controls.Add(this.verifyBtn);
            this.tabPage3.Controls.Add(this.label8);
            this.tabPage3.Controls.Add(this.verify_fileTB);
            this.tabPage3.Location = new System.Drawing.Point(4, 29);
            this.tabPage3.Margin = new System.Windows.Forms.Padding(4);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Padding = new System.Windows.Forms.Padding(4);
            this.tabPage3.Size = new System.Drawing.Size(713, 323);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "Verify";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(414, 54);
            this.label6.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(158, 20);
            this.label6.TabIndex = 18;
            this.label6.Text = "Public key file name";
            // 
            // verify_pubTB
            // 
            this.verify_pubTB.Location = new System.Drawing.Point(417, 90);
            this.verify_pubTB.Margin = new System.Windows.Forms.Padding(4);
            this.verify_pubTB.Name = "verify_pubTB";
            this.verify_pubTB.Size = new System.Drawing.Size(225, 26);
            this.verify_pubTB.TabIndex = 17;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(104, 179);
            this.label7.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(158, 20);
            this.label7.TabIndex = 16;
            this.label7.Text = "Signature file name:";
            // 
            // verify_sigTB
            // 
            this.verify_sigTB.Location = new System.Drawing.Point(107, 215);
            this.verify_sigTB.Margin = new System.Windows.Forms.Padding(4);
            this.verify_sigTB.Name = "verify_sigTB";
            this.verify_sigTB.Size = new System.Drawing.Size(225, 26);
            this.verify_sigTB.TabIndex = 15;
            // 
            // verifyBtn
            // 
            this.verifyBtn.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(255)))));
            this.verifyBtn.Location = new System.Drawing.Point(435, 175);
            this.verifyBtn.Margin = new System.Windows.Forms.Padding(4);
            this.verifyBtn.Name = "verifyBtn";
            this.verifyBtn.Size = new System.Drawing.Size(182, 66);
            this.verifyBtn.TabIndex = 14;
            this.verifyBtn.Text = "Verify";
            this.verifyBtn.UseVisualStyleBackColor = false;
            this.verifyBtn.Click += new System.EventHandler(this.verifyBtn_Click);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(99, 54);
            this.label8.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(136, 20);
            this.label8.TabIndex = 13;
            this.label8.Text = "File want to sign:";
            // 
            // verify_fileTB
            // 
            this.verify_fileTB.Location = new System.Drawing.Point(103, 90);
            this.verify_fileTB.Margin = new System.Windows.Forms.Padding(4);
            this.verify_fileTB.Name = "verify_fileTB";
            this.verify_fileTB.Size = new System.Drawing.Size(225, 26);
            this.verify_fileTB.TabIndex = 12;
            // 
            // status
            // 
            this.status.AutoSize = true;
            this.status.Location = new System.Drawing.Point(431, 257);
            this.status.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.status.Name = "status";
            this.status.Size = new System.Drawing.Size(97, 20);
            this.status.TabIndex = 19;
            this.status.Text = "Click to see";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.ClientSize = new System.Drawing.Size(825, 434);
            this.Controls.Add(this.tabControl1);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "Form1";
            this.Text = "22521076 Digital-Signature GUI";
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
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox kg_pubTB;
        private System.Windows.Forms.Button keygenBtn;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox kg_priTB;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox sign_priTB;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox sign_sigTB;
        private System.Windows.Forms.Button signBtn;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox sign_fileTB;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox verify_pubTB;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox verify_sigTB;
        private System.Windows.Forms.Button verifyBtn;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.TextBox verify_fileTB;
        private System.Windows.Forms.Label status;
    }
}


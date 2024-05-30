namespace hash_GUI
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
            this.algoCBB = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.inputFileNameTB = new System.Windows.Forms.TextBox();
            this.outputFileNameTB = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.executeBtn = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // algoCBB
            // 
            this.algoCBB.FormattingEnabled = true;
            this.algoCBB.Items.AddRange(new object[] {
            "MD5",
            "SHA1",
            "SHA224",
            "SHA256",
            "SHA384",
            "SHA512",
            "SHA512-224",
            "SHA512-256",
            "SHA3-224",
            "SHA3-256",
            "SHA3-384",
            "SHA3-512",
            "SHAKE128",
            "SHAKE256"});
            this.algoCBB.Location = new System.Drawing.Point(59, 54);
            this.algoCBB.Name = "algoCBB";
            this.algoCBB.Size = new System.Drawing.Size(169, 24);
            this.algoCBB.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(56, 35);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(66, 16);
            this.label1.TabIndex = 1;
            this.label1.Text = "Algorithm:";
            // 
            // inputFileNameTB
            // 
            this.inputFileNameTB.Location = new System.Drawing.Point(291, 54);
            this.inputFileNameTB.Name = "inputFileNameTB";
            this.inputFileNameTB.Size = new System.Drawing.Size(168, 22);
            this.inputFileNameTB.TabIndex = 2;
            // 
            // outputFileNameTB
            // 
            this.outputFileNameTB.Location = new System.Drawing.Point(517, 54);
            this.outputFileNameTB.Name = "outputFileNameTB";
            this.outputFileNameTB.Size = new System.Drawing.Size(168, 22);
            this.outputFileNameTB.TabIndex = 3;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(288, 35);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(95, 16);
            this.label2.TabIndex = 4;
            this.label2.Text = "Input file name:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(514, 35);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(105, 16);
            this.label3.TabIndex = 5;
            this.label3.Text = "Output file name:";
            // 
            // executeBtn
            // 
            this.executeBtn.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.executeBtn.Location = new System.Drawing.Point(306, 130);
            this.executeBtn.Name = "executeBtn";
            this.executeBtn.Size = new System.Drawing.Size(133, 48);
            this.executeBtn.TabIndex = 6;
            this.executeBtn.Text = "Execute";
            this.executeBtn.UseVisualStyleBackColor = false;
            this.executeBtn.Click += new System.EventHandler(this.executeBtn_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.ClientSize = new System.Drawing.Size(785, 246);
            this.Controls.Add(this.executeBtn);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.outputFileNameTB);
            this.Controls.Add(this.inputFileNameTB);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.algoCBB);
            this.Name = "Form1";
            this.Text = "Hash GUI";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox algoCBB;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox inputFileNameTB;
        private System.Windows.Forms.TextBox outputFileNameTB;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button executeBtn;
    }
}


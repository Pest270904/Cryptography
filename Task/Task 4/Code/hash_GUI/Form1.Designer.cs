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
            this.plainLabel = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.executeBtn = new System.Windows.Forms.Button();
            this.lengthLabel = new System.Windows.Forms.Label();
            this.lengthTB = new System.Windows.Forms.TextBox();
            this.checkBox1 = new System.Windows.Forms.CheckBox();
            this.SuspendLayout();
            // 
            // algoCBB
            // 
            this.algoCBB.FormattingEnabled = true;
            this.algoCBB.Items.AddRange(new object[] {
            "SHA224",
            "SHA256",
            "SHA384",
            "SHA512",
            "SHA3-224",
            "SHA3-256",
            "SHA3-384",
            "SHA3-512",
            "SHAKE128",
            "SHAKE256"});
            this.algoCBB.Location = new System.Drawing.Point(68, 112);
            this.algoCBB.Name = "algoCBB";
            this.algoCBB.Size = new System.Drawing.Size(169, 24);
            this.algoCBB.TabIndex = 0;
            this.algoCBB.TextChanged += new System.EventHandler(this.algoCBB_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(65, 93);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(66, 16);
            this.label1.TabIndex = 1;
            this.label1.Text = "Algorithm:";
            // 
            // inputFileNameTB
            // 
            this.inputFileNameTB.Location = new System.Drawing.Point(300, 112);
            this.inputFileNameTB.Name = "inputFileNameTB";
            this.inputFileNameTB.Size = new System.Drawing.Size(168, 22);
            this.inputFileNameTB.TabIndex = 2;
            // 
            // outputFileNameTB
            // 
            this.outputFileNameTB.Location = new System.Drawing.Point(526, 112);
            this.outputFileNameTB.Name = "outputFileNameTB";
            this.outputFileNameTB.Size = new System.Drawing.Size(168, 22);
            this.outputFileNameTB.TabIndex = 3;
            // 
            // plainLabel
            // 
            this.plainLabel.AutoSize = true;
            this.plainLabel.Location = new System.Drawing.Point(297, 93);
            this.plainLabel.Name = "plainLabel";
            this.plainLabel.Size = new System.Drawing.Size(120, 16);
            this.plainLabel.TabIndex = 4;
            this.plainLabel.Text = "Plain text file name:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(523, 93);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(105, 16);
            this.label3.TabIndex = 5;
            this.label3.Text = "Output file name:";
            // 
            // executeBtn
            // 
            this.executeBtn.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.executeBtn.Location = new System.Drawing.Point(320, 181);
            this.executeBtn.Name = "executeBtn";
            this.executeBtn.Size = new System.Drawing.Size(133, 48);
            this.executeBtn.TabIndex = 6;
            this.executeBtn.Text = "Execute";
            this.executeBtn.UseVisualStyleBackColor = false;
            this.executeBtn.Click += new System.EventHandler(this.executeBtn_Click);
            // 
            // lengthLabel
            // 
            this.lengthLabel.AutoSize = true;
            this.lengthLabel.Location = new System.Drawing.Point(65, 188);
            this.lengthLabel.Name = "lengthLabel";
            this.lengthLabel.Size = new System.Drawing.Size(106, 16);
            this.lengthLabel.TabIndex = 8;
            this.lengthLabel.Text = "Length of Digest:";
            this.lengthLabel.Visible = false;
            // 
            // lengthTB
            // 
            this.lengthTB.Location = new System.Drawing.Point(68, 207);
            this.lengthTB.Name = "lengthTB";
            this.lengthTB.Size = new System.Drawing.Size(168, 22);
            this.lengthTB.TabIndex = 7;
            this.lengthTB.Visible = false;
            // 
            // checkBox1
            // 
            this.checkBox1.AutoSize = true;
            this.checkBox1.Location = new System.Drawing.Point(68, 25);
            this.checkBox1.Name = "checkBox1";
            this.checkBox1.Size = new System.Drawing.Size(175, 20);
            this.checkBox1.TabIndex = 9;
            this.checkBox1.Text = "Plain text from keyboard:";
            this.checkBox1.UseVisualStyleBackColor = true;
            this.checkBox1.CheckedChanged += new System.EventHandler(this.checkBox1_CheckedChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.ClientSize = new System.Drawing.Size(773, 305);
            this.Controls.Add(this.checkBox1);
            this.Controls.Add(this.lengthLabel);
            this.Controls.Add(this.lengthTB);
            this.Controls.Add(this.executeBtn);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.plainLabel);
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
        private System.Windows.Forms.Label plainLabel;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button executeBtn;
        private System.Windows.Forms.Label lengthLabel;
        private System.Windows.Forms.TextBox lengthTB;
        private System.Windows.Forms.CheckBox checkBox1;
    }
}


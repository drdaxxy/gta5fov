namespace FovCalc
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
            this.label1 = new System.Windows.Forms.Label();
            this.resolutionList = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.desiredHFovInput = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.calculatedVFovInput = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(24, 37);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(57, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Resolution";
            // 
            // resolutionList
            // 
            this.resolutionList.FormattingEnabled = true;
            this.resolutionList.Location = new System.Drawing.Point(161, 37);
            this.resolutionList.Name = "resolutionList";
            this.resolutionList.Size = new System.Drawing.Size(100, 21);
            this.resolutionList.TabIndex = 6;
            this.resolutionList.SelectedIndexChanged += new System.EventHandler(this.resolutionList_SelectedIndexChanged);
            this.resolutionList.TextUpdate += new System.EventHandler(this.resolutionList_TextUpdate);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(24, 73);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(115, 13);
            this.label2.TabIndex = 7;
            this.label2.Text = "Desired horizontal FOV";
            // 
            // desiredHFovInput
            // 
            this.desiredHFovInput.Location = new System.Drawing.Point(161, 73);
            this.desiredHFovInput.Name = "desiredHFovInput";
            this.desiredHFovInput.Size = new System.Drawing.Size(100, 20);
            this.desiredHFovInput.TabIndex = 8;
            this.desiredHFovInput.Text = "115";
            this.desiredHFovInput.TextChanged += new System.EventHandler(this.desiredHFovInput_TextChanged);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(24, 111);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(118, 13);
            this.label3.TabIndex = 9;
            this.label3.Text = "Calculated vertical FOV";
            // 
            // calculatedVFovInput
            // 
            this.calculatedVFovInput.Location = new System.Drawing.Point(161, 107);
            this.calculatedVFovInput.Name = "calculatedVFovInput";
            this.calculatedVFovInput.Size = new System.Drawing.Size(100, 20);
            this.calculatedVFovInput.TabIndex = 10;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(291, 171);
            this.Controls.Add(this.calculatedVFovInput);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.desiredHFovInput);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.resolutionList);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Fov Calc";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox desiredHFovInput;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox calculatedVFovInput;
        public System.Windows.Forms.ComboBox resolutionList;
    }
}


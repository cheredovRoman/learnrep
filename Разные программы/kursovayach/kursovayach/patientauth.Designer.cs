
namespace kursovayach
{
    partial class patientauth
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
            this.textBoxnamep = new System.Windows.Forms.TextBox();
            this.vhodb = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(98, 78);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(101, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Введите ваше имя";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // textBoxnamep
            // 
            this.textBoxnamep.Location = new System.Drawing.Point(65, 109);
            this.textBoxnamep.Name = "textBoxnamep";
            this.textBoxnamep.Size = new System.Drawing.Size(166, 20);
            this.textBoxnamep.TabIndex = 1;
            // 
            // vhodb
            // 
            this.vhodb.Location = new System.Drawing.Point(85, 149);
            this.vhodb.Name = "vhodb";
            this.vhodb.Size = new System.Drawing.Size(127, 31);
            this.vhodb.TabIndex = 2;
            this.vhodb.Text = "Войти";
            this.vhodb.UseVisualStyleBackColor = true;
            this.vhodb.Click += new System.EventHandler(this.vhodb_Click);
            // 
            // patientauth
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(299, 295);
            this.Controls.Add(this.vhodb);
            this.Controls.Add(this.textBoxnamep);
            this.Controls.Add(this.label1);
            this.Name = "patientauth";
            this.Text = "Войдите как пациент";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBoxnamep;
        private System.Windows.Forms.Button vhodb;
    }
}
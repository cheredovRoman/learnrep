
namespace kursovayach
{
    partial class docpaneldo
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
            this.button1 = new System.Windows.Forms.Button();
            this.resb = new System.Windows.Forms.Button();
            this.delb = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(69, 65);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(202, 45);
            this.button1.TabIndex = 0;
            this.button1.Text = "Добавить опрос";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // resb
            // 
            this.resb.Location = new System.Drawing.Point(69, 139);
            this.resb.Name = "resb";
            this.resb.Size = new System.Drawing.Size(202, 45);
            this.resb.TabIndex = 1;
            this.resb.Text = "Посмотреть результат";
            this.resb.UseVisualStyleBackColor = true;
            // 
            // delb
            // 
            this.delb.Location = new System.Drawing.Point(69, 214);
            this.delb.Name = "delb";
            this.delb.Size = new System.Drawing.Size(202, 45);
            this.delb.TabIndex = 2;
            this.delb.Text = "Удаление опроса";
            this.delb.UseVisualStyleBackColor = true;
            // 
            // docpaneldo
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(372, 324);
            this.Controls.Add(this.delb);
            this.Controls.Add(this.resb);
            this.Controls.Add(this.button1);
            this.Name = "docpaneldo";
            this.Text = "Панель доктора";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button resb;
        private System.Windows.Forms.Button delb;
    }
}
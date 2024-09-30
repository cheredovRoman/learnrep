
namespace kursovayach
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.docb = new System.Windows.Forms.Button();
            this.patientb = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // docb
            // 
            this.docb.Location = new System.Drawing.Point(103, 94);
            this.docb.Name = "docb";
            this.docb.Size = new System.Drawing.Size(154, 49);
            this.docb.TabIndex = 0;
            this.docb.Text = "Доктор";
            this.docb.UseVisualStyleBackColor = true;
            this.docb.Click += new System.EventHandler(this.docb_Click);
            // 
            // patientb
            // 
            this.patientb.Location = new System.Drawing.Point(103, 184);
            this.patientb.Name = "patientb";
            this.patientb.Size = new System.Drawing.Size(154, 49);
            this.patientb.TabIndex = 1;
            this.patientb.Text = "Пациент";
            this.patientb.UseVisualStyleBackColor = true;
            this.patientb.Click += new System.EventHandler(this.patientb_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(100, 58);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(151, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "Авторизуйтесь в программу";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(381, 302);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.patientb);
            this.Controls.Add(this.docb);
            this.Name = "Form1";
            this.Text = "Опрос пациента";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button docb;
        private System.Windows.Forms.Button patientb;
        private System.Windows.Forms.Label label1;
    }
}


namespace last
{
    partial class MainForm
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
            this.label_number = new System.Windows.Forms.Label();
            this.act_textbox = new System.Windows.Forms.TextBox();
            this.label_data = new System.Windows.Forms.Label();
            this.dateTimePicker = new System.Windows.Forms.DateTimePicker();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.textBox_okud = new System.Windows.Forms.TextBox();
            this.textBox_okpo = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.textBox_deyat = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.textBox_operation = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.textBox_sdal = new System.Windows.Forms.TextBox();
            this.textBox_sdal_dolzh = new System.Windows.Forms.TextBox();
            this.label11 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.label13 = new System.Windows.Forms.Label();
            this.textBox_prinyal = new System.Windows.Forms.TextBox();
            this.textBox_prinyal_dol = new System.Windows.Forms.TextBox();
            this.textBox_admin = new System.Windows.Forms.TextBox();
            this.textBox_admin_dol = new System.Windows.Forms.TextBox();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage = new System.Windows.Forms.TabPage();
            this.clear_button = new System.Windows.Forms.Button();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.clear_button_tar = new System.Windows.Forms.Button();
            this.dataGridView2 = new System.Windows.Forms.DataGridView();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.Export_button = new System.Windows.Forms.Button();
            this.button_clear = new System.Windows.Forms.Button();
            this.comboBox_org = new System.Windows.Forms.ComboBox();
            this.comboBox_struct = new System.Windows.Forms.ComboBox();
            this.t_name = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.t_code = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.E_name = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.E_code = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.mass = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.col = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.cost = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.sum = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn2 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn3 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn5 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn6 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn7 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn8 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn9 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn10 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.tabControl1.SuspendLayout();
            this.tabPage.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.tabPage1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).BeginInit();
            this.tabPage2.SuspendLayout();
            this.SuspendLayout();
            // 
            // label_number
            // 
            this.label_number.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.label_number.AutoSize = true;
            this.label_number.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F);
            this.label_number.Location = new System.Drawing.Point(328, 9);
            this.label_number.Name = "label_number";
            this.label_number.Size = new System.Drawing.Size(76, 26);
            this.label_number.TabIndex = 0;
            this.label_number.Text = "Акт №";
            // 
            // act_textbox
            // 
            this.act_textbox.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.act_textbox.Location = new System.Drawing.Point(410, 11);
            this.act_textbox.Name = "act_textbox";
            this.act_textbox.Size = new System.Drawing.Size(158, 22);
            this.act_textbox.TabIndex = 1;
            this.act_textbox.TextChanged += new System.EventHandler(this.act_textbox_TextChanged);
            // 
            // label_data
            // 
            this.label_data.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.label_data.AutoSize = true;
            this.label_data.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F);
            this.label_data.Location = new System.Drawing.Point(572, 9);
            this.label_data.Name = "label_data";
            this.label_data.Size = new System.Drawing.Size(63, 26);
            this.label_data.TabIndex = 2;
            this.label_data.Text = "Дата";
            // 
            // dateTimePicker
            // 
            this.dateTimePicker.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.dateTimePicker.Location = new System.Drawing.Point(633, 11);
            this.dateTimePicker.Name = "dateTimePicker";
            this.dateTimePicker.Size = new System.Drawing.Size(166, 22);
            this.dateTimePicker.TabIndex = 3;
            this.dateTimePicker.ValueChanged += new System.EventHandler(this.dateTimePicker_ValueChanged);
            // 
            // label1
            // 
            this.label1.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F);
            this.label1.Location = new System.Drawing.Point(229, 54);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(802, 26);
            this.label1.TabIndex = 4;
            this.label1.Text = "Акт о передачи товаров и тары при смене материально ответственного лица";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label2.Location = new System.Drawing.Point(12, 101);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(98, 18);
            this.label2.TabIndex = 5;
            this.label2.Text = "Организация";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label3.Location = new System.Drawing.Point(8, 135);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(199, 18);
            this.label3.TabIndex = 7;
            this.label3.Text = "Структурное поразделение";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label4.Location = new System.Drawing.Point(826, 109);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(126, 18);
            this.label4.TabIndex = 9;
            this.label4.Text = "Форма по ОКУД";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label5.Location = new System.Drawing.Point(848, 149);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(74, 18);
            this.label5.TabIndex = 10;
            this.label5.Text = "по ОКПО";
            // 
            // textBox_okud
            // 
            this.textBox_okud.Location = new System.Drawing.Point(1036, 105);
            this.textBox_okud.Name = "textBox_okud";
            this.textBox_okud.Size = new System.Drawing.Size(158, 22);
            this.textBox_okud.TabIndex = 11;
            this.textBox_okud.TextChanged += new System.EventHandler(this.textBox_okud_TextChanged);
            // 
            // textBox_okpo
            // 
            this.textBox_okpo.Location = new System.Drawing.Point(1036, 145);
            this.textBox_okpo.Name = "textBox_okpo";
            this.textBox_okpo.Size = new System.Drawing.Size(158, 22);
            this.textBox_okpo.TabIndex = 12;
            this.textBox_okpo.TextChanged += new System.EventHandler(this.textBox_okpo_TextChanged);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label7.Location = new System.Drawing.Point(824, 196);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(195, 18);
            this.label7.TabIndex = 15;
            this.label7.Text = "Вид деятельности по окдп";
            // 
            // textBox_deyat
            // 
            this.textBox_deyat.Location = new System.Drawing.Point(1036, 192);
            this.textBox_deyat.Name = "textBox_deyat";
            this.textBox_deyat.Size = new System.Drawing.Size(158, 22);
            this.textBox_deyat.TabIndex = 16;
            this.textBox_deyat.TextChanged += new System.EventHandler(this.textBox_deyat_TextChanged);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label8.Location = new System.Drawing.Point(826, 232);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(104, 18);
            this.label8.TabIndex = 17;
            this.label8.Text = "Вид операции";
            // 
            // textBox_operation
            // 
            this.textBox_operation.Location = new System.Drawing.Point(1036, 232);
            this.textBox_operation.Name = "textBox_operation";
            this.textBox_operation.Size = new System.Drawing.Size(158, 22);
            this.textBox_operation.TabIndex = 18;
            this.textBox_operation.TextChanged += new System.EventHandler(this.textBox_operation_TextChanged);
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label9.Location = new System.Drawing.Point(3, 50);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(49, 18);
            this.label9.TabIndex = 19;
            this.label9.Text = "Сдал";
            this.label9.Click += new System.EventHandler(this.label9_Click);
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label10.Location = new System.Drawing.Point(458, 10);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(44, 18);
            this.label10.TabIndex = 20;
            this.label10.Text = "ФИО";
            // 
            // textBox_sdal
            // 
            this.textBox_sdal.Location = new System.Drawing.Point(342, 46);
            this.textBox_sdal.Name = "textBox_sdal";
            this.textBox_sdal.Size = new System.Drawing.Size(265, 22);
            this.textBox_sdal.TabIndex = 21;
            this.textBox_sdal.TextChanged += new System.EventHandler(this.textBox_sdal_TextChanged);
            // 
            // textBox_sdal_dolzh
            // 
            this.textBox_sdal_dolzh.Location = new System.Drawing.Point(700, 46);
            this.textBox_sdal_dolzh.Name = "textBox_sdal_dolzh";
            this.textBox_sdal_dolzh.Size = new System.Drawing.Size(313, 22);
            this.textBox_sdal_dolzh.TabIndex = 22;
            this.textBox_sdal_dolzh.TextChanged += new System.EventHandler(this.textBox_sdal_dolzh_TextChanged);
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label11.Location = new System.Drawing.Point(797, 10);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(89, 18);
            this.label11.TabIndex = 23;
            this.label11.Text = "Должность";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label12.Location = new System.Drawing.Point(3, 94);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(66, 18);
            this.label12.TabIndex = 24;
            this.label12.Text = "Принял";
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label13.Location = new System.Drawing.Point(3, 144);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(253, 18);
            this.label13.TabIndex = 25;
            this.label13.Text = "Представитель администрации";
            // 
            // textBox_prinyal
            // 
            this.textBox_prinyal.Location = new System.Drawing.Point(342, 90);
            this.textBox_prinyal.Name = "textBox_prinyal";
            this.textBox_prinyal.Size = new System.Drawing.Size(265, 22);
            this.textBox_prinyal.TabIndex = 27;
            this.textBox_prinyal.TextChanged += new System.EventHandler(this.textBox_prinyal_TextChanged);
            // 
            // textBox_prinyal_dol
            // 
            this.textBox_prinyal_dol.AcceptsReturn = true;
            this.textBox_prinyal_dol.Location = new System.Drawing.Point(700, 90);
            this.textBox_prinyal_dol.Name = "textBox_prinyal_dol";
            this.textBox_prinyal_dol.Size = new System.Drawing.Size(313, 22);
            this.textBox_prinyal_dol.TabIndex = 29;
            this.textBox_prinyal_dol.TextChanged += new System.EventHandler(this.textBox_prinyal_dol_TextChanged);
            // 
            // textBox_admin
            // 
            this.textBox_admin.Location = new System.Drawing.Point(342, 140);
            this.textBox_admin.Name = "textBox_admin";
            this.textBox_admin.Size = new System.Drawing.Size(265, 22);
            this.textBox_admin.TabIndex = 31;
            this.textBox_admin.TextChanged += new System.EventHandler(this.textBox_admin_TextChanged);
            // 
            // textBox_admin_dol
            // 
            this.textBox_admin_dol.Location = new System.Drawing.Point(700, 143);
            this.textBox_admin_dol.Name = "textBox_admin_dol";
            this.textBox_admin_dol.Size = new System.Drawing.Size(313, 22);
            this.textBox_admin_dol.TabIndex = 33;
            this.textBox_admin_dol.TextChanged += new System.EventHandler(this.textBox_admin_dol_TextChanged);
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage);
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Location = new System.Drawing.Point(15, 288);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(1179, 372);
            this.tabControl1.TabIndex = 34;
            // 
            // tabPage
            // 
            this.tabPage.Controls.Add(this.clear_button);
            this.tabPage.Controls.Add(this.dataGridView1);
            this.tabPage.Location = new System.Drawing.Point(4, 25);
            this.tabPage.Name = "tabPage";
            this.tabPage.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage.Size = new System.Drawing.Size(1171, 343);
            this.tabPage.TabIndex = 0;
            this.tabPage.Text = "Товар";
            this.tabPage.UseVisualStyleBackColor = true;
            // 
            // clear_button
            // 
            this.clear_button.Location = new System.Drawing.Point(6, 300);
            this.clear_button.Name = "clear_button";
            this.clear_button.Size = new System.Drawing.Size(135, 23);
            this.clear_button.TabIndex = 2;
            this.clear_button.Text = "Удалить строку";
            this.clear_button.UseVisualStyleBackColor = true;
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.t_name,
            this.t_code,
            this.E_name,
            this.E_code,
            this.mass,
            this.col,
            this.cost,
            this.sum});
            this.dataGridView1.Location = new System.Drawing.Point(-1, 0);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowHeadersWidth = 51;
            this.dataGridView1.RowTemplate.Height = 24;
            this.dataGridView1.Size = new System.Drawing.Size(1172, 293);
            this.dataGridView1.TabIndex = 0;
            this.dataGridView1.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellContentClick);
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.clear_button_tar);
            this.tabPage1.Controls.Add(this.dataGridView2);
            this.tabPage1.Location = new System.Drawing.Point(4, 25);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(1171, 343);
            this.tabPage1.TabIndex = 1;
            this.tabPage1.Text = "Тара";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // clear_button_tar
            // 
            this.clear_button_tar.Location = new System.Drawing.Point(6, 299);
            this.clear_button_tar.Name = "clear_button_tar";
            this.clear_button_tar.Size = new System.Drawing.Size(135, 23);
            this.clear_button_tar.TabIndex = 4;
            this.clear_button_tar.Text = "Удалить строку";
            this.clear_button_tar.UseVisualStyleBackColor = true;
            // 
            // dataGridView2
            // 
            this.dataGridView2.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView2.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dataGridViewTextBoxColumn2,
            this.dataGridViewTextBoxColumn3,
            this.dataGridViewTextBoxColumn5,
            this.dataGridViewTextBoxColumn6,
            this.dataGridViewTextBoxColumn7,
            this.dataGridViewTextBoxColumn8,
            this.dataGridViewTextBoxColumn9,
            this.dataGridViewTextBoxColumn10});
            this.dataGridView2.Location = new System.Drawing.Point(-1, 0);
            this.dataGridView2.Name = "dataGridView2";
            this.dataGridView2.RowHeadersWidth = 51;
            this.dataGridView2.RowTemplate.Height = 24;
            this.dataGridView2.Size = new System.Drawing.Size(1172, 293);
            this.dataGridView2.TabIndex = 1;
            this.dataGridView2.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView2_CellContentClick);
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.label9);
            this.tabPage2.Controls.Add(this.label10);
            this.tabPage2.Controls.Add(this.textBox_sdal);
            this.tabPage2.Controls.Add(this.textBox_admin_dol);
            this.tabPage2.Controls.Add(this.label11);
            this.tabPage2.Controls.Add(this.textBox_sdal_dolzh);
            this.tabPage2.Controls.Add(this.textBox_admin);
            this.tabPage2.Controls.Add(this.label12);
            this.tabPage2.Controls.Add(this.textBox_prinyal_dol);
            this.tabPage2.Controls.Add(this.label13);
            this.tabPage2.Controls.Add(this.textBox_prinyal);
            this.tabPage2.Location = new System.Drawing.Point(4, 25);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Size = new System.Drawing.Size(1171, 343);
            this.tabPage2.TabIndex = 2;
            this.tabPage2.Text = "Форма сдачи";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // Export_button
            // 
            this.Export_button.Location = new System.Drawing.Point(981, 681);
            this.Export_button.Name = "Export_button";
            this.Export_button.Size = new System.Drawing.Size(208, 30);
            this.Export_button.TabIndex = 35;
            this.Export_button.Text = "Экспортировать";
            this.Export_button.UseVisualStyleBackColor = true;
            this.Export_button.Click += new System.EventHandler(this.Export_button_Click);
            // 
            // button_clear
            // 
            this.button_clear.Location = new System.Drawing.Point(18, 681);
            this.button_clear.Name = "button_clear";
            this.button_clear.Size = new System.Drawing.Size(208, 30);
            this.button_clear.TabIndex = 36;
            this.button_clear.Text = "Очистить таблицы";
            this.button_clear.UseVisualStyleBackColor = true;
            // 
            // comboBox_org
            // 
            this.comboBox_org.FormattingEnabled = true;
            this.comboBox_org.Location = new System.Drawing.Point(113, 95);
            this.comboBox_org.Name = "comboBox_org";
            this.comboBox_org.Size = new System.Drawing.Size(489, 24);
            this.comboBox_org.TabIndex = 37;
            this.comboBox_org.SelectedIndexChanged += new System.EventHandler(this.comboBox_org_SelectedIndexChanged);
            // 
            // comboBox_struct
            // 
            this.comboBox_struct.FormattingEnabled = true;
            this.comboBox_struct.Location = new System.Drawing.Point(213, 134);
            this.comboBox_struct.Name = "comboBox_struct";
            this.comboBox_struct.Size = new System.Drawing.Size(389, 24);
            this.comboBox_struct.TabIndex = 38;
            this.comboBox_struct.SelectedIndexChanged += new System.EventHandler(this.comboBox_struct_SelectedIndexChanged);
            // 
            // t_name
            // 
            this.t_name.HeaderText = "Наименование";
            this.t_name.MinimumWidth = 6;
            this.t_name.Name = "t_name";
            this.t_name.Width = 125;
            // 
            // t_code
            // 
            this.t_code.HeaderText = "Код";
            this.t_code.MinimumWidth = 6;
            this.t_code.Name = "t_code";
            this.t_code.Width = 125;
            // 
            // E_name
            // 
            this.E_name.HeaderText = "Наименование";
            this.E_name.MinimumWidth = 6;
            this.E_name.Name = "E_name";
            this.E_name.Width = 125;
            // 
            // E_code
            // 
            this.E_code.HeaderText = "Код по ОКЕИ";
            this.E_code.MinimumWidth = 6;
            this.E_code.Name = "E_code";
            this.E_code.Width = 125;
            // 
            // mass
            // 
            this.mass.HeaderText = "Масса";
            this.mass.MinimumWidth = 6;
            this.mass.Name = "mass";
            this.mass.Width = 125;
            // 
            // col
            // 
            this.col.HeaderText = "Количество";
            this.col.MinimumWidth = 6;
            this.col.Name = "col";
            this.col.Width = 125;
            // 
            // cost
            // 
            this.cost.HeaderText = "Цена руб. коп.";
            this.cost.MinimumWidth = 6;
            this.cost.Name = "cost";
            this.cost.Width = 125;
            // 
            // sum
            // 
            this.sum.HeaderText = "Сумма руб. коп.";
            this.sum.MinimumWidth = 6;
            this.sum.Name = "sum";
            this.sum.Width = 125;
            // 
            // dataGridViewTextBoxColumn2
            // 
            this.dataGridViewTextBoxColumn2.HeaderText = "Наименование";
            this.dataGridViewTextBoxColumn2.MinimumWidth = 6;
            this.dataGridViewTextBoxColumn2.Name = "dataGridViewTextBoxColumn2";
            this.dataGridViewTextBoxColumn2.Width = 125;
            // 
            // dataGridViewTextBoxColumn3
            // 
            this.dataGridViewTextBoxColumn3.HeaderText = "Код";
            this.dataGridViewTextBoxColumn3.MinimumWidth = 6;
            this.dataGridViewTextBoxColumn3.Name = "dataGridViewTextBoxColumn3";
            this.dataGridViewTextBoxColumn3.Width = 125;
            // 
            // dataGridViewTextBoxColumn5
            // 
            this.dataGridViewTextBoxColumn5.HeaderText = "Наименование";
            this.dataGridViewTextBoxColumn5.MinimumWidth = 6;
            this.dataGridViewTextBoxColumn5.Name = "dataGridViewTextBoxColumn5";
            this.dataGridViewTextBoxColumn5.Width = 125;
            // 
            // dataGridViewTextBoxColumn6
            // 
            this.dataGridViewTextBoxColumn6.HeaderText = "Код по ОКЕИ";
            this.dataGridViewTextBoxColumn6.MinimumWidth = 6;
            this.dataGridViewTextBoxColumn6.Name = "dataGridViewTextBoxColumn6";
            this.dataGridViewTextBoxColumn6.Width = 125;
            // 
            // dataGridViewTextBoxColumn7
            // 
            this.dataGridViewTextBoxColumn7.HeaderText = "Масса";
            this.dataGridViewTextBoxColumn7.MinimumWidth = 6;
            this.dataGridViewTextBoxColumn7.Name = "dataGridViewTextBoxColumn7";
            this.dataGridViewTextBoxColumn7.Width = 125;
            // 
            // dataGridViewTextBoxColumn8
            // 
            this.dataGridViewTextBoxColumn8.HeaderText = "Количество";
            this.dataGridViewTextBoxColumn8.MinimumWidth = 6;
            this.dataGridViewTextBoxColumn8.Name = "dataGridViewTextBoxColumn8";
            this.dataGridViewTextBoxColumn8.Width = 125;
            // 
            // dataGridViewTextBoxColumn9
            // 
            this.dataGridViewTextBoxColumn9.HeaderText = "Цена руб. коп.";
            this.dataGridViewTextBoxColumn9.MinimumWidth = 6;
            this.dataGridViewTextBoxColumn9.Name = "dataGridViewTextBoxColumn9";
            this.dataGridViewTextBoxColumn9.Width = 125;
            // 
            // dataGridViewTextBoxColumn10
            // 
            this.dataGridViewTextBoxColumn10.HeaderText = "Сумма руб. коп.";
            this.dataGridViewTextBoxColumn10.MinimumWidth = 6;
            this.dataGridViewTextBoxColumn10.Name = "dataGridViewTextBoxColumn10";
            this.dataGridViewTextBoxColumn10.Width = 125;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1222, 723);
            this.Controls.Add(this.comboBox_struct);
            this.Controls.Add(this.comboBox_org);
            this.Controls.Add(this.button_clear);
            this.Controls.Add(this.Export_button);
            this.Controls.Add(this.tabControl1);
            this.Controls.Add(this.textBox_operation);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.textBox_deyat);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.textBox_okpo);
            this.Controls.Add(this.textBox_okud);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.dateTimePicker);
            this.Controls.Add(this.label_data);
            this.Controls.Add(this.act_textbox);
            this.Controls.Add(this.label_number);
            this.Name = "MainForm";
            this.Text = "ОП-18 Вариант-1";
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.tabControl1.ResumeLayout(false);
            this.tabPage.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.tabPage1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).EndInit();
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label_number;
        private System.Windows.Forms.TextBox act_textbox;
        private System.Windows.Forms.Label label_data;
        private System.Windows.Forms.DateTimePicker dateTimePicker;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox textBox_okud;
        private System.Windows.Forms.TextBox textBox_okpo;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox textBox_deyat;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.TextBox textBox_operation;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.TextBox textBox_sdal;
        private System.Windows.Forms.TextBox textBox_sdal_dolzh;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.TextBox textBox_prinyal;
        private System.Windows.Forms.TextBox textBox_prinyal_dol;
        private System.Windows.Forms.TextBox textBox_admin;
        private System.Windows.Forms.TextBox textBox_admin_dol;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Button clear_button;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.DataGridView dataGridView2;
        private System.Windows.Forms.Button clear_button_tar;
        private System.Windows.Forms.Button Export_button;
        private System.Windows.Forms.Button button_clear;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.ComboBox comboBox_org;
        private System.Windows.Forms.ComboBox comboBox_struct;
        private System.Windows.Forms.DataGridViewTextBoxColumn t_name;
        private System.Windows.Forms.DataGridViewTextBoxColumn t_code;
        private System.Windows.Forms.DataGridViewTextBoxColumn E_name;
        private System.Windows.Forms.DataGridViewTextBoxColumn E_code;
        private System.Windows.Forms.DataGridViewTextBoxColumn mass;
        private System.Windows.Forms.DataGridViewTextBoxColumn col;
        private System.Windows.Forms.DataGridViewTextBoxColumn cost;
        private System.Windows.Forms.DataGridViewTextBoxColumn sum;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn2;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn3;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn5;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn6;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn7;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn8;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn9;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn10;
    }
}


using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Spire.Xls;

namespace last
{
    public struct struct_podraz
    {
        public string NAME { get; set; }
        public string OKDP { get; set; }
    }

    public struct org
    {
        public string NAME { get; set; }
        public List<struct_podraz> STR_POD { get; set; }
        public string OKPO { get; set; }

    }

    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label9_Click(object sender, EventArgs e)
        {

        }

        private void act_textbox_TextChanged(object sender, EventArgs e)
        {

        }

        private void dateTimePicker_ValueChanged(object sender, EventArgs e)
        {

        }

        private void comboBox_org_SelectedIndexChanged(object sender, EventArgs e)
        {
            comboBox_struct.Items.Clear();
            int index = comboBox_org.SelectedIndex;
            textBox_okpo.Text = orgs[index].OKPO.ToString();
            for (int i = 0; i < orgs[index].STR_POD.Count; i++)
            {
                comboBox_struct.Items.Add(orgs[index].STR_POD[i].NAME);
            }
            comboBox_struct.SelectedIndex = 0;
            textBox_okud.Text = orgs[index].STR_POD[0].OKDP;
        }

        private void comboBox_struct_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void textBox_okud_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox_okpo_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox_deyat_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox_operation_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox_sdal_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox_prinyal_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox_admin_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox_sdal_dolzh_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox_prinyal_dol_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox_admin_dol_TextChanged(object sender, EventArgs e)
        {

        }

        private void dataGridView2_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
        private List<org> orgs;
        private void MainForm_Load(object sender, EventArgs e)
        {
            string file = @"info.txt";
            var textFile = new StreamReader(file);
            string line;
            orgs = new List<org>();
            act_textbox.Text = textFile.ReadLine();
            dateTimePicker.Value = Convert.ToDateTime(textFile.ReadLine());
            org new_org = new org();
            new_org.NAME = textFile.ReadLine();
            new_org.OKPO = textFile.ReadLine();

            struct_podraz new_sp = new struct_podraz();
            new_sp.NAME = textFile.ReadLine();
            new_sp.OKDP = textFile.ReadLine();
            new_org.STR_POD = new List<struct_podraz>();
            new_org.STR_POD.Add(new_sp);

            new_sp = new struct_podraz();
            new_sp.NAME = textFile.ReadLine();
            new_sp.OKDP = textFile.ReadLine();
            new_org.STR_POD.Add(new_sp);

            new_sp = new struct_podraz();
            new_sp.NAME = textFile.ReadLine();
            new_sp.OKDP = textFile.ReadLine();
            new_org.STR_POD.Add(new_sp);

            orgs.Add(new_org);



            new_org = new org();
            new_org.STR_POD = new List<struct_podraz>();

            new_org.NAME = textFile.ReadLine();
            new_org.OKPO = textFile.ReadLine();

            new_sp = new struct_podraz();
            new_sp.NAME = textFile.ReadLine();
            new_sp.OKDP = textFile.ReadLine();
            new_org.STR_POD.Add(new_sp);

            new_sp = new struct_podraz();
            new_sp.NAME = textFile.ReadLine();
            new_sp.OKDP = textFile.ReadLine();
            new_org.STR_POD.Add(new_sp);

            new_sp = new struct_podraz();
            new_sp.NAME = textFile.ReadLine();
            new_sp.OKDP = textFile.ReadLine();
            new_org.STR_POD.Add(new_sp);

            orgs.Add(new_org);

            comboBox_org.Items.Add(orgs[0].NAME);
            comboBox_org.Items.Add(orgs[1].NAME);
            //установка первого элементак как активный
            comboBox_org.SelectedIndex = 0;

        }

        private void Export_button_Click(object sender, EventArgs e)
        {
            Workbook workbook = new Workbook();
            workbook.LoadFromFile("18.xls");
            Worksheet sheet = workbook.Worksheets[0];
            sheet.Range["A6"].Value = comboBox_org.Text;
            sheet.Range["A8"].Value = comboBox_struct.Text;
            sheet.Range["AO6"].Value = textBox_okpo.Text;
            sheet.Range["AO9"].Value = textBox_okud.Text;
            sheet.Range["AO10"].Value = textBox_operation.Text;
            sheet.Range["G52"].Value = textBox_sdal_dolzh.Text;
            sheet.Range["G54"].Value = textBox_prinyal_dol.Text;
            sheet.Range["R56"].Value = textBox_admin_dol.Text;
            sheet.Range["AB52"].Value = textBox_sdal.Text;
            sheet.Range["AB54"].Value = textBox_prinyal.Text;
            sheet.Range["AL56"].Value = textBox_admin.Text;
            sheet.Range["AA13"].Value = act_textbox.Text;
            sheet.Range["AI13"].Value = dateTimePicker.Value.Day.ToString() +
                "." + dateTimePicker.Value.Month.ToString() + "." + dateTimePicker.Value.Year.ToString();
            //tovar
            //1
            sheet.Range["E27"].Value = dataGridView1.Rows[0].Cells[0].Value.ToString();
            sheet.Range["S27"].Value = dataGridView1.Rows[0].Cells[1].Value.ToString();
            sheet.Range["V27"].Value = dataGridView1.Rows[0].Cells[2].Value.ToString();
            sheet.Range["Z27"].Value = dataGridView1.Rows[0].Cells[3].Value.ToString();
            sheet.Range["AD27"].Value = dataGridView1.Rows[0].Cells[4].Value.ToString();
            sheet.Range["AH27"].Value = dataGridView1.Rows[0].Cells[5].Value.ToString();
            sheet.Range["AM27"].Value = dataGridView1.Rows[0].Cells[6].Value.ToString();
            sheet.Range["AR27"].Value = dataGridView1.Rows[0].Cells[7].Value.ToString();
            //2
            sheet.Range["E28"].Value = dataGridView1.Rows[1].Cells[0].Value.ToString();
            sheet.Range["S28"].Value = dataGridView1.Rows[1].Cells[1].Value.ToString();
            sheet.Range["V28"].Value = dataGridView1.Rows[1].Cells[2].Value.ToString();
            sheet.Range["Z28"].Value = dataGridView1.Rows[1].Cells[3].Value.ToString();
            sheet.Range["AD28"].Value = dataGridView1.Rows[1].Cells[4].Value.ToString();
            sheet.Range["AH28"].Value = dataGridView1.Rows[1].Cells[5].Value.ToString();
            sheet.Range["AM28"].Value = dataGridView1.Rows[1].Cells[6].Value.ToString();
            sheet.Range["AR28"].Value = dataGridView1.Rows[1].Cells[7].Value.ToString();
            //3
            sheet.Range["E29"].Value = dataGridView1.Rows[2].Cells[0].Value.ToString();
            sheet.Range["S29"].Value = dataGridView1.Rows[2].Cells[1].Value.ToString();
            sheet.Range["V29"].Value = dataGridView1.Rows[2].Cells[2].Value.ToString();
            sheet.Range["Z29"].Value = dataGridView1.Rows[2].Cells[3].Value.ToString();
            sheet.Range["AD29"].Value = dataGridView1.Rows[2].Cells[4].Value.ToString();
            sheet.Range["AH29"].Value = dataGridView1.Rows[2].Cells[5].Value.ToString();
            sheet.Range["AM29"].Value = dataGridView1.Rows[2].Cells[6].Value.ToString();
            sheet.Range["AR29"].Value = dataGridView1.Rows[2].Cells[7].Value.ToString();
            //tara
            //1
            sheet.Range["E45"].Value = dataGridView2.Rows[0].Cells[0].Value.ToString();
            sheet.Range["S45"].Value = dataGridView2.Rows[0].Cells[1].Value.ToString();
            sheet.Range["V45"].Value = dataGridView2.Rows[0].Cells[2].Value.ToString();
            sheet.Range["Z45"].Value = dataGridView2.Rows[0].Cells[3].Value.ToString();
            sheet.Range["AD45"].Value = dataGridView2.Rows[0].Cells[4].Value.ToString();
            sheet.Range["AH45"].Value = dataGridView2.Rows[0].Cells[5].Value.ToString();
            sheet.Range["AM45"].Value = dataGridView2.Rows[0].Cells[6].Value.ToString();
            sheet.Range["AR45"].Value = dataGridView2.Rows[0].Cells[7].Value.ToString();
            //2
            sheet.Range["E46"].Value = dataGridView2.Rows[1].Cells[0].Value.ToString();
            sheet.Range["S46"].Value = dataGridView2.Rows[1].Cells[1].Value.ToString();
            sheet.Range["V46"].Value = dataGridView2.Rows[1].Cells[2].Value.ToString();
            sheet.Range["Z46"].Value = dataGridView2.Rows[1].Cells[3].Value.ToString();
            sheet.Range["AD46"].Value = dataGridView2.Rows[1].Cells[4].Value.ToString();
            sheet.Range["AH46"].Value = dataGridView2.Rows[1].Cells[5].Value.ToString();
            sheet.Range["AM46"].Value = dataGridView2.Rows[1].Cells[6].Value.ToString();
            sheet.Range["AR46"].Value = dataGridView2.Rows[1].Cells[7].Value.ToString();
            //3
            sheet.Range["E47"].Value = dataGridView2.Rows[2].Cells[0].Value.ToString();
            sheet.Range["S47"].Value = dataGridView2.Rows[2].Cells[1].Value.ToString();
            sheet.Range["V47"].Value = dataGridView2.Rows[2].Cells[2].Value.ToString();
            sheet.Range["Z47"].Value = dataGridView2.Rows[2].Cells[3].Value.ToString();
            sheet.Range["AD47"].Value = dataGridView2.Rows[2].Cells[4].Value.ToString();
            sheet.Range["AH47"].Value = dataGridView2.Rows[2].Cells[5].Value.ToString();
            sheet.Range["AM47"].Value = dataGridView2.Rows[2].Cells[6].Value.ToString();
            sheet.Range["AR47"].Value = dataGridView2.Rows[2].Cells[7].Value.ToString();
            workbook.SaveToFile("18.xlsx", ExcelVersion.Version2007);

        }
    }
}

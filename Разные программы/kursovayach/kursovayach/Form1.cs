using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace kursovayach
{
    public partial class Form1 : Form
    {   

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void docb_Click(object sender, EventArgs e)
        {
            docpanel docad = new docpanel();
            docad.ShowDialog();

        }

        private void patientb_Click(object sender, EventArgs e)
        {
            patientauth patient = new patientauth();
            patient.ShowDialog();

        }
        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            File.Delete("res.txt");
        }
    }
}

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace kursovayach
{
    public partial class patientauth : Form
    {
        public patientauth()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void vhodb_Click(object sender, EventArgs e)
        {
            if (textBoxnamep.Text != string.Empty)
            {
                username = textBoxnamep.Text;
                this.Close();
            }
            else
            {
                MessageBox.Show("вы ничего не ввели");
            }

        }
    }
}

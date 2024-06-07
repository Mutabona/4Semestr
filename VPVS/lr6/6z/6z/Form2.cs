using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _6z
{
    public partial class Form2 : Form
    {
        int[,] data = new int[30,30];
        public Form2()
        {
            InitializeComponent();
        }


        private void button1_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < 30; i++)
            {
                DataGridViewTextBoxColumn column = new DataGridViewTextBoxColumn();
                dataGridView1.Columns.Insert(i, column);
                dataGridView1.Rows.Add();
            }

            var rand = new Random();

            for (int i = 0; i < 30; i++)
            {
                for (int j = 0; j < 30; j++)
                {
                    data[i, j] = rand.Next(50);
                    DataGridViewTextBoxCell cell = new DataGridViewTextBoxCell();
                    cell.Value = data[i, j];
                    dataGridView1[i, j] = cell;
                }
            }
        }
    }
}

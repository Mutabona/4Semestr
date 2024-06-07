using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace z4
{
    public partial class Form1 : Form
    {
        private System.Windows.Forms.ListBox listBox;

        public Form1()
        {
            InitializeComponent();
            CreateListBox();
        }

        private void Calculate(Object sender, EventArgs e)
        {
            double x = Convert.ToDouble(textBox1.Text);
            double y = Convert.ToDouble(textBox2.Text);

            

            listBox.Items.Add(calculator.Calculate(x,y).ToString());
        }

        private void Clear(Object sender, EventArgs e)
        {
            listBox.Items.Clear();
        }

        private void CreateListBox()
        {
            listBox = new System.Windows.Forms.ListBox();
            listBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            listBox.FormattingEnabled = true;
            listBox.ItemHeight = 32;
            listBox.Location = new System.Drawing.Point(478, 12);
            listBox.Name = "listBox1";
            listBox.Size = new System.Drawing.Size(310, 420);
            listBox.TabIndex = 4;
            Controls.Add(this.listBox);
        }
    }
}

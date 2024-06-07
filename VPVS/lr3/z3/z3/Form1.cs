using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace z3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Calculate(Object sender, EventArgs e)
        {
            double x = Convert.ToDouble(textBox3.Text);
            double y = Convert.ToDouble(textBox2.Text);
            double z = Convert.ToDouble(textBox1.Text);

            double W = Math.Pow(Math.Abs(Math.Cos(x) - Math.Cos(y)), 1+2*Math.Pow(Math.Sin(y), 2))*(1+z+z*z/2+Math.Pow(z, 3)/3+Math.Pow(z, 4) / 4);

            label1.Text = W.ToString();
        }
    }
}

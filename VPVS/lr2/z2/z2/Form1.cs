using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace z2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            MessageBox.Show("Задание 1.\nЗдравствуйте!\nПользователь", "Приветствие");
            ShowHelpDialog();
        }

        private void ShowHelpDialog()
        {
            DialogResult result = MessageBox.Show("Нужна помощь?", "Вопрос", MessageBoxButtons.OKCancel, MessageBoxIcon.Question);
            if (result == DialogResult.OK)
            {
                MessageBox.Show("Раздел помощи находится в разработке");
            }
        }


        private void HideTextBox(object sender, EventArgs e)
        {
            textBox1.Visible = false;
        }

        private void ShowTextBox(object sender, EventArgs e)
        {
            textBox1.Visible = true;
        }

        private void ClearTextBox(object sender, EventArgs e)
        {
            textBox1.Clear();
        }

        private void ChangeLabelTextTo2(object sender, EventArgs e)
        {
            label1.Text = 2.ToString();
        }
        private void ChangeLabelTextTo3(object sender, EventArgs e)
        {
            label1.Text = 3.ToString();
        }
        private void ChangeLabelTextTo4(object sender, EventArgs e)
        {
            label1.Text = 4.ToString();
        }
        private void ChangeLabelTextTo5(object sender, EventArgs e)
        {
            label1.Text = 5.ToString();
        }
        private void ChangeLabelTextTo1(object sender, EventArgs e)
        {
            label1.Text = 1.ToString();
        }
        private void ResetLabelText(object sender, EventArgs e)
        {
            label1.Text = "";
        }
    }
}

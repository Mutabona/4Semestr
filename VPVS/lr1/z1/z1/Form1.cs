namespace z1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void ChangeBackColorToRed(object sender, EventArgs e)
        {
            this.BackColor = Color.Red;
        }

        private void ChangeBackColorToBlue(object sender, EventArgs e)
        {
            this.BackColor = Color.Blue;
        }

        private void ChangeBackColorToGreen(object sender, EventArgs e)
        {
            this.BackColor = Color.Green;
        }

        private void ChangeBackColorToYellow(object sender, EventArgs e)
        {
            this.BackColor = Color.Yellow;
        }

        private void ChangeLabelTextToHello(object sender, EventArgs e)
        {
            label1.Text = "Hello";
        }

        private void ChangeLabelTextToGoodbye(object sender, EventArgs e)
        {
            label1.Text = "Goodbye";
        }

        private void HideLabel(object sender, EventArgs e)
        {
            label1.Visible = false;
        }

        private void ShowLabel(object sender, EventArgs e)
        {
            label1.Visible = true;
        }

        private void SetStartLabelText(object sender, EventArgs e)
        {
            label1.Text = "Start";
        }
    }
}

namespace z1
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            button1 = new Button();
            button2 = new Button();
            button3 = new Button();
            button4 = new Button();
            label1 = new Label();
            button5 = new Button();
            button6 = new Button();
            button7 = new Button();
            button8 = new Button();
            SuspendLayout();
            // 
            // button1
            // 
            button1.Location = new Point(12, 28);
            button1.Name = "button1";
            button1.Size = new Size(199, 65);
            button1.TabIndex = 0;
            button1.Text = "Красный";
            button1.UseVisualStyleBackColor = true;
            button1.Click += ChangeBackColorToRed;
            // 
            // button2
            // 
            button2.Location = new Point(573, 28);
            button2.Name = "button2";
            button2.Size = new Size(199, 65);
            button2.TabIndex = 1;
            button2.Text = "Синий";
            button2.UseVisualStyleBackColor = true;
            button2.Click += ChangeBackColorToBlue;
            // 
            // button3
            // 
            button3.Location = new Point(12, 122);
            button3.Name = "button3";
            button3.Size = new Size(199, 65);
            button3.TabIndex = 2;
            button3.Text = "Жёлтый";
            button3.UseVisualStyleBackColor = true;
            button3.Click += ChangeBackColorToYellow;
            // 
            // button4
            // 
            button4.Location = new Point(573, 122);
            button4.Name = "button4";
            button4.Size = new Size(199, 65);
            button4.TabIndex = 3;
            button4.Text = "Зелёный";
            button4.UseVisualStyleBackColor = true;
            button4.Click += ChangeBackColorToGreen;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(349, 228);
            label1.Name = "label1";
            label1.Size = new Size(48, 25);
            label1.TabIndex = 4;
            label1.Text = "Start";
            // 
            // button5
            // 
            button5.Location = new Point(12, 228);
            button5.Name = "button5";
            button5.Size = new Size(199, 65);
            button5.TabIndex = 5;
            button5.Text = "Hello";
            button5.UseVisualStyleBackColor = true;
            button5.Click += ChangeLabelTextToHello;
            // 
            // button6
            // 
            button6.Location = new Point(573, 228);
            button6.Name = "button6";
            button6.Size = new Size(199, 65);
            button6.TabIndex = 6;
            button6.Text = "Goodbye";
            button6.UseVisualStyleBackColor = true;
            button6.Click += ChangeLabelTextToGoodbye;
            // 
            // button7
            // 
            button7.Location = new Point(12, 332);
            button7.Name = "button7";
            button7.Size = new Size(199, 65);
            button7.TabIndex = 7;
            button7.Text = "Hide";
            button7.UseVisualStyleBackColor = true;
            button7.Click += HideLabel;
            // 
            // button8
            // 
            button8.Location = new Point(573, 332);
            button8.Name = "button8";
            button8.Size = new Size(199, 65);
            button8.TabIndex = 8;
            button8.Text = "Show";
            button8.UseVisualStyleBackColor = true;
            button8.Click += ShowLabel;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(button8);
            Controls.Add(button7);
            Controls.Add(button6);
            Controls.Add(button5);
            Controls.Add(label1);
            Controls.Add(button4);
            Controls.Add(button3);
            Controls.Add(button2);
            Controls.Add(button1);
            Name = "Form1";
            Text = "Form1";
            ResumeLayout(false);
            PerformLayout();

            Load += SetStartLabelText;
        }

        #endregion

        private Button button1;
        private Button button2;
        private Button button3;
        private Button button4;
        private Label label1;
        private Button button5;
        private Button button6;
        private Button button7;
        private Button button8;
    }
}

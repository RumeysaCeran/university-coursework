using Microsoft.VisualBasic.ApplicationServices;

namespace ObjectOrientedProgrammingAssignment2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();




        }



        private void Form1_Load(object sender, EventArgs e)
        {
            string[] dosyalar = Directory.GetFiles(Application.StartupPath, "*.txt");

            foreach (string dosya in dosyalar)
            {
                string dosya_adi = Path.GetFileNameWithoutExtension(dosya);
                comboBox1.Items.Add(dosya_adi);

            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string secili_dosya = comboBox1.SelectedItem.ToString();
            Form2 form2 = new Form2();
            form2.SeciliDosya = secili_dosya;
            this.Hide();
            form2.Show();
            
           

        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (comboBox1.SelectedItem == null)
            {   button2.Enabled = false;
                MessageBox.Show("L�tfen Bir Se�enek Se�iniz!");
            }
            else
            { button2.Enabled = true; }
        }
    }
}

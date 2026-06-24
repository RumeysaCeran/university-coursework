
/*****************************************************
**         SAKARYA ÜNÝVERSÝTESÝ
*       BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**      BÝLGÝSAYAR MÜHENDÝLÝÐÝ BÖLÜMÜ
**      NESNEYE DAYALI PROGRAMLAMA
**      2024-2025 BAHAR DÖNEMÝ
**
**      ÖDEV NUMARASI:3
*       ÖDEV NUMARASI.......:B241210370
**      ÖÐRENCÝ ADI.........:RÜMEYSA CERAN
**      DERSÝN ALDIÐI GRUP..:B
**
************************************************/

using System.Linq.Expressions;

namespace B241210370_PROJE_
{
    public partial class Form1 : Form
    {
        string dosyaAdiMekan = "mekan.txt";
        private string dosyaYoluMekan = "";
        string dosyaAdiOturan = "data.txt";
        private string dosyaYoluOturan = "";
        string dosyaAdiHavuz = "havuzkul.txt";
        private string dosyaYoluHavuz = "";
        string dosyaAdiFitness = "fitnesskul.txt";
        private string dosyaYoluFitness = "";
        string dosyaAdiOdemeler = "odeme.txt";
        private string dosyaYoluOdemeler = "";

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            dosyaYoluMekan = Path.Combine(Directory.GetCurrentDirectory(), dosyaAdiMekan);
            if (File.Exists(dosyaYoluMekan))
            {
                try
                {
                    File.Delete(dosyaYoluMekan);
                   

                }
                catch
                {
                    MessageBox.Show("mekan.txt silinemedi.");
                }
            }

            dosyaYoluOturan = Path.Combine(Directory.GetCurrentDirectory(),dosyaAdiOturan);
            if(File.Exists(dosyaYoluOturan))
            {
                try
                {
                    File.Delete(dosyaYoluOturan);
                   
                }
                catch 
                {
                    MessageBox.Show("data.txt silinemedi.");
                }
            }


            dosyaYoluHavuz = Path.Combine(Directory.GetCurrentDirectory(),dosyaAdiHavuz);
            if(File.Exists(dosyaYoluHavuz))
            {
                try
                {
                    File.Delete(dosyaYoluHavuz);
                   
                }
                catch
                {
                    MessageBox.Show("havuzkul.txt silinemedi");
                }
            }


            dosyaYoluFitness = Path.Combine(Directory.GetCurrentDirectory(), dosyaAdiFitness);
            if (File.Exists(dosyaYoluFitness))
            {
                try
                {
                    File.Delete(dosyaYoluFitness);
                   
                }
                catch 
                {
                    MessageBox.Show("havuzkul.txt silinemedi");
                }
            }


            dosyaYoluOdemeler = Path.Combine(Directory.GetCurrentDirectory(), dosyaAdiOdemeler);
            if(File.Exists(dosyaYoluOdemeler))
            {
                try
                {
                    File.Delete(dosyaYoluOdemeler);
                   
                }
                catch
                {
                    MessageBox.Show("odemeler.txt silinemedi");
                }
            }

        }




        private void button1_Click(object sender, EventArgs e)
        {

            Form2 form2 = new Form2(this);
            Form3 form3 = new Form3(this);
            Form4 form4 = new Form4(this, form3);


            switch (comboBox1.SelectedIndex)
            {
                case 0:
                    this.Hide();
                    form2.Show();
                    break;
                case 1:
                    this.Hide();
                    form3.Show();
                    break;
                case 2:
                    this.Hide();
                    form4.Show();
                    break;
                default:
                    MessageBox.Show("Lütfen bir menü seçiniz");
                    break;
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}

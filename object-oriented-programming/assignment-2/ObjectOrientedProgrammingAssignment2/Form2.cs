using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ObjectOrientedProgrammingAssignment2
{
    public partial class Form2 : Form
    {
        public string SeciliDosya { get; set; }
        string[] dosyalar = Directory.GetFiles(Application.StartupPath, "*.txt");
        List<string> turkceKelimeler = new List<string>();
        List<string> ingilizceKelimeler = new List<string>();
        string dogruCevap;
        string soru;
        int soruSayisi = 0;
        int dogruCevapSayisi = 0;
        List<string> secilmisKelimeler = new List<string>();
        int toplamSoruSayisi;


        
        public Form2()
        {
            InitializeComponent();
            
           
        }


        private void Form2_Load(object sender, EventArgs e)
        {
            string[] dosyalar = Directory.GetFiles(Application.StartupPath, "*.txt");
            List<string> turkceKelimeler = new List<string>();
            List<string> ingilizceKelimeler = new List<string>();


            foreach (string dosya in dosyalar)
            {
                string dosya_adi = Path.GetFileNameWithoutExtension(dosya);
                if (SeciliDosya == dosya_adi)
                {

                    string[] kelimeCiftleri = File.ReadAllLines(dosya);

                    foreach (string kelime_cifti in kelimeCiftleri)
                    {
                        string[] kelimeler = kelime_cifti.Split('\t');
                        ingilizceKelimeler.Add(kelimeler[0]);
                        turkceKelimeler.Add(kelimeler[1]);
                        toplamSoruSayisi = ingilizceKelimeler.Count();
                    }
                }
            }


            Random rnd = new Random();
            int rastgeleIndex = rnd.Next(ingilizceKelimeler.Count());
            List<string> secenekler = new List<string>();
            richTextBox2.SelectAll();
            richTextBox2.SelectionAlignment = HorizontalAlignment.Center;
            richTextBox2.Text = ingilizceKelimeler[rastgeleIndex];
            soru = ingilizceKelimeler[rastgeleIndex];
            secilmisKelimeler.Add(soru);
            dogruCevap = turkceKelimeler[rastgeleIndex];
            secenekler.Add(dogruCevap);

            string secenek2, secenek3, secenek4;

            do
            {
                Random rnd2 = new Random();
                secenek2 = turkceKelimeler[rnd2.Next(turkceKelimeler.Count())];
            } while (secenekler.Contains(secenek2));
            secenekler.Add(secenek2);

            do
            {
                Random rnd3 = new Random();
                secenek3 = turkceKelimeler[rnd3.Next(turkceKelimeler.Count())];
            } while (secenekler.Contains(secenek3));
            secenekler.Add(secenek3);

            do
            {
                Random rnd4 = new Random();
                secenek4 = turkceKelimeler[rnd4.Next(turkceKelimeler.Count())];
            } while (secenekler.Contains(secenek4));
            secenekler.Add(secenek4);

            int button1Index;
            int button2Index;
            int button3Index;
            int button4Index;
            List<int> buttonList = new List<int>();

            do
            {
                Random rnd5 = new Random();
                button1Index = rnd5.Next(4);
            } while (buttonList.Contains(button1Index));
            buttonList.Add(button1Index);
            do
            {
                Random rnd6 = new Random();
                button2Index = rnd6.Next(4);
            } while (buttonList.Contains(button2Index));
            buttonList.Add(button2Index);
            do
            {
                Random rnd7 = new Random();
                button3Index = rnd7.Next(4);
            } while (buttonList.Contains(button3Index));
            buttonList.Add(button3Index);
            do
            {
                Random rnd8 = new Random();
                button4Index = rnd8.Next(4);
            } while (buttonList.Contains(button4Index));
            buttonList.Add(button4Index);

            button1.BackColor = Color.White;
            button2.BackColor = Color.White;
            button3.BackColor = Color.White;
            button4.BackColor = Color.White;
            button1.Text = secenekler[buttonList[0]];
            button2.Text = secenekler[buttonList[1]];
            button3.Text = secenekler[buttonList[2]];
            button4.Text = secenekler[buttonList[3]];



            richTextBox1.Text = soruSayisi.ToString() + " / " + toplamSoruSayisi.ToString() + "                                                                           " + dogruCevapSayisi.ToString();


        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (button1.Text != dogruCevap) 
            { 
                button1.BackColor = Color.Red;
               
            }
            else
            {
                dogruCevapSayisi += 1;
                soruSayisi += 1;
                Form2_Load(sender, e);

            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (button2.Text != dogruCevap)
            {
                button2.BackColor = Color.Red;
               
            }
            else
            {
                dogruCevapSayisi += 1;
                soruSayisi += 1;
                Form2_Load(sender, e);
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (button3.Text != dogruCevap)
            {
                button3.BackColor = Color.Red;
                
               

            }
            else
            {
                dogruCevapSayisi += 1;
                soruSayisi += 1;
                Form2_Load(sender, e);
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if (button4.Text != dogruCevap)
            {
                button4.BackColor = Color.Red;
                
            }
            else
            {
                dogruCevapSayisi += 1;
                soruSayisi += 1;
                Form2_Load(sender, e);
            }
        }
    }
}

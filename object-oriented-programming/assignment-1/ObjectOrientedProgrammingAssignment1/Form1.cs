using System;
using System.Collections.Generic;


namespace NesneyeDayalıProgramlamaÖdevi1
{



    public partial class Form1 : Form
    {

        // Menü sıfından m nesnesi oluşturma
        Menu m = new Menu();
        double hesap;
     
        public Form1()
        {
            InitializeComponent();
        }

        /*
       
        private void Form1_Load(object sender, EventArgs e)
        {

          
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
        */ 
        



        private void button1_Click(object sender, EventArgs e)
        {
            /// tüm kutucukların boş veya boşluk olup olmadığını kontrol etme ve uyarı mesajı
            if (string.IsNullOrWhiteSpace(textBox1.Text) && string.IsNullOrWhiteSpace(textBox2.Text) && string.IsNullOrWhiteSpace(textBox3.Text) && string.IsNullOrWhiteSpace(textBox4.Text) && string.IsNullOrWhiteSpace(textBox5.Text) && string.IsNullOrWhiteSpace(comboBox1.Text))
            {
                MessageBox.Show("Lütfen Tüm Bilgileri Eksiksiz Giriniz!");
            }
            else
            {
                // yiyecek sınıfından s nesnesini oluşturma
                Yiyecek s = new Yiyecek();

                // sayı girilen textboxların verilerini double veri türüne çevirme
                double s2, s3, s4;
                double.TryParse(textBox3.Text, out s2); double.TryParse(textBox2.Text, out s3); double.TryParse(textBox5.Text, out s4);
                if (double.TryParse(textBox3.Text, out s2) && double.TryParse(textBox2.Text, out s3) && double.TryParse(textBox5.Text, out s4))
                {
                    
                    // comboboxda seçilen yiyecek türünü kontol etme
                    switch (comboBox1.Text)
                    {
                        case "içecek":
                            // kalori ve fiyat bilgilerini kontrol etme
                            if(s4 >= 700 || s4 <= 0)
                            {
                                MessageBox.Show("Bir İçecek İçin Kalori Aralığı 0-700 Arasıdır!");
                            }
                            if (s2 <= 10 || s2 >= 150)
                            {
                                MessageBox.Show("Bir İçecek İçin Fiyat Aralığı 10-150 TL dir!");
                            }
                            Icecek icecek = new Icecek(textBox1.Text, textBox4.Text, s2, s3, s4);
                            s = (Yiyecek)icecek;
                            m.ekle(s);
                            break;

                        case "meyve":
                            // kalori ve fiyat bilgilerini kontrol etme
                            if (s4 >= 500 || s4 <= 30)
                            {
                                MessageBox.Show("Bir Meyve İçin Kalori Aralığı 30 - 500 Arasıdır!");
                                break;
                            }
                            if (s2 <= 10 || s2 >= 90)
                            {
                                MessageBox.Show("Bir Meyve İçin Fiyat Aralığı 10-90 TL dir!");
                                break;
                            }
                            Meyve meyve = new Meyve(textBox1.Text, textBox4.Text, s2, s3, s4);
                            s = (Yiyecek)meyve;
                            m.ekle(s);
                            break;
                        case "tatlı":
                            // kalori ve fiyat bilgilerini kontrol etme
                            if (s4 >= 1000 || s4 <= 50)
                            {
                                MessageBox.Show("Bir Tatlı İçin Kalori Aralığı 50-1000 Arasıdır!");
                                break;
                            }
                            if (s2 <= 50 || s2 >= 800)
                            {
                                MessageBox.Show("Bir Tatlı İçin Fiyat Aralığı 50-800 TL dir!");
                                break;
                            }
                            Tatli tatli = new Tatli(textBox1.Text, textBox4.Text, s2, s3, s4);
                            s = (Yiyecek)tatli;
                            m.ekle(s);
                            break;
                        case "salata":
                            // kalori ve fiyat bilgilerini kontrol etme
                            if (s4 >= 900 || s4 <= 50)
                            {
                                MessageBox.Show("Bir Salata İçin Kalori Aralığı 50-900 Arasıdır!");
                                break;
                            }
                            
                            if(s2 <= 200 || s2 >= 400)
                            {
                                MessageBox.Show("Bir Salata İçin Fiyat Aralığı 200-400 TL dir!");
                                break;
                            }
                            Salata salata = new Salata(textBox1.Text, textBox4.Text, s2, s3, s4);
                            s = (Yiyecek)salata;
                            m.ekle(s);
                            break;
                        default:
                            break;
                    }
                    // menu sınıfında oluşturulan liste elemanlarını listboxda yazdırma ve tutarın yazdırılması
                    if (m.menuYazdir().Count != 0)
                    {
                        List<Yiyecek> menuEleman = m.menuYazdir();
                        listBox1.Items.Add(menuEleman[menuEleman.Count - 1].yazdir());
                        hesap += menuEleman[menuEleman.Count - 1].fiyat;
                        textBox6.Text = "Tutar: " + hesap;
                    }
                }
                else
                {
                    MessageBox.Show("Lütfen Geçerli Değerler Giriniz!");
                }

            }

        }

        //sil butonu 
        private void button2_Click(object sender, EventArgs e)
        {
            foreach(int sayi in listBox1.SelectedIndices)
            {
                hesap -= m.menuYazdir()[sayi].fiyat;
                m.sil(sayi);
                listBox1.Items.RemoveAt(sayi);
            }
            
            textBox6.Text = "Tutar: " + hesap;
            
        }
    }

    class Yiyecek
    {
        public string adi;
        public string cins;
        public double fiyat;
        public double kdvOrani;

        public Yiyecek() { adi = ""; cins = ""; fiyat = 0; kdvOrani = 0; }

        public Yiyecek(string a, string c, double f, double kdv) { adi = a; cins = c; fiyat = f; kdvOrani = kdv; }

        public virtual string yazdir()
        {
            String data = String.Format("{0, 10} {1, 10} {2, 10} {3, 10}", adi, cins, fiyat, kdvOrani);
            return data;
        }
    }

    class Meyve : Yiyecek
    {
        public double kalori;
        public Meyve():base() { kalori = 0; }
        public Meyve(string a, string c, double f, double kdv, double cal):base(a, c, f, kdv) { kalori = cal; }

        public override string yazdir()
        {
            string dataMeyve = base.yazdir() + String.Format("{0, 5}", kalori);

            return dataMeyve ;
        }

    }

    class Tatli : Yiyecek
    {

        public double kalori;

        public Tatli() :base() { kalori = 0; }
        public Tatli(string a, string c, double f, double kdv, double cal) : base(a, c, f, kdv) { kalori = cal; }

        public override string yazdir()
        {
            string dataTatli = base.yazdir() + String.Format("{0, 5}", kalori);

            return dataTatli;
        }

    }
    
    class Salata : Yiyecek
    {
        public double kalori;
        public Salata() : base() { kalori = 0; }
        public Salata(string a, string c, double f, double kdv, double cal) : base(a, c, f, kdv) { kalori = cal; }

        public override string yazdir()
        {
            string dataSalata = base.yazdir() + String.Format("{0, 5}", kalori); 

            return dataSalata;
        }
    }

    class Icecek : Yiyecek
    {
        public double kalori;

        public Icecek() : base() { kalori = 0; }
        public Icecek(string a, string c, double f, double kdv, double cal) : base(a, c, f, kdv){ kalori = cal; }

        public override string yazdir()
        {
            string dataIcecek = base.yazdir() + String.Format("{0,5}", kalori);

            return dataIcecek;
        }
    }

    class Menu
    {
        public List<Yiyecek> liste;

        public Menu() { liste = new List<Yiyecek>(); }


        public void ekle(Yiyecek y)
        {
            liste.Add(y);
        }

        public void sil(int indeks)
        {
            liste.RemoveAt(indeks);
        }

        public List<Yiyecek> menuYazdir() 
        {
            return liste;
        }

    }

}

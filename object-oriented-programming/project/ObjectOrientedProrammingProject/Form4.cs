/*****************************************************
**         SAKARYA ÜNİVERSİTESİ
*       BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**      BİLGİSAYAR MÜHENDİLİĞİ BÖLÜMÜ
**      NESNEYE DAYALI PROGRAMLAMA
**      2024-2025 BAHAR DÖNEMİ
**
**      ÖDEV NUMARASI:3
*       ÖDEV NUMARASI.......:B241210370
**      ÖĞRENCİ ADI.........:RÜMEYSA CERAN
**      DERSİN ALDIĞI GRUP..:B
**
************************************************/



using B241210370_PROJE_.MODEL;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics.Eventing.Reader;
using System.DirectoryServices.ActiveDirectory;
using System.Drawing;
using System.Linq;
using System.Linq.Expressions;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Runtime.InteropServices.JavaScript.JSType;

namespace B241210370_PROJE_
{

    public partial class Form4 : Form
    {


        int daireSayisi = 0;
       
     
        Form1 form1ref;
        Form3 form3ref;
        public Form4(Form1 form1, Form3 form3)
        {
            InitializeComponent();
            form1ref = form1;
            form3ref = form3;
        }

        private void Form4_Load(object sender, EventArgs e)
        {
        }


        //Geri butonu tüm aracları gizler
        private void button2_Click(object sender, EventArgs e)
        {
            if (button1.Visible)
            {
                this.Hide();
                form1ref.Show();

            }
            else
            {
                comboBox1.SelectedIndex = -1;
                comboBox1.Visible = true;
                foreach (Control arac in panel1.Controls)
                {
                    arac.Visible = false;
                    if (arac is TextBox)
                    {
                        ((TextBox)arac).Text = "";
                    }
                    else if (arac is ComboBox)
                    {
                        ((ComboBox)arac).SelectedIndex = -1;

                    }
                    else if (arac is GroupBox)
                    {
                        foreach (Control arac2 in ((GroupBox)arac).Controls)
                        {

                        }

                    }
                    else if (arac is NumericUpDown)
                    {
                        ((NumericUpDown)arac).Value = ((NumericUpDown)arac).Minimum;
                    }
                    else if (arac is Label)
                    {
                        ((Label)arac).Text = "";
                    }

                    else if (arac is ListBox)
                    {
                        ((ListBox)arac).Items.Clear();
                    }

                    else if (arac is DateTimePicker)
                    {
                        ((DateTimePicker)arac).Checked = false;
                    }
                    button1.Visible = true;
                    button4.Hide();
                }
            }


        }

        //ileri butonu
        private void button1_Click(object sender, EventArgs e)
        {

            //tüm aracların görünürlüğünün kontolü için fonksiyonlar
            void görünürYap(params Control[] araclar)
            {
                foreach (var arac in araclar)
                {
                    arac.Visible = true;
                }
            };

            void görünmezYap(params Control[] araclar)
            {
                foreach (var arac in araclar)
                {
                    arac.Visible = false;
                }
            }

            //comboboxda daire seçimi için max daire ve bina no belirleme
            void BinaveDaireMaxBelirle(NumericUpDown numeric1, NumericUpDown numeric2)
            {
                int binaNoMax = 0;
                for (daireSayisi = 0; daireSayisi < OrtakNesneler.daireler.Count(); daireSayisi++)
                {
                    int a;

                    a = OrtakNesneler.daireler[daireSayisi].binaNo;
                    if (a > binaNoMax)
                    {
                        binaNoMax = a;
                    }
                }

                int daireNoMax = 0;
                for (daireSayisi = 0; daireSayisi < OrtakNesneler.daireler.Count(); daireSayisi++)
                {
                    int b;

                    b = OrtakNesneler.daireler[daireSayisi].daireNo;
                    if (b > daireNoMax)
                    {
                        daireNoMax = b;
                    }
                }
                numeric1.Maximum = binaNoMax;
                numeric2.Maximum = daireNoMax;

            }
          
            switch (comboBox1.SelectedIndex)
            {
                //oluştur menünü
                case 0:
                    if (OrtakNesneler.daireler.Count() == 0)
                    {
                        MessageBox.Show("Sitede hiç kayıtlı daire bulunmamaktadır, önce MEKAN/EKLE menüsüne gitmelisiniz");
                    }
                    else
                    {
                        button4.Text = "OLUŞTUR";
                        label2.Text = "Kaydı oluşturulacak kişi ismi:";
                        label3.Text = "Kaydı oluşturulacak kişi soyismi:";
                        label4.Text = "Kaydı oluşturulacak kişi bina no:";
                        label5.Text = "Kaydı oluşturulacak kişi daire no:";
                        radioButton4.Text = "Misafir";
                        radioButton3.Text = "Aile Reisi";
                        groupBox2.Text = "Kişi Tip:";
                        BinaveDaireMaxBelirle(numericUpDown1, numericUpDown2);
                        görünmezYap(label1, label6, label7, label8, label9, textBox3, textBox4, numericUpDown2, numericUpDown3, button1, radioButton1, radioButton2, comboBox1, comboBox2, comboBox3, dateTimePicker1);
                        görünürYap(label2, label3, label4, label5, textBox1, textBox2, numericUpDown1, numericUpDown2, button4, button2, radioButton3, radioButton4, groupBox2);
                    }
                    break;
                case 1:
                    if (OrtakNesneler.oturanlar.Count() == 0)
                    {
                        MessageBox.Show("Sitede hiç kayıtlı kişi bulunmamaktadır, önce OLUŞTUR menüsüne gitmelisiniz!");

                    }
                    else if (OrtakNesneler.daireler.Count() == 0)
                    {
                        MessageBox.Show("Sitede hiç kayıtlı daire bulunmamaktadır, önce MEKAN/EKLE menüsüne gitmelisiniz");
                    }
                    //Sil menüsü
                    else
                    {
                        button4.Text = "SİL";
                        label2.Text = "Kaydı silinecek kişi ismi:";
                        label3.Text = "Kaydı silinecek kişi soyismi:";
                        label4.Text = "Kaydı silinecek kişi bina no:";
                        label5.Text = "Kaydı silinecek kişi daire no:";
                        radioButton4.Text = "Misafir";
                        radioButton3.Text = "Aile Reisi";
                        groupBox2.Text = "Kişi Tipi:";
                       //comboboxda isim seçerken listedeki isimlerin çıkmasını sağlar
                        foreach (Oturan oturan in OrtakNesneler.oturanlar)
                        {
                            if (!comboBox2.Items.Contains(oturan.ad))
                            { comboBox2.Items.Add(oturan.ad); }
                            if (!comboBox3.Items.Contains(oturan.soyad))
                            { comboBox3.Items.Add(oturan.soyad); }
                        }
                        BinaveDaireMaxBelirle(numericUpDown1, numericUpDown2);
                        görünmezYap(label1, label6, label7, label8, label9, textBox3, textBox4, numericUpDown4, numericUpDown3, button1, radioButton1, radioButton2, comboBox1, textBox1, textBox2, dateTimePicker1);
                        görünürYap(label2, label3, label4, label5, comboBox2, comboBox3, numericUpDown1, numericUpDown2, button4, button2, radioButton3, radioButton4, groupBox2);
                    }

                    break;
                case 2:
                    if (OrtakNesneler.oturanlar.Count() == 0)
                    {
                        MessageBox.Show("Sitede hiç kayıtlı kişi bulunmamaktadır, önce OLUŞTUR menüsüne gitmelisiniz!");

                    }
                    else if (OrtakNesneler.daireler.Count() == 0)
                    {
                        MessageBox.Show("Sitede hiç kayıtlı daire bulunmamaktadır, önce MEKAN/EKLE menüsüne gitmelisiniz");
                    }
                    else
                    {
                        button4.Text = "GÜNCELLE";
                        label2.Text = "Kaydı güncellenecek kişi ismi:";
                        label3.Text = "Kaydı güncellencek kişi soyismi:";
                        label4.Text = "Kaydı güncellencek kişi bina no:";
                        label5.Text = "Kaydı güncellenecek kişi daire no:";
                        label6.Text = "Yeni isim:";
                        label7.Text = "Yeni soyisim:";
                        label8.Text = "Yeni bina no:";
                        label9.Text = "Yeni daire  no:";
                        radioButton4.Text = "Misafir";
                        radioButton3.Text = "Aile Reisi";
                        radioButton1.Text = "Aile Reisi";
                        radioButton2.Text = "Misafir";
                        groupBox1.Text = "Güncellenecek kişi tip:";
                        groupBox2.Text = "Yeni kişi tip:";
                        BinaveDaireMaxBelirle(numericUpDown1, numericUpDown2);
                        BinaveDaireMaxBelirle(numericUpDown3, numericUpDown4);
                        foreach (Oturan oturan in OrtakNesneler.oturanlar)
                        {
                            if (!comboBox2.Items.Contains(oturan.ad))
                            { comboBox2.Items.Add(oturan.ad); }
                            if (!comboBox3.Items.Contains(oturan.soyad))
                            { comboBox3.Items.Add(oturan.soyad); }
                        }

                        görünmezYap(label1, button1, comboBox1, textBox1, textBox2, dateTimePicker1);
                        görünürYap(label2, label3, label4, label5, label6, label7, label8, label9, comboBox2, comboBox3, textBox3, textBox4, button4, numericUpDown1, numericUpDown2, numericUpDown3, numericUpDown4, button2, radioButton1, radioButton2, radioButton3, radioButton4, groupBox2, groupBox3);
                    }

                    break;
                case 3:
                    button1.Hide();
                    if (OrtakNesneler.oturanlar.Count() == 0)
                    {
                        MessageBox.Show("Sitede hiç kayıtlı kişi bulunmamaktadır, önce OLUŞTUR menüsüne gitmelisiniz!");
                    }
                    else if (OrtakNesneler.daireler.Count() == 0)
                    {
                        MessageBox.Show("Sitede hiç kayıtlı daire bulunmamaktadır, önce MEKAN/EKLE menüsüne gitmelisiniz");
                    }
                    else
                    {
                        
                        foreach(Oturan oturan in OrtakNesneler.oturanlar)
                        {
                            listBox1.Items.Add("kisi tipi: " + oturan.kisi_tipi + " " +"isim: " + oturan.ad + " " + "soyisim: " + oturan.soyad + " " + "bina no: " + oturan.binaNo + " " + "daire no: "+ oturan.daireNo + " " + "havuz kaydı: " + oturan.havuzKaydi +" " + "fitness kaydı: " + oturan.fitnessKaydi);
                        }
                        listBox1.Visible = true;

                    }
                    break;
                case 4:
                    if (OrtakNesneler.oturanlar.Count() == 0)
                    {
                        MessageBox.Show("Sitede hiç kayıtlı kişi bulunmamaktadır, önce OLUŞTUR menüsüne gitmelisiniz!");
                    }
                    else if (OrtakNesneler.daireler.Count() == 0)
                    {
                        MessageBox.Show("Sitede hiç kayıtlı daire bulunmamaktadır, önce MEKAN/EKLE menüsüne gitmelisiniz");
                    }
                    else
                    {
                        button4.Text = "KAYDET";
                        label2.Text = "İsim:";
                        label3.Text = "Soyisim:";
                        label4.Text = "Bina no:";
                        label5.Text = "Daire no:";
                        radioButton1.Text = "Havuz Kaydı";
                        radioButton2.Text = "Fitness Kaydı";
                        groupBox2.Text = "Kişi Tipi";
                        groupBox3.Text = "Kayıt Tipi:";
                        BinaveDaireMaxBelirle(numericUpDown1, numericUpDown2);
                        foreach (Oturan oturan in OrtakNesneler.oturanlar)
                        {
                            if (!comboBox2.Items.Contains(oturan.ad))
                            { comboBox2.Items.Add(oturan.ad); }
                            if (!comboBox3.Items.Contains(oturan.soyad))
                            { comboBox3.Items.Add(oturan.soyad); }
                        }
                        görünmezYap(label1, label6, label7, label8, label9, numericUpDown3, numericUpDown4, button1, comboBox1, textBox1, textBox2, textBox3, textBox4, dateTimePicker1);
                        görünürYap(label2, label3, label4, label5, comboBox2, comboBox3, numericUpDown1, numericUpDown2, radioButton1, radioButton2, button4, button2, groupBox3, radioButton3, radioButton4, groupBox2);
                    }
                    break;
                case 5:
                    if (OrtakNesneler.oturanlar.Count() == 0)
                    {
                        MessageBox.Show("Sitede hiç kayıtlı kişi bulunmamaktadır, önce OLUŞTUR menüsüne gitmelisiniz!");

                    }
                    else
                    {
                        button4.Text = "KULLAN";
                        label2.Text = "İsim:";
                        label3.Text = "Soyisim:";
                        label4.Text = "Bina no:";
                        label5.Text = "Daire no:";
                        radioButton1.Text = "Havuz Kullan";
                        radioButton2.Text = "Fitness Salonu Kullan";
                        groupBox2.Text = "Kişi Tipi";
                        groupBox3.Text = "Kayıt Tipi";
                        radioButton3.Text = "aile-reisi";
                        radioButton4.Text = "misafir";
                        BinaveDaireMaxBelirle(numericUpDown1, numericUpDown2);
                        foreach (Oturan oturan in OrtakNesneler.oturanlar)
                        {
                            if (!comboBox2.Items.Contains(oturan.ad))
                            { comboBox2.Items.Add(oturan.ad); }
                            if (!comboBox3.Items.Contains(oturan.soyad))
                            { comboBox3.Items.Add(oturan.soyad); }
                        }
                        görünmezYap(label1, label6, label7, label8, label9, numericUpDown3, numericUpDown4, button1, comboBox1, textBox1, textBox2, textBox3, textBox4);
                        görünürYap(label2, label3, label4, label5, comboBox2, comboBox3, numericUpDown1, numericUpDown2, radioButton1, radioButton2, button4, button2, groupBox3, radioButton3, radioButton4, groupBox2, dateTimePicker1);

                    }
                    break;
                default:
                    MessageBox.Show("Lütfen bir seçenek seçiniz!");
                    break;
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {

            string kisiIsmi;
            string kisiSoyismi;
            bool kisiBulundu = false;
            int binaNo = (int)numericUpDown1.Value;
            int daireNo = (int)numericUpDown2.Value;
            string kisiTipi = "";
            bool daireVar = false;
            if (radioButton3.Checked)
            {
                kisiTipi = "aile-reisi";
            }
            else if (radioButton4.Checked)
            {
                kisiTipi = "misafir";
            }

            switch (comboBox1.SelectedIndex)
            {
                case 0:

                    kisiBulundu = false;
                    kisiIsmi = textBox1.Text;
                    kisiSoyismi = textBox2.Text;
                    daireVar = false;
                    foreach (Mekan mekan in OrtakNesneler.mekanlar)
                    {
                        if (mekan is Daire)
                        {
                            Daire daire = (Daire)mekan;
                            if (daire.binaNo == binaNo && daire.daireNo == daireNo)
                            {
                                daireVar = true;
                            }
                        }
                    }
                    if (!daireVar)
                    {
                        MessageBox.Show("Kayıtlarda böyle bir daire bulunmamaktadır!");
                        break;
                    }

                    else if ((!radioButton3.Checked) && (!radioButton4.Checked))
                    {
                        MessageBox.Show("Lütfen misafir ve aile seçeneklerinden birini seçiniz!");
                        break;
                    }
                    try
                    {

                        if (radioButton3.Checked)
                        {

                            AileReisi aileReisi = new AileReisi(kisiIsmi, kisiSoyismi, binaNo, daireNo);
                            if (OrtakNesneler.oturanlar.Contains(aileReisi))
                            {
                                MessageBox.Show("Bu kişi zaten kayıtlarda bulunmaktadır!");
                                break;
                            }

                            else
                            {
                                OrtakNesneler.oturanlar.Add(aileReisi);
                                kisiBulundu = true;
                            }

                        }
                        else if (radioButton4.Checked)
                        {

                            Misafir misafir = new Misafir(kisiIsmi, kisiSoyismi, binaNo, daireNo);
                            if (OrtakNesneler.oturanlar.Contains(misafir))
                            {
                                MessageBox.Show("Bu kişi zaten kayıtlarda bulunmaktadır!");
                                break;
                            }
                            else
                            {
                                OrtakNesneler.oturanlar.Add(misafir);
                                kisiBulundu = true;
                            }

                        }


                        if (!kisiBulundu)
                        {
                            MessageBox.Show("Kayıtlarda böyle bir kişi bulunmamaktadır!");
                        }
                        else
                        {   
                            //bir kişi eklendiğinde kişi mekan.txt de de ilgili yerlerde kişi sayısı arttırılır
                            for (int mekanIndex = OrtakNesneler.mekanlar.Count() - 1; mekanIndex >= 0; mekanIndex--)
                            {
                                if (OrtakNesneler.mekanlar[mekanIndex] is Daire)
                                {
                                    Daire daire = (Daire)OrtakNesneler.mekanlar[mekanIndex];

                                    if (daire.binaNo == binaNo && daire.daireNo == daireNo)
                                    {
                                        daire.kisiSayisiArttir();
                                    }

                                }

                            }
                            OrtakNesneler.DataDosyasınıYaz();
                            OrtakNesneler.MekanDosyasınıYaz();
                            MessageBox.Show("Oluştur işkemi başarıyla gerçekleşmiştir!");
                        }
                    }
                    catch
                    {
                        MessageBox.Show("Oluştur işlemi gerçekleştirilememiştir!");
                    }

                    break;
                case 1:
                    kisiIsmi = comboBox2.Text;
                    kisiSoyismi = comboBox3.Text;
                    kisiBulundu = false;

                    if ((!radioButton3.Checked) && (!radioButton4.Checked))
                    {
                        MessageBox.Show("Lütfen misafir ve aile seçeneklerinden birini seçiniz!");
                    }
                    else
                    {
                         try
                         {

                            for (int i = OrtakNesneler.oturanlar.Count() - 1; i >= 0; i--)
                            {

                                if (OrtakNesneler.oturanlar[i].kisi_tipi == kisiTipi && OrtakNesneler.oturanlar[i].ad == kisiIsmi && OrtakNesneler.oturanlar[i].soyad == kisiSoyismi && OrtakNesneler.oturanlar[i].binaNo == binaNo && OrtakNesneler.oturanlar[i].daireNo == daireNo)
                                {

                                    for (int mekanIndex = OrtakNesneler.mekanlar.Count() - 1; mekanIndex >= 0; mekanIndex--)
                                    {
                                        if (OrtakNesneler.mekanlar[mekanIndex] is Daire)
                                        {
                                            Daire daire = (Daire)OrtakNesneler.mekanlar[mekanIndex];
                                            if (daire.binaNo == binaNo && daire.daireNo == daireNo)
                                            {
                                                daire.kisiSayisi -= 1;
                                            }

                                        }
                                        else if (OrtakNesneler.mekanlar[mekanIndex].binaNo == binaNo)
                                        {
                                            if (OrtakNesneler.oturanlar[i].havuzKaydi == "yapıldı")
                                            {
                                                if (OrtakNesneler.mekanlar[mekanIndex] is Havuz)
                                                {
                                                    OrtakNesneler.mekanlar[mekanIndex].kisiSayisi -= 1;
                                                }
                                            }
                                            if (OrtakNesneler.oturanlar[i].fitnessKaydi == "yapıldı")
                                            {
                                                if (OrtakNesneler.mekanlar[mekanIndex] is Fitness)
                                                {
                                                    OrtakNesneler.mekanlar[mekanIndex].kisiSayisi -= 1;
                                                }
                                            }
                                        }

                                    }
                                    OrtakNesneler.oturanlar.RemoveAt(i);
                                    kisiBulundu = true;

                                }

                            }

                            if (!kisiBulundu)
                            { MessageBox.Show("Kayıtlarda Böyle bir kişi bulunmamaktadır!"); }
                            else
                            {

                                OrtakNesneler.DataDosyasınıYaz();
                                OrtakNesneler.MekanDosyasınıYaz();
                                MessageBox.Show("Silme işlemi başarıyla gerçekleştirildi!");
                            }

                         }                       
                         catch
                         {
                            MessageBox.Show("Silme işlemi gerçekleştirilemedi");
                          }
                    }                   
                   
                   
                    break;
                case 2:

                    string yeniIsim = textBox3.Text;
                    string yeniSoyIsim = textBox4.Text;
                    int yeniBinaNo = (int)numericUpDown3.Value;
                    int yeniDaireNo = (int)numericUpDown4.Value;
                    kisiIsmi = comboBox2.Text;
                    kisiSoyismi = comboBox3.Text;
                    daireVar = false;
                    bool kisiBulundu2 = false;

                    if (((!radioButton1.Checked) && (!radioButton2.Checked)) || ((!radioButton3.Checked) && (!radioButton4.Checked)))
                    {
                        MessageBox.Show("Lütfen \" Misafir \" veya \" Aile Reisi \" seçeneklerinden birini seçiniz!");
                    }
                    else
                    {

                        foreach (Mekan mekan in OrtakNesneler.mekanlar)
                        {
                            if (mekan is Daire)
                            {
                                Daire daire = (Daire)mekan;
                                if (daire.binaNo == binaNo && daire.daireNo == daireNo)
                                {
                                    daireVar = true;
                                }
                            }
                        }
                        try
                        {
                            if (!daireVar)
                            {
                                MessageBox.Show("Kayıtlarda böyle bir daire bulunmamaktadır!");
                                break;
                            }
                            else
                            {
                                for (int i = 0; i < OrtakNesneler.oturanlar.Count(); i++)
                                {
                                    if (OrtakNesneler.oturanlar[i].ad == yeniIsim && OrtakNesneler.oturanlar[i].soyad == yeniSoyIsim && OrtakNesneler.oturanlar[i].binaNo == yeniBinaNo && OrtakNesneler.oturanlar[i].daireNo == yeniDaireNo)
                                    {
                                        if ((radioButton3.Checked && OrtakNesneler.oturanlar[i].kisi_tipi == "aile-reisi") || (radioButton4.Checked && OrtakNesneler.oturanlar[i].kisi_tipi == "misafir"))
                                        {
                                            kisiBulundu2 = true;
                                            break;
                                        }
                                    }
                                    else if (OrtakNesneler.oturanlar[i].kisi_tipi == kisiTipi && OrtakNesneler.oturanlar[i].ad == kisiIsmi && OrtakNesneler.oturanlar[i].soyad == kisiSoyismi && OrtakNesneler.oturanlar[i].binaNo == binaNo && OrtakNesneler.oturanlar[i].daireNo == daireNo)
                                    {


                                        if (radioButton1.Checked)
                                        {
                                            OrtakNesneler.oturanlar[i].kisi_tipi = "aile-reisi";
                                        }
                                        else
                                        {
                                            OrtakNesneler.oturanlar[i].kisi_tipi = "misafir";
                                        }
                                        OrtakNesneler.oturanlar[i].ad = yeniIsim;
                                        OrtakNesneler.oturanlar[i].soyad = yeniSoyIsim;
                                        OrtakNesneler.oturanlar[i].binaNo = yeniBinaNo;
                                        OrtakNesneler.oturanlar[i].daireNo = yeniDaireNo;

                                        for (int mekanIndex = OrtakNesneler.mekanlar.Count() - 1; mekanIndex >= 0; mekanIndex--)
                                        {
                                            if (OrtakNesneler.mekanlar[mekanIndex] is Daire)
                                            {
                                                Daire daire = (Daire)OrtakNesneler.mekanlar[mekanIndex];
                                                if (daire.binaNo == binaNo && daire.daireNo == daireNo)
                                                {
                                                    daire.kisiSayisi -= 1;
                                                }
                                                else if(daire.daireNo == yeniDaireNo && daire.binaNo == yeniBinaNo )
                                                {
                                                    daire.kisiSayisiArttir();
                                                }
                                            }
                                            else if (OrtakNesneler.mekanlar[mekanIndex].binaNo == binaNo)
                                            {
                                                if (OrtakNesneler.oturanlar[i].havuzKaydi == "yapıldı")
                                                {
                                                    if (OrtakNesneler.mekanlar[mekanIndex] is Havuz)
                                                    {
                                                        OrtakNesneler.mekanlar[mekanIndex].kisiSayisi -= 1;
                                                    }
                                                    
                                                }
                                                if (OrtakNesneler.oturanlar[i].fitnessKaydi == "yapıldı")
                                                {
                                                    if (OrtakNesneler.mekanlar[mekanIndex] is Fitness)
                                                    {
                                                        OrtakNesneler.mekanlar[mekanIndex].kisiSayisi -= 1;
                                                    }
                                                }
                                            }
                                            else if(OrtakNesneler.mekanlar[mekanIndex].binaNo == yeniBinaNo)
                                            {
                                                if (OrtakNesneler.oturanlar[i].havuzKaydi == "yapıldı")
                                                {
                                                    if (OrtakNesneler.mekanlar[mekanIndex] is Havuz)
                                                    {
                                                        OrtakNesneler.mekanlar[mekanIndex].kisiSayisiArttir();
                                                    }

                                                }
                                                if (OrtakNesneler.oturanlar[i].fitnessKaydi == "yapıldı")
                                                {
                                                    if (OrtakNesneler.mekanlar[mekanIndex] is Fitness)
                                                    {
                                                        OrtakNesneler.mekanlar[mekanIndex].kisiSayisiArttir();
                                                    }
                                                }
                                            }

                                        }
                                        OrtakNesneler.oturanlar.RemoveAt(i);
                                        kisiBulundu = true;
                                    }

                                }
                                if (!kisiBulundu)
                                {
                                    MessageBox.Show(" Kayıtlarda böyle bir kişi bulunmamaktadır! ");
                                }
                                else if (kisiBulundu2)
                                {
                                    MessageBox.Show("Kayıtlarda zaten böyle bir kişi bulunmaktadır!");
                                }
                                else
                                {
                                    OrtakNesneler.DataDosyasınıYaz();


                                    for (int mekanIndex = OrtakNesneler.mekanlar.Count() - 1; mekanIndex >= 0; mekanIndex--)
                                    {
                                        if (OrtakNesneler.mekanlar[mekanIndex].binaNo == binaNo)
                                        {
                                            OrtakNesneler.mekanlar[mekanIndex].kisiSayisi -= 1;
                                        }
                                        else if (OrtakNesneler.mekanlar[mekanIndex].binaNo == yeniBinaNo)
                                        {
                                            OrtakNesneler.mekanlar[mekanIndex].kisiSayisiArttir();
                                        }
                                    }
                                    OrtakNesneler.MekanDosyasınıYaz();
                                    MessageBox.Show("Güncelleme işlemi  başarıyla gerçekleştirilmiştir!");

                                }
                            }
                        }
                        catch(Exception er)
                        {
                            MessageBox.Show("Güncelleme işlemi gerçekleştirilemedi");
                        }
                                              
                    }

                    break;
                case 4:

                    kisiIsmi = comboBox2.Text;
                    kisiSoyismi = comboBox3.Text;

                    if (((!radioButton1.Checked) && (!radioButton2.Checked)) || ((!radioButton3.Checked) && (!radioButton4.Checked)))
                    {
                        MessageBox.Show("Lütfen misafir ve aile seçeneklerinden birini seçiniz!");
                    }
                    else
                    {
                        try
                        {
                            for (int i = OrtakNesneler.oturanlar.Count - 1; i >= 0; i--)
                            {
                                if (OrtakNesneler.oturanlar[i].kisi_tipi == kisiTipi && OrtakNesneler.oturanlar[i].ad == kisiIsmi && OrtakNesneler.oturanlar[i].soyad == kisiSoyismi && OrtakNesneler.oturanlar[i].binaNo == binaNo && OrtakNesneler.oturanlar[i].daireNo == daireNo)
                                {
                                    if (radioButton1.Checked)
                                    {
                                        if (OrtakNesneler.oturanlar[i].havuzKaydi == "yapıldı")
                                        {
                                            MessageBox.Show("Kişinin zaten havuz kaydı bulunmaktadır!");
                                        }
                                        else if (radioButton3.Checked)
                                        {
                                            OrtakNesneler.oturanlar[i].havuzKaydiYap();
                                            for (int mekanIndeks = OrtakNesneler.mekanlar.Count()-1;  mekanIndeks >= 0; mekanIndeks--)
                                            {
                                                if(OrtakNesneler.mekanlar[mekanIndeks] is Havuz)
                                                {
                                                    Havuz havuz = (Havuz)OrtakNesneler.mekanlar[mekanIndeks];
                                                    if(havuz.binaNo == binaNo)
                                                    {
                                                        havuz.kisiSayisiArttir();
                                                    }
                                                }
                                            }
                                            kisiBulundu = true;
                                        }

                                    }
                                    else if (radioButton2.Checked)
                                    {
                                        if (OrtakNesneler.oturanlar[i].fitnessKaydi == "yapıldı")
                                        {
                                            MessageBox.Show("Kişinin zaten fitness kaydı bulunmaktadır!");
                                        }
                                        else if (radioButton3.Checked)
                                        {
                                            OrtakNesneler.oturanlar[i].fitnessKaydiYap();
                                            for (int mekanIndeks = OrtakNesneler.mekanlar.Count() - 1; mekanIndeks >= 0; mekanIndeks--)
                                            {
                                                if (OrtakNesneler.mekanlar[mekanIndeks] is Fitness)
                                                {
                                                    Fitness fitness = (Fitness)OrtakNesneler.mekanlar[mekanIndeks];
                                                    if (fitness.binaNo == binaNo)
                                                    {
                                                        fitness.kisiSayisiArttir();
                                                    }
                                                }
                                            }
                                            kisiBulundu = true;
                                        }
                                    }
                                    kisiBulundu = true;
                                }
                            }
                            if (!kisiBulundu)
                            {
                                MessageBox.Show("Kayıtlarda böyle bir kişi bulunmamaktadır!");
                            }
                            else
                            {
                                OrtakNesneler.DataDosyasınıYaz();
                                MessageBox.Show("Kayıt başarıyla gerçekleştirildi!");

                            }
                        }
                        catch(Exception er)
                        {
                            MessageBox.Show("Kayıt gerçekleştirilemedi!");
                        }
                       
                    }
                    break;
                case 5:

                    kisiIsmi = comboBox2.Text;
                    kisiSoyismi = comboBox3.Text;                  
                    string tarih = dateTimePicker1.Value.ToString();

                    if ((!radioButton1.Checked && !radioButton2.Checked) || (!radioButton3.Checked && !radioButton4.Checked))
                    {
                        MessageBox.Show("Lütfen buton seçeneklerini boş bırakmayınız!");
                    }
                    else
                    {
                      
                        for (int i = OrtakNesneler.oturanlar.Count() - 1; i >= 0; i--)
                        {
                            if (OrtakNesneler.oturanlar[i].kisi_tipi == kisiTipi && OrtakNesneler.oturanlar[i].ad == kisiIsmi && OrtakNesneler.oturanlar[i].soyad == kisiSoyismi && OrtakNesneler.oturanlar[i].binaNo == binaNo && OrtakNesneler.oturanlar[i].daireNo == daireNo)
                            {
                                if (radioButton1.Checked)
                                {
                                    if (OrtakNesneler.oturanlar[i].havuzKaydi == "yapılmadı")
                                    {

                                        MessageBox.Show("Kişinin havuz kaydı bulunmamaktadır,havuzu kullanmak için önce \" Havuz/Fitness Kaydı Oluştur \" menüsünden kayıt yapmalısınız!");
                                    }
                                    else if (OrtakNesneler.oturanlar[i].havuzKaydi == "yapıldı")
                                    {
                                        
                                        for(int mekanIndeks = OrtakNesneler.mekanlar.Count() - 1; mekanIndeks >= 0; mekanIndeks--)
                                        {
                                            if (OrtakNesneler.mekanlar[mekanIndeks] is Daire )
                                            {
                                                Daire daire = (Daire)OrtakNesneler.mekanlar[mekanIndeks];
                                                if(daire.binaNo == binaNo && daire.daireNo == daireNo)
                                                {
                                                    if((radioButton3.Checked) && daire.havuzBorc != 0)
                                                    {
                                                        OrtakNesneler.HavuzDosyasınıYaz(OrtakNesneler.oturanlar[i], tarih , true);
                                                    }
                                                    else if (radioButton3.Checked && daire.havuzBorc == 0)
                                                    {
                                                        OrtakNesneler.HavuzDosyasınıYaz(OrtakNesneler.oturanlar[i], tarih, false);
                                                        daire.havuzBorc += 70;
                                                        OrtakNesneler.havuzOdemeleri.Add(daire);
                                                        OrtakNesneler.OdemeDosyasiYaz();
                                                     
                                                    }
                                                    else
                                                    {
                                                        OrtakNesneler.HavuzDosyasınıYaz(OrtakNesneler.oturanlar[i], tarih, false);
                                                    }
                                                }
                                            }
                                        }
                                        kisiBulundu = true;
                                    }
                                }
                                else if (radioButton2.Checked)
                                {
                                    if (OrtakNesneler.oturanlar[i].fitnessKaydi == "yapılmadı")
                                    {

                                        MessageBox.Show("Kişinin fitness kaydı bulunmamaktadır,fitness salonunu kullanmak için önce \" Havuz/Fitness Kaydı Oluştur \" menüsünden kayıt yapmalısınız!");
                                    }
                                    else if (OrtakNesneler.oturanlar[i].fitnessKaydi == "yapıldı")
                                    {
                                        for (int mekanIndeks = OrtakNesneler.mekanlar.Count() - 1; mekanIndeks >= 0; mekanIndeks--)
                                        {
                                            if (OrtakNesneler.mekanlar[mekanIndeks] is Daire)
                                            {
                                                Daire daire = (Daire)OrtakNesneler.mekanlar[mekanIndeks];
                                                if (daire.binaNo == binaNo && daire.daireNo == daireNo)
                                                {
                                                    if ((radioButton3.Checked) && daire.fitnessBorc != 0)
                                                    {
                                                        OrtakNesneler.FitnessDosyasiYaz(OrtakNesneler.oturanlar[i], tarih, true);
                                                    }
                                                    else if(radioButton3.Checked && daire.fitnessBorc == 0)
                                                    {
                                                        OrtakNesneler.FitnessDosyasiYaz(OrtakNesneler.oturanlar[i], tarih, false);
                                                        daire.fitnessBorc += 50;
                                                        OrtakNesneler.fitnessOdemeleri.Add(daire);
                                                        OrtakNesneler.OdemeDosyasiYaz();

                                                    }
                                                    else if(radioButton4.Checked)
                                                    {
                                                        OrtakNesneler.FitnessDosyasiYaz(OrtakNesneler.oturanlar[i], tarih, false);
                                                    }
                                                }
                                            }
                                        }
                                        kisiBulundu = true;
                                    }
                                }

                            }
                        }
                        if (!kisiBulundu)
                        {
                            MessageBox.Show("Kayıtlarda böyle bir kişi bulunmamaktadır!");
                        }
                        else
                        {
                            try
                            {
                                if (radioButton1.Checked)
                                {

                                    for (int mekanIndeks = OrtakNesneler.mekanlar.Count() - 1; mekanIndeks >= 0; mekanIndeks--)
                                    {
                                        if (OrtakNesneler.mekanlar[mekanIndeks] is Havuz)
                                        {
                                            Havuz havuz = (Havuz)OrtakNesneler.mekanlar[mekanIndeks];
                                            if (havuz.binaNo == binaNo)
                                            {
                                                havuz.kisiSayisiArttir();
                                            }

                                        }
                                    }
                                }
                                else if (radioButton2.Checked)
                                {

                                    for (int mekanIndeks = OrtakNesneler.mekanlar.Count() - 1; mekanIndeks >= 0; mekanIndeks--)
                                    {
                                        if (OrtakNesneler.mekanlar[mekanIndeks] is Fitness)
                                        {
                                            Fitness fitness = (Fitness)OrtakNesneler.mekanlar[mekanIndeks];
                                            if (fitness.binaNo == binaNo)
                                            {
                                                fitness.kisiSayisiArttir();
                                            }

                                        }
                                    }
                                }

                                OrtakNesneler.MekanDosyasınıYaz();
                                MessageBox.Show("İşlem başarıyla gerçekleştirildi! ");
                            }
                            catch
                            {
                                MessageBox.Show("İşlem gerçekleştirilemedi! ");
                            }

                          
                        }
                    }
                    break;
                default:
                    break;
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            form1ref.Close();
        }

       
    }
}

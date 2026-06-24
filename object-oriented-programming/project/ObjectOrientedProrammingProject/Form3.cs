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
using System.Diagnostics;
using System.Diagnostics.Eventing.Reader;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace B241210370_PROJE_
{
    public partial class Form3 : Form
    {
        

        Form1 form1ref;
            
        public Form3(Form1 form1)
        {
            InitializeComponent();
            form1ref = form1;
                        
        }

        private void Form3_Load(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (button1.Visible)
            {
                this.Hide();
                form1ref.Show();
            }
            else
            {
                button4.Hide();
                comboBox1.Visible = true;
                button1.Visible = true;
                comboBox1.SelectedIndex = -1;

                

                foreach (Control arac in panel1.Controls)
                {

                    arac.Hide();

                    if (arac is TextBox)
                    {
                        ((TextBox)arac).Text = "";
                    }
                    else if (arac is ComboBox)
                    {
                        ((ComboBox)arac).SelectedIndex = -1;
                    }
                    else if (arac is RadioButton)
                    {
                        ((RadioButton)arac).Checked = false;
                    }
                    else if (arac is HScrollBar)
                    {
                        ((HScrollBar)arac).Value = ((HScrollBar)arac).Minimum;
                    }
                    else if (arac is DateTimePicker)
                    {
                        ((DateTimePicker)arac).Checked = false;
                    }
                    else if (arac is NumericUpDown)
                    {
                        ((NumericUpDown)arac).Value = ((NumericUpDown)arac).Minimum;
                    }
                    else if (arac is Label)
                    {
                        ((Label)arac).Text = "";
                    }
                    else if (arac is CheckBox)
                    {
                        ((CheckBox)arac).Checked = false;
                        ((CheckBox)arac).Text = "";
                    }
                    
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {

            void görünürYap(params Control[] araclar)
            {
                foreach (var arac in araclar)
                {
                    arac.Visible = true;
                }
            }

            void görünmezYap(params Control[] araclar)
            {
                foreach (var arac in araclar)
                {
                    arac.Visible = false;
                }
            }

            switch (comboBox1.SelectedIndex)
            {
                case 0:
                    label2.Text = "Ödeme yapılacak kişi isim:";
                    label3.Text = "Ödeme yapılacak kişi soyisim:";
                    label4.Text = "Ödeme yapacak kisinin bina no:";                 
                    label5.Text = "Ödeme yapacak kişi daire no:";
                    label11.Text = "Ödenecek tutar:";     
                    button4.Text = "ÖDE";
                    groupBox2.Text = "Kişi Tipi:";
                    groupBox3.Text = "Ödeme Tipi:";
                    radioButton3.Text = "aile-reisi";
                    radioButton4.Text = "misafir";
                    radioButton1.Text = "havuz";
                    radioButton2.Text = "finess";
                    foreach (Oturan oturan in OrtakNesneler.oturanlar)
                    {
                        if (!comboBox2.Items.Contains(oturan.ad))
                        { comboBox2.Items.Add(oturan.ad); }
                        if (!comboBox3.Items.Contains(oturan.soyad))
                        { comboBox3.Items.Add(oturan.soyad); }
                    }
                    görünürYap(radioButton1, radioButton2, label2, label3, label4, label5, label11, button4, textBox3, hScrollBar1, comboBox2, comboBox3, numericUpDown1, numericUpDown2, groupBox3, groupBox2,radioButton3, radioButton4);
                    görünmezYap(button1, label1, comboBox1);
                    break;
                case 1:
                   
                    label4.Text = "Silinecek ödemeye ait bina no:";
                    label5.Text = "Silinecek ödemeye ait daire no:";                 
                    button4.Text = "SİL";     
                    groupBox3.Text = "Ödeme Tipi";
                    radioButton1.Text = "havuz";
                    radioButton2.Text = "finess";
                    görünürYap(radioButton1, radioButton2, label4, label5, button4, numericUpDown1, numericUpDown2, button2, groupBox3);
                    görünmezYap(label1, label11, comboBox1, button1, hScrollBar1, textBox3,hScrollBar1, checkBox1, radioButton3, radioButton4);
                    break;
                case 2:
                   
                    label4.Text = "Eklenecek ödemeye ait bina no:";
                    label5.Text = "Ekelenecek ödemeye ait daire no:";       
                    button4.Text = "EKLE";                   
                    groupBox3.Text = "Ödeme Tipi:";
                    label11.Text = "Eklenecek tutar";
                    radioButton1.Text = "havuz";
                    radioButton2.Text = "finess";
                    görünürYap(radioButton1, radioButton2,  label11, button4, textBox3, hScrollBar1, groupBox3, label4, label5, numericUpDown1, numericUpDown2);
                    görünmezYap(label1, button1, label2, label3, radioButton3, radioButton4, groupBox2, checkBox1, radioButton3 ,radioButton4);
                    break;
                case 3:
                   
                    label4.Text = "Düzeltilecek ödeme bina no:";
                    label5.Text = "Düzeltilecek ödeme daire no:";
                    button4.Text = "DÜZELT";                  
                    label11.Text = "Eski borç";
                    groupBox3.Text = "Ödeme Tipi:";
                    radioButton1.Text = "havuz";
                    radioButton2.Text = "finess";
                    görünürYap(button4, label4, label5, label11, numericUpDown1, numericUpDown2,  groupBox3,textBox3 ,hScrollBar1);
                    görünmezYap(button1, label1, comboBox1, checkBox1, radioButton3 ,radioButton4);
                    break;
                case 4:
                    button1.Hide();
                    using(StreamReader reader = new StreamReader(OrtakNesneler.odosyaYolu))
                    {
                        string[] kelimeler;
                         while(!reader.EndOfStream)
                            {
                            kelimeler = reader.ReadLine().Split(" ");
                            listBox1.Items.Add( " bina no: " + kelimeler[0] + " daire no: " + kelimeler[1] + " " + " borç: " + kelimeler[2] + " "  + kelimeler[3]);
                            listBox1.Items.Add("\n");
                            }
                    }
                    listBox1.Visible = true;

                    break;
                default:
                    MessageBox.Show("Lütfen bir seçenek seçiniz!");
                    break;
            }
        }


        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            hScrollBar1.Maximum = 60;
            hScrollBar1.Minimum = 1;
            checkBox1.Text = "Daireye ait tüm fitness borcunu silmek ister misiniz?";
            checkBox1.Visible = true;
            hScrollBar1.Visible = true;
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            hScrollBar1.Maximum = 50;
            hScrollBar1.Minimum = 1;
            checkBox1.Text = "Daireye ait tüm havuz borcunu silmek ister misiniz?";
            checkBox1.Visible = true;
            hScrollBar1.Visible = true;
        }

       
        private void hScrollBar1_Scroll(object sender, ScrollEventArgs e)
        {
            textBox3.Text = hScrollBar1.Value.ToString();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            form1ref.Close();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            string kisiAdi = comboBox2.Text;
            string kisiSoyAdi = comboBox3.Text;
            int binaNo = (int)numericUpDown1.Value;
            int daireNo = (int)numericUpDown2.Value;
            bool kisiBulundu = false;        
            string kayitTipi = "";
            bool daireBulundu = false;
            if (radioButton1.Checked)
            {
                kayitTipi = "havuz";
            }
            else if(radioButton2.Checked)
            {
                kayitTipi = "fitness";
            }
           
            switch (comboBox1.SelectedIndex)
            {
                case 0:

                    int odenecekBorcTutari;
                    bool cevrildi = int.TryParse(textBox3.Text, out odenecekBorcTutari);
                    if ((!radioButton1.Checked && !radioButton2.Checked) || (!radioButton3.Checked && !radioButton4.Checked))
                    {
                        MessageBox.Show("Lütfen buton seçeneklerini boş bırakmayınız!");
                    }
                    else if (radioButton4.Checked)
                    {
                        MessageBox.Show("Misafirler ödeme yapamaz!");
                    }                  
                    else
                    {
                        try
                        {
                            foreach (Oturan oturan in OrtakNesneler.oturanlar)
                            {
                                if (oturan.kisi_tipi == "aile-reisi" && oturan.ad == kisiAdi && oturan.soyad == kisiSoyAdi && oturan.binaNo == binaNo && oturan.daireNo == daireNo)
                                {
                                    kisiBulundu = true;
                                    break;
                                }

                            }
                            if (!kisiBulundu)
                            {
                                MessageBox.Show("Kayıtlarda böyle bir aile-reisi  bulunmamaktadır!");
                            }
                            else
                            {

                                for (int mekanIndex = OrtakNesneler.mekanlar.Count() - 1; mekanIndex >= 0; mekanIndex--)
                                {

                                    if (OrtakNesneler.mekanlar[mekanIndex] is Daire)
                                    {
                                        Daire daire1 = (Daire)OrtakNesneler.mekanlar[mekanIndex];

                                        if (daire1.binaNo == binaNo && daire1.daireNo == daireNo)
                                        {
                                            if (radioButton1.Checked)
                                            {
                                                if (daire1.havuzBorc == 0)
                                                {
                                                    MessageBox.Show("Havuz borcu bulunmamaktadır!");
                                                }
                                                else
                                                {
                                                    if (checkBox1.Checked)
                                                    {
                                                        daire1.havuzBorc = 0;
                                                    }
                                                    else
                                                    {
                                                        if (daire1.havuzBorc < odenecekBorcTutari)
                                                        {
                                                            MessageBox.Show("Fazlatutar girdiniz!");
                                                            break;
                                                        }
                                                    }
                                                    daire1.havuzBorcuAzalt(odenecekBorcTutari);
                                                    for (int odemeIndeks = OrtakNesneler.havuzOdemeleri.Count() - 1; odemeIndeks >= 0; odemeIndeks--)
                                                    {

                                                        Daire daire2 = (Daire)OrtakNesneler.havuzOdemeleri[odemeIndeks];
                                                        if (daire2.binaNo == daire1.binaNo && daire2.daireNo == daire1.daireNo)
                                                        {
                                                            daire2.havuzBorc = daire1.havuzBorc;

                                                        }
                                                    }
                                                }
                                            }
                                            else if (radioButton2.Checked)
                                            {
                                                if (daire1.fitnessBorc == 0)
                                                {
                                                    MessageBox.Show("fitness borcu bulunmamaktadır!");
                                                }
                                                else
                                                {
                                                    if (checkBox1.Checked)
                                                    {
                                                        daire1.fitnessBorc = 0;
                                                    }
                                                    else
                                                    {
                                                        if (daire1.fitnessBorc < odenecekBorcTutari)
                                                        {
                                                            MessageBox.Show("Fazlatutar girdiniz!");
                                                            break;
                                                        }
                                                    }
                                                    daire1.fitnessBorcuAzalt(odenecekBorcTutari);
                                                    for (int odemeIndeks = OrtakNesneler.fitnessOdemeleri.Count() - 1; odemeIndeks >= 0; odemeIndeks--)
                                                    {

                                                        Daire daire3 = (Daire)OrtakNesneler.fitnessOdemeleri[odemeIndeks];
                                                        if (daire3.binaNo == daire1.binaNo && daire3.daireNo == daire1.daireNo)
                                                        {
                                                            daire3.havuzBorc = daire1.havuzBorc;

                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                OrtakNesneler.OdemeDosyasiYaz();
                                OrtakNesneler.MekanDosyasınıYaz();
                                MessageBox.Show("Ödeme başarıyla gerçekleşti!");
                            }
                        }
                        catch
                        {
                            MessageBox.Show("Ödeme gerçekleştirilemedi");

                        }

                    }                                         
                    break;
                case 1:
                 
                    if ((!radioButton1.Checked && !radioButton2.Checked))
                    {
                        MessageBox.Show("Lütfen buton seçeneklerini boş bırakmayınız!");
                    }                 
                    else
                    {
                        try
                        {
                            using (StreamReader reader = new StreamReader(OrtakNesneler.odosyaYolu))
                            {
                                string[] kelimeler;
                                while (!reader.EndOfStream)
                                {
                                    kelimeler = reader.ReadLine().Split(" ");
                                    if (binaNo.ToString() == kelimeler[0] && daireNo.ToString() == kelimeler[1] && kelimeler[3] == kayitTipi)
                                    {
                                        daireBulundu = true;
                                        break;
                                    }
                                }
                            }
                            if (daireBulundu)
                            {
                                for (int mekanIndeks = OrtakNesneler.mekanlar.Count() - 1; mekanIndeks >= 0; mekanIndeks--)
                                {
                                    if (OrtakNesneler.mekanlar[mekanIndeks] is Daire)
                                    {
                                        Daire daire = (Daire)OrtakNesneler.mekanlar[mekanIndeks];
                                        if (daire.daireNo == daireNo && daire.binaNo == binaNo)
                                        {
                                            if (radioButton1.Checked)
                                            {
                                                daire.havuzBorc = 0;
                                                for (int odemeIndeks = OrtakNesneler.havuzOdemeleri.Count() - 1; odemeIndeks >= 0; odemeIndeks--)
                                                {
                                                    OrtakNesneler.havuzOdemeleri.RemoveAt(odemeIndeks);
                                                }
                                            }
                                            else if (radioButton2.Checked)
                                            {
                                                daire.fitnessBorc = 0;
                                                for (int odemeIndeks = OrtakNesneler.fitnessOdemeleri.Count() - 1; odemeIndeks >= 0; odemeIndeks--)
                                                {
                                                    OrtakNesneler.fitnessOdemeleri.RemoveAt(odemeIndeks);
                                                }
                                            }
                                        }
                                    }
                                }
                                OrtakNesneler.OdemeDosyasiYaz();
                                OrtakNesneler.MekanDosyasınıYaz();
                                MessageBox.Show("Silme işlemi başarıyla gerççekleşti!");
                            }
                            else
                            {
                                MessageBox.Show("Ödeme kayıtlarında böyle bir daire bulunmamaktadır!");
                            }

                        }
                        catch
                        {
                            MessageBox.Show("Silme işlemi gerçekleştirilemedi!");
                        }
                    }
                    break;
                case 2:
                    bool daireBulundu2 = false;
                    if ((!radioButton1.Checked && !radioButton2.Checked) || (!radioButton3.Checked && !radioButton4.Checked))
                    {
                        MessageBox.Show("Lütfen buton seçeneklerini boş bırakmayınız!");
                    }
                    else
                    {
                        try
                        {
                            int eklenecekBorcTutari;
                            bool cevrildi2 = int.TryParse(textBox3.Text, out eklenecekBorcTutari);

                            using (StreamReader reader = new StreamReader(OrtakNesneler.odosyaYolu))
                            {
                                string[] kelimeler;
                                while (!reader.EndOfStream)
                                {
                                    kelimeler = reader.ReadLine().Split(" ");
                                    if (binaNo.ToString() == kelimeler[0] && daireNo.ToString() == kelimeler[1] && kelimeler[3] == kayitTipi)
                                    {
                                        daireBulundu = true;
                                        break;
                                    }
                                }
                            }
                            if (daireBulundu)
                            {
                                MessageBox.Show("Zaten bu daireye ait borç bulunmaktadır!");
                            }
                            else
                            {

                                for (int mekanIndeks = OrtakNesneler.mekanlar.Count() - 1; mekanIndeks >= 0; mekanIndeks--)
                                {
                                    if (OrtakNesneler.mekanlar[mekanIndeks] is Daire)
                                    {
                                        Daire daire = (Daire)OrtakNesneler.mekanlar[mekanIndeks];
                                        if (daire.daireNo == daireNo && daire.binaNo == binaNo)
                                        {
                                            if (radioButton1.Checked)
                                            {
                                                daire.havuzBorc = eklenecekBorcTutari;
                                                OrtakNesneler.havuzOdemeleri.Add(daire);
                                            }
                                            else if (radioButton2.Checked)
                                            {
                                                daire.fitnessBorc = eklenecekBorcTutari;
                                                OrtakNesneler.fitnessOdemeleri.Add(daire);
                                            }
                                            daireBulundu2 = true;
                                            break;
                                        }
                                    }
                                }
                                if (daireBulundu2)
                                {
                                    OrtakNesneler.OdemeDosyasiYaz();
                                    OrtakNesneler.MekanDosyasınıYaz();
                                    MessageBox.Show("Ekleme işlemi başarıyla gerçekleşti!");
                                }
                                else
                                {
                                    MessageBox.Show("kayıtlarda böyle bir daire bulunmamaktadır!");
                                }
                            }
                        }
                        catch
                        {
                            MessageBox.Show("Ekleme işlemi gerçekleştirilemedi!");
                        }
                    }                 
                    break;
                case 3:
                    int yeniBorcTutari;
                    bool cevrildi3 = int.TryParse(textBox3.Text, out yeniBorcTutari);
                    if ((!radioButton1.Checked && !radioButton2.Checked))
                    {
                        MessageBox.Show("Lütfen buton seçeneklerini boş bırakmayınız!");
                    }
                    else
                    {


                        try
                        {
                            using (StreamReader reader = new StreamReader(OrtakNesneler.odosyaYolu))
                            {
                                string[] kelimeler;
                                while (!reader.EndOfStream)
                                {
                                    kelimeler = reader.ReadLine().Split(" ");
                                    if (binaNo.ToString() == kelimeler[0] && daireNo.ToString() == kelimeler[1] && kelimeler[3] == kayitTipi)
                                    {
                                        daireBulundu = true;
                                        break;
                                    }
                                }
                            }
                            if (daireBulundu)
                            {
                                for (int mekanIndeks = OrtakNesneler.mekanlar.Count() - 1; mekanIndeks >= 0; mekanIndeks--)
                                {
                                    if (OrtakNesneler.mekanlar[mekanIndeks] is Daire)
                                    {
                                        Daire daire = (Daire)OrtakNesneler.mekanlar[mekanIndeks];
                                        if (daire.daireNo == daireNo && daire.binaNo == binaNo)
                                        {
                                            if (radioButton1.Checked)
                                            {
                                                daire.havuzBorc = yeniBorcTutari;
                                                for (int odemeIndeks = OrtakNesneler.mekanlar.Count() - 1; odemeIndeks >= 0; odemeIndeks--)
                                                {
                                                    Daire daire2 = (Daire)OrtakNesneler.mekanlar[odemeIndeks];
                                                    if (daire2.daireNo == daire.daireNo && daire2.binaNo == daire.binaNo)
                                                    {
                                                        daire2.havuzBorc = yeniBorcTutari;
                                                        break;
                                                    }
                                                }
                                            }
                                            else if (radioButton2.Checked)
                                            {
                                                daire.fitnessBorc = yeniBorcTutari;
                                                for (int odemeIndeks = OrtakNesneler.mekanlar.Count() - 1; odemeIndeks >= 0; odemeIndeks--)
                                                {
                                                    Daire daire2 = (Daire)OrtakNesneler.mekanlar[odemeIndeks];
                                                    if (daire2.daireNo == daire.daireNo && daire2.binaNo == daire.binaNo)
                                                    {
                                                        daire2.fitnessBorc = yeniBorcTutari;
                                                        break;
                                                    }
                                                }
                                            }

                                        }
                                    }
                                }
                                OrtakNesneler.OdemeDosyasiYaz();
                                OrtakNesneler.MekanDosyasınıYaz();
                                MessageBox.Show("Düzeltme işlemi başarıyla gerçekleşti!");

                            }
                            else
                            {
                                MessageBox.Show("Kayıtlarda böyle bir daire bulunmamaktadır!");
                            }

                        }                       
                        catch
                        {
                            MessageBox.Show("Düzeltme işlemi gerçekleştirilemedi!");
                        }
                        
                    }
                    break;
                default:
                    break;

            }

        }
    }
}

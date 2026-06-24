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
using Microsoft.VisualBasic;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Drawing.Text;
using static System.Runtime.InteropServices.JavaScript.JSType;
using System.Diagnostics.Eventing.Reader;

namespace B241210370_PROJE_
{
    
    public partial class Form2 : Form
    {


        int daireSayisi;


        public static int binaNo;
        

        private Form1 form1Ref;

        public Form2(Form1 form1)
        {
            

            InitializeComponent();
            this.form1Ref = form1;

            label2.Font = new Font("Segoe UI", 10);
            label3.Font = new Font("Segoe UI", 10);
            label4.Font = new Font("Segoe UI", 10);
            label5.Font = new Font("Segoe UI", 10);

            button4.Hide();

        }

        private void Form2_Load(object sender, EventArgs e)
        {
           
        }



        private void button2_Click(object sender, EventArgs e)
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
                    
                    button2.Hide();
                    button4.Text = "EKLE";
                    button4.Show();
                    label2.Text = "Eklemek istediğiniz bina sayısı:";
                    label3.Text = "Bir binada olmasını istediğiniz daire sayısı:";
                    görünürYap(label2, label3, numericUpDown1, numericUpDown2, button4);
                    görünmezYap(label1, comboBox1, numericUpDown3, numericUpDown4, button2);

                    numericUpDown1.Maximum = 20;
                    numericUpDown2.Maximum = 30;                  
                    break;

                case 1:
                   
                    if (OrtakNesneler.daireler.Count != 0)
                    {
                        
                        button4.Text = "SİL";
                        label2.Text = "Silmek istediğiniz dairenin bina no:";
                        label3.Text = "Silmek istediğiniz dairenin daire no:";
                        görünürYap(label2, label3, numericUpDown1, numericUpDown2, button4);
                        görünmezYap(label1, comboBox1, button2, numericUpDown3, numericUpDown4);
                        numericUpDown1.Maximum = binaNo;

                        int binaNoMax = 0;
                        for(daireSayisi = 0; daireSayisi<OrtakNesneler.daireler.Count(); daireSayisi++ )
                        {
                            int a;

                            a = OrtakNesneler.daireler[daireSayisi].binaNo;
                            if(a>binaNoMax)
                            {
                                binaNoMax = a;
                            }
                        }
                        numericUpDown1.Maximum = binaNoMax;

                        int daireNoMax = 0;
                        for (daireSayisi=0; daireSayisi<OrtakNesneler.daireler.Count(); daireSayisi++)
                        {
                            int b;

                            b = OrtakNesneler.daireler[daireSayisi].daireNo;
                            if (b > daireNoMax)
                            {
                                daireNoMax = b;
                            }
                         
                           

                        }
                        numericUpDown2.Maximum = daireNoMax;

                    }
                    else
                    {

                        MessageBox.Show("Sitede hiç daire ve bina bulunmamaktadır, önce 'EKLE' menüsüne gitmelisiniz!");
                    }
                    break;
                case 2:
                   
                    if (OrtakNesneler.daireler.Count != 0)
                    {
                        button4.Text = "DÜZELT";
                        label2.Text = "Düzeltmek istediğiniz dairenin bina no:";
                        label3.Text = "Düzeltmek istediğiniz dairenin daire no:";
                        label4.Text = "Yeni bina no:";
                        label5.Text = "Yeni daire no:";
                        görünürYap(button4, label2, label3, label4, label5, numericUpDown1, numericUpDown2, numericUpDown3, numericUpDown4);
                        görünmezYap(label1, comboBox1, button2);

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
                        numericUpDown1.Maximum = binaNoMax;

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
                        numericUpDown2.Maximum = daireNoMax;

                        numericUpDown3.Maximum = 20;
                        numericUpDown4.Maximum = 30;

                    }
                    else
                    {
                        MessageBox.Show("Sitede hiç daire ve bina bulunmamaktadır, önce 'EKLE' menüsüne gitmelisiniz!");
                    }                   
                    break;
                case 3:
                   
                    if(OrtakNesneler.daireler.Count != 0)
                    {
                        button2.Hide();
                        foreach(Mekan mekan in OrtakNesneler.mekanlar)
                        {
                            if(mekan is Daire)
                            {
                                Daire daire = (Daire)mekan;
                                listBox1.Items.Add("bina no:" + daire.binaNo + " " +"daire no:" + " " + daire.daireNo + "  " + "kişi sayısı:" + daire.kisiSayisi);

                            }
                            else if(mekan is Havuz)
                            {
                                Havuz havuz = (Havuz)mekan;
                                listBox1.Items.Add("bina no:" + havuz.binaNo + " " + "kişi sayısı" + havuz.kisiSayisi);
                                    
                            }
                            else if(mekan is Fitness)
                            {
                                Fitness fitness = (Fitness)mekan;
                                listBox1.Items.Add("bina no:" + fitness.binaNo + " " + "kişi sayısı" + " " + fitness.kisiSayisi + "\n");
                            }

                        }
                        listBox1.Visible = true;
                    }
                    else
                    {
                        MessageBox.Show("Sitede hiç daire ve bina bulunmamaktadır, önce 'EKLE' menüsüne gitmelisiniz!");
                    }
                    break;
                default:
                    MessageBox.Show("Lütfen bir seçenek seçiniz!");
                    break;
            }

        }

        private void button1_Click(object sender, EventArgs e)
        {

            if (button2.Visible)
            {

                this.Hide();
                form1Ref.Show();

            }
            else
            {
                comboBox1.SelectedIndex = -1;
                comboBox1.Visible = true;
                button2.Visible = true;
                button4.Visible = false;

                foreach (Control arac in panel1.Controls)
                {
                    arac.Visible = false;
                    if (arac is TextBox)
                    {
                        ((TextBox)arac).Text = "";
                    }
                    else if (arac is Label)
                    {
                        ((Label)arac).Text = "";
                    }
                    else if (arac is ComboBox)
                    {
                        ((ComboBox)arac).SelectedIndex = -1;
                    }
                    else if (arac is NumericUpDown)
                    {
                        ((NumericUpDown)arac).Value = ((NumericUpDown)arac).Minimum;
                    }
                    else if(arac is ListBox)
                    {
                        ((ListBox)arac).Items.Clear();
                    }
                }


            }

        }

        private void button3_Click(object sender, EventArgs e)
        {

            form1Ref.Close();
        }

        private void button4_Click(object sender, EventArgs e)
        {

            bool daireBulundu = false;
            switch (comboBox1.SelectedIndex)
            {
                case 0:

                    int binaSayisi = Convert.ToInt32(numericUpDown1.Value);
                    int daireSayisi = (int)numericUpDown2.Value;                  
                    try
                    {

                        for (int i = 1; i <= binaSayisi; i++)
                        {

                            binaNo += 1;
                            for (int daireNo = 1; daireNo <= daireSayisi; daireNo++)
                            {
                                Daire daire = new Daire(binaNo, daireNo);
                                OrtakNesneler.daireler.Add(daire);
                                OrtakNesneler.mekanlar.Add(daire);
                                  
                                   
                            }
                            Havuz havuz = new Havuz(binaNo);
                            Fitness fitness = new Fitness(binaNo);
                            OrtakNesneler.havuzlar.Add(havuz);
                            OrtakNesneler.fitnessSalonlari.Add(fitness);
                            OrtakNesneler.mekanlar.Add(fitness);
                            OrtakNesneler.mekanlar.Add(havuz);

                        }

                        OrtakNesneler.MekanDosyasınıYaz();
                        MessageBox.Show("Ekleme işlemi başarıyla gerçekleştirildi!");
                    }
                    catch(Exception er)
                    {
                        MessageBox.Show("Ekleme işlemi gerçekleştirilemedi!" + er.Message);
                    }
                    break;

                case 1:
                 
                    int silinecekBinaNo = Convert.ToInt32(numericUpDown1.Value);
                    int silinecekDaireNo = (int)numericUpDown2.Value;

                    try
                    {
                        for(int mekanIndeks = OrtakNesneler.mekanlar.Count() - 1; mekanIndeks >= 0; mekanIndeks--)
                        {
                            if(OrtakNesneler.mekanlar[mekanIndeks]  is Daire )
                            {
                                Daire daire = (Daire)OrtakNesneler.mekanlar[mekanIndeks];
                         
                                if(daire.binaNo == silinecekBinaNo && daire.daireNo == silinecekDaireNo)
                                {
                                    daire.fitnessBorc = 0;
                                    daire.havuzBorc = 0;
                                    OrtakNesneler.mekanlar.Remove(daire);
                                    daireBulundu = true;
                                    break;
                                }
                            
                            }

                        }
                        if (daireBulundu)
                        {
                            for(int kisiIndeks = OrtakNesneler.oturanlar.Count() -1 ; kisiIndeks >= 0; kisiIndeks--)
                            {
                                
                                if (OrtakNesneler.oturanlar[kisiIndeks].binaNo == silinecekBinaNo && OrtakNesneler.oturanlar[kisiIndeks].daireNo == silinecekDaireNo)
                                {
                                    OrtakNesneler.oturanlar.RemoveAt(kisiIndeks);
                                }
                            }
                            for(int odemeIndeks = OrtakNesneler.havuzOdemeleri.Count() -1 ; odemeIndeks >= 0; odemeIndeks--)
                            {
                                if (OrtakNesneler.havuzOdemeleri[odemeIndeks].binaNo == silinecekBinaNo && OrtakNesneler.havuzOdemeleri[odemeIndeks].daireNo == silinecekDaireNo)
                                {

                                    OrtakNesneler.havuzOdemeleri.RemoveAt(odemeIndeks);

                                }
                            }
                            for (int odemeIndeks = OrtakNesneler.fitnessOdemeleri.Count() - 1; odemeIndeks >= 0; odemeIndeks--)
                            {
                                if (OrtakNesneler.fitnessOdemeleri[odemeIndeks].binaNo == silinecekBinaNo && OrtakNesneler.fitnessOdemeleri[odemeIndeks].daireNo == silinecekDaireNo)
                                {

                                    OrtakNesneler.fitnessOdemeleri.RemoveAt(odemeIndeks);

                                }

                            }

                            OrtakNesneler.MekanDosyasınıYaz();                         
                            MessageBox.Show("Silme işlemi başarıyla gerçekleşmiştir!");
                        }
                        else
                        {
                            MessageBox.Show("Kayıtlarda böyle bir daire bulunmamaktadır!");
                        }
                    }
                    catch(Exception er)
                    {
                        MessageBox.Show("Silme işlemi gerçekleştirilemedi!" + er.Message);
                    }                 
                    break;
                case 2:
 
                    int eskiBinaNo = Convert.ToInt32(numericUpDown1.Value);
                    int eskiDaireNo = (int)numericUpDown2.Value;
                    int yeniDaireNo = (int)numericUpDown4.Value;
                    int yeniBinaNo = Convert.ToInt32(numericUpDown3.Value);
                    bool daireBulundu2 = false;

                    try
                    {

                        for (int mekanIndeks = OrtakNesneler.mekanlar.Count() - 1; mekanIndeks >= 0; mekanIndeks--) 
                        {
                            if (OrtakNesneler.mekanlar[mekanIndeks] is Daire)
                            {
                                Daire daire = (Daire)OrtakNesneler.mekanlar[mekanIndeks];


                                if (daire.binaNo == yeniBinaNo && daire.daireNo == yeniDaireNo)
                                {
                                   
                                    daireBulundu2 = true;
                                    break;
                                }
                                else if(daire.binaNo == eskiBinaNo && daire.daireNo == eskiDaireNo)
                                {
                                    daire.binaNo = yeniBinaNo;
                                    daire.daireNo = yeniDaireNo;
                                    daireBulundu = true;
                                }

                            }

                        }
         
                        if (daireBulundu2)
                        {

                            MessageBox.Show("Böyle bir daire zaten bulunmaktadır!");
                            OrtakNesneler.MekanDosyasınıYaz();
                          
                        }
                        else if(daireBulundu)
                        {
                            OrtakNesneler.MekanDosyasınıYaz();
                            MessageBox.Show("Güncelleme işlemi başarıyla gerçekleştirilmiştir!");

                        }
                        else if(!daireBulundu)
                        {
                            MessageBox.Show("Kayıtlarda böyle bir daire bulunmamaktadır!");
                        }
                       
                    }
                    catch
                    {
                        MessageBox.Show("Güncelleme işlemi gerçekleştirilemedi!");
                    }

                    break;              
                default:
                    break;

            }
        }
    }
}


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



using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B241210370_PROJE_.MODEL
{
    internal class OrtakNesneler
    {
        
        public static List<Oturan> oturanlar = new List<Oturan>();
        public static List<Daire> daireler = new List<Daire>();
        public static List<Havuz> havuzlar = new List<Havuz>();
        public static List<Fitness> fitnessSalonlari = new List<Fitness>();
        public static List<Mekan> mekanlar = new List<Mekan>();
        public static List<Daire> havuzOdemeleri = new List<Daire>();
        public static List<Daire> fitnessOdemeleri = new List<Daire>();

        public static string mdosyaYolu = Path.Combine(Directory.GetCurrentDirectory(), "mekan.txt");
        public static string mgeciciDosyaYolu = Path.Combine(Directory.GetCurrentDirectory(), "mekan.tmp");

        public static string dgeciciDosyaYolu = Path.Combine(Directory.GetCurrentDirectory(), "data.txt");
        public static  string ddosyaYolu = Path.Combine(Directory.GetCurrentDirectory(), "data.tmp");
      
        public static string hgeciciDosyaYolu = Path.Combine(Directory.GetCurrentDirectory(), "havuzkul.tmp");
        public static string hdosyaYolu = Path.Combine(Directory.GetCurrentDirectory(), "havuzkul.txt");

        public static string fgeciciDosyaYolu = Path.Combine(Directory.GetCurrentDirectory(), "fitnesskul.tmp");
        public static string fdosyaYolu = Path.Combine(Directory.GetCurrentDirectory(), "fitnesskul.txt");
      
        public static string odosyaYolu = Path.Combine(Directory.GetCurrentDirectory(), "odemeler.txt");
        public static string ogeciciDosyaYolu = Path.Combine(Directory.GetCurrentDirectory(), "odemeler.tmp");


        public static void MekanDosyasınıYaz()
        {
           

            using (StreamWriter writer = new StreamWriter(mgeciciDosyaYolu, append: true))
            {

                foreach (Mekan mekan in mekanlar)
                {
                    if (mekan is Daire)
                    {
                        Daire daire = (Daire)mekan;
                        writer.WriteLine(daire.binaNo + " " + daire.daireNo + " " + daire.kisiSayisi);
                    }
                    else if (mekan is Havuz)
                    {
                        Havuz havuz = (Havuz)mekan;
                        writer.WriteLine(havuz.binaNo + " " + havuz.kisiSayisi);
                    }
                    else if (mekan is Fitness)
                    {
                        Fitness fitness = (Fitness)mekan;
                        writer.WriteLine(fitness.binaNo + " " + fitness.kisiSayisi);
                    }
                }

            }

            File.Delete(mdosyaYolu);
            File.Move(mgeciciDosyaYolu, mdosyaYolu);

        }


        public static void DataDosyasınıYaz()
        {
            using(StreamWriter writer = new StreamWriter(dgeciciDosyaYolu))
            {
                for (int kisiIndeksi = 0; kisiIndeksi < oturanlar.Count(); kisiIndeksi++)
                {
                    writer.WriteLine(oturanlar[kisiIndeksi].kisi_tipi + " " + oturanlar[kisiIndeksi].ad+ " " + oturanlar[kisiIndeksi].soyad + " " + oturanlar[kisiIndeksi].binaNo + " " + oturanlar[kisiIndeksi].havuzKaydi + " " + oturanlar[kisiIndeksi].fitnessKaydi);
                }
            }

            File.Delete(ddosyaYolu);
            File.Move(dgeciciDosyaYolu, ddosyaYolu);

        }

        public static void HavuzDosyasınıYaz(Oturan oturan, string tarih , bool borcVar)
        {
          
            if(borcVar)
            {
                using (StreamWriter writer = new StreamWriter(hdosyaYolu, append: true))
                {
                    writer.WriteLine(oturan.kisi_tipi + " " + oturan.ad + " " + oturan.soyad + " " + oturan.binaNo + " " + oturan.daireNo + " " + tarih + " " + "kullandırılmadı");
                }
            }
            else
            {
                using (StreamWriter writer = new StreamWriter(hdosyaYolu, append: true))
                {
                    writer.WriteLine(oturan.kisi_tipi + " " + oturan.ad + " " + oturan.soyad + " " + oturan.binaNo + " " + oturan.daireNo + " " + tarih + " " + "kullandırıldı");
                }
            }
           
           

        }

        public static void FitnessDosyasiYaz(Oturan oturan, string tarih, bool borcVar)
        {
            if(borcVar)
            {
                using (StreamWriter writer = new StreamWriter(fdosyaYolu, append: true))
                {
                    writer.WriteLine(oturan.kisi_tipi + " " + oturan.ad + " " + oturan.soyad + " " + oturan.binaNo + " " + oturan.daireNo + " " + tarih + "kullandırılmadı");
                }
            }
            else
            {
                using (StreamWriter writer = new StreamWriter(fdosyaYolu, append: true))
                {
                    writer.WriteLine(oturan.kisi_tipi + " " + oturan.ad + " " + oturan.soyad + " " + oturan.binaNo + " " + oturan.daireNo + " " + tarih + "kullandırıldı");
                }
            }
            
        }

        public static void OdemeDosyasiYaz()
        {

            using (StreamWriter writer = new StreamWriter(ogeciciDosyaYolu, append: true))
            {
                foreach (Daire daire in havuzOdemeleri)
                {
                    writer.WriteLine(daire.binaNo + " " + daire.daireNo + " " + daire.havuzBorc + " " + "havuz");
                }
                foreach (Daire daire in fitnessOdemeleri)
                {
                    writer.WriteLine(daire.binaNo + " " + daire.daireNo + " " + daire.fitnessBorc + " " + "fitness");
                }
            }
            File.Delete(odosyaYolu);
            File.Move(ogeciciDosyaYolu, odosyaYolu);

        }

    }


}

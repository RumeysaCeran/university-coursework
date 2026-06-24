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
    internal abstract class Oturan
    {

       
        public string kisi_tipi {  get; set; }
        public string ad { get; set; }

        public string soyad { get; set; }

        public int binaNo { get; set; }

        public int daireNo { get; set; }

        public string havuzKaydi { get; set; }

        public string fitnessKaydi { get; set; }
        public abstract void havuzKaydiYap();

        public abstract void fitnessKaydiYap();

       

    }
}

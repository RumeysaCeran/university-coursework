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
    internal class Misafir:Oturan
    {
        
        public Misafir(string isim, string soyisim, int bNo, int dNo)
        {
            ad = isim;
            soyad = soyisim;
            binaNo = bNo;
            daireNo = dNo;
            kisi_tipi = "misafir";
            havuzKaydi = "yapılmadı";
            fitnessKaydi = "yapılmadı";
          
        }

        public override void fitnessKaydiYap()
        {
            fitnessKaydi = "yapıldı";

        }
        public override void havuzKaydiYap()
        {
            havuzKaydi = "yapıldı";
        }

       


    }
}

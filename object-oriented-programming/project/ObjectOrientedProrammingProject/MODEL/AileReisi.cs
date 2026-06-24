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
    internal class AileReisi:Oturan
    {

         
        public AileReisi(string isim, string soyIsim, int bNo, int dNo) 
        {
            ad = isim;
            soyad = soyIsim;
            binaNo = bNo;
            daireNo = dNo;
            kisi_tipi = "aile-reisi";
            fitnessKaydi = "yapılmadı";
            havuzKaydi = "yapılmadı";
            
        }

        public override void havuzKaydiYap()
        {
            havuzKaydi = "yapıldı";
                 
        }

        public override void fitnessKaydiYap()
        {
            fitnessKaydi = "yapıldı";
        }

       

    }
}

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
using System.DirectoryServices;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B241210370_PROJE_.MODEL
{
    internal class Daire:Mekan
    {
       
       
        public int daireNo;
        public int havuzBorc;
        public int fitnessBorc;

    
        public Daire(int bNo, int dNo)
        {
            daireNo = dNo;
            binaNo = bNo;
        }

       
        
        public override void kisiSayisiArttir()
        {
            kisiSayisi++;
        }


        public void havuzBorcuAzalt(int x)
        {
            havuzBorc -= x;
        }

        public void fitnessBorcuAzalt(int y)
        {
            fitnessBorc -= y;
        }

    }
}

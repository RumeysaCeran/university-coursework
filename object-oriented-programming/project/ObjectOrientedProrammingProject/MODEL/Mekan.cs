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
    internal abstract class Mekan
    {

       
        public int binaNo { get; set; }
       

        public int kisiSayisi { get; set; }

        public abstract void kisiSayisiArttir();
       
    }
}

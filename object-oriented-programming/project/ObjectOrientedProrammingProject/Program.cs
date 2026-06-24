/*****************************************************
**         SAKARYA ÜNÝVERSÝTESÝ
*       BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**      BÝLGÝSAYAR MÜHENDÝLÝÐÝ BÖLÜMÜ
**      NESNEYE DAYALI PROGRAMLAMA
**      2024-2025 BAHAR DÖNEMÝ
**
**      ÖDEV NUMARASI:3
*       ÖDEV NUMARASI.......:B241210370
**      ÖÐRENCÝ ADI.........:RÜMEYSA CERAN
**      DERSÝN ALDIÐI GRUP..:B
**
************************************************/


namespace B241210370_PROJE_
{
    internal static class Program
    {
        /// <summary>
        ///  The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            
            ApplicationConfiguration.Initialize();
            Application.Run(new Form1());
            
    }
    }
}
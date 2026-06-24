/******************************************************
*               SAKARYA ÜNİVERSİTESİ                  *
*       BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ     *
*           BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ            *
*           PROGRAMLAMAYA GİRİŞ DERSİ ÖDEVİ           *
*                                                     *
*   ÖDEV NUMARASI.....:2                              *
*   ÖĞRENCİ ADI.......:RÜMEYSA CERAN                  *
*******************************************************/



#include <iostream>
#include <locale.h>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;
//tavukların özelliklerini belirlemek için tavuk sınıfı oluşturma
class Tavuk{
private:
    int yumurtlamadigi_gun_sayisi;
    int yumurta_sayisi;
    int ciftlige_geldigi_gunden_gecen_sure;
public:
    int gunluk_yumurta_sayisi = 0;
    int  gunluk_yem_tuketimi = 0;
    Tavuk() :yumurtlamadigi_gun_sayisi(0),yumurta_sayisi(0),ciftlige_geldigi_gunden_gecen_sure(0)
    {}
    Tavuk(int g, int y, int s):yumurtlamadigi_gun_sayisi(0), yumurta_sayisi(0), ciftlige_geldigi_gunden_gecen_sure(0)
    {}

    // çiftliğe geldiği günü hesaplayan fonksiyon
    void ciftlige_geldigi_gunden_gecen_sure_hesaplama() 
    {
        ciftlige_geldigi_gunden_gecen_sure ++;
    }
 
    //tavuğun günlük yumurta sayısını döndüren yumurtla fonksiyonu
    int yumurtla()
    {   
        if (ciftlige_geldigi_gunden_gecen_sure > 3)
        {
          
            gunluk_yumurta_sayisi = rand() % 3;

            if (yumurta_sayisi < 100)
            {
                yumurta_sayisi += gunluk_yumurta_sayisi;            
            }
                     
        }    
        return gunluk_yumurta_sayisi;
    }

    // yumurtlamadığı gün sayısını çiftliğe geldiği 3.günden itibaren tutan fonksiyon
    void yumurtlamadigi_gun_sayisi_hesaplama()
    {
        if (ciftlige_geldigi_gunden_gecen_sure>3)
        {
            //her yumurtlamadığında yumurtlamadığı_gün_sayısı değişkenini bir arttırıyor eğer bu değişken 3 ten küçükse, eğer  yumurtlamadıysa bu değişkeni sıfırlıyor
            if (yumurtlamadigi_gun_sayisi < 3)
            {
                if (gunluk_yumurta_sayisi == 0)
                    yumurtlamadigi_gun_sayisi ++ ;
                
                else
                    yumurtlamadigi_gun_sayisi = 0;
            }

        }
    }

    // günlük yem tüketimini döndüren fonksiyon
    int yem_ye(){
       
        return gunluk_yem_tuketimi =  (rand() % 21) + 100;
    }

   // yumurta sayısı 100' e eşit ve büyükse veya yumurtlamadığı gün sayısı 3'e eşit ve büyükse "1"  değilse "0" değerini döndüren fonksiyon
    int tavuk_kesildi_mi() 
    {
        if (yumurta_sayisi >= 100 ||  yumurtlamadigi_gun_sayisi >= 3)
            return 1;
        else
            return 0;
    }

};

//ciftlik özelliklerini içinde bulunduran ciftlik sınıfı oluşturma
class Ciftlik {
private:
    float baslangic_sermayesi;
    int tavuk_sayisi;
    float yem_fiyati_kg;
    float yumurta_satis_fiyati;
    float tavuk_alim_fiyati;
public:
    int yem_miktari_g = 700000;
    Tavuk* tavuk_dizisi = new Tavuk[tavuk_sayisi];

    Ciftlik() :baslangic_sermayesi(0), tavuk_sayisi(0), yem_fiyati_kg(0), yumurta_satis_fiyati(0), tavuk_alim_fiyati(0)
    {}

    Ciftlik(float s, int t, float yem, float y, float a) :baslangic_sermayesi(s), tavuk_sayisi(t), yem_fiyati_kg(yem), yumurta_satis_fiyati(y), tavuk_alim_fiyati(a)
    {}

    
    // simulasyon yapmak için gun_sayısı parametresiyle tablo oluşturan fonksiyon
    void simulasyonYap(int gun_sayisi)
    {
        srand(time(NULL));
        //çiftliğin bir günki değerlerini tutan değişkenler
        int gunluk_kesilen_tavuk_sayisi = 0;
        float gunluk_gelir = 0.0F;
        float gunluk_gider = 0.0F;
        int gunluk_alinan_yem_miktari = 0;
        int gunluk_toplam_yumurta_sayisi = 0;
        int gunluk_toplam_yem_tuketimi = 0;
        int gunluk_alinan_tavuk_sayisi = 0;
        // tablo oluştururken kullanacağımız string
        string ciftlikgun = "";
        // tavuk dizisi oluşturan döngü
        for (int i = 0; i < tavuk_sayisi; i++)
        {          
            tavuk_dizisi[i] = Tavuk(0,0,0);
        }
        // çiftlikteki bir günün değerlerini hesaplayan döngü
        for (int gun = 0; gun < gun_sayisi; gun++)
        {
            //her yeni bir gün için değerler sıfırlanıyor
            gunluk_kesilen_tavuk_sayisi = 0;
            gunluk_gelir = 0.0F;
            gunluk_gider = 0.0F;
            gunluk_alinan_yem_miktari = 0;
            gunluk_toplam_yumurta_sayisi = 0;
            gunluk_toplam_yem_tuketimi = 0;
            gunluk_alinan_tavuk_sayisi = 0;
            
            //her bir tavuk için o günün değerlerini dömdüren döngü
            for (int i = 0; i < tavuk_sayisi; i++)
            {   
               
                //tavuğun kesilip kesilmediğini kontrol eden koşul, eğer kesildiyse döngüyü bir geri alarak yeni tavuğun da o günki değerleri alınıyor
                if (tavuk_dizisi[i].tavuk_kesildi_mi())
                {
                    gunluk_alinan_tavuk_sayisi++;
                    gunluk_kesilen_tavuk_sayisi++;
                    tavuk_dizisi[i] = Tavuk();
                    i--;
                }
                               
                //bir tavuğun çiftlikteki bir gününde yaptıkları
                tavuk_dizisi[i].ciftlige_geldigi_gunden_gecen_sure_hesaplama();
                gunluk_toplam_yumurta_sayisi = gunluk_toplam_yumurta_sayisi + tavuk_dizisi[i].yumurtla();
                tavuk_dizisi[i].yumurtlamadigi_gun_sayisi_hesaplama();
                gunluk_toplam_yem_tuketimi = gunluk_toplam_yem_tuketimi + tavuk_dizisi[i].yem_ye();               

            }
            // yem miktarı gün sonunda güncelleniyor
            yem_miktari_g = yem_miktari_g - gunluk_toplam_yem_tuketimi;
            if (yem_miktari_g < 70000)
            {
                gunluk_alinan_yem_miktari += 700000;
                yem_miktari_g = yem_miktari_g + gunluk_alinan_yem_miktari;
            }

            // gunluk gelir ve gider hesaplanıp kalan para bulunuyor
            gunluk_gelir = (gunluk_toplam_yumurta_sayisi * yumurta_satis_fiyati) + (gunluk_kesilen_tavuk_sayisi * (tavuk_alim_fiyati) / 2);
            gunluk_gider = ((float)(gunluk_alinan_yem_miktari * yem_fiyati_kg) / 1000) + (gunluk_alinan_tavuk_sayisi*tavuk_alim_fiyati);
            //eğer ilk günse ilk gün aldığımız yem ve tavuk sayısı da o günün giderlerinde sayılıyor
            if (gun == 0)
                gunluk_gider = gunluk_gider + (tavuk_sayisi *  tavuk_alim_fiyati) + (yem_fiyati_kg * ((float)yem_miktari_g / 1000));
            

            baslangic_sermayesi = (baslangic_sermayesi) + ((gunluk_gelir)-(gunluk_gider));
           
            // tablo yapmak için stringe o günün verilerini atama
            if (gun == 0)
            {
                ciftlikgun = to_string(gun + 1) + '-' + to_string(gunluk_toplam_yem_tuketimi) + '-' + to_string(gunluk_toplam_yumurta_sayisi) + '-' + to_string(gunluk_kesilen_tavuk_sayisi) + '-' + to_string(gunluk_gelir) + '-' + to_string(gunluk_gider) +  '-' + to_string(yem_miktari_g) + '-' + to_string(baslangic_sermayesi) + '\n';
            }

            else
            {
                ciftlikgun = ciftlikgun + '-' + to_string(gun + 1) + '-' + to_string(gunluk_toplam_yem_tuketimi) + '-' + to_string(gunluk_toplam_yumurta_sayisi) + '-' + to_string(gunluk_kesilen_tavuk_sayisi) + '-' + to_string(gunluk_gelir) + '-' + to_string(gunluk_gider) + '-' + to_string(yem_miktari_g) + '-' + to_string(baslangic_sermayesi) + '\n';
            }
        
        }

        //stringi tablo şeklinde yazdırma
        int j = 0;
        string kelime = "";
        cout << setw(15) << "Gün" << setw(15) << "Yem Tüketimi" << setw(15)<<"Yumurta" << setw(15) << "Kesilen Tavuk" << setw(15) << "Günlük Gelir" << setw(15)<< "Günlük Gider"<< setw(15) << "Kalan Yem" << setw(15) << "Kalan Para" << endl << endl;
        
        while (ciftlikgun[j] != '\0')
        {
               
            if (ciftlikgun[j] != '-')
            {
                kelime += ciftlikgun[j];
            }

            else
            {                              
                cout << setw(15) << kelime;             
                kelime.clear();
            }
          
            if (baslangic_sermayesi < 0)
            {
                cout << "iflas ettiniz";
                break;
            }
            j++;           
        }        
    }
};

int main()
{
    setlocale(LC_ALL, "Turkish");

    float baslangic_sermayesi;
    int tavuk_sayisi;
    float yem_fiyati_kg;
    float yumurta_satis_fiyati;
    float tavuk_alim_fiyati;
    int simulasyon_gun_sayisi;

    //çiftliği kurarken gerekli verilerin alınması
    cout << "           -Simulasyona Hoşgeldiniz-               ";
    cout << endl << "Baslangic sermayesi............:";
    cin >> baslangic_sermayesi;
    cout << endl << "Tavuk sayısı...................:";
    cin >> tavuk_sayisi;
    cout << endl << "Yem kilogram fiyatı............:";
    cin >> yem_fiyati_kg;
    cout << endl << "Yumurta fiyatı.................:";
    cin >> yumurta_satis_fiyati;
    cout << endl << "Tavuk alım fiyatı..............:";
    cin >> tavuk_alim_fiyati;
    cout << endl << "Simulasyon yapılacak gün sayısı:";
    cin >> simulasyon_gun_sayisi;

    //çiftlik kurucu fonksiyonuna bu verilerin atanması
    Ciftlik ciftlik(baslangic_sermayesi,tavuk_sayisi, yem_fiyati_kg, yumurta_satis_fiyati, tavuk_alim_fiyati);

    ciftlik.simulasyonYap(simulasyon_gun_sayisi);
    return 0;

}

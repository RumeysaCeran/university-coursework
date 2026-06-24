// @ Rümeysa Ceran

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Kisi.h"
#include "Mahalle.h"
#include "Ilce.h"
#include "Sehir.h"
#include "NesneleriOlustur.h"

NesneleriOlustur NesneleriOlusturOlusturma(){
    NesneleriOlustur this = (NesneleriOlustur)malloc(sizeof(struct NESNELERI_OLUSTUR));

    if (!this) {
        printf("Bellek hatasi!\n");
        exit(1);
    }

    this->kisi_dosya    = fopen("./data/kisi_isim_veri.txt",    "r");
    this->ilce_dosya    = fopen("./data/ilce_isim_veri.txt",    "r");
    this->mahalle_dosya = fopen("./data/mahalle_isim_veri.txt", "r");
    this->sehir_dosya   = fopen("./data/sehir_isim_veri.txt",   "r");

    if (!this->kisi_dosya || !this->ilce_dosya ||
        !this->mahalle_dosya || !this->sehir_dosya) {
        printf("Dosya acilamadi!\n");
        exit(1);
    }

    this->sehirSayisi          = 0;
    this->baslangicDegerleriniAl = (int* (*)(struct NESNELERI_OLUSTUR*))&BaslangicDegerleriniAl;
    this->kisileriOlustur        = (Kisi* (*)(struct NESNELERI_OLUSTUR*, int))&KisileriOlustur;
    this->mahalleleriOlustur     = (Mahalle* (*)(struct NESNELERI_OLUSTUR*, int, int))&MahalleleriOlustur;
    this->ilceleriOlustur        = (Ilce* (*)(struct NESNELERI_OLUSTUR*, int, int, int))&IlceleriOlustur;
    this->sehirleriOlustur       = (Sehir* (*)(struct NESNELERI_OLUSTUR*))&SehirleriOlustur;
    this->yoket                  = (void (*)(struct NESNELERI_OLUSTUR*))&NesneleriOlusturYoket;
    this->kayitlariGetir         = &KayitlariGetir;

    return this;
}

int* BaslangicDegerleriniAl(const NesneleriOlustur this){
    char satir[256];
    int* girilen_degerler = malloc(sizeof(int) * 100);

    int boyut = 0;

    while (true) {
        printf("baslangic degerleri (2 basamakli sayilar): ");
        fgets(satir, sizeof(satir), stdin);
        satir[strcspn(satir, "\n")] = '\0';

        char* parca = strtok(satir, " ");
        bool durum = false;
        boyut = 0;

        while (parca != NULL && boyut < 100) {
            char* endptr;
            int sayi = (int)strtol(parca, &endptr, 10);

            if (*endptr != '\0' || sayi < 10 || sayi > 99) {
                printf("Hatali giris!\n");
                durum = true;
                break;
            }

            girilen_degerler[boyut++] = sayi;
            parca = strtok(NULL, " ");
        }

        if (durum) continue;
        break;
    }

    this->sehirSayisi = boyut;
    return girilen_degerler;
}

// 
Kisi* KisileriOlustur(const NesneleriOlustur this, int mahalle_nufusu){
   
    char (*isimSoyisimler)[100] = malloc(mahalle_nufusu * 100);
    this->kayitlariGetir(this->kisi_dosya, isimSoyisimler, mahalle_nufusu);//kisi sayisi kadar isim dosyadan getirilir

    Kisi* kisiler = (Kisi*)malloc(sizeof(Kisi) * mahalle_nufusu); 

    for(int i = 0; i < mahalle_nufusu; i++){
      
        char* ad_soyad = malloc(100);
        strcpy(ad_soyad, isimSoyisimler[i]);
        int yas = 1 + rand() % 50; // 0- 50 arası yas atanir
        kisiler[i] = KisiOlusturma(ad_soyad, yas);
    }

    free(isimSoyisimler);
    return kisiler;
}

Mahalle* MahalleleriOlustur(const NesneleriOlustur this, int mahalle_nufusu, int ilcenin_mahalle_sayisi){
    char (*mahalleIsimleri)[100] = malloc(ilcenin_mahalle_sayisi * 100);
    this->kayitlariGetir(this->mahalle_dosya, mahalleIsimleri, ilcenin_mahalle_sayisi);//mahalle sayisi kadar mahalle ismi dosyadan getirilir

    Mahalle* mahalleler = (Mahalle*)malloc(sizeof(Mahalle) * ilcenin_mahalle_sayisi);

    for(int i = 0; i < ilcenin_mahalle_sayisi; i++){//mahalleler olusturulur
        char* ad = malloc(100);
        strcpy(ad, mahalleIsimleri[i]);
        Kisi* kisiler = this->kisileriOlustur(this, mahalle_nufusu);//her mahallenin kisileri olusturulur
        Mahalle mahalle = MahalleOlusturma(ad, mahalle_nufusu);
        mahalle->kisiler = kisiler;
        mahalleler[i] = mahalle;
    }

    free(mahalleIsimleri);
    return mahalleler;
}

Ilce* IlceleriOlustur(const NesneleriOlustur this, int nufus, int mahalle_sayisi, int ilce_sayisi){
    char (*ilceIsimleri)[100] = malloc(ilce_sayisi * 100);
    this->kayitlariGetir(this->ilce_dosya, ilceIsimleri, ilce_sayisi);//ilce sayisi kadar ilce isimleri getirilir

    Ilce* ilceler = (Ilce*)malloc(sizeof(Ilce) * ilce_sayisi);

    int ilcenin_nufusu        = nufus / ilce_sayisi; 
    int ilcenin_mahalle_sayisi = mahalle_sayisi / ilce_sayisi;
    int mahalle_nufusu        = nufus / mahalle_sayisi;

    for(int i = 0; i < ilce_sayisi; i++){ //ilceler olusturulur
        char* ad = malloc(100);
        strcpy(ad, ilceIsimleri[i]);
        Mahalle* mahalleler = this->mahalleleriOlustur(this, mahalle_nufusu, ilcenin_mahalle_sayisi);//her bir ilcenin mahalleleri olusturulur
        Ilce ilce = IlceOlusturma(ad, ilcenin_nufusu); //ilce olusturulur
        ilce->mahalleler  = mahalleler; //ilceye mahalleler atanir
        ilce->mahalleSayisi = ilcenin_mahalle_sayisi; //ilcenin mahalle sayisi guncellenir
        ilceler[i] = ilce;
    }

    free(ilceIsimleri);
    return ilceler;
}

Sehir* SehirleriOlustur(const NesneleriOlustur this){
    int* girilenDegerler = this->baslangicDegerleriniAl(this);// kullanıcıdan baslangıctaki sehir nufuslari alinir

    if (!girilenDegerler || this->sehirSayisi <= 0) {
        printf("Gecersiz veri!\n");
        return NULL;
    }

    int sehirSayisi = this->sehirSayisi; //nesneleriOlustur dan gelen sehirSayisi alir

    char (*sehirIsimleri)[100] = malloc(sehirSayisi * 100);//sehir sayisi kadar sehir ismi dosyadan getirilir
    this->kayitlariGetir(this->sehir_dosya, sehirIsimleri, sehirSayisi);

    Sehir* sehirler = malloc(sizeof(Sehir) * sehirSayisi);
    if (!sehirler) { printf("malloc fail!\n"); exit(1); }

    for(int i = 0; i < sehirSayisi; i++){ // sehir sayisi kadar sehir olusturulur
        int nufus = girilenDegerler[i];

        int ilce_sayisi = nufus/10;  
        int mahalle_sayisi = nufus%10;
        
        //mahalle_sayisi/ilce_sayisi kontrolu
        int mahalle_ilce_orani = mahalle_sayisi % ilce_sayisi;
        if(mahalle_sayisi == 0) {mahalle_sayisi=ilce_sayisi;} //mahalle sayisi 0 ise ilce sayisi kadar mahalle olusturulmali
        else if(mahalle_ilce_orani != 0) { //eger mahalle sayisi ilce sayisina bolunemiyorsa mahalle sayisi duzenlenmeli
        
                int mahalle_sayisi_artisi = ilce_sayisi - mahalle_ilce_orani; // artırılacak mahalle sayisi hesaplanir
                if((nufus+mahalle_sayisi_artisi)/(10) != ilce_sayisi) {
                    mahalle_sayisi -= mahalle_ilce_orani;
                }
                else {
                    mahalle_sayisi += mahalle_sayisi_artisi;
                }
        }
    
        nufus = mahalle_sayisi+ilce_sayisi*10;
        
        // nufus sayisi mahalle sayisina esit mi kontrolu yapılır
        int nufus_mahalle_orani = nufus % mahalle_sayisi;
        if(nufus_mahalle_orani != 0) { // nufus sayisi mahalle sayisina bolunemiyorsa, nufus sayisi artirilir.
            int nufus_artisi = mahalle_sayisi - nufus_mahalle_orani;
            nufus += nufus_artisi; 
        }

        Ilce* ilceler = this->ilceleriOlustur(this, nufus, mahalle_sayisi, ilce_sayisi);//ilceler olusturulur
        if (!ilceler) continue;

        char* sehir_ad = malloc(100);
        strcpy(sehir_ad, sehirIsimleri[i]);
        Sehir sehir = SehirOlusturma(sehir_ad, nufus); 
        sehir->ilceler   = ilceler; // sehre ilceler atanir
        sehir->ilceSayisi = ilce_sayisi; // sehre ilce sayisi atanir
        sehirler[i] = sehir;
    }

    free(sehirIsimleri);
    free(girilenDegerler);
    return sehirler;
}

//yok edici fonksiyon
void NesneleriOlusturYoket(const NesneleriOlustur this){
    if(this == NULL) return;
    fclose(this->ilce_dosya); // FİLE* pointerlar bırakılır
    fclose(this->kisi_dosya);
    fclose(this->mahalle_dosya);
    fclose(this->sehir_dosya);
    free(this);
}


//verilen dosyadan istenen sayi kadar kaydı yine verilen diziye atar
void KayitlariGetir(FILE* dosya, char kayitlar[][100], int kacSatir){
    if (!dosya) return;

    char satir[100];
    int i = 0;

    while (i < kacSatir && fgets(satir, sizeof(satir), dosya)){
        satir[strcspn(satir, "\n")] = '\0';
        strcpy(kayitlar[i], satir);
        i++;
    }
}
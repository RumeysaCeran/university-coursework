// @ Rümeysa Ceran

#include "NesneleriOlustur.h"
#include "Ilce.h"
#include "Sehir.h"
#include "Mahalle.h"
#include "Kisi.h"
#include "BasamakKontrol.h"

BasamakKontrol BasamakKontrolOlusturma(){
    BasamakKontrol this = (BasamakKontrol)malloc(sizeof(struct BASAMAK_KONTROL));

    this->basamakKontroluIlce      = (Ilce* (*)(struct BASAMAK_KONTROL*, Sehir, NesneleriOlustur))&BasamakKontroluIlce;
    this->basamakKontroluMahalle   = &BasamakKontroluMahalle;
    this->basamakKontroluKisi      = &BasamakKontroluKisi;
    this->nufusBasamakSayisiKontrolu = (void (*)(struct BASAMAK_KONTROL*, Sehir**, int*, const NesneleriOlustur))&NufusBasamakSayisiKontrolu;
    this->yeniIlceSayisiAta        = (void (*)(struct BASAMAK_KONTROL*, int))&YeniIlceSayisiAta;
    this->yoket                    = (void (*)(struct BASAMAK_KONTROL*))&BasamakKontrolYoket;
    this->yeniIlceSayisi           = 0;

    return this;
}

//ilce sayisi 1 mi yoksa daha fazla mı kontrolu yaparak gerekli islemleri yapar
Ilce* BasamakKontroluIlce(const BasamakKontrol this, Sehir sehir, const NesneleriOlustur nesneleriOlustur){
    int ilce_sayisi     = sehir->ilceSayisi;
    int yeni_ilce_sayisi = ilce_sayisi / 2;

   
    if (yeni_ilce_sayisi != 0){//ilce sayisi 1 den fazla is ilceleri ikiye bolerek yeni ilceler olusturur
        Ilce* yeni_ilceler = (Ilce*)malloc(sizeof(Ilce) * yeni_ilce_sayisi);

        // eski sehirdeki ilceleri yeni_ilceler dizisine atar
        for (int i = 0; i < yeni_ilce_sayisi; i++)
        {       
            yeni_ilceler[i] = sehir->ilceler[i];
        }
        
        //eski sehirde kalan ilce sayısı hesaplanir
        int kalan = ilce_sayisi - yeni_ilce_sayisi;
        //kalan_ilceler dizisine yeni_ilceler dısında kalan ilceler atanir
        Ilce* kalan_ilceler =
        malloc(sizeof(Ilce) * kalan);
        for (int i = 0; i < kalan; i++) {

        kalan_ilceler[i] =
        sehir->ilceler[yeni_ilce_sayisi + i];
        }

        //eski adres bırakılır
        free(sehir->ilceler);

        // kalan ilceler eski sehrin ilceler dizisine atanir
        sehir->ilceler = kalan_ilceler;
        // eski sehrin ilce sayisi guncellenir
        sehir->ilceSayisi = kalan;
        
        //yeni ilce sayısı guncellenir
        this->yeniIlceSayisiAta(this, yeni_ilce_sayisi);

        return yeni_ilceler;
    }
    else{//ilce sayısının 1 oldugu durumda mahalle sayılarını bolmek icin BasamakKontorolMahalle fonksiyonuna gider
        this->yeniIlceSayisiAta(this, 1); // bu durumda olusacak yeni ilce sayısı 1 olur
        return this->basamakKontroluMahalle(this,sehir->ilceler[0], nesneleriOlustur);
    }
}


//mahalle sayisinin 1 den fazla olup olmadıgına bakar ve buna gore mahalle bolme islemini gerceklestirir
Ilce* BasamakKontroluMahalle(const BasamakKontrol this, Ilce ilce, const NesneleriOlustur nesneleriOlustur){
    int yeni_mahalle_sayisi = (ilce->mahalleSayisi)/ 2;

    
    if (yeni_mahalle_sayisi != 0){//mahalle sayısının 1 den fazla oldugu durumdur yani mahalle sayııs ikiye bolunur
        Ilce* yeni_ilceler =(Ilce*)malloc(sizeof(Ilce));
        Mahalle* yeni_mahalleler = (Mahalle*)malloc(sizeof(Mahalle) * yeni_mahalle_sayisi);

        //eski ilcenin mahallelerinden yeni mahalle sayisi kadar mahalle yeni_mahalleler dizisine atanir
        for (int i = 0; i < yeni_mahalle_sayisi; i++)
            yeni_mahalleler[i] = ilce->mahalleler[i];

        //yeni olusacak ilcenin nufusu hesaplanir
        int yeni_nufus = yeni_mahalle_sayisi * yeni_mahalleler[0]->super->nufus;

        //eski ilcenin nufusu hesaplanir
        int kalan = ilce->mahalleSayisi - yeni_mahalle_sayisi;

        //yeni mahallelerin atanma isleminden geriye kalan mahalleler, kalan mahalleler dizisine atanir
        Mahalle* kalan_mahalleler =
            malloc(sizeof(Mahalle) * kalan);

        for (int i = 0; i < kalan; i++) {
            kalan_mahalleler[i] =
               ilce->mahalleler[yeni_mahalle_sayisi + i];
        }

        free(ilce->mahalleler);

        //eski ilceye kalan mahalleler atanir
        ilce->mahalleler = kalan_mahalleler;
        ilce->mahalleSayisi = kalan; //eski ilcenin mahalle sayisi guncellenir
        ilce->super->nufus -= yeni_nufus; // eski ilcenin nufusu guncellenir

        // yeni ilce icin dosyadan isim getirilir
        char* ilce_ad = malloc(100);
        char ilce_isim[1][100];
        nesneleriOlustur->kayitlariGetir(nesneleriOlustur->ilce_dosya, ilce_isim, 1);
        strcpy(ilce_ad, ilce_isim[0]);

        //yeni ilce olusturulur
        Ilce yeni_ilce = IlceOlusturma(ilce_ad, yeni_nufus);
        yeni_ilce->mahalleler   = yeni_mahalleler;
        yeni_ilce->mahalleSayisi = yeni_mahalle_sayisi;
        yeni_ilceler[0] = yeni_ilce;

        return yeni_ilceler;
    }else{
        return this->basamakKontroluKisi(ilce, nesneleriOlustur);
    }
}


Ilce* BasamakKontroluKisi(Ilce ilce, const NesneleriOlustur nesneleriOlustur){
    Mahalle mevcut = ilce->mahalleler[0]; 
    int yeni_kisi_sayisi = (mevcut->super->nufus) / 2;

    Ilce* yeni_ilceler = (Ilce*)malloc(sizeof(Ilce));
    Kisi* yeni_kisiler = (Kisi*)malloc(sizeof(Kisi) * yeni_kisi_sayisi);


    // eski mahalleden yeni kisi sayisi kadar kisi yeni_kisiler dizisine atanir
    for (int i = 0; i < yeni_kisi_sayisi; i++){
         yeni_kisiler[i] = mevcut->kisiler[i];
    }
       
    // eski mahallenin nufusu hesaplanir
    int kalan = mevcut->super->nufus - yeni_kisi_sayisi;

    //yeni kisilerden kalan kisiler kalan_kisiler dizisine atanir
    Kisi* kalan_kisiler =
        malloc(sizeof(Kisi) * kalan);

    for (int i = 0; i < kalan; i++) {
        kalan_kisiler[i] =
            mevcut->kisiler[yeni_kisi_sayisi + i];
    }

    free(mevcut->kisiler);

    // eski mahallenin kisilerine kalan kisler atanir
    mevcut->kisiler = kalan_kisiler;
    // eski mahallenin nufusu guncellenir
    mevcut->super->nufus = kalan;

    //eski ilcenin nufusu hesaplanir
    ilce->super->nufus   -= yeni_kisi_sayisi;

    //mahalle adi dosyadan getirilir
    char* mahalle_ad = malloc(100);
    char mahalle_isim[1][100];
    nesneleriOlustur->kayitlariGetir(nesneleriOlustur->mahalle_dosya, mahalle_isim, 1);
    strcpy(mahalle_ad, mahalle_isim[0]);

    // yeni mahalle olusturulur
    Mahalle yeni_mahalle = MahalleOlusturma(mahalle_ad, yeni_kisi_sayisi);
    yeni_mahalle->kisiler = yeni_kisiler;

    Mahalle* yeni_mahalleler =(Mahalle*)malloc(sizeof(Mahalle));
    yeni_mahalleler[0] = yeni_mahalle;

    //yeni ilce adi dosyadan getirilir
    char* ilce_ad = malloc(100);
    char ilce_isim[1][100];
    nesneleriOlustur->kayitlariGetir(nesneleriOlustur->ilce_dosya, ilce_isim, 1);
    strcpy(ilce_ad, ilce_isim[0]);

    //yeni ilce olusturulur
    Ilce yeni_ilce = IlceOlusturma(ilce_ad, yeni_kisi_sayisi);
    yeni_ilce->mahalleler   = yeni_mahalleler;
    yeni_ilce->mahalleSayisi = 1;
    yeni_ilceler[0] = yeni_ilce;

    return yeni_ilceler;
}


// yeni ilce sayısını degistirmek için kullanılır
void YeniIlceSayisiAta(const BasamakKontrol this, int sayi){
    this->yeniIlceSayisi = sayi;
}


// nufusun 4 basamaklı olup olmama durumuna gore islemler gerceklesir
void NufusBasamakSayisiKontrolu(const BasamakKontrol this, Sehir** sehirler, int* sehirSayisi, const NesneleriOlustur nesneleriOlustur){
    // yeni sehirler icin bellekte alan acılır
    Sehir* yeniSehirler = (Sehir*)malloc(sizeof(Sehir));
    int yeniSayac = 0;

    // tum sehirler sırasıyla nufuslarının basamak sayısına gore kontrol edilir
    for (int i = 0; i < *sehirSayisi; i++){
        if (((*sehirler)[i]->super->nufus) > 999){ //  4 basamaktan fazla ise
            Ilce* yeni_ilceler = this->basamakKontroluIlce(this, (*sehirler)[i], nesneleriOlustur); // once ilceler bolunuyor mu kontrolu

            int yeni_ilce_sayisi = this->yeniIlceSayisi; // yein olusan ilce sayısı alınır
            int yeni_nufus = yeni_ilce_sayisi * yeni_ilceler[0]->super->nufus; // yeni sehrin nufusu hesaplanir

            (*sehirler)[i]->super->nufus -= yeni_nufus; // eski sehrin nufusu azaltırılır

            // sehir adı nesneleri olustur struct'ın fonksiyonu olan kayitlariGetir fonksiyonu ile dosyadan getirilir
            char* sehir_ad = malloc(100);
            char isim[1][100];
            nesneleriOlustur->kayitlariGetir(nesneleriOlustur->sehir_dosya, isim, 1);
            strcpy(sehir_ad, isim[0]);

            //yeni sehir olusturulur
            Sehir yeni_sehir = SehirOlusturma(sehir_ad, yeni_nufus);
            yeni_sehir->ilceler   = yeni_ilceler; // yeni ilceler yeni sehre atanir
            yeni_sehir->ilceSayisi = yeni_ilce_sayisi; // sehrin ilce sayısı atanir


            yeniSehirler = realloc(yeniSehirler, (yeniSayac + 1) * sizeof(Sehir)); //
            yeniSehirler[yeniSayac++] = yeni_sehir; // yeni_sehir en son sehirler dizisine eklenmek uzere  yeniSehirler dizisine eklenir

            this->yeniIlceSayisi = 0; //yeniIlceSayisi diger sehirler icin sıfırlanır
        }
    }

    Sehir* tmp = realloc(*sehirler, (*sehirSayisi + yeniSayac) * sizeof(Sehir));
    if (!tmp) return;

    *sehirler = tmp; // sehriler dizisinin alanı artırılır

    for (int i = 0; i < yeniSayac; i++) // sehirler dizisine yeni sehirler atanir
        (*sehirler)[*sehirSayisi + i] = yeniSehirler[i];

    *sehirSayisi += yeniSayac; // sehirSayisi guncellenir
    free(yeniSehirler); // yeniSehirler dizisini tutan adres bırakılır
}

// yok edici fonskiyon
void BasamakKontrolYoket(const BasamakKontrol this){
    if(this == NULL) return;
    free(this);
}
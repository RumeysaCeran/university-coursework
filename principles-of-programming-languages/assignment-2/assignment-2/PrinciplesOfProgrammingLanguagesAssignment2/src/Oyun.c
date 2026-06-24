// @ Rümeysa Ceran

#include <stdbool.h>
#include "stdio.h"
#include "stdlib.h"


#include "Sehir.h"
#include "NesneleriOlustur.h"
#include "BasamakKontrol.h"

#include "Oyun.h"

Oyun OyunOlusturma(){
    Oyun this;
    this = (Oyun)malloc(sizeof(struct OYUN));
    this->turSayisiniAl = &TurSayisiniAl;
    this->turAt = &TurAt;
    this->ekrandaGoster = &EkrandaGoster;
    this->ekranTemizle = &EkranTemizle;
    this->bilgileriGoster = &BilgileriGoster;
    this->oyunaBasla = &OyunaBasla;
    this->yoket = &Yoket;
    this->sehirSayisi = malloc(sizeof(int));
    return this;
};
int TurSayisiniAl(){ //kullanicidan tur sayisi alir
   
    int tur_sayisi;

    while (1) {

        printf("tur sayisi: ");

        if (scanf("%d", &tur_sayisi) == 1) {

            int c;
            while ((c = getchar()) != '\n' && c != EOF); 
            break;
        }

        while(getchar() != '\n');
    }

    return tur_sayisi;	
}

// bir turdaki tum olayları yaptıran fonksiyondur
void TurAt(const Oyun this, Sehir* sehirler, int *sehirSayisi, const NesneleriOlustur nesneleriOlustur){

    for(int s=0; s<*sehirSayisi; s++) {

        int nufus = sehirler[s]->super->nufus;

        int birler = nufus % 10;
        int onlar = nufus / 10;
        if(onlar>9)
		{
				onlar = onlar%10;
		}
        int mahalle_nufus_artis_kati = birler + onlar; // bir mahaledeki nufus artıs kati hesaplanir
        if(mahalle_nufus_artis_kati!=0){
            Ilce* ilceler = sehirler[s]->ilceler;
            int ilceSayisi = sehirler[s]->ilceSayisi;
            for(int i=0; i<ilceSayisi; i++){
                Mahalle* mahalleler = ilceler[i]->mahalleler;
                int mahalleSayisi = ilceler[i]->mahalleSayisi;
                for(int m=0; m<mahalleSayisi; m++) {
                    int eski = mahalleler[m]->super->nufus;
                    int olusturulacakKisiSayisi = mahalleler[m]->super->nufus; 
                    mahalleler[m]->super->nufus = mahalleler[m]->super->nufus*mahalle_nufus_artis_kati; //mahalle nufusu artirilir
                    olusturulacakKisiSayisi = mahalleler[m]->super->nufus - olusturulacakKisiSayisi; // yeni nufusa gore olusturulmasi gereken kisi sayisi hesaplanir
                    Kisi* yeni = nesneleriOlustur->kisileriOlustur(nesneleriOlustur,olusturulacakKisiSayisi);//yeni kisileri olusturur

                    //mahallelerin kisilerinin boyutu artıtılır ki yeni kisiler eklenebilsin
                    Kisi* temp = realloc(mahalleler[m]->kisiler,(eski + olusturulacakKisiSayisi) * sizeof(Kisi));
                    mahalleler[m]->kisiler = temp;
                    for(int k=0; k<olusturulacakKisiSayisi; k++) {
                    mahalleler[m]->kisiler[eski + k] = yeni[k];
                    }
                    free(yeni);
                    mahalleler[m]->super->nufus = eski + olusturulacakKisiSayisi;//yeni nufus guncellenir

                    for(int k=0; k<mahalleler[m]->super->nufus; k++) {
                        mahalleler[m]->kisiler[k]->yas++;
                    }
                }
                ilceler[i]->super->nufus = (mahalleSayisi)*(mahalleler[0]->super->nufus);//ilceninde nufusu artirilir
            
            }
            sehirler[s]->super->nufus = (ilceSayisi)*(ilceler[0]->super->nufus);//en son sehrin nfusu da artirilir
        }
        else {	//birler ve onlar basamagı toplami 0 ise 
				Ilce* ilceler = sehirler[s]->ilceler;
                int ilceSayisi = sehirler[s]->ilceSayisi;
				for(int i=0; i<ilceSayisi; i++) {
					Mahalle* mahalleler = ilceler[i]->mahalleler;
                    int mahalleSayisi = ilceler[i]->mahalleSayisi;
                    for(int m=0; m<mahalleSayisi; m++) {
                        int eski = mahalleler[m]->super->nufus;
						mahalleler[m]->super->nufus = mahalleler[m]->super->nufus + 1; //mahalle nufusu 1 artirilir
						Kisi* yeni = nesneleriOlustur->kisileriOlustur(nesneleriOlustur,1); //1 yeni kisi olusturulur

                        //mahallelerin kisilerinin boyutu artıtılır ki yeni kisi eklenebilsin
                        Kisi* temp = realloc(mahalleler[m]->kisiler,(eski + 1) * sizeof(Kisi));
                        mahalleler[m]->kisiler = temp;
                        for(int k=0; k<1; k++) {
                        mahalleler[m]->kisiler[eski + k] = yeni[k];
                        }

                        free(yeni);

                        mahalleler[m]->super->nufus = eski + 1;//yeni nufus guncellenir

                        for(int k=0; k<mahalleler[m]->super->nufus; k++) {
                            mahalleler[m]->kisiler[k]->yas++;
                        }
					}		
					ilceler[i]->super->nufus = (mahalleSayisi)*(mahalleler[0]->super->nufus); //ilcenin yeni nufusu guncellenir
				}
				sehirler[s]->super->nufus = (ilceSayisi)*(ilceler[0]->super->nufus); // sehrin yeni nufusu guncellenir
		}
    }

}

//ekranda her satırda 5 il olacak sekilde gosterme fonksiyonudur
void EkrandaGoster(Sehir* sehirler, int *sehirSayisi){

    if (!sehirler || *sehirSayisi <= 0) return;

    for(int i=0; i<*sehirSayisi; i++) {

        if (!sehirler[i]) continue;

        printf("[%d]", sehirler[i]->super->nufus);

        if(i != *sehirSayisi - 1)
            printf("-");

        if((i+1) % 5 == 0)
            printf("\n");
    }

    printf("\n");
}

//ekranı full temizler
void EkranTemizle(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
};

//en son kullanıcıdan sati ve sutun bilgisi alarak o sehrin bilgilerini gosterir
void BilgileriGoster(const Oyun this){

    int sutun = 5;
    int toplam = *(this->sehirSayisi);
    int satir = (toplam + sutun - 1) / sutun;

    int array_satir = 0;
    int array_sutun = 0;
    int durum;

    // satir alinir
    do {

        durum = 0;

        printf("Satir giriniz(0 dahil): ");

        if (scanf("%d", &array_satir) != 1) {

            durum = 1;

            while(getchar() != '\n');

            continue;
        }

        while(getchar() != '\n');

        if (array_satir < 0 || array_satir >= satir) {

            printf("Gecersiz satir!\n");

            durum = 1;
        }

    } while (durum);

    //sutun alinir
    do {

        durum = 0;

        printf("Sutun giriniz(0 dahil): ");

        if (scanf("%d", &array_sutun) != 1) {

            durum = 1;

            while(getchar() != '\n');

            continue;
        }

        while(getchar() != '\n');

        if (array_sutun < 0 || array_sutun >= sutun) {

            printf("Gecersiz sutun!\n");

            durum = 1;
        }

        int index = array_satir * sutun + array_sutun;

        if (index < 0 || index >= *(this->sehirSayisi)) {

            printf("Bu konumda sehir yok!\n");

            durum = 1;
        }

    } while (durum);

    int index = array_satir * sutun + array_sutun;

    Sehir sehir = this->sehirler[index];

    printf("Sehir: %s - Nufus: %d\n",
           sehir->super->ad,
           sehir->super->nufus);

    for (int i = 0; i < sehir->ilceSayisi; i++) {

        Ilce ilce = sehir->ilceler[i];

        printf("  Ilce: %s - Nufus: %d\n",
               ilce->super->ad,
               ilce->super->nufus);

        for (int j = 0; j < ilce->mahalleSayisi; j++) {

            Mahalle mahalle = ilce->mahalleler[j];

            printf("    Mahalle: %s - Nufus: %d\n",
                   mahalle->super->ad,
                   mahalle->super->nufus);

            for (int k = 0; k < mahalle->super->nufus; k++) {

                Kisi kisi = mahalle->kisiler[k];

                printf("      %d - %s - %d\n",
                       kisi->id,
                       kisi->ad_soyad,
                       kisi->yas);
            }
        }
    }
}

//tum oyunun oynandıgı fonksiyondur
void OyunaBasla(const Oyun this){

    if (!this) return;

    printf("OyunaBasla girdi\n");

    this->turSayisi = this->turSayisiniAl();// tur sayısı kullanıcıdan alinir

    //oyun boyunca kullanılıcak olan nesnealeriOlusturma ve basamakKontrolu nesneleri olusuturulur
    NesneleriOlustur nesneleriOlustur = NesneleriOlusturOlusturma();
    BasamakKontrol basamakKontrol  = BasamakKontrolOlusturma();

    //sehirler olusturulur
    this->sehirler = nesneleriOlustur->sehirleriOlustur(nesneleriOlustur);

    if (!this->sehirler) {
        printf("sehirler NULL!\n");
        return;
    }

    //oyundaki sehir sayisi guncellenir
    *(this->sehirSayisi) = nesneleriOlustur->sehirSayisi;

    //alınan tur sayısı kadar tur doner
    for(int i=0; i<this->turSayisi; i++) {

        this->turAt(this, this->sehirler, this->sehirSayisi, nesneleriOlustur);

        //tur sonu ekran temizlenir
        this->ekranTemizle();

        printf("TUR %d SON\n", i+1);

        //tur bitimi basamak kontrolu ile yeni sehirler olusturulur
        basamakKontrol->nufusBasamakSayisiKontrolu(
            basamakKontrol,
            &this->sehirler,
            this->sehirSayisi,
            nesneleriOlustur
        );

        //ve yeni olusan sehirler ile birlikte tum sehirler ekranda gosterilir
        this->ekrandaGoster(this->sehirler, this->sehirSayisi);

        if (!this->sehirler) {
            printf("BasamakKontrol sonrası sehirler NULL!\n");
            return;
        }
    }

    //turlar bittikten sonra bilgiler gosterilir
    this->bilgileriGoster(this);

    //oyun bittigi icin bellek bosaltılıt
    nesneleriOlustur->yoket(nesneleriOlustur);
    basamakKontrol->yoket(basamakKontrol);
}

//yok edici fonksiyon
void Yoket(const Oyun this){
    if(this==NULL)return;
    for(int i=0;i<*(this->sehirSayisi);i++){
        this->sehirler[i]->yoket(this->sehirler[i]);
    }
    free(this->sehirler);
    free(this);
};
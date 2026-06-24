// @ Rümeysa Ceran 

#include "Yerlesim.h"
#include "Ilce.h"

//kurucu fonksiyondur, Yerlesim strutct tan miras alir
Ilce IlceOlusturma(char* ad, int nufus){
    Ilce this;
    this = (Ilce)malloc(sizeof(struct ILCE));
    this->super = YerlesimOlusturma(ad, nufus);//super()
    this->yoket = &IlceYoket;
    this->mahalleSayisi = 0;
    return this;
}

//yok edici fonksiyondur ayrıca ilcenin her bir mahalleside yok edilir
void IlceYoket(const Ilce this){
    if(this == NULL) return;

    for(int i = 0; i < this->mahalleSayisi; i++){
        if(this->mahalleler[i] != NULL){
            this->mahalleler[i]->yoket(this->mahalleler[i]);
        }
    }

    free(this->mahalleler);
    this->super->yoket(this->super);
    free(this);
}
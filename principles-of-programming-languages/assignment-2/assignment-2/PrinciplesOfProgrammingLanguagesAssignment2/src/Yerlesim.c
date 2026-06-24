// @ Rümeysa Ceran

#include "Yerlesim.h"


//abstract sınıf benzetimidir
Yerlesim YerlesimOlusturma(char* ad, int nufus){
    Yerlesim this;
    this = (Yerlesim)malloc(sizeof(struct YERLESIM));
    this->ad = ad;
    this->nufus = nufus;
    this->yoket = &YerlesimYoket;
    return this;
}

//yok edici fonksiyon
void YerlesimYoket(const Yerlesim this){
    if(this == NULL) return;
    free(this->ad);
    free(this);
}
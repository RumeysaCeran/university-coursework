// @ Rümeysa Ceran

#include "Sehir.h"
#include "Yerlesim.h"

//kurucu fonksiyondur, Yerlesim strutct tan miras alir
Sehir SehirOlusturma(char* ad, int nufus){
    Sehir this;
    this = (Sehir)malloc(sizeof(struct SEHIR));
    this->super = YerlesimOlusturma(ad, nufus);//super()
    this->yoket = &SehirYoket;
    return this;
}

//yok edici fonksiyondur ayrıca sehrin her bir ilceside yok edilir
void SehirYoket(const Sehir this){
    if(this == NULL) return;

    for(int i = 0; i < this->ilceSayisi; i++){
        if(this->ilceler[i] != NULL){
            this->ilceler[i]->yoket(this->ilceler[i]);
        }
    }

    free(this->ilceler);
    this->super->yoket(this->super);
    free(this);
}
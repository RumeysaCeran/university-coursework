// @ Rümeysa Ceran

#include "Yerlesim.h"
#include "Mahalle.h"
 
//kurucu fonksiyondur, Yerlesim strutct tan miras alir
Mahalle MahalleOlusturma(char* ad, int nufus){
    Mahalle this;
    this = (Mahalle)malloc(sizeof(struct MAHALLE));//super()
    this->super = YerlesimOlusturma(ad, nufus);
    this->yoket = &MahalleYoket;
    return this;
}
 

//yok edici fonksiyondur ayrıca mahllenin her bir kisiside yok edilir
void MahalleYoket(const Mahalle this){
    if(this == NULL) return;
 
    for(int i = 0; i < this->super->nufus; i++){
        if(this->kisiler[i] != NULL){
            this->kisiler[i]->yoket(this->kisiler[i]);
        }
    }
 
    free(this->kisiler);
    this->super->yoket(this->super);
    free(this);
}
 
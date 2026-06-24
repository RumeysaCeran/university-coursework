// @ Rümeysa Ceran 

#include "Kisi.h"
#include <stdlib.h>

static int ID = 0;

Kisi KisiOlusturma(char* ad_soyad, int yas){
    Kisi this;
    this = (Kisi)malloc(sizeof(struct KISI));
    this->ad_soyad = ad_soyad;
    this->yas = yas;
    this->yoket = &KisiYoket;
    this->id = ++ID;
    return this;
}

void KisiYoket(const Kisi this){
    if(this == NULL) return;
    free(this->ad_soyad);
    free(this);
}

//int KisiSayisi(int a){
//    return ++a;
//}
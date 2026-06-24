#ifndef SEHIR_H
#define SEHIR_H

#include "Ilce.h"
#include "Yerlesim.h"

struct SEHIR{
    Yerlesim super;
    Ilce* ilceler;
    int ilceSayisi;
    void(*yoket)(struct SEHIR*);
};

typedef struct SEHIR* Sehir;

Sehir SehirOlusturma(char*, int);
void SehirYoket(const Sehir);

#endif
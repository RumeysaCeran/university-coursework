#ifndef ILCE_H
#define ILCE_H
 
#include "Yerlesim.h"
#include "Mahalle.h"
 
struct ILCE{
    Yerlesim super;
    Mahalle* mahalleler;
    int mahalleSayisi;
    void(*yoket)(struct ILCE*);
};
 
typedef struct ILCE* Ilce;
 
Ilce IlceOlusturma(char*, int);
void IlceYoket(const Ilce);
 
#endif
 
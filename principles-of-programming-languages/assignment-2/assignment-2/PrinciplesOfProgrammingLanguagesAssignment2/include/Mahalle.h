#ifndef MAHALLE_H
#define MAHALLE_H
 
#include "Yerlesim.h"
#include "Kisi.h"
 
struct MAHALLE{
    Yerlesim super;
    Kisi* kisiler;
    void(*yoket)(struct MAHALLE*);
};
 
typedef struct MAHALLE* Mahalle;
 
Mahalle MahalleOlusturma(char*, int);
void MahalleYoket(const Mahalle);
 
#endif
 
#ifndef YERLESIM_H
#define YERLESIM_H

#include "stdio.h"
#include "stdlib.h"
#include "math.h"

struct YERLESIM{
    int nufus;
    char* ad;
    void (*yoket)(struct YERLESIM*);
};

typedef struct YERLESIM* Yerlesim;

Yerlesim YerlesimOlusturma(char*, int);
void YerlesimYoket(const Yerlesim);

#endif
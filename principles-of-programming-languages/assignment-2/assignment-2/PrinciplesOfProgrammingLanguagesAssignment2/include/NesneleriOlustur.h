#ifndef NESNELERIOLUSTUR_H
#define NESNELERIOLUSTUR_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Kisi.h"
#include "Mahalle.h"
#include "Ilce.h"
#include "Sehir.h"

struct NESNELERI_OLUSTUR{
    FILE* kisi_dosya;
    FILE* mahalle_dosya;
    FILE* ilce_dosya;
    FILE* sehir_dosya;
    int* (*baslangicDegerleriniAl)(struct NESNELERI_OLUSTUR*);
    Kisi* (*kisileriOlustur)(struct NESNELERI_OLUSTUR*, int);
    Mahalle* (*mahalleleriOlustur)(struct NESNELERI_OLUSTUR*, int, int);
    Ilce* (*ilceleriOlustur)(struct NESNELERI_OLUSTUR*, int, int, int);
    Sehir* (*sehirleriOlustur)(struct NESNELERI_OLUSTUR*);
    void (*yoket)(struct NESNELERI_OLUSTUR*);
    void (*kayitlariGetir)(FILE*, char[][100], int);
    int sehirSayisi;
};

typedef struct NESNELERI_OLUSTUR* NesneleriOlustur;

NesneleriOlustur NesneleriOlusturOlusturma();
int* BaslangicDegerleriniAl(const NesneleriOlustur);
Kisi* KisileriOlustur(const NesneleriOlustur, int);
Mahalle* MahalleleriOlustur(const NesneleriOlustur, int, int);
Ilce* IlceleriOlustur(const NesneleriOlustur, int, int, int);
Sehir* SehirleriOlustur(const NesneleriOlustur);
void KayitlariGetir(FILE*, char[][100], int);
void NesneleriOlusturYoket(const NesneleriOlustur);

#endif
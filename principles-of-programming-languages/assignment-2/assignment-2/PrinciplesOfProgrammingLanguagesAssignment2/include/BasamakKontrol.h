#ifndef BASAMAKKONTROL_H
#define BASAMAKKONTROL_H

#include "Ilce.h"
#include "Sehir.h"
#include "Mahalle.h"
#include "Kisi.h"
#include "NesneleriOlustur.h"

struct BASAMAK_KONTROL{
    Ilce* (*basamakKontroluIlce)(struct BASAMAK_KONTROL*, Sehir, NesneleriOlustur);
    Ilce* (*basamakKontroluMahalle)(struct BASAMAK_KONTROL*,Ilce, const NesneleriOlustur);
    Ilce* (*basamakKontroluKisi)(Ilce, const NesneleriOlustur);
    void (*nufusBasamakSayisiKontrolu)(struct BASAMAK_KONTROL*, Sehir**, int*, const NesneleriOlustur);
    void (*yeniIlceSayisiAta)(struct BASAMAK_KONTROL*, int);
    void (*yoket)(struct BASAMAK_KONTROL*);
    int yeniIlceSayisi;
};

typedef struct BASAMAK_KONTROL* BasamakKontrol;

BasamakKontrol BasamakKontrolOlusturma();

Ilce* BasamakKontroluIlce(const BasamakKontrol, Sehir, const NesneleriOlustur);
Ilce* BasamakKontroluMahalle(const BasamakKontrol, Ilce,const NesneleriOlustur);
Ilce* BasamakKontroluKisi(Ilce, const NesneleriOlustur);
void NufusBasamakSayisiKontrolu(const BasamakKontrol, Sehir**, int*, const NesneleriOlustur);
void YeniIlceSayisiAta(const BasamakKontrol, int);
void BasamakKontrolYoket(const BasamakKontrol);

#endif
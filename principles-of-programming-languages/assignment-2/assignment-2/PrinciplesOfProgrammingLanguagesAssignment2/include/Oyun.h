#ifndef OYUN_H
#define OYUN_H

#include "Sehir.h"
#include "NesneleriOlustur.h"
#include "BasamakKontrol.h"

struct OYUN{
    int turSayisi;
    Sehir* sehirler;
    int* sehirSayisi;
    int (*turSayisiniAl)();
    void (*turAt)(struct OYUN*, Sehir*, int*, const NesneleriOlustur);
    void (*ekrandaGoster)(Sehir*, int*);
    void (*ekranTemizle)();
    void (*bilgileriGoster)(struct OYUN*);
    void (*oyunaBasla)(struct OYUN*);
    void (*yoket)(struct OYUN*);
};

typedef struct OYUN* Oyun;

Oyun OyunOlusturma();
int TurSayisiniAl();
void TurAt(const Oyun, Sehir*, int*, const NesneleriOlustur);
void EkrandaGoster(Sehir*, int*);
void EkranTemizle();
void BilgileriGoster(const Oyun);
void OyunaBasla(const Oyun);
void Yoket(const Oyun);

#endif
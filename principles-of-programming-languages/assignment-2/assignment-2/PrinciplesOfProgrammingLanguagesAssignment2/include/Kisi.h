#ifndef KISI_H
#define KISI_H
 
struct KISI{
    char* ad_soyad;
    int yas;
    int id;
    void (*yoket)(struct KISI*);
    //int (*KisiSayisi)();
};
 
typedef struct KISI* Kisi;
 
Kisi KisiOlusturma(char*, int);
void KisiYoket(const Kisi);
//int KisiSayisi(int);
 
#endif





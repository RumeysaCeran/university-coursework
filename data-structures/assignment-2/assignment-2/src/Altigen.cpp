/**
* AgacDugum.cpp 
* Altigen bir öncelikli dairesel kuyruktur, AgacDugum düğümüdür.
* ÖDEV-2
* Rümeysa Ceran
*/

#include "Altigen.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector> 

using namespace std;


Altigen::Altigen() {
    ilk = son = nullptr;
}


Altigen::~Altigen() {
    if (!ilk) return;
    
  
    son->sonraki = nullptr; 
    
    AgacDugum* gec = ilk;
    while (gec != nullptr) {
        AgacDugum* sil = gec;
        gec = gec->sonraki;
        delete sil; 
    }
    ilk = son = nullptr;
}

void Altigen::ekle(AgacDugum* yeniDugum) {
    if (!ilk) {
        ilk = son = yeniDugum;
        yeniDugum->sonraki = yeniDugum; 
    } else {
        son->sonraki = yeniDugum;
        son = yeniDugum;
        son->sonraki = ilk; 
}
}


AgacDugum* Altigen::cikarIlk() {
    if (!ilk) return nullptr; 

    AgacDugum* cikan = ilk;

    if (ilk == son) {
        ilk = son = nullptr;
    } else {
        ilk = ilk->sonraki;
        son->sonraki = ilk; 
    }
    
    cikan->sonraki = nullptr; 
    return cikan;
}



AgacDugum* Altigen::enYuksekAgaciBul() {
    if (!ilk) return nullptr;
    
    AgacDugum* enYuksek = ilk;
    int maxYukseklik = ilk->agac->getirKokMaxYukseklik(); 
    
    AgacDugum* gec = ilk->sonraki;
    
    do {
        int mevcutYukseklik = gec->agac->getirKokMaxYukseklik();
        
     
        if (mevcutYukseklik > maxYukseklik) {
            maxYukseklik = mevcutYukseklik;
            enYuksek = gec;
        }
        
        gec = gec->sonraki;
    } while (gec != ilk);
    
    return enYuksek;
}



AgacDugum* Altigen::cikarOncelikli() {
    if (!ilk) return nullptr; 
    
    AgacDugum* oncelikli = enYuksekAgaciBul();
    
    if (ilk == son) { 
        ilk = son = nullptr;
        oncelikli->sonraki = nullptr;
        return oncelikli;
    }

    if (oncelikli == ilk) { 
        return cikarIlk();
    }
    
   
    AgacDugum* onceki = ilk;
    while (onceki->sonraki != oncelikli) {
        onceki = onceki->sonraki;
    }
    
    
    onceki->sonraki = oncelikli->sonraki;
    
    if (oncelikli == son) {
        son = onceki;
    }
    
    oncelikli->sonraki = nullptr;
    return oncelikli;
}


int Altigen::AgacSayisi() {
    if (!ilk) return 0;
    int sayi = 0;
    AgacDugum* gec = ilk;
    do {
        sayi++;
        gec = gec->sonraki;
    } while (gec != ilk);
    return sayi;
}


int Altigen::Oran() {
    if (AgacSayisi() == 0) return 0;


    int ilkKoku = 0;
    if (ilk && ilk->agac->kok) {
        ilkKoku = ilk->agac->kok->veri;
    } else {
        return 0; 
    }


    AgacDugum* oncelikliDugum = this->enYuksekAgaciBul(); 
    
    int oncelikliKoku = 0;
    if (oncelikliDugum && oncelikliDugum->agac->kok) {
        oncelikliKoku = oncelikliDugum->agac->kok->veri;
    } else {
        return 0;
    }

 
    if (oncelikliKoku != 0) {
        return ilkKoku / oncelikliKoku; 
    }

    return 0; 
}




IkiliAramaAgaci* Altigen::getir() {
    if (!ilk) throw std::out_of_range("Altigen bos");
    return ilk->agac;
}

std::vector<int> Altigen::AltigenOncelikliPostOrder() {
    AgacDugum* oncelikli = enYuksekAgaciBul();
    if (!oncelikli) return {};
  
    return oncelikli->agac->PostorderElemanlariAl();
}


void Altigen::AltigenAgaclarinaElemanEkle(std::vector<int> sayilar) {
    if (!ilk || sayilar.empty()) return;

    int agacSayisi = AgacSayisi();
    AgacDugum* gec = ilk;
    
    for (size_t i = 0; i < sayilar.size(); ++i) {
        int index = i % agacSayisi; 
        
       
        gec = ilk;
        for (int k = 0; k < index; ++k) {
            gec = gec->sonraki;
        }
        
        gec->agac->ekle(sayilar[i]);
    }
}

std::vector<int> Altigen::AltigenIlkAgacPostOrder() {
    if (!ilk) {
     
        return {};
    }
   
    return ilk->agac->PostorderElemanlariAl();
}
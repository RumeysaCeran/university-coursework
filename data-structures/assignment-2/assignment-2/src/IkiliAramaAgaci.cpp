/**
* IkiliAramaAgaci.cpp 
* SayiDugum düğümüdür.
* ÖDEV-2
* Rümeysa Ceran
*/
#include "IkiliAramaAgaci.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

IkiliAramaAgaci::IkiliAramaAgaci() {
    kok = nullptr;
    kokMaxYukseklik = -1;
}

IkiliAramaAgaci::~IkiliAramaAgaci() {
    temizle(kok);
    kok = nullptr;
}

void IkiliAramaAgaci::temizle(SayiDugum* dugum) {
    if (!dugum) return;
    temizle(dugum->sol);
    temizle(dugum->sag);
    delete dugum;
}

void IkiliAramaAgaci::ekle(int veri) {
    if (!kok) {
        kok = new SayiDugum(veri);
    } else {
        ekle(veri, kok);
    }
   
    kokMaxYukseklik = yukseklik(kok); 
}

void IkiliAramaAgaci::ekle(int veri, SayiDugum*& aktifDugum) {
    if (veri < aktifDugum->veri) {
        if (aktifDugum->sol)
            ekle(veri, aktifDugum->sol);
        else
            aktifDugum->sol = new SayiDugum(veri);
    } else if (veri > aktifDugum->veri) {
        if (aktifDugum->sag)
            ekle(veri, aktifDugum->sag);
        else
            aktifDugum->sag = new SayiDugum(veri);
    }
}

int IkiliAramaAgaci::yukseklik(SayiDugum* aktifDugum) {
    if (!aktifDugum) return -1;
    return 1 + max(yukseklik(aktifDugum->sol), yukseklik(aktifDugum->sag));
}

int IkiliAramaAgaci::getirKokMaxYukseklik() const {
    return kokMaxYukseklik;
}


std::vector<int> IkiliAramaAgaci::PostorderElemanlariAl() {
    std::vector<int> liste;
    PostorderElemanlariAl(kok, liste);
    return liste;
}


void IkiliAramaAgaci::PostorderElemanlariAl(SayiDugum* aktif, std::vector<int>& liste) {
    if (!aktif) return;
    PostorderElemanlariAl(aktif->sol, liste);
    PostorderElemanlariAl(aktif->sag, liste);
    liste.push_back(aktif->veri);
}



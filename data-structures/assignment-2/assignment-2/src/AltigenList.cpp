/**
* AltigenList.cpp 
* AltigenDugum düğümüdür.Tek tönlü dairesel ibr listedir.Altigenleri dolaşmayı sağlar.
* ÖDEV-2
* Rümeysa Ceran
*/
#include "AltigenList.hpp"
#include "AltigenDugum.hpp"
#include "Altigen.hpp"
#include "AgacDugum.hpp"
#include "IkiliAramaAgaci.hpp"
#include "SayiDugum.hpp" 
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm> 
#include <windows.h> 


void ekraniGuncelle(AltigenList* liste, int mevcutAdim, int toplamAdim);

using namespace std;


AltigenList::AltigenList() {
    ilk = son = nullptr;
    srand(time(0));
}

AltigenList::~AltigenList() {
    if (!ilk) return;
    
  
    son->sonraki = nullptr; 
    
    AltigenDugum* gec = ilk;
    while (gec != nullptr) {
        AltigenDugum* sil = gec;
        gec = gec->sonraki;
        delete sil; 
    }
    ilk = son = nullptr;
}


void AltigenList::ekle(Altigen* altigen) {
    AltigenDugum* yeni = new AltigenDugum(altigen);
    if (!ilk) {
        ilk = son = yeni;
        yeni->sonraki = yeni;
    } else {
        son->sonraki = yeni;
        son = yeni;
        son->sonraki = ilk;
    }
}


void AltigenList::AltigenEkle(Altigen* altigen) {
    ekle(altigen);
}

bool AltigenList::bosMu() {
    return ilk == nullptr;
}

int AltigenList::AltigenSayisi() {
    if (!ilk) return 0;
    int sayi = 0;
    AltigenDugum* gec = ilk;
    do {
        sayi++;
        gec = gec->sonraki;
    } while (gec != ilk);
    return sayi;
}


void AltigenList::AltigeniSil(AltigenDugum* onceki) {
    if (!onceki || !ilk) return;
    
    AltigenDugum* silinecek = onceki->sonraki;

    
    if (silinecek == silinecek->sonraki) {
        delete silinecek;
        ilk = son = nullptr;
        return;
    }
    
    onceki->sonraki = silinecek->sonraki;
    
    
    if (silinecek == ilk) ilk = silinecek->sonraki;
    if (silinecek == son) son = onceki;

    
    delete silinecek; 
}


void AltigenList::DosyadanOlustur(const string& dosyaAdi, int toplamSatir) {
    ifstream dosya(dosyaAdi);
    if (!dosya.is_open()) {
        cerr << "Hata: data.txt dosyasi acilamadi!" << endl;
        return;
    }
    
    string satir;
    Altigen* mevcutAltigen = nullptr;
    int agacSayisi = 6; 
    int okunanSatir = 0;
    
    int tahminiAltigenSayisi = (toplamSatir + 5) / 6;

    ekraniGuncelle(this, 0, tahminiAltigenSayisi);
   

    while (getline(dosya, satir)) {
        okunanSatir++;
        stringstream ss(satir);
        int sayi;
        
        
        if (agacSayisi == 6) { 
            mevcutAltigen = new Altigen();
            this->ekle(mevcutAltigen);
            agacSayisi = 0;
        }
        
        
        IkiliAramaAgaci* yeniBst = new IkiliAramaAgaci(); 
        while (ss >> sayi) {
            yeniBst->ekle(sayi); 
        }
        
       
        AgacDugum* yeniDugum = new AgacDugum(yeniBst); 
        mevcutAltigen->ekle(yeniDugum); 
        
        agacSayisi++; 
        
       
        ekraniGuncelle(this, okunanSatir, tahminiAltigenSayisi);
        
      
    }
    dosya.close();
    
    ekraniGuncelle(this, toplamSatir, tahminiAltigenSayisi);
 
}



void AltigenList::TurAt(int tur, int* ekran, int elemanSayisi) {
    if (AltigenSayisi() <= 1) return; 

   
    AltigenDugum* onceki = son; 
    AltigenDugum* gec = ilk;

    int baslangicAltigenSayisi = AltigenSayisi();
    int islenenAltigenSayisi = 0;
    

    while (islenenAltigenSayisi < baslangicAltigenSayisi && AltigenSayisi() > 1) { 
        
       
        AltigenDugum* sonrakiGec = gec->sonraki; 
        
        Altigen* altigen = gec->altigen;
        Altigen* sagAltigen = gec->sonraki->altigen; 
        
        vector<int> v;
        
      
        if (altigen->AgacSayisi() > 0) {
            if (tur % 2 == 0) {
                v = altigen->AltigenOncelikliPostOrder();
                altigen->cikarOncelikli();
            } else { 
                v = altigen->AltigenIlkAgacPostOrder();
                altigen->cikarIlk();
            }
            
           
            sagAltigen->AltigenAgaclarinaElemanEkle(v);
        }

       
        if (altigen->AgacSayisi() == 0) {
           
            AltigeniSil(onceki); 
           
        } else {
           
            onceki = gec; 
        }
        
       
        gec = sonrakiGec;
        islenenAltigenSayisi++;

        if (AltigenSayisi() <= 1) break;
    }
}


void AltigenList::DosyayaYazdir(const string& data) {
    ofstream dosya(data);
    if (!dosya.is_open()) return;

    if (!ilk) return;

    AltigenDugum* gec = ilk;

    do {
        Altigen* altigen = gec->altigen;
        
        if (altigen->AgacSayisi() > 0) {
            AgacDugum* a = altigen->ilk;
            
           
            do {
                
                postorderTekSatir(a->agac->kok, dosya);
                dosya << endl; 
                
                a = a->sonraki;
            } while (a != altigen->ilk);
        }
        
        gec = gec->sonraki;
    } while (gec != ilk);
    
    dosya.close(); 
}


void AltigenList::postorderTekSatir(SayiDugum* dugum, ofstream& dosya) {
    if (!dugum) return;
    postorderTekSatir(dugum->sol, dosya);
    postorderTekSatir(dugum->sag, dosya);
    dosya << dugum->veri << " ";
}


IkiliAramaAgaci* AltigenList::randomAgacOlustur() {
    IkiliAramaAgaci* agac = new IkiliAramaAgaci();
    int n = 3 + rand() % 6; 
    for (int i = 0; i < n; i++)
        agac->ekle(1 + rand() % 1000); 
    return agac;
}


void AltigenList::rastgeleAgaclariAltigenlereDagit(int toplamAgac) {
    Altigen* altigen = new Altigen();
    for (int i = 0; i < toplamAgac; i++) {
        IkiliAramaAgaci* agac = randomAgacOlustur();
        
        if (altigen->AgacSayisi() == 6) {
            
            ekle(altigen); 
            altigen = new Altigen();
        }
        
        
        AgacDugum* yeniDugum = new AgacDugum(agac);
        altigen->ekle(yeniDugum); 
    }
    
    
    if (altigen->AgacSayisi() > 0)
        ekle(altigen);
    else 
        delete altigen;
}


SayiDugum* AltigenList::AgacPostorderIleKur(const vector<int>& post) {
    if (post.empty()) return nullptr;

   
    int kokDeger = post.back();
    SayiDugum* kok = new SayiDugum(kokDeger);

    std::vector<int> sol;
    std::vector<int> sag;
    
    
    for (size_t i = 0; i < post.size() - 1; i++) {
        if (post[i] < kokDeger) 
            sol.push_back(post[i]);
        else 
            sag.push_back(post[i]);
    }


    kok->sol = AgacPostorderIleKur(sol);
    kok->sag = AgacPostorderIleKur(sag);
    return kok;
}


int* AltigenList::OranlariDinamikDizi(int* ekran) {
    if (!ilk) return nullptr;

    AltigenDugum* gec = ilk;
    int index = 0;

    do {
        
        ekran[index++] = gec->altigen->Oran(); 
        gec = gec->sonraki;
    } while (gec != ilk);

    return ekran; 
}


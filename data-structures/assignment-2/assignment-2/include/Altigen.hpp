#ifndef ALTIGEN_HPP
#define ALTIGEN_HPP
#include "AgacDugum.hpp"
#include "IkiliAramaAgaci.hpp"
#include <vector>
#include <string> 

using namespace std;

class Altigen {
public:
    AgacDugum* ilk;
    AgacDugum* son;

    Altigen();
    ~Altigen();

    void ekle(AgacDugum* yeniDugum); 
    AgacDugum* cikarIlk();
    AgacDugum* cikarOncelikli(); 
    int AgacSayisi();
    int Oran();   
    AgacDugum* enYuksekAgaciBul();  
    vector<int> AltigenOncelikliPostOrder();   
    vector<int> AltigenIlkAgacPostOrder();   
    void AltigenAgaclarinaElemanEkle(std::vector<int> sayilar);
    IkiliAramaAgaci* getir();

    
};

#endif
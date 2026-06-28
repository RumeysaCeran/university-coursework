#ifndef ALTIGENLIST_HPP
#define ALTIGENLIST_HPP
#include "AltigenDugum.hpp"
#include "Altigen.hpp"
#include "IkiliAramaAgaci.hpp"
#include <string>
#include <vector>
using namespace std;

class AltigenList {
public:
    AltigenDugum* ilk;
    AltigenDugum* son;
  
    AltigenList();
    ~AltigenList();

    void ekle(Altigen* altigen);
    bool bosMu();
    void rastgeleAgaclariAltigenlereDagit(int toplamAgac);
    void DosyayaYazdir(const string& data);
    void DosyadanOlustur(const string& dosyaAdi,int toplamSatir);
    void AltigenEkle(Altigen* altigen);
    int AltigenSayisi();
    int* OranlariDinamikDizi(int* ekran);
    void AltigeniSil(AltigenDugum* silinecekOncekiDugum); 
    
    
    void TurAt(int tur, int* ekran, int elemanSayisi); 

private:
    IkiliAramaAgaci* randomAgacOlustur();
    void postorderTekSatir(SayiDugum* dugum, ofstream& dosya);
    SayiDugum* AgacPostorderIleKur(const vector<int>& post);
};
#endif
/**
* main.cpp 
*Önce dosyadan oluşturma yaparak daha sonra kullanıcıdan tur sayısı istiyor ve TurAt fonksiyonunu çağırıyor.
* ÖDEV-2
* Rümeysa Ceran
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits> 
#include <windows.h> 


#include "AltigenList.hpp" 


using namespace std;


void ekranTemizle() {
   
    system("cls"); 
  
}

void tusaBasmayiBekle() {
    cout << "\nDevam etmek için ENTER'a basın...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


void ekraniGuncelle(AltigenList* liste, int mevcutAdim, int toplamAdim) {
    ekranTemizle(); 
    
    AltigenDugum* gec = liste->ilk;
    int sayac = 0;
    const int MAX_SUTUN = 6;
    
    if (gec) {
        do {
          
           
            cout << gec->altigen->Oran(); 
            
            sayac++;
            
            if (sayac % MAX_SUTUN == 0) {
                cout << "\n"; 
            } else {
                cout << "\t"; 
            }
            
            gec = gec->sonraki;
        } while (gec != liste->ilk);
        
        if (sayac % MAX_SUTUN != 0) {
            cout << "\n"; 
        }
    } 
    
}




int main() {
   
    int toplamSatir = 0;
    ifstream sayacDosya("data.txt");
    if (!sayacDosya.is_open()) {
        cerr << "Hata: data.txt dosyasi acilamadi!" << endl;
        tusaBasmayiBekle();
        return 1;
    }
    string satir;
    while (getline(sayacDosya, satir)) {
        toplamSatir++;
    }
    sayacDosya.close();
    
   
    int tahminiAltigenSayisi = (toplamSatir + 5) / 6;

    
    AltigenList* altigenList = new AltigenList();
    
    altigenList->DosyadanOlustur("data.txt", toplamSatir); 

  
    ekranTemizle();
    int istenenTurSayisi;

    do {
        cout << "Lutfen yapilmasini istediginiz tur sayisini giriniz (Minimum 1): ";
        cin >> istenenTurSayisi;
    } while (istenenTurSayisi < 1);
    
    int mevcutTur = 1;

    tusaBasmayiBekle();

    int elemanSayisi = altigenList->AltigenSayisi();
    if (elemanSayisi == 0) elemanSayisi = 1; 

    int* ekran = new int[elemanSayisi]; 



    while (altigenList->AltigenSayisi() > 1 && mevcutTur <= istenenTurSayisi) { 
    
    int yeniElemanSayisi = altigenList->AltigenSayisi();
    if (yeniElemanSayisi == 0) yeniElemanSayisi = 1; 
    
    
    if (yeniElemanSayisi != elemanSayisi) {
        delete[] ekran;
        elemanSayisi = yeniElemanSayisi;
        ekran = new int[elemanSayisi];
    }
    
  
   
    ekraniGuncelle(altigenList, mevcutTur, istenenTurSayisi); 
    
    

   
    altigenList->TurAt(mevcutTur, ekran, elemanSayisi); 
    
  
    mevcutTur++;
}
    
   
 
    altigenList->DosyayaYazdir("data.txt");
    delete[] ekran;
    delete altigenList; 

    return 0;
}
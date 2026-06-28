#ifndef IKILIARAMAAGACI_HPP
#define IKILIARAMAAGACI_HPP
#include "SayiDugum.hpp"
#include <vector>

class IkiliAramaAgaci {
public:
    SayiDugum* kok;
    int kokMaxYukseklik;

    IkiliAramaAgaci();
    ~IkiliAramaAgaci();

    void ekle(int veri);
    
    
    std::vector<int> PostorderElemanlariAl(); 

   
    int getirKokMaxYukseklik() const;

private:
    void ekle(int veri, SayiDugum*& aktifDugum);
    void temizle(SayiDugum* dugum);
  
   
    int yukseklik(SayiDugum* aktifDugum);
    
   
    void PostorderElemanlariAl(SayiDugum* aktif, std::vector<int>& liste); 
};

#endif
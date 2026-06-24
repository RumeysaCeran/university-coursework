// @ Rümeysa Ceran

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Oyun.h"

int main(){
    srand(time(NULL));
    Oyun oyun = OyunOlusturma();// oyun kurucu fonksiyonu olusturulur
    oyun->ekranTemizle(); // baslangıcta ekran temizlenir
    oyun->oyunaBasla(oyun); // oyuna baslanır
    printf("Devam etmek icin bir tusa bas...");
    while(getchar() != '\n');
    getchar();
    oyun->yoket(oyun); // en son tum nesneler silinir
    return 0;
}
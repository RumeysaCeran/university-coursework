/**
* AltigenDugum.cpp 
* Altigeni veri olarak tutan düğümdür.AltigenListin düğümüdür.
* ÖDEV-2
* Rümeysa Ceran
*/
#include "AltigenDugum.hpp"

AltigenDugum::AltigenDugum(Altigen* altigen) {
    this->altigen = altigen;
    sonraki = nullptr;
}

AltigenDugum::~AltigenDugum() {
    delete altigen;
    altigen = nullptr;
}
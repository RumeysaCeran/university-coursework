/**
* AgacDugum.cpp 
* İkiliAramaAgacını veri olarak tutan düğümdür.Altigen kuyruğunun düğümüdür.
* ÖDEV-2
* Rümeysa Ceran
*/
#include "AgacDugum.hpp"

AgacDugum::AgacDugum(IkiliAramaAgaci* agac) {
    this->agac = agac;
    sonraki = nullptr;
}

AgacDugum::~AgacDugum() {
    delete agac;
    agac = nullptr;
}
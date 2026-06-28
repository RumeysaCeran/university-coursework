#ifndef AGACDUGUM_HPP
#define AGACDUGUM_HPP

#include "IkiliAramaAgaci.hpp"

class AgacDugum {
public:
    IkiliAramaAgaci* agac;
    AgacDugum* sonraki;

    AgacDugum(IkiliAramaAgaci* agac);
    ~AgacDugum();
};
#endif
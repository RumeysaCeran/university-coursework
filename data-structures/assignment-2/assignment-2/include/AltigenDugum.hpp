#ifndef ALTIGENDUGUM_HPP
#define ALTIGENDUGUM_HPP

#include "Altigen.hpp"

class AltigenDugum {
public:
    Altigen* altigen;
    AltigenDugum* sonraki;

    AltigenDugum(Altigen* altigen);
    ~AltigenDugum();
};

#endif
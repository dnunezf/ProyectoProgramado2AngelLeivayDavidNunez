#pragma once
#include "Strategy.h"
#include <cstdlib>

class JuegoCercano : public Strategy
{
    private:
        int lastT1, lastT2; // Última posición jugada por el oponente

    public:
        JuegoCercano();
        void placeLine(Jugada&, int);
};
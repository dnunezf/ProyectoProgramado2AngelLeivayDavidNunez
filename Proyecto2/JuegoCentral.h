#pragma once
#include "Strategy.h"

class JuegoCentral : public Strategy 
{
    public:
        void placeLine(Jugada& jugada, int jugador);
};

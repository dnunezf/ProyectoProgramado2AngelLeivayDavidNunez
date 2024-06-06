#pragma once
#include "Strategy.h"
#include <cstdlib>
#include <cmath>

class JuegoCentral : public Strategy 
{
    public:
        void placeLine(Jugada&, int);
};

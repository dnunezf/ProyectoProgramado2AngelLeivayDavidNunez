#pragma once
#include "Strategy.h"
#include <cstdlib>

class JuegoPeriferico : public Strategy 
{
    public:
        void placeLine(Jugada&, int);
};

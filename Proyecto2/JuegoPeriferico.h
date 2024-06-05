#pragma once
#include "Strategy.h"

class JuegoPeriferico : public Strategy 
{
    public:
        void placeLine(Jugada&, int);
};

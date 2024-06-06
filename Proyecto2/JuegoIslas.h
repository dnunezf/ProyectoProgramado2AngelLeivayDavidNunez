#pragma once
#include"Strategy.h"
#include <cstdlib>

class JuegoIslas : public Strategy 
{
    public:
        void placeLine(Jugada&, int);
};
/* -------------------------------------------------------------------+
* |
* (c) 2024 |
* 1-1934-0740 - �ngel Ari�n Leiva Abarca   |
* 1-1908-0008 - David Alberto N��ez Franco |
* version 1.0.0 2024-06-01 |
* |
* -------------------------------------------------------------------+
*/

#pragma once
#include "Strategy.h"
#include <cstdlib>

class JuegoPeriferico : public Strategy 
{
    public:
        void placeLine(Jugada&, int);
};

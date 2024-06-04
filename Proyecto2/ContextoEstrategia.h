#pragma once
#include "Strategy.h"

class ContextoEstrategia 
{
    private:
        Strategy* strategy;

    public:
        ContextoEstrategia(Strategy*);
        ~ContextoEstrategia();
        void setStrategy(Strategy*);
        void executeStrategy(Jugada&, int);
};
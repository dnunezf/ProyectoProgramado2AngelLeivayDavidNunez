#include "ContextoEstrategia.h"

//Inicializa el puntero strategy nullptr
ContextoEstrategia::ContextoEstrategia(Strategy* strategy = nullptr) : strategy(strategy)
{

}

ContextoEstrategia::~ContextoEstrategia()
{
	delete strategy;
}

void ContextoEstrategia::setStrategy(Strategy* newStrategy) {
    delete strategy;

    strategy = newStrategy;
}

void ContextoEstrategia::executeStrategy(Jugada& jugada, int jugador) {
    if (strategy) 
    {
        strategy->placeLine(jugada, jugador);
    }

    else 
    {
        cerr << "Estrategia no seleccionada" << endl;
    }
}
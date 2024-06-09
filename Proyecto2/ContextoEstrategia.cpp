/* -------------------------------------------------------------------+
* |
* (c) 2024 |
* 1-1934-0740 - Ángel Arián Leiva Abarca   |
* 1-1908-0008 - David Alberto Núñez Franco |
* version 1.0.0 2024-06-01 |
* |
* -------------------------------------------------------------------+
*/

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
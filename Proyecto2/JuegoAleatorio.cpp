#include "JuegoAleatorio.h"

JuegoAleatorio::JuegoAleatorio()
{
	srand(time(nullptr));
}

void JuegoAleatorio::placeLine(Jugada& jugada, int jugador) 
{
    int t1, t2;
    bool success;

    do 
    {
        t1 = rand() % jugada.getTam1();
        t2 = rand() % jugada.getTam2();

        success = jugada.hacerJugada(t1, t2, jugador);
    } while (!success);
}
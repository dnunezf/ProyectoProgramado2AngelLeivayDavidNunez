/* -------------------------------------------------------------------+
* |
* (c) 2024 |
* 1-1934-0740 - Ángel Arián Leiva Abarca   |
* 1-1908-0008 - David Alberto Núñez Franco |
* version 1.0.0 2024-06-01 |
* |
* -------------------------------------------------------------------+
*/

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
/* -------------------------------------------------------------------+
* |
* (c) 2024 |
* 1-1934-0740 - Ángel Arián Leiva Abarca   |
* 1-1908-0008 - David Alberto Núñez Franco |
* version 1.0.0 2024-06-01 |
* |
* -------------------------------------------------------------------+
*/

#include "JuegoPeriferico.h"

void JuegoPeriferico::placeLine(Jugada& jugada, int jugador) 
{
    bool success = false;
    int tam1 = jugada.getTam1();
    int tam2 = jugada.getTam2();

    // Primero, intenta cerrar todo el borde del área de juego
    for (int i = 0; i < tam1; ++i) 
    {
        for (int j = 0; j < tam2; ++j) 
        {
            if (i == 0 || i == tam1 - 1 || j == 0 || j == tam2 - 1) 
            {
                success = jugada.hacerJugada(i, j, jugador);

                if (success) return;
            }
        }
    }

    // Si no se pudo jugar en el borde, juegue aleatoriamente
    int t1, t2;
    do 
    {
        t1 = rand() % tam1;
        t2 = rand() % tam2;

        success = jugada.hacerJugada(t1, t2, jugador);
    } while (!success);
}

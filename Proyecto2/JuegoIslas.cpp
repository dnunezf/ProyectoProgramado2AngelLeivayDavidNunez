/* -------------------------------------------------------------------+
* |
* (c) 2024 |
* 1-1934-0740 - Ángel Arián Leiva Abarca   |
* 1-1908-0008 - David Alberto Núñez Franco |
* version 1.0.0 2024-06-01 |
* |
* -------------------------------------------------------------------+
*/

#include "JuegoIslas.h"

void JuegoIslas::placeLine(Jugada& jugada, int jugador)
{
    bool success = false;
    int tam1 = jugada.getTam1();
    int tam2 = jugada.getTam2();

    // Intentar completar pequeñas islas (casillas incompletas)
    for (int i = 1; i < tam1 - 1; i += 2) 
    {
        for (int j = 1; j < tam2 - 1; j += 2) 
        {
            if (jugada.esCuadroCompleto(i, j)) {
                success = jugada.hacerJugada(i - 1, j, jugador);
                if (success) return;

                success = jugada.hacerJugada(i + 1, j, jugador);
                if (success) return;

                success = jugada.hacerJugada(i, j - 1, jugador);
                if (success) return;

                success = jugada.hacerJugada(i, j + 1, jugador);
                if (success) return;
            }
        }
    }

    // Si no se pudo completar una isla, jugar aleatoriamente
    int t1, t2;
    do 
    {
        t1 = rand() % tam1;
        t2 = rand() % tam2;
        success = jugada.hacerJugada(t1, t2, jugador);
    } while (!success);
}

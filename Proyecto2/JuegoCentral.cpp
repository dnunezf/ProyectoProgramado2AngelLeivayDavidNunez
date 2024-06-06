#include "JuegoCentral.h"

void JuegoCentral::placeLine(Jugada& jugada, int jugador)
{
    bool success = false;
    int tam1 = jugada.getTam1();
    int tam2 = jugada.getTam2();

    int centroT1 = tam1 / 2;
    int centroT2 = tam2 / 2;

    // Intentar colocar una linea cerca del centro del area de juego
    for (int radio = 0; radio <= max(tam1, tam2) / 2; radio++)
    {
        for (int i = centroT1 - radio; i <= centroT1 + radio; i++)
        {
            for (int j = centroT2 - radio; j <= centroT2 + radio; j++)
            {
                if (i >= 0 && i < tam1 && j >= 0 && j < tam2)
                {
                    success = jugada.hacerJugada(i, j, jugador);

                    if (success) return;
                }
            }
        }
    }

    // Si no se pudo jugar cerca del centro, jugar aleatoriamente
    int t1, t2;
    do {
        t1 = rand() % tam1;
        t2 = rand() % tam2;

        success = jugada.hacerJugada(t1, t2, jugador);
    } while (!success);
}
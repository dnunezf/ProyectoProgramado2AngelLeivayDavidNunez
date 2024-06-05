#pragma once
#include "JuegoCercano.h"


JuegoCercano::JuegoCercano() : lastT1(-1), lastT2(-1)
{
}


void JuegoCercano::placeLine(Jugada& jugada, int jugador) 
{
    int t1, t2;
    bool success = false;

    // Si no hay un último movimiento registrado, juegue aleatoriamente
    if (lastT1 == -1 || lastT2 == -1) {
        do 
        {
            t1 = std::rand() % jugada.getTam1();
            t2 = std::rand() % jugada.getTam2();

            success = jugada.hacerJugada(t1, t2, jugador);
        } while (!success);
        return;
    }

    int directions[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; // Direcciones: derecha, abajo, izquierda, arriba

    for (int i = 0; i < 4; i++) 
    {
        int newT1 = lastT1 + directions[i][0];
        int newT2 = lastT2 + directions[i][1];

        if (newT1 >= 0 && newT1 < jugada.getTam1() && newT2 >= 0 && newT2 < jugada.getTam2()) 
        {
            success = jugada.hacerJugada(newT1, newT2, jugador);

            if (success) {
                lastT1 = newT1;
                lastT2 = newT2;
                return;
            }
        }
    }

    // Si no se pudo jugar cerca del último movimiento, jugar aleatoriamente
    do 
    {
        t1 = rand() % jugada.getTam1();
        t2 = rand() % jugada.getTam2();

        success = jugada.hacerJugada(t1, t2, jugador);
    } while (!success);
}


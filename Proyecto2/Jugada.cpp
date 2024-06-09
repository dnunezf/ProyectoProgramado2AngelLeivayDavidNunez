/* -------------------------------------------------------------------+
* |
* (c) 2024 |
* 1-1934-0740 - Ángel Arián Leiva Abarca   |
* 1-1908-0008 - David Alberto Núñez Franco |
* version 1.0.0 2024-06-01 |
* |
* -------------------------------------------------------------------+
*/

#include "Jugada.h"
#include"Apoyo.h"

Jugada::Jugada(int t1, int t2) : tam1(t1), tam2(t2), can(0), puntosJugador1(0), puntosJugador2(0), puntoChequeo(0)
{
    // Crear arreglo dinámico de punteros
    tablero = new ComponenteTablero * *[tam1];

    for (int i = 0; i < tam1; ++i)
    {
        tablero[i] = new ComponenteTablero * [tam2];
        for (int j = 0; j < tam2; ++j)
        {
            tablero[i][j] = nullptr; // Inicializar a nullptr

            if (i % 2 == 0)
            {
                if (j % 2 == 0)
                {
                    tablero[i][j] = new Punto();
                }
                else
                {
                    tablero[i][j] = new LineaHorizontal();
                }
            }
            else
            {
                if (j % 2 == 0)
                {
                    tablero[i][j] = new LineaVertical();
                }
                else
                {
                    tablero[i][j] = new Espacio();
                }
            }
        }
    }
}

Jugada::~Jugada()
{
    for (int i = 0; i < tam1; ++i)
    {
        for (int j = 0; j < tam2; ++j)
        {
            delete tablero[i][j];
        }
        delete[] tablero[i]; 
    }
    delete[] tablero; 
}


int Jugada::getTam1() const
{
    return tam1;
}

int Jugada::getTam2() const
{
    return tam2;
}

string Jugada::toString()
{
    stringstream s;

    s << "  ";
    for (int aux = 1; aux <= tam2; aux++)
    {
        s << aux << " ";
    }
        
    s << endl;

    for (int i = 0; i < tam1; i++) 
    {
        s << i + 1 << " ";

        for (int j = 0; j < tam2; j++) 
        {
            s << tablero[i][j]->toString() << " ";
        }

        s << endl;
    }
    return s.str();
}

bool Jugada::jugada1(int t1, int t2)
{
    if (t1 >= tam1 || t2 >= tam2 || t1 < 0 || t2 < 0) 
    {
        cout << "Casillas no existe" << endl;

        return false;
    }
    if (tablero[t1][t2]->toString() == "- ") 
    {
        delete tablero[t1][t2];

        tablero[t1][t2] = new JugadaJugador1();

        return true;
    }
    else if (tablero[t1][t2]->toString() == "|") 
    {
        delete tablero[t1][t2];

        tablero[t1][t2] = new JugadaJugador1();

        return true;
    }
    return false;
}

bool Jugada::jugada2(int t1, int t2)
{
    if (t1 >= tam1 || t2 >= tam2 || t1 < 0 || t2 < 0) 
    {
        cout << "Casillas no existe" << endl;

        return false;
    }
    if (tablero[t1][t2]->toString() == "- ") 
    {
        delete tablero[t1][t2];

        tablero[t1][t2] = new JugadaJugador2();

        return true;
    }
    else if (tablero[t1][t2]->toString() == "|") 
    {
        delete tablero[t1][t2];

        tablero[t1][t2] = new JugadaJugador2();

        return true;
    }
    return false;
}

void Jugada::verificandoPuntos() 
{
    for (int i = 1; i < tam1 - 1; i += 2) 
    {
        for (int j = 1; j < tam2 - 1; j += 2) 
        {
            if (tablero[i][j]->toString() != "1" && tablero[i][j]->toString() != "2") 
            {
                if (tablero[i + 1][j]->toString() == "°" && tablero[i - 1][j]->toString() == "°" &&
                    tablero[i][j + 1]->toString() == "°" && tablero[i][j - 1]->toString() == "°") 
                {
                    delete tablero[i][j];

                    tablero[i][j] = new PuntoJugador1();

                    puntosJugador1++;
                }
                else if (tablero[i - 1][j]->toString() == "~" && tablero[i + 1][j]->toString() == "~" &&
                    tablero[i][j - 1]->toString() == "~" && tablero[i][j + 1]->toString() == "~") 
                {
                    delete tablero[i][j];

                    tablero[i][j] = new PuntoJugador2();

                    puntosJugador2++;
                }
            }
        }
    }
}

int Jugada::getPuntoChequeo()
{
    return puntoChequeo;
}

void Jugada::setPuntoChequeo(int pto)
{
    puntoChequeo = pto;
}

bool Jugada::hacerJugada(int t1, int t2, int jugador)
{
    if (t1 >= tam1 || t2 >= tam2 || t1 < 0 || t2 < 0) {
        cout << "Casillas no existe" << endl;
        return false;
    }
    if (tablero[t1][t2]->toString() == "- " || tablero[t1][t2]->toString() == "|") {
        delete tablero[t1][t2];
        if (jugador == 1) {
            tablero[t1][t2] = new JugadaJugador1();
        }
        else {
            tablero[t1][t2] = new JugadaJugador2();
        }
        return true;
    }
    return false;
}

bool Jugada::esCuadroCompleto(int t1, int t2)
{
    if (t1 <= 0 || t1 >= tam1 - 1 || t2 <= 0 || t2 >= tam2 - 1) 
    {
        return false;
    }

    int ladoCompleto = 0;

    if (tablero[t1 - 1][t2]->toString() != "|") ladoCompleto++;
    if (tablero[t1 + 1][t2]->toString() != "|") ladoCompleto++;
    if (tablero[t1][t2 - 1]->toString() != "- ") ladoCompleto++;
    if (tablero[t1][t2 + 1]->toString() != "- ") ladoCompleto++;

    return ladoCompleto < 4;
}

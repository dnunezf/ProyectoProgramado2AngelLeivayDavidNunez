#pragma once
#include"Apoyo.h"
using namespace std;

class Jugada
{
	private:
		ComponenteTablero*** tablero; 
		int tam1;
		int tam2;
		int can;
		int puntosJugador1;
		int puntosJugador2;
		int puntoChequeo;

	public:
		Jugada(int t1, int t2);
		virtual ~Jugada();
		int getTam1() const;
		int getTam2() const;
		string toString();
		bool jugada1(int t1, int t2);
		bool jugada2(int t1, int t2);
		void verificandoPuntos();
		int getPuntoChequeo();
		void setPuntoChequeo(int);
		bool hacerJugada(int t1, int t2, int jugador);
};
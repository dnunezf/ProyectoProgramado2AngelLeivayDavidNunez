#pragma once
#include"Apoyo.h"
using namespace std;

class Jugada
{
	private:
		vector<vector<ComponenteTablero*>> tablero;
		int tam1;
		int tam2;
		int can;
		int puntosJugador1;
		int puntosJugador2;
		int puntoChequeo;

	public:
		Jugada(int t1, int t2);
		virtual ~Jugada();
		string toString();
		bool jugada1(int t1, int t2);
		bool jugada2(int t1, int t2);
		void verificandoPuntos();
		int getPuntoChequeo();
		void setPuntoChequeo(int);
};
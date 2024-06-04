#pragma once
#include"Strategy.h"
#include<cstdlib>
#include<ctime>

class JuegoAleatorio : public Strategy
{
	public:
		JuegoAleatorio();
		void placeLine(Jugada&, int);
};
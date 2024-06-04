#pragma once
#include"Jugada.h"

class Strategy
{
	public:
		virtual ~Strategy()
		{

		}

		virtual void placeLine(Jugada&, int) = 0;
};
#pragma once
#include"Jugada.h"

class Memento {
private:
	Jugada* estado;        // estado = foto del juego..
public:
	Memento(Jugada* est) { estado = est; }
	Jugada* getEstado() { return estado; }
};
#pragma once
#include"Memento.h"

class Originador {
private:
	Jugada* estado;   // Es una foro del juego
public:
	void setEstado(Jugada* est) { estado = est; }
	Jugada* getEstado() { return estado; };
	Memento* retornaMemento() { return new Memento(estado); }
	void restauraMemento(Memento* m) { estado = m->getEstado(); }
};
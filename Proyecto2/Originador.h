/* -------------------------------------------------------------------+
* |
* (c) 2024 |
* 1-1934-0740 - Ángel Arián Leiva Abarca   |
* 1-1908-0008 - David Alberto Núñez Franco |
* version 1.0.0 2024-06-01 |
* |
* -------------------------------------------------------------------+
*/

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
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
#include"Jugada.h"

class Memento {
private:
	Jugada* estado;        // estado = foto del juego..
public:
	Memento(Jugada* est) { estado = est; }
	Jugada* getEstado() { return estado; }
};
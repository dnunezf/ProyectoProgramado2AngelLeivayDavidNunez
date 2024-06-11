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

class RepositorioMementos {
private:
	Memento* vec[10];
	int can;
	int tam;
public:
	RepositorioMementos() {
		can = 0;
		tam = 10;
		for (int i = 0; i < tam; i++)
			vec[i] = NULL;
	}
	void agregaMemento(Memento* m) {
		if (can < tam)
			vec[can++] = m;
	}

	Memento* getMemento(int pos) {
		if (pos >= 0 && pos < can)
			return vec[pos];
		else
			return NULL;
	}

	string toStringINPo(int po) {
		stringstream s;
		s << "---------------LISTADO DE MEMENTOS---------------" << endl
			<< "------------------------------------------------------------" << endl;
		for (int i = 0; i < can; i++) {
			if (i == po) {
				s << " No." << i << endl
					<< " El punto de chequeo es: "
					<< vec[i]->getEstado()->getPuntoChequeo() << endl
					<< " La jugado fue: "
					<< vec[i]->getEstado()->toString() << endl;
			}
			else {
				s << "La jugada no exite" << endl;
			}
		}
		return s.str();
	}

	string toString() {
		stringstream s;
		s << "---------------LISTADO DE MEMENTOS---------------" << endl
			<< "------------------------------------------------------------" << endl;
		for (int i = 0; i < can; i++) {
			s << " No." << i << endl
				<< " El punto de chequeo es: "
				<< vec[i]->getEstado()->getPuntoChequeo() << endl
				<< " La jugado fue: "
				<< vec[i]->getEstado()->toString() << endl;
		}
		return s.str();
	}
};
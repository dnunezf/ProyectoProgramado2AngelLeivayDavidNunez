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

	string toString() {
		stringstream s;
		s << "---------------LISTADO DE MEMENTOS---------------" << endl
			<< "------------------------------------------------------------" << endl;
		for (int i = 0; i < can; i++) {
			s << " No." << i << endl
				<< " El punto de chequeo es: "
				<< vec[i]->getEstado()->getPuntoChequeo() << endl
				<< " El numero aleatorio es: "
				<< vec[i]->getEstado()->getNumeroAleatorio() << endl;
		}
		return s.str();
	}
};
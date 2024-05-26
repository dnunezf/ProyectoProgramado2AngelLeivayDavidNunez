#include"Matriz.h"

int main() {
	int jugadas = 0;
	int can;
	int tam1, tam2;
	bool funciona;
	cout << "------AJUSTES DE PARTIDA------" << endl;

	cout << "Ingrese el tamanio de la columna: ";
	cin >> tam1;
	// hkahnisdof
	cout << "Ingrese el tamanio de la fila: ";
	cin >> tam2;
	cout << "De cuantos turnos sera la partida: ";
	cin >> can;
	Juego* mat = new Juego(tam1 * 2 + 1, tam2 * 2 + 1);
	mat->puntos();
	system("pause");
	system("cls");
	cout << mat->toString();
	do {
		do {
			cout << "Jugador 1" << endl;
			cout << "Cual quiere modificar: " << endl;
			cout << "Nota: Ingrese en el siguiente orden: Columna, Fila" << endl;
			cin >> tam1;
			cin >> tam2;
			system("pause");
			system("cls");
			cout << "Realizando Jugada" << endl;
			system("pause");
			system("cls");
			funciona = mat->jugada1(tam2 - 1, tam1 - 1);
			if (funciona)
				cout << "Jugada Exitosa" << endl;
			else
				cout << "Jugada Invalida" << endl;
			system("pause");
			system("cls");
			mat->VerificandoPuntos();
			cout << mat->toString();
		} while (!funciona);

		do {
			cout << "Jugador 2" << endl;
			cout << "Cual quiere modificar: " << endl;
			cout << "Nota: Ingrese en el siguiente orden: Columna, Fila" << endl;
			cin >> tam1;
			cin >> tam2;
			system("pause");
			system("cls");
			cout << "Realizando Jugada" << endl;
			system("pause");
			system("cls");
			funciona = mat->jugada2(tam2 - 1, tam1 - 1);
			if (funciona)
				cout << "Jugada Exitosa" << endl;
			else
				cout << "Jugada Invalida" << endl;
			system("pause");
			system("cls");
			mat->VerificandoPuntos();
			cout << mat->toString();
		} while (!funciona);
		jugadas++;
	} while (jugadas != can);
	/*cout << "Contando Puntos" << endl;
	system("puase");
	system("cls");
	cout << "Puntos jugador 1: " << mat->getPuntosJugador1() << endl;
	cout << "Puntos jugador 2: " << mat->getPuntosJugador2() << endl;*/
	system("pause");
	return 0;
}
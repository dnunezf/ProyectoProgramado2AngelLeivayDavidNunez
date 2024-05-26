#pragma once
#pragma once
#include<iostream>
#include<sstream>
using namespace std;

class Juego {
private:
    string*** vec;
    int tam1;
    int tam2;
    int can;
    int puntosJugador1;
    int puntosJugador2;
public:
    Juego(int ta1, int ta2) : tam1(ta1), tam2(ta2), can(0), puntosJugador1(0), puntosJugador2(0) {
        vec = new string * *[tam1]; // Crear un arreglo de punteros a punteros
        for (int i = 0; i < tam1; i++) {
            vec[i] = new string * [tam2]; // Para cada fila, crear un arreglo de punteros
            for (int j = 0; j < tam2; j++) {
                vec[i][j] = new string(""); // Inicializar cada elemento con una cadena vacía
            }
        }
    }
    virtual ~Juego() {
        for (int i = 0; i < tam1; i++) {
            for (int j = 0; j < tam2; j++)
                delete vec[i][j];
            delete vec[i];
        }
        delete[] vec;
    }

    void puntos() {
        for (int i = 0; i < tam1; i++) {
            for (int j = 0; j < tam2; j++) {
                if (i % 2 == 0) {
                    if (j % 2 == 0)
                        vec[i][j] = new string("*");
                    else
                        vec[i][j] = new string("- ");
                }
                else {
                    if (j % 2 == 0)
                        vec[i][j] = new string("|");
                    else
                        vec[i][j] = new string("  ");
                }
            }
        }
    }


    string toString() {
        stringstream ss;

        // Etiquetar las columnas
        ss << "  ";
        for (int h = 1; h <= tam2; h++)
            ss << h << " ";
        ss << endl;

        // Iterar sobre las filas
        for (int i = 0; i < tam1; i++) {
            // Etiquetar las filas
            ss << i + 1 << " ";
            // Iterar sobre las columnas de la fila actual
            for (int j = 0; j < tam2; j++) {
                ss << *vec[i][j] << " ";
            }
            ss << endl;
        }
        return ss.str();
    }

    bool jugada1(int ta1, int ta2) {
        if (ta1 > tam1 || ta2 > tam2 || ta1 < 0 || ta2 < 0) {
            cerr << "Casillas no existe" << endl;
            return false;
        }
        else if (*vec[ta1][ta2] == "- ") {
            vec[ta1][ta2] = new string("° ");
            return true;
        }
        else if (*vec[ta1][ta2] == "|") {
            vec[ta1][ta2] = new string("°");
            return true;
        }
        return false;
    }

    bool jugada2(int ta1, int ta2) {
        if (ta1 > tam1 || ta2 > tam2 || ta1 < 0 || ta2 < 0) {
            cerr << "Casillas no existe" << endl;
            return false;
        }
        else if (*vec[ta1][ta2] == "- ") {
            vec[ta1][ta2] = new string("~ ");
            return true;
        }
        else if (*vec[ta1][ta2] == "|") {
            vec[ta1][ta2] = new string("~");
            return true;
        }
        return false;
    }

    void VerificandoPuntos() {
        for (int i = 1; i < tam1 - 1; i += 2) {
            for (int j = 1; j < tam2 - 1; j += 2) {
                if (*vec[i][j] != "1" && *vec[i][j] != "2") { // Solo verifica si el punto no ha sido marcado antes
                    if (*vec[i + 1][j] == "° " && *vec[i - 1][j] == "°" && *vec[i][j + 1] == "° " && *vec[i][j - 1] == "°") {
                        *vec[i][j] = "1";
                        puntosJugador1++;
                    }
                    else if (*vec[i - 1][j] == "~ " && *vec[i + 1][j] == "~" && *vec[i][j - 1] == "~ " && *vec[i][j + 1] == "~") {
                        *vec[i][j] = "2";
                        puntosJugador2++;
                    }
                }
            }
        }
    }


};
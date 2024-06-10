/* -------------------------------------------------------------------+
* |
* (c) 2024 |
* 1-1934-0740 - Ángel Arián Leiva Abarca   |
* 1-1908-0008 - David Alberto Núñez Franco |
* version 1.0.0 2024-06-01 |
* |
* -------------------------------------------------------------------+
*/ 

#include"Jugada.h"
#include "ContextoEstrategia.h"
#include "JuegoAleatorio.h"
#include"JuegoCercano.h"
#include"JuegoPeriferico.h"
#include"JuegoCentral.h"
#include"JuegoIslas.h"


int main() 
{
    int opcion = 0;
    int jugadas = 0;
    int can = 0;
    int tam1 = 0, tam2 = 0;
    bool funciona;
    int modoJuego;
    int estrategiaSeleccionada;

    /*cout << "------AJUSTES DE PARTIDA------" << endl;
    cout << "Ingrese el tamanio de la columna: ";
    cin >> tam1;
    cout << "Ingrese el tamanio de la fila: ";
    cin >> tam2;
    cout << "De cuantos turnos sera la partida: ";
    cin >> can;*/
    cout << "------AJUSTE DE PARTIDA------" << endl;
    cout << "Escoger el tamaño del tablero: " << endl;
    cout << "   1- Tamaño de 3x3   " << endl;
    cout << "   2- Tamaño de 5x5   " << endl;
    cout << "   3- Tamaño de 8x8   " << endl;
    cout << "   4- Tamaño Personalizado " << endl;
    cout << " Ingrese opcion: " << endl;
    cin >> opcion;
    switch (opcion)
    {
    case 1: tam1 = 3; tam2 = 3; can = 23; break;
    case 2: tam1 = 5; tam2 = 5; can = 23; break;
    case 3: tam1 = 8; tam2 = 8; can = 23; break;
    case 4:
        cout << "------AJUSTES DE PARTIDA------" << endl;
        cout << "Ingrese el tamanio de la columna: ";
        cin >> tam1;
        cout << "Ingrese el tamanio de la fila: ";
        cin >> tam2;
        break;
    default:
        break;
    }

    Jugada* matriz = new Jugada(tam1 * 2 + 1, tam2 * 2 + 1);
    ContextoEstrategia* contexto = nullptr;
    JuegoCercano* juegoCercano = nullptr;
    JuegoPeriferico* juegoPeriferico = nullptr;
    JuegoCentral* juegoCentral = nullptr;
    JuegoIslas* juegoIslas = nullptr;

    cout << "Seleccione el modo de juego:\n1. Jugador vs Jugador\n2. Jugador vs Maquina" << std::endl;
    cin >> modoJuego;

    if (modoJuego == 2) 
    {
        cout << "Seleccione la estrategia de la maquina: " << endl;
        cout << "\n1. Juego Aleatorio" << endl;
        cout << "2. Juego Cercano" << endl;
        cout << "3. Juego Periferico" << endl;
        cout << "4. Juego Central" << endl;
        cout << "4. Juego Islas" << endl;
        cin >> estrategiaSeleccionada;

        switch (estrategiaSeleccionada) 
        {
            case 1:
                contexto = new ContextoEstrategia(new JuegoAleatorio());
                break;

            case 2:
                contexto = new ContextoEstrategia(new JuegoCercano());
                break;

            case 3:
                contexto = new ContextoEstrategia(new JuegoPeriferico());
                break;

            case 4:
                contexto = new ContextoEstrategia(new JuegoCentral());
                break;

            case 5:
                contexto = new ContextoEstrategia(new JuegoIslas());
                break;

            default:
                std::cout << "Estrategia no valida, se utilizara la estrategia aleatoria por defecto." << std::endl;
                contexto = new ContextoEstrategia(new JuegoAleatorio());
        }
    }

    cout << matriz->toString();

    do 
    {
        do 
        {
            cout << "Jugador 1" << endl;
            cout << "Cual quiere modificar: " << endl;
            cout << "Nota: Ingrese en el siguiente orden: Columna, Fila" << endl;
            cin >> tam1 >> tam2;

            funciona = matriz->jugada1(tam2 - 1, tam1 - 1);

            if (funciona)
            {
                cout << "Jugada Exitosa" << endl;
            }
            else
            {
                cout << "Jugada Invalida" << endl;
            }    

            matriz->verificandoPuntos();

            cout << matriz->toString();

        } while (!funciona);

        if (modoJuego == 2) 
        {
            contexto->executeStrategy(*matriz, 2);
            matriz->verificandoPuntos();
            cout << matriz->toString();
        }
        else
        {
            do
            {
                cout << "Jugador 2" << endl;
                cout << "Cual quiere modificar: " << endl;
                cout << "Nota: Ingrese en el siguiente orden: Columna, Fila" << endl;
                cin >> tam1 >> tam2;

                funciona = matriz->jugada2(tam2 - 1, tam1 - 1);

                if (funciona)
                {
                    cout << "Jugada Exitosa" << endl;
                }
                else
                {
                    cout << "Jugada Invalida" << endl;
                }

                matriz->verificandoPuntos();

                cout << matriz->toString();
            } while (!funciona);
        }

        jugadas++;

    } while (jugadas < can);

    delete matriz;

    system("pause");
    return 0;
}
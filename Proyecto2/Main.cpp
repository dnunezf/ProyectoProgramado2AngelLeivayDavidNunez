#include"Jugada.h"
#include "ContextoEstrategia.h"
#include "JuegoAleatorio.h"

int main() 
{
    int jugadas = 0;
    int can;
    int tam1, tam2;
    bool funciona;
    int modoJuego;
    int estrategiaSeleccionada;

    cout << "------AJUSTES DE PARTIDA------" << endl;
    cout << "Ingrese el tamanio de la columna: ";
    cin >> tam1;
    cout << "Ingrese el tamanio de la fila: ";
    cin >> tam2;
    cout << "De cuantos turnos sera la partida: ";
    cin >> can;

    Jugada* matriz = new Jugada(tam1 * 2 + 1, tam2 * 2 + 1);
    ContextoEstrategia* contexto = nullptr;

    cout << "Seleccione el modo de juego:\n1. Jugador vs Jugador\n2. Jugador vs Maquina" << std::endl;
    cin >> modoJuego;

    if (modoJuego == 2) 
    {
        cout << "Seleccione la estrategia de la maquina:\n1. Estrategia Aleatoria" << endl;
        cin >> estrategiaSeleccionada;

        switch (estrategiaSeleccionada) 
        {
            case 1:
                contexto = new ContextoEstrategia(new JuegoAleatorio());
                break;

            default:
                std::cout << "Estrategia no válida, se utilizará la estrategia aleatoria por defecto." << std::endl;
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
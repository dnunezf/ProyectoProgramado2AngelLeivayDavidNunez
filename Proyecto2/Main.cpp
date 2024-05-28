#include"Jugada.h"

int main() 
{
    int jugadas = 0;
    int can;
    int tam1, tam2;
    bool funciona;

    cout << "------AJUSTES DE PARTIDA------" << endl;
    cout << "Ingrese el tamanio de la columna: ";
    cin >> tam1;
    cout << "Ingrese el tamanio de la fila: ";
    cin >> tam2;
    cout << "De cuantos turnos sera la partida: ";
    cin >> can;

    Jugada* matriz = new Jugada(tam1 * 2 + 1, tam2 * 2 + 1);

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
                cout << "Jugada Exitosa" << std::endl;
            }
            else
            {
                cout << "Jugada Invalida" << std::endl;
            }    

            matriz->verificandoPuntos();

            cout << matriz->toString();

        } while (!funciona);

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

        jugadas++;

    } while (jugadas < can);

    delete matriz;

    system("pause");
    return 0;
}
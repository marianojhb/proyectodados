#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "funciones.h"

int main()
{
    // variables generales del juego
    srand(time(NULL));
    int opcion;
    bool simulado = false;

    while(true)
    {
        mostrarMenu(simulado);
        cin >> opcion;

        switch (opcion)
        {

        // funcion juegoSol
        case 1:
            modoSolitario(simulado);
            break;
        case 2:
            multijugador();
            break;

        case 3:
            // mostrarVector(dados, TAM);
            break;

        case 4:
            toggleSimulado(simulado);
        case 0:
            cout<<"Saliendo del programa..."<<endl;
            break;

        default:
            cout<<"Ingrese una opcion correcta."<<endl;
            system("pause");
            break;
        }

    }


    return 0;
}

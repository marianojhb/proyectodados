#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "funciones.h"

int main()
{
    // variables generales del juego

    int opcion;
    bool simulado = false;

    // Ranking
    int ranking_len=11; // extensión del ranking
    string ranking_lista[ranking_len]; // la lista de ranking
    ponerVectorEnVacio(ranking_lista,ranking_len); // inicializo el ranking

    while(true)
    {
        mostrarMenu(simulado);
        cin >> opcion;

        switch (opcion)
        {

        // funcion juegoSol
        case 1:
            modoSolitario(simulado, ranking_lista);
            break;
        case 2:
            dosjugadores(simulado, ranking_lista);
            break;
        case 3:
            multijugador(simulado, ranking_lista);
            break;

        case 4:
            mostrarVectorString(ranking_lista, ranking_len-1); // -1 porque el vector es de 11 pero solo muestro los 10 primeros
            break;

        case 5:
            toggleSimulado(simulado);
            break;
        case 0:
            cout<<"Saliendo del programa..."<<endl;
            return 0;
            break;

        default:
            cout<<"Ingrese una opcion correcta."<<endl;
            system("pause");
            break;
        }

    }


    return 0;
}

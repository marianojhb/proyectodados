#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "funciones.h"
#include "rlutil.h"

int main()
{
    //CAMBIAMOS EL DE LA CONSOLA:
    system("color 52");

    //OCULTAMOS EL CURSOR
    rlutil::hidecursor();
    // variables generales del juego
    int opcion;
    bool simulado = false;
    // KEY , RETORNA LO QUE VECUELVE KI
    // Y , NOS VA A SERVIR, PARA PODER MOVERNOS EN EL MENU
    int key , y = 0;
    // Ranking
    int ranking_len=11; // extensión del ranking
    string ranking_lista[ranking_len]; // la lista de ranking
    ponerVectorEnVacio(ranking_lista,ranking_len); // inicializo el ranking

    while(true)
    {
        mostrarMenu(simulado);
        //COLOCAMOS LA FIGURA " >> " EN LA OPCION 1:
        rlutil::locate(38,11+y);
        //CASTEAMOS EL DATO "(char)175", ES DECIR , LO INTERPRETAMOS COMO SI FUERA UN CARACTER.
        cout << (char)175 << endl;;
        key = rlutil::getkey();


        switch (key)
        {
          case 14: // ARRIBA
            //BORRAMOS EL CURSOS ANTERIOR
            rlutil::locate(38,11+y);
             cout << " " << endl;;
            y--;
            // PONEMOS LIMITE SUPERIOR A LA FIGURA " << "
            if ( y < 0)
            {
              y = 0;
            }
          break;
          case 15: // ABAJO
            //BORRAMOS EL CURSOS ANTERIOR
            rlutil::locate(38,11+y);
            cout << " " << endl;;
            y++;
            // PONEMOS LIMITE INFERIOR A LA FIGURA " << "
            if ( y > 5)
            {
              y = 5;
            }
          break;
          case 1: //ENTER
            //TENEMOS QUE ANALIZAR A Y
            switch (y)
            {
              case 0: modoSolitario(simulado, ranking_lista);
                break;
              case 1: dosjugadores(simulado, ranking_lista);
                break;
              case 2: multijugador(simulado, ranking_lista);
                break;
              case 3: mostrarVectorString(ranking_lista, ranking_len-1);
               // -1 porque el vector es de 11 pero solo muestro los 10 primeros
                break;
              case 4: toggleSimulado(simulado);
                break;
              case 5: return 0;
                break;
              default:
                break;
            }
          break;
        default:
            break;
        }

        /*
        //cin >> opcion;
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
      */
    }


    return 0;
}

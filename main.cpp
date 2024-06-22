#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "rlutil.h"
#include "funciones.h"
using namespace std;

int main()
{
    srand(time(NULL));

    //CAMBIAMOS EL COLOR DE LA CONSOLA:
    rlutil::setBackgroundColor(rlutil::LIGHTMAGENTA);
    rlutil::cls();

    //OCULTAMOS EL CURSOR
    rlutil::hidecursor();
    // variables generales del juego
    bool simulado = false;
    // KEY , RETORNA LO QUE DEVUELVE Y
    // Y , NOS VA A SERVIR, PARA PODER MOVERNOS EN EL MENU
    int key;
    int offset_y=0;
//    int cantidad_opciones = 7;
    // Ranking
    int ranking_len = 11; // extensión del ranking
    string ranking_lista[ranking_len]; // la lista de ranking
    ponerVectorEnVacio(ranking_lista,ranking_len); // inicializo el ranking


    while(true)
    {
        mostrarMenu(simulado);

        //COLOCAMOS LA FIGURA " >> " EN LA OPCION 1:

        rlutil::locate(22,7+offset_y);
        //CASTEAMOS EL DATO "(char)175", ES DECIR , LO INTERPRETAMOS COMO SI FUERA UN CARACTER.
        cout << (char)175 << (char)175 << endl;
        key = rlutil::getkey();

        switch (key)
        {
          case 14: // ARRIBA
            //BORRAMOS EL CURSOS ANTERIOR
            rlutil::locate(22,7+offset_y);
             cout << "  " << endl;;
            offset_y--;
            // PONEMOS LIMITE SUPERIOR A LA FIGURA " << "
            if ( offset_y < 0)
            {
                offset_y = 6;
                 rlutil::locate(22,7+offset_y);
            }
          break;
          case 15: // ABAJO
            //BORRAMOS EL CURSOS ANTERIOR
            rlutil::locate(22,7+offset_y);
            cout << "  " << endl;
            offset_y++;
            // PONEMOS LIMITE INFERIOR A LA FIGURA " << "
            if ( offset_y > 6 )
            {
              offset_y = 0;
              rlutil::locate(22,7+offset_y);
            }
          break;
          case 1: //ENTER
            //TENEMOS QUE ANALIZAR A Y

            switch (offset_y)
            {
              case 0: modoSolitario(simulado, ranking_lista);
                break;
              case 1: dosjugadores(simulado, ranking_lista);
                break;
              case 2: multijugador(simulado, ranking_lista);
                break;
              case 3: menuRanking(ranking_lista, ranking_len);
               // -1 porque el vector es de 11 pero solo muestro los 10 primeros
                break;
              case 4: toggleSimulado(simulado);
                break;
              case 5: creditos();
                break;
              case 6: return 0;
                break;
              default:
                break;
            }
          break;
        default:
            break;
        }
    }

//
//  cout << " " << endl;
//  cout << " " << endl;
//  cout << " " << endl;
//  rlutil::locate(42,25);
  return 0;
}

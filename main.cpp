#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "rlutil.h"
#include "funciones.h"
using namespace std;

int main()
{
    srand(time(NULL));
    //CAMBIAMOS EL COLOR DE FONDO DE LA CONSOLA:
    rlutil::setBackgroundColor(rlutil::LIGHTMAGENTA);
    rlutil::cls();

    //OCULTAMOS EL CURSOR
    rlutil::hidecursor();
    // variables generales del juego
    bool simulado = false;
    // KEY , RETORNA LO QUE DEVUELVE Y
    // Y , NOS VA A SERVIR, PARA PODER MOVERNOS EN EL MENU
    int key;
    int offset_y =0;
    // Ranking
    int const ranking_len = 11; // LONGITUD DEL TAMAÑO DEL VECTOR.
    string ranking_lista[ranking_len]; // VECTOR DE STRING, LISTA DE RANKING
    ponerVectorEnVacio(ranking_lista,ranking_len); // inicializo el ranking

    // INICIO PROGRAMA . . .
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(21,2);
    cout << "* * * *   B I E N V E N I D O S   * * * *" << endl;

    while(true)
    {
        mostrarMenu(simulado);

        //COLOCAMOS LA FIGURA " >> " EN LA OPCION 1:
        rlutil::locate(22,7+offset_y);

        //CASTEAMOS EL DATO "(char)175", ES DECIR , LO INTERPRETAMOS COMO SI FUERA UN CARACTER.
        cout << (char)175 << (char)175 << endl;
        key = rlutil::getkey();

        // SWITCH PARA NAVEGAR HACIA ARRIBA Y ABAJO CON LAS FLECHAS (TECLAS CODIGO 14 Y 15)
        switch (key)
        {

        case 14: // FLECHA-ARRIBA

            rlutil::locate(22,7+offset_y);

            //BORRAMOS EL CURSOS ANTERIOR
            cout << "  " << endl;;
            offset_y--;

            // PONEMOS LIMITE SUPERIOR A LA FIGURA " << "
            if ( offset_y < 0)
            {
                // PARAMETROS PARA HACER UN BUCLE INFINITO DEL MENU
                offset_y = 6;
                rlutil::locate(22,7+offset_y);
            }
            break;

        case 15: // FLECHA-ABAJO

            rlutil::locate(22,7+offset_y);

            //BORRAMOS EL CURSOS ANTERIOR
            cout << "  " << endl;
            offset_y++;

            // PONEMOS LIMITE INFERIOR A LA FIGURA " << "
            if ( offset_y > 6 )
            {
                // PARAMETROS PARA HACER UN BUCLE INFINITO DEL MENU
                offset_y = 0;
                rlutil::locate(22,7+offset_y);
            }
            break;

        // PARA ELEGIR LA OPCION DEL MENU PRESIONAMOS ENTER (TECLA CODIGO 1)
        case 1:

            //TENEMOS QUE ANALIZAR A offset_y QUE CORRESPONDE CON LA OPCION ELEGIDA
            switch (offset_y)
            {
            case 0:
                modoSolitario(simulado, ranking_lista);
                break;
            case 1:
                multijugador(simulado, ranking_lista, 2);
                break;
            case 2:
                multijugador(simulado, ranking_lista, 0);
                break;
            case 3:
                menuRanking(ranking_lista, ranking_len);
                break;
            case 4:
                toggleSimulado(simulado);
                break;
            case 5:
                creditos();
                break;
            case 6:
                rlutil::cls();
                return 0;
                break;
            default:
                break;
            }
        default:
            break;
        }
    }
    return 0;
}

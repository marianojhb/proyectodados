#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "rlutil.h"
using namespace std;
#include "funciones.h"

void modoSolitario(bool simulado, std::string r[])
{

    string jugador1;
    cargarNombre(jugador1);

    // VARIABLES JUEGO SOLITARIO
    int const tam = 6;
    int dados[tam];
    int lanzamiento;
    int ronda = 1;
    int puntajeTotal = 0; // suma del juego
    int maximoPorRonda = 0;
    int puntaje;
    bool escalera = false;

    while(puntajeTotal < 100 && escalera == false )
    {
        puntaje = 0; // por lanzamiento
        maximoPorRonda = 0;

        // Lanzamientos:
        for ( lanzamiento = 1 ; lanzamiento <= 3; lanzamiento++)
        {
            menuJuegoSolitario(puntajeTotal, jugador1, ronda, lanzamiento, maximoPorRonda, simulado);

            lanzar2(simulado,dados,tam);

            cout << endl << endl << endl;
            cout << "                           ";
            mostrarVector(dados, tam); // muestra el resultado en pantalla
            puntaje=sumaVector(dados, tam); // suma el los valores del vector en la variable puntaje

            // ESCALERA
            if (esEscalera(dados,tam, puntaje))
            {
                escalera=true;
                cout << "Saco escalera y GANO EL JUEGO!!" << endl;
                actualizaRanking(r,jugador1,100);
                rlutil::anykey();
                rlutil::cls();
                return;
            }
            else
            {
                // Generala de 1-5: multiplica valor del dado x 10
                generala(dados,tam,puntaje);
                // Generala de 6: vuelve a 0 el puntaje total
                seisSeis(puntaje,puntajeTotal);
                mostrarPuntaje(puntaje);
                if (puntaje>maximoPorRonda)
                {
                    maximoPorRonda = puntaje;
                }
            }


            rlutil::anykey();
        }

        // Cartel fin de ronda:

        sumaPuntaje(maximoPorRonda, puntajeTotal);
        interfas_fin_ronda(ronda, maximoPorRonda, puntajeTotal);
        ronda++;

    }
    cout << "TERMINO LA PARTIDA! " << endl;
    cout << jugador1 << ", hiciste " << puntajeTotal << " puntos en " << ronda-1<< " rondas" << endl << endl;
    actualizaRanking(r, jugador1, puntajeTotal);

    rlutil::anykey();
    rlutil::cls();
};

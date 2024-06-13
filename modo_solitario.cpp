#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "funciones.h"

void modoSolitario(bool simulado)
{
    string jugador1;
    cargarNombre(jugador1);


    // VARIABLES JUEGO SOLITARIO
    int tam = 6;
    int dados[tam];
    int ronda = 1;
    int puntajeTotal = 0; // suma del juego
    int maximoPorRonda = 0;
    bool escalera = false;
    puntajeTotal = 0;
    int lanzamiento;

    while(puntajeTotal < 100 && escalera == false )
    {
        int puntaje = 0; // por lanzamiento
        maximoPorRonda = 0;

        // Lanzamientos:
        for ( lanzamiento = 1 ; lanzamiento <= 3; lanzamiento++)
        {
            menuJuegoSolitario(puntajeTotal, jugador1, ronda, lanzamiento, maximoPorRonda, simulado);

            if (simulado==false)
            {
                if(lanzar()) {} // pide lanzar los dados presionando L

                cargarVectorAleatorio(dados, tam); // carga el vector aleatorio en memoria

            }
            else
            {
                cargarVectorManual(dados, tam);
            }
            mostrarVector(dados, tam); // muestra el resultado en pantalla
            puntaje=sumaVector(dados, tam); // suma el los valores del vector en la variable puntaje

            // ESCALERA
            if (esEscalera(dados,tam,puntaje))
            {
                escalera=true;
                cout << "Saco escalera y GANO EL JUEGO!!" << endl;
                system("pause");
                break;
            }
            else
            {
                // Generala de 1-5: multiplica valor del dado x 10
                generala(dados,tam,puntaje);
                // Generala de 6: vuelve a 0 el puntaje total
                seisSeis(puntaje,puntajeTotal,lanzamiento);
                mostrarPuntaje(puntaje);
                if (puntaje>maximoPorRonda)
                    maximoPorRonda = puntaje;
            }


            system("pause");
        }

        // Cartel fin de ronda:
        if(escalera == true)
        {
            break;
        }
        else
        {
            menuJuegoSolitario(puntajeTotal, jugador1, ronda, lanzamiento-1, maximoPorRonda, simulado);

            cout << "Fin de la ronda. Sumo " << maximoPorRonda << " puntos." << endl;
            sumaPuntaje(maximoPorRonda, puntajeTotal);
            system("pause");
            ronda++;
        }

    }

    if (escalera == true)
    {
        system("cls");
        cout << "Gano por obtener escalera" << endl;
    }
    else
    {
        menuJuegoSolitario(puntajeTotal, jugador1, ronda-1, lanzamiento-1, maximoPorRonda, simulado);
        cout << "Termino la partida con " << puntajeTotal << " en la ronda " << ronda-1 << endl ;

    }
    system("pause");
};

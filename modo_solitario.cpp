#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "funciones.h"

void modoSolitario()
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

    while(puntajeTotal < 100 || escalera == false )
    {
        int puntaje = 0; // por lanzamiento
        maximoPorRonda = 0;

        // Lanzamientos:
        for ( lanzamiento = 1 ; lanzamiento <= 3; lanzamiento++)
        {
            menuJuegoSolitario(puntajeTotal, jugador1, ronda, lanzamiento, maximoPorRonda);
            if(lanzar()) {} // pide lanzar los dados presionando L
            cargarVectorAleatorio(dados, tam); // carga el vector aleatorio en memoria
            mostrarVector(dados, tam); // muestra el resultado en pantalla
            puntaje=sumaVector(dados, tam); // suma el los valores del vector en la variable puntaje

            mostrarPuntaje(puntaje);
            if (puntaje>maximoPorRonda)
                maximoPorRonda = puntaje;

            // ESCALERA
            if (esEscalera(dados,tam,puntaje))
            {
                escalera=true;
                lanzamiento=4; // sumo uno para mostrar el lanzamiento correcto
                cout << "Saco escalera y GANO EL JUEGO!!" << endl;
            }
            if (puntaje == 36)
            {
                cout << "6 dados 6 reinicia el puntaje total a 0 " << endl;
                puntajeTotal=0;
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
            menuJuegoSolitario(puntajeTotal, jugador1, ronda, lanzamiento-1, maximoPorRonda);
            system("pause");
            cout << "Fin de la ronda. Sumo " << maximoPorRonda << " puntos." << endl;
            sumaPuntaje(maximoPorRonda, puntajeTotal);
            system("pause");
            ronda++;
        }

    }

    if (escalera == true)
    {
        system("cls");
        cout << "Gano por obtenter escalera" << endl;
    }
    else
    {
        menuJuegoSolitario(puntajeTotal, jugador1, ronda-1, lanzamiento-1, maximoPorRonda);
    }
    system("pause");
};

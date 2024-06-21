#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "funciones.h"

void multijugador(bool simulado, string r[])
{
    // CON VECTORES

    int cantidadJugadores; // cantidad de jugadores
    cout << endl << "INGRESE LA CANTIDAD DE JUGADORES ";
    cin >> cantidadJugadores;

    string jugador[cantidadJugadores];

    for (int i=0; i<cantidadJugadores; i++)
    {
        cout << "Ingrese el nombre del jugador " << i+1 << " ";
        cin >> jugador[i];

    }


    // VARIABLES JUEGO MULTIJUGADOR
    int const tam = 6;
    int dados[tam];
    int lanzamiento;
    int ronda = 1;
    int puntajeTotal[cantidadJugadores];
    ponerVectorEn0(puntajeTotal, cantidadJugadores);
    int maximoPorRonda ;
    int puntaje=0;
    bool escalera = false;
    bool alcanzo100 = false;
    int jugadorGanador;

    while (alcanzo100 == false)
    {

        // Turnos de Jugadores
        for(int i=0; i<cantidadJugadores; i++)
        {
            maximoPorRonda = 0;

            // Lanzamientos
            for(lanzamiento=1; lanzamiento<=3; lanzamiento++)
            {
                menuJuegoMultijugador(puntajeTotal[i], jugador[i], ronda, lanzamiento, maximoPorRonda, simulado);
                lanzar2(simulado,dados,tam);
                mostrarVector(dados,tam);
                puntaje = sumaVector(dados,tam);

                // condiciones
                if (esEscalera(dados,tam,puntaje))
                {
                    escalera=true;
                    cout << "Saco escalera y GANO EL JUEGO!!" << endl;
                    system("pause");
                    actualizaRanking(r,jugador[i],100);
                    return;
                }
                else
                {
                    // Generala de 1-5: multiplica valor del dado x 10
                    generala(dados,tam,puntaje);
                    // Generala de 6: vuelve a 0 el puntaje total
                    seisSeis(puntaje,puntajeTotal[i]);
                }

                mostrarPuntaje(puntaje);
                system("pause");
                if(puntaje>maximoPorRonda)
                {
                    maximoPorRonda=puntaje;
                }
            }
            cout << "Puntaje total previo=" << puntajeTotal[i]<< endl;
            puntajeTotal[i]+=maximoPorRonda;
            cout << "Puntaje de esta ronda=" << maximoPorRonda << endl;
            cout << "Puntaje total luego=" << puntajeTotal[i]<< endl;
            if(cantidadJugadores!=(i+1))
            {
                cout << endl;
                cout << "Turno de " << jugador[i+1] << endl;
            }
            system("pause");
        }
        for(int i=0; i<cantidadJugadores; i++)
        {
            if (puntajeTotal[i]>100)
            {
                alcanzo100 = true;
            }
        }
        if (alcanzo100)
        {
            cout << "Se termino la partida." << endl;
        }
        else
        {
            // proxima ronda
            system("cls");
            cout << "Fin de la ronda." << endl;

            cout << "Puntaje hasta el momento: "<< endl;
            for(int i=0; i<cantidadJugadores; i++)
            {
                cout << jugador[i] << " " << puntajeTotal[i] << " puntos." << endl;
            }
            cout << endl;

            cout << "Proximo turno de " << jugador[0] << endl;

            system("pause");
        }
        ronda++;

    }
    system("cls");
    cout << "Resultado final: "<< endl;
    for(int i=0; i<cantidadJugadores; i++)
    {
        cout << jugador[i] << " " << puntajeTotal[i] << " puntos." << endl;
    }
    cout << endl;

    jugadorGanador = maximoVectorIndice(puntajeTotal, cantidadJugadores);

    cout << "El ganador es " << jugador[jugadorGanador] << " con " << puntajeTotal[jugadorGanador] << " puntos."<< endl;

    actualizaRanking(r,jugador[jugadorGanador],puntajeTotal[jugadorGanador]);

    system("pause");
}

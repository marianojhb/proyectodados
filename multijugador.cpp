#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "rlutil.h"
#include "funciones.h"
using namespace std;

void multijugador(bool simulado, std::string r[], int cantidadJugadores)
{
    // CON VECTORES

//    int cantidadJugadores; // cantidad de jugadores


    // PREGUNTA CANTIDAD DE JUGADORES
    if (cantidadJugadores==0)
    {
        rlutil::cls();
        rlutil::locate(25, 8);
        cout << "INGRESE LA CANTIDAD DE JUGADORES ";
        rlutil::showcursor();

        rlutil::locate(40, 10);
        cin >> cantidadJugadores;
        rlutil::hidecursor();
    }

    // CARGO LOS NOMBRES
    string jugador[cantidadJugadores];

    for (int i=0; i<cantidadJugadores; i++)
    {
        rlutil::cls();
        rlutil::locate(20, 12);
        cout << "INGRESE EL NOMBRE DEL JUGADOR  " << i+1 << ": ";
        rlutil::showcursor();
        rlutil::locate(54, 12);
        cin >> jugador[i];
        rlutil::hidecursor();

    }
    rlutil::cls();


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

        // INICIO RONDA
        rlutil::locate(35,9);
        cout << "RONDA N" << (char)248 << " " << ronda;
        dibujo_cuadrado();
        rlutil::anykey();
        rlutil::cls();

        // Turnos de Jugadores
        for(int i=0; i<cantidadJugadores; i++)
        {
            maximoPorRonda = 0;

            // TURNO DE

            rlutil::cls();
            rlutil::locate(33,9);
            cout << "TURNO DE " << jugador[i];
            dibujo_cuadrado();
            rlutil::anykey();
            rlutil::cls();

            // Lanzamientos
            for(lanzamiento=1; lanzamiento<=3; lanzamiento++)
            {
                menuJuegoMultijugador(puntajeTotal[i], jugador[i], ronda, lanzamiento, maximoPorRonda, simulado);

                lanzar2(simulado,dados,tam);


                // GRAFICO DADO
                mostrarDado(dados[0],1,14);

                // GRAFICO DADO
                mostrarDado(dados[1],15,14);

                // GRAFICO DADO
                mostrarDado(dados[2],29,14);

                // GRAFICO DADO
                mostrarDado(dados[3],43,14);

                // GRAFICO DADO
                mostrarDado(dados[4],57,14);

                // GRAFICO DADO
                mostrarDado(dados[5],71,14);



                // CARTEL PUNTOS QUE SUMO EL VECTOR

                puntaje=sumaVector(dados, tam); // suma el los valores del vector en la variable puntaje

                // condiciones
                if (esEscalera(dados,tam,puntaje))
                {
                    escalera=true;
                    rlutil::locate(25,22);
                    cout << "Saco escalera y GANO EL JUEGO!!" << endl;
                    rlutil::anykey();
                    actualizaRanking(r,jugador[i],100);
                    rlutil::cls();
                    return;
                }
                else
                {
                    // Generala de 1-5: multiplica valor del dado x 10
                    generala(dados,tam,puntaje);
                    // Generala de 6: vuelve a 0 el puntaje total
                    seisSeis(puntaje,puntajeTotal[i]);
                }

                if(puntaje>maximoPorRonda)
                {
                    maximoPorRonda=puntaje;
                }
                if(lanzamiento!=3)
                {
                    mostrarPuntaje(puntaje);
                    rlutil::anykey();

                }
                else
                {
                    mostrarPuntaje(puntaje);
                    rlutil::anykey();
                    rlutil::cls();
                    dibujo_cuadrado();
                    rlutil::locate(27,9);
                    cout << jugador[i] << " SUMO " << maximoPorRonda << " EN LA RONDA";
                    sumaPuntaje(maximoPorRonda, puntajeTotal[i]);
                    rlutil::anykey();
                }
            }
        }
        for(int i=0; i<cantidadJugadores; i++)
        {
            if (puntajeTotal[i]>=100)
            {
                alcanzo100 = true;
            }
        }
        if (alcanzo100)
        {

            rlutil::cls();
            dibujo_cuadrado();
            rlutil::locate(30,6);
            cout << "RESULTADO FINAL: ";
            for(int i=0; i<cantidadJugadores; i++)
            {
                rlutil::locate(30,8+i);
                cout << jugador[i] << " " << puntajeTotal[i] << " PUNTOS" << endl;
            }
            rlutil::anykey();

            jugadorGanador = maximoVectorIndice(puntajeTotal, cantidadJugadores);

            rlutil::cls();
            dibujo_cuadrado();
            rlutil::locate(24,10);
            cout << "El ganador es " << jugador[jugadorGanador] << " con " << puntajeTotal[jugadorGanador] << " puntos."<< endl;

            actualizaRanking(r,jugador[jugadorGanador],puntajeTotal[jugadorGanador]);

            rlutil::anykey();
            rlutil::cls();
        }
        else
        {

            // RONDA SIGUIENTE
            rlutil::cls();
            dibujo_cuadrado();
            rlutil::locate(30,7);
            cout << "FIN DE DE LA RONDA " << ronda << endl;
            rlutil::locate(30,9);
            cout << "PUNTAJES: "<< endl;
            for(int i=0; i<cantidadJugadores; i++)
            {
                rlutil::locate(30,10+i);
                cout << jugador[i] << " " << puntajeTotal[i] << " PUNTOS";
            }
            rlutil::anykey();
            rlutil::cls();
        }
        ronda++;

    }

}

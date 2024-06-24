#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "rlutil.h"
#include "funciones.h"
using namespace std;

void dosjugadores(bool simulado, std::string r[])
{

    std::string nombre_1, nombre_2;
    cargarNombre(nombre_1);
    cargarNombre(nombre_2);

    // VARIABLES JUEGO MULTIJUGADOR
    int const tam = 6;
    int dados1[tam], dados2[tam];
    int lanzamiento;
    int ronda = 0;
    int puntajeTotal_1 = 0, puntajeTotal_2 = 0;
    int maximoPorRonda ;
    int puntaje;
    bool escalera = false;

    while ((puntajeTotal_1 < 100) && (puntajeTotal_2 < 100))
    {
        ronda++;

        lanzamiento = 0;
        maximoPorRonda = 0;


        // INICIO RONDA
        rlutil::locate(35,9);
        cout << "RONDA N" << (char)248 << " " << ronda;
        dibujo_cuadrado();
        rlutil::anykey();
        rlutil::cls();




        for (int i = 0; i < 3 ; i++)
        {
            // MOSTRAMOS MENUES
            lanzamiento++;
            interfas_parteUP ( ronda, nombre_1, puntajeTotal_1);
            interfas_parteMiD( lanzamiento, maximoPorRonda);
            // TIRAMOS LOS DADOS
            puntaje = tirar_sumar_mostrar_dados (dados1,tam);


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





            //VERIFICAMOS SI ES ESCALERA:
            escalera = esEscalera( dados1, tam, puntaje);

            if(escalera)
            {
                cout << "ESCALERA, GANASTE LA PARTIDA!" << endl;
                actualizaRanking(r,nombre_1,100);
                return ;
            }
            //VERIFICAMOS GENERALA.
            generala( dados1, tam, puntaje);
            //VERIFICAMOS SI ES SEXTETO-6
            if ( puntaje == 36 )
            {
                // SE REINICIA EL PUNTAJE TOTAL, TAMBIEN SE REINICIA EL PUNTAJE Y EL MAXIMO POR RONDA.
                puntajeTotal_1 = puntaje = maximoPorRonda = 0;
                cout << "SACO SEXTETO 6 -- SE REINICIA EL PUNTAJE TOTAL" << endl;
            }
            else
            {
                if ( puntaje > maximoPorRonda)
                {
                    maximoPorRonda = puntaje;
                }
            }
            // SI J ES 2 ES EL FINAL DE LA RONDA.
            if ( i == 2 )
            {
                puntajeTotal_1 += maximoPorRonda;
                interfas_entre_turnos ( ronda, nombre_2, nombre_1, puntajeTotal_1, puntajeTotal_2 );
                //REINICIMOS LAS VARIABLES PARA LA PROXIMA RONDA.
                lanzamiento = 0;
                maximoPorRonda = 0;
            }
        }
        for ( int j = 0; j < 3; j++)
        {
            lanzamiento++;
            // MOSTRAMOS MENUES
            interfas_parteUP ( ronda, nombre_2, puntajeTotal_2);
            interfas_parteMiD (lanzamiento, maximoPorRonda);
            // TIRAMOS LOS DADOS
            puntaje = tirar_sumar_mostrar_dados (dados2,tam);
            //VERIFICAMOS SI ES ESCALERA:
            escalera = esEscalera( dados2, tam, puntaje);
            if(escalera)
            {
                cout << "ESCALERA, GANASTE LA PARTIDA!" << endl;
                actualizaRanking(r,nombre_2,100);
                return ;
            }
            //VERIFICAMOS GENERALA.
            generala( dados2, tam, puntaje);

            //VERIFICAMOS SI ES SEXTETO-6
            if ( puntaje == 36 )
            {
                // SE REINICIA EL PUNTAJE TOTAL, TAMBIEN SE REINICIA EL PUNTAJE Y EL MAXIMO POR RONDA.
                puntajeTotal_2 = puntaje = maximoPorRonda = 0;
                cout << "SACO SEXTETO 6 -- SE REINICIA EL PUNTAJE TOTAL" << endl;
            }
            else
            {
                if ( puntaje > maximoPorRonda)
                {
                    maximoPorRonda = puntaje;
                }
            }
            // SI J ES 2 ES EL FINAL DE LA RONDA.
            if ( j == 2)
            {
                puntajeTotal_2 += maximoPorRonda;
                interfas_entre_turnos ( ronda, nombre_1, nombre_2, puntajeTotal_2, puntajeTotal_1);
                //REINICIMOS LAS VARIABLES PARA LA PROXIMA RONDA.
                lanzamiento = 0;
                maximoPorRonda = 0;
            }
        }
    }

    if ( puntajeTotal_1 > puntajeTotal_2)
    {
        cout << "GANADOR: " << nombre_1 << endl;
        cout << "CON: " << puntajeTotal_1 << endl;
        actualizaRanking(r,nombre_1,puntajeTotal_1);

    }
    else
    {
        cout << "GANADOR: " << nombre_2 << endl;
        cout << "CON: " << puntajeTotal_2 << endl;
        actualizaRanking(r,nombre_2,puntajeTotal_2);
    }
    rlutil::anykey();
//
//  rlutil::cls();
}
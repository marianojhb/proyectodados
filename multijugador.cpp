#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "funciones.h"


void multijugador(){

  int const tam = 6;
  int vec1[tam];
  int vec2[tam];
  int ronda = 0, lanzamiento;
  int puntajeTotal_1 = 0;
  int puntajeTotal_2 = 0;
  int puntaje;
  int maximoPorRonda ;
  string nombre_1, nombre_2;
  bool rtaEscalera = false;
  cargarNombre(nombre_1);
  cargarNombre(nombre_2);

  while ((puntajeTotal_1 < 100) && (puntajeTotal_2 < 100))
  {
    ronda++;
    ///////////////////////////////////////////////
      lanzamiento = 0;
      maximoPorRonda = 0;
        for (int i = 0; i < 3 ; i++)
        {
          // MOSTRAMOS MENUES
          lanzamiento++;
          interfas_parteUP ( ronda, nombre_1, puntajeTotal_1);
          interfas_parteMiD( lanzamiento, maximoPorRonda);
          // TIRAMOS LOS DADOS
          puntaje = tirar_sumar_mostrar_dados (vec1,tam);
          //VERIFICAMOS SI ES ESCALERA:
          rtaEscalera = esEscalera( vec1, tam);
            if(rtaEscalera)
            {
              cout << "ESCALERA, GANASTE LA PARTIDA!" << endl;
              return ;
            }
          //VERIFICAMOS GENERALA.
          generala( vec1, tam, puntaje);
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

          if ( i == 2 )
          {
            puntajeTotal_1 += maximoPorRonda;
            //interfas_fin_ronda( ronda, maximoPorRonda, puntajeTotal_1);
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
          puntaje = tirar_sumar_mostrar_dados (vec2,tam);
          //VERIFICAMOS SI ES ESCALERA:
          rtaEscalera = esEscalera( vec2, tam);
            if(rtaEscalera)
            {
              cout << "ESCALERA, GANASTE LA PARTIDA!" << endl;
              return ;
            }
          //VERIFICAMOS GENERALA.
          generala( vec2, tam, puntaje);

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

          if ( j == 2)
          {
            puntajeTotal_2 += maximoPorRonda;
            //interfas_fin_ronda(ronda, maximoPorRonda, puntajeTotal_2);
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


  }
  else
  {
    cout << "GANADOR: " << nombre_2 << endl;
    cout << "CON: " << puntajeTotal_2 << endl;
  }
  system("pause");
//
//  system("cls");
}

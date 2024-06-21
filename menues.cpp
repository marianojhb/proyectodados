#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "funciones.h"

void mostrarMenu(bool simulado)
{
  system("cls");
  cout << " ---- Escalera o Cien ---- " << endl;
  cout << " 1 - Comenzar 1 JUGADOR " << endl;
  cout << " 2 - Comenzar 2 JUGADORES " << endl;
  cout << " 3 - Comenzar MULTIJUGADOR " << endl;
  cout << " 4 - Mostrar mayores puntuaciones " << endl;
  cout << " 5 - Modo simulado (ON/OFF): " << labelSimulado(simulado) << endl;
  cout << " 0 - Salir " << endl;
  cout << endl;
  cout << " Ingrese la opcion deseada: ";

}

void menuJuegoSolitario(int puntajeTotal,
                        string nombre,
                        int ronda,
                        int lanzamiento,
                        int maximoPorRonda,
                        bool simulado)
{
  system("cls");
  cout << "---------------------------------------------------------------------------------" << endl;
  cout << "JUGADOR: " << nombre << " | MODO DE JUEGO SIMULADO: " << labelSimulado(simulado) << endl;
  cout << "JUEGO SOLITARIO | RONDA No "<< ronda <<" | PUNTAJE TOTAL: " << puntajeTotal << " PUNTOS" << endl;
  cout << "---------------------------------------------------------------------------------" << endl;
  cout << "MAXIMO PUNTAJE DE LA RONDA: "<< maximoPorRonda <<"  PUNTOS" << endl;
  cout << "LANZAMIENTO No " << lanzamiento << endl;
  cout << "---------------------------------------------------------------------------------" << endl;
 }

 void menuJuegoMultijugador(int puntajeTotal,
                        string jugador,
                        int ronda,
                        int lanzamiento,
                        int maximoPorRonda,
                        bool simulado
                        )
{
  system("cls");
  cout << "---------------------------------------------------------------------------------" << endl;
  cout << "TURNO DE: " << jugador << " | MODO DE JUEGO SIMULADO: " << labelSimulado(simulado) << endl;
  cout << "JUEGO MULTIJUGADOR | RONDA No "<< ronda <<" | PUNTAJE TOTAL: " << puntajeTotal << " PUNTOS" << endl;
  cout << "---------------------------------------------------------------------------------" << endl;
  cout << "MAXIMO PUNTAJE DE LA RONDA: "<< maximoPorRonda <<"  PUNTOS" << endl;
  cout << "LANZAMIENTO No " << lanzamiento << endl;
  cout << "---------------------------------------------------------------------------------" << endl;
 }

// INTERFAS_FIN_PARTIDA.
void interfas_entre_turnos( int ronda, string proxTurno, string antTurno, int puntajeTotal_ant, int puntajeTotal_prox )
{
  cout << "RONDA No " << ronda << endl;
  cout << "PROXIMO TURNO: " << proxTurno << endl;
  cout << endl;
  cout << "PUNTAJE " << antTurno << ": "<< puntajeTotal_ant << endl;
  cout << "PUNTAJE " << proxTurno << ": "<< puntajeTotal_prox << endl;
  cout << endl;
  system("pause");
  system("cls");
}
// INTERFAS_FIN_RONDA.
void interfas_fin_ronda( int ronda, int maxPuntajeRonda, int puntajeTotal)
{
  system("cls");
  cout << endl;
  cout << "FIN DE DE LA RONDA " << ronda << endl;
  cout << "SUMASTE: " << maxPuntajeRonda << " PUNTOS." << endl;
  cout << "PUNTAJE TOTAL: " << puntajeTotal << " PUNTOS." << endl;
  system("pause");
  system("cls");
}

void interfas_parteUP ( int ronda, string nombre , int puntajeTotal)
{
  cout << "TURNO DE " << nombre << " | RONDA No " << ronda << " | PUNTAJE TOTAL: " << puntajeTotal << " PUNTOS" << endl;
}

void interfas_parteMiD(int lanzamiento, int maxPuntajeRonda)
{
  cout << "---------------------------------------------------------------------------------" << endl;
  cout << "MAXIMO PUNTAJE DE LA RONDA: " << maxPuntajeRonda << " PUNTOS" << endl;
  cout << "LAMZAMIENTO No " << lanzamiento << endl;
  cout << "---------------------------------------------------------------------------------" << endl;
  system("pause");
  //BORRA LO QUE VENGA POR DEBAJO:
  // system("cls");
}










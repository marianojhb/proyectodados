#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "funciones.h"
#include "rlutil.h"
void mostrarMenu(bool simulado)
{
  //system("cls");
  //CAMBIAMOS EL COLOR DE TEXTO:
  rlutil::setColor(rlutil::COLOR::WHITE);
  //CAMBIAMOS LA POSICION DE LA COLUMNA:
  rlutil::locate(40,10);
  cout << " ---- Escalera o Cien ---- " << endl;
  rlutil::locate(40,11);
  cout << "COMENZAR UN JUGADOR" << endl;
  rlutil::locate(40,12);
  cout << "COMENZAR DOS JUGADORES" << endl;
  rlutil::locate(40,13);
  cout << "COMENZAR MULTIJUGADOR " << endl;
  rlutil::locate(40,14);
  cout << "MOSTRAR MAYORES PUNTUACIONES" << endl;
  rlutil::locate(40,15);
  cout << "MODO SIMULADO (ON/OFF): " << labelSimulado(simulado) << endl;
  rlutil::locate(40,16);
  cout << "SALIR" << endl;
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
  cout << "TURNO DE " << nombre << " | RONDA N" << (char)248 << ronda << " | PUNTAJE TOTAL: " << puntajeTotal << " PUNTOS" << endl;
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










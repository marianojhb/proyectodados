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
  cout << " 3 - Mostrar mayores puntuaciones " << endl;
  cout << " 4 - Modo simulado (ON/OFF): " << labelSimulado(simulado) << endl;
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

// INTERFAS_FIN_RONDA.
void interfas_fin_ronda( int ronda, int maxPuntajeRonda, int puntajeTotal)
{
  cout << endl;
  cout << "FIN DE DE LA RONDA " << ronda << endl;
  cout << "SUMASTE: " << maxPuntajeRonda << " PUNTOS." << endl;
  cout << "PUNTAJE TOTAL: " << puntajeTotal << " PUNTOS." << endl;
  system("pause");
  system("cls");
}
// INTERFAS_FIN_PARTIDA.

void interfas_parteUP ( int ronda, string nombre , int puntajeTotal)
{
  cout << "TURNO DE " << nombre << " | RONDA N° " << ronda << " | PUNTAJE TOTAL: " << puntajeTotal << " PUNTOS" << endl;
}

void interfas_parteMiD(int lanzamiento, int maxPuntajeRonda)
{
  cout << "---------------------------------------------------------------------------------" << endl;
  cout << "MAXIMO PUNTAJE DE LA RONDA: " << maxPuntajeRonda << " PUNTOS" << endl;
  cout << "LAMZAMIENTO N° " << lanzamiento << endl;
  cout << "---------------------------------------------------------------------------------" << endl;
  system("pause");
  //BORRA LO QUE VENGA POR DEBAJO:
  // system("cls");
}










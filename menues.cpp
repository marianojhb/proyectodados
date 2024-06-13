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

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void mostrarMenu()
{
  system("cls");
  cout << " ---- Escalera o Cien ---- " << endl;
  cout << " 1 - Comenzar 1 JUGADOR " << endl;
  cout << " 2 - Comenzar 2 JUGADORES " << endl;
  cout << " 3 - Mostrar mayores puntuaciones " << endl;
  cout << " 0 - Salir " << endl;
  cout << endl;
  cout << " Ingrese la opcion deseada: ";

}

void menuJuegoSolitario(int puntajeTotal,
                        string nombre,
                        int ronda,
                        int lanzamiento,
                        int maximoPorRonda)
{
  system("cls");
  cout << "---------------------------------------------------------------------------------" << endl;
  cout << "JUGADOR: " << nombre << endl;
  cout << "JUEGO SOLITARIO | RONDA No "<< ronda <<" | PUNTAJE TOTAL: " << puntajeTotal << " PUNTOS" << endl;
  cout << "---------------------------------------------------------------------------------" << endl;
  cout << "MAXIMO PUNTAJE DE LA RONDA: "<< maximoPorRonda <<"  PUNTOS" << endl;
  cout << "LANZAMIENTO No " << lanzamiento << endl;
  cout << "---------------------------------------------------------------------------------" << endl;
 }

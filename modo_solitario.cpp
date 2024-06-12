#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "funciones.h"
#include "vectores.cpp"


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

  while(puntajeTotal < 100 || escalera == true)
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
      system("pause");
    }
    // Cartel fin de ronda:
    menuJuegoSolitario(puntajeTotal, jugador1, ronda, lanzamiento-1, maximoPorRonda);
    cout << "Fin de la ronda. Sumo " << maximoPorRonda << " puntos." << endl;
    sumaPuntaje(maximoPorRonda, puntajeTotal);
    system("pause");
    ronda++;
  }

  menuJuegoSolitario(puntajeTotal, jugador1, ronda-1, lanzamiento-1, maximoPorRonda);
  cout << "Llego a " << puntajeTotal << " puntos. Uso " << ronda-1 << " rondas." << endl;
  system("pause");
};

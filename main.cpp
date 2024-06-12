#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
#include "funciones.h"

int main()
{
  // variables generales del juego
  srand(time(NULL));
  // const int TAM=6;
  // int dados[TAM]= {1,2,3,4,5,6};
  int opcion;

  while(true)
  {
    mostrarMenu();
    cin >> opcion;

    switch (opcion)
    {

    // funcion juegoSol
    case 1:
      modoSolitario();
      break;

    case 3:
      // mostrarVector(dados, TAM);
      break;

    case 0:
      cout<<"Saliendo del programa..."<<endl;
      break;

    default:
      cout<<"Ingrese una opcion correcta."<<endl;
      system("pause");
      break;
    }

  }


  return 0;
}

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


bool esEscalera(int vec[], int tam, int puntaje)
{
  int resultado;
  int uno,dos,tres,cuatro,cinco,seis=0;
  if (puntaje !=21)
  {
    resultado = false;
  }
  else
  {
    for (int i = 0 ; i < tam; i++ ) {
        switch(vec[i])
        {
          case 1: uno++;
          break;
          case 2: dos++;
          break;
          case 3: tres++;
          break;
          case 4: cuatro++;
          break;
          case 5: cinco++;
          break;
          case 6: seis++;
          break;
        }
    }
    if (uno == dos == tres == cuatro == cinco == seis == 1) {
      resultado = true;
    }

  }
  return resultado;
}

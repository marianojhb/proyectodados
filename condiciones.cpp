#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


// ESCALERA
bool esEscalera(int vec[], int tam, int puntaje)
{
    bool resultado;
    int uno=0,dos=0,tres=0,cuatro=0,cinco=0,seis=0;

    if (puntaje != 21)
    {
        resultado = false;
    }
    else
    {
        // RECORREMOS CADA POSICION DEL VECTOR.
        for (int i = 0 ; i < tam; i++ )
        {
            switch(vec[i])
            {
              case 1:
                  uno++;
                  break;
              case 2:
                  dos++;
                  break;
              case 3:
                  tres++;
                  break;
              case 4:
                  cuatro++;
                  break;
              case 5:
                  cinco++;
                  break;
              case 6:
                  seis++;
                  break;
            }
        }

    }
    // UNA VEZ QUE VERIFICAMOS CUANTOS NUMEROS SE REPITEN
      // DETERMINAMOS SI ES ESCALERA.
      if ( (uno == 1) && (dos == 1) && (tres == 1) && (cuatro == 1) && (cinco == 1) && (seis == 1))
      {
          resultado = true;
      }
      else
      {
        resultado = false;
      }

  return resultado;
}

// 6 dados 6 reincia el puntaje total
void seisSeis(int &puntaje, int &puntajeTotal)
{
    if (puntaje==36)
    {
        puntajeTotal = 0;
        puntaje = 0;
        cout << "6 dados 6 reinicia el puntaje total a 0 " << endl;
    }
}
// 6 dados iguales (que no sean 6), multiplica por 10 el valor
void generala(int vec[], int tam, int &puntaje)
{
  // VERIFICAMOS QUE EL PRIMER DADO NO SEA 6.
    if (vec[0]!=6)
    {
      // INICIALMENTE, ASUMIMOS QUE TODOS LOS DADOS SON IGUALES.
        bool generala = true;
      //RECORREMOS EL RESTO DE LOS DADOS PARA VERIFICAR.
        for (int i=1; i<tam; i++)
        {
            if (vec[0] != vec[i])
            {
                generala = false;
                break; // SALIR DEL BUCLE SI ENCONTRAMOS UN DADO DIFERENTE
            }
        }
        // SI ES "VERDADERO" SIGUE SIENDO GENERALA.
        if (generala)
        {
          puntaje = vec[0]*10;
        }
    }
}

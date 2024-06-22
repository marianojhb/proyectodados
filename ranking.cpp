#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "funciones.h"

void actualizaRanking (string vec[], string n, int p)
{
    string ultimaPartida = intToString(p) + " " + n;
    vec[10] = ultimaPartida;

    // ORDENAR UN VECTOR CON METODO BURBUJA
    string aux = "";
    for (int j=0; j<10; j++)
    {
        for(int i=0; i<10; i++) // 0
        {
            if (vec[i]<vec[i+1])
            {
                aux=vec[i];
                vec[i]=vec[i+1];
                vec[i+1]=aux;
            }
        }
    }
}


string intToString(int n) //182  1+8+2=182
{

    string respuesta = "xxx";
    int centenas = (int)(n/100);
    int decenas = (int)(n-centenas*100)/10;
    int unidades =  n-centenas*100-decenas*10;

    respuesta[0] = centenas+48;
    respuesta[1] = decenas+48;
    respuesta[2] = unidades+48;

    return respuesta;
}


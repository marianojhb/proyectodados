#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "funciones.h"

void actualizaRanking (string r[], string n, int p)
{
    string nombre=n;
    int puntaje=p;
    int num = stringToInt(r[0]);
    if (num<puntaje) {
        r[0] = intToString(puntaje) + " " + nombre;
        cout << r[0] << endl;
        // si es mayor al ranking devolver un cout advirtiendo esto en la pantalla de cada modo solitario y multijugador
        cout << "Nuevo record de " << nombre << " con " << puntaje << " puntos." << endl;
    }
}

void mostrarRanking (){}

int stringToInt(string s)
{
    int num=0;
    num = charToInt(s[0])*100 + charToInt(s[1])*10 + charToInt(s[2]);
    return num;
}

int charToInt(char c)
{
    int respuesta=c-48;
    return respuesta;
}

string intToString(int n)
{
    cout << "Numero a convertir=" << n << endl;
    string respuesta = "xxx";
    int centenas = (int)(n/100);
    int decenas = (int)(n-centenas*100)/10;
    int unares =  n-centenas*100-decenas*10;


    respuesta[0] = centenas+48; // centenas
    respuesta[1] = decenas+48; // decenas
    respuesta[2] = unares+48;

    return respuesta;
}


#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "rlutil.h"
using namespace std;
#include "funciones.h"

void mostrarUltimasPartidas(string ultimaPartida)
{

    cout << "Partidas anteriores: " << endl;
    string partidasAnteriores = "";
    partidasAnteriores += ultimaPartida;
//    rlutil::anykey();
}

void cargarNombre(string &nombre)
{
    rlutil::cls();
//    rlutil::cls();

    cout << endl;
    cout << "INGRESE SU NOMBRE: ";
    cin >> nombre;
    rlutil::cls();
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "                          Hola, " << nombre << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    rlutil::anykey();
    rlutil::cls();
}

int sumaPuntaje (int puntaje, int &puntajeTotal)
{
    puntajeTotal += puntaje;
    return puntajeTotal;
}

void lanzar2(bool simulado, int dados[], int tam)
{
    if (simulado==false)
    {
        cout << endl << endl << "                         LANZAR LOS DADOS" << endl << endl;
        rlutil::anykey();
        cargarVectorAleatorio(dados, tam); // carga el vector aleatorio en memoria
    }
    else
    {
        cargarVectorManual(dados, tam);
    }
}



void mostrarPuntaje(int puntaje)
{
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "                            ";
    cout << endl;
    cout << "Sumo " << puntaje << " puntos." << endl;
    cout << endl;
}

void toggleSimulado(bool &simulado)
{
    simulado = !simulado;
}

string labelSimulado(bool simulado)
{
    if (simulado)
    {
        return "ON ";
    }
    else
    {
        return "OFF";
    }
}

int tirar_sumar_mostrar_dados ( int v[], int tam)
{
    int puntaje;
    cargarVectorAleatorio(v,tam);
    mostrarVector(v,tam);
    puntaje = sumaVector (v,tam);
    cout << endl;
    cout << "SUMASTE: " << puntaje << endl;
    cout << endl;
    rlutil::anykey();
    system ("cls");
    return puntaje;


}










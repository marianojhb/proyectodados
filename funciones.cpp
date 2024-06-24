#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "rlutil.h"
#include "funciones.h"
using namespace std;

void mostrarUltimasPartidas(std::string ultimaPartida)
{

    cout << "PARTIDAS ANTERIORES: " << endl;
    string partidasAnteriores = "";
    partidasAnteriores += ultimaPartida;
}

void cargarNombre(std::string &nombre)
{
    rlutil::cls();
    cout << endl;
    rlutil::locate(20,10);
    cout << "INGRESE SU NOMBRE: ";
    rlutil::showcursor();
    cin >> nombre;
    rlutil::hidecursor();
    rlutil::cls();
    /*
    rlutil::locate(32,12);
    cout << "Hola, " << nombre << "!!!"<<endl;
    rlutil::anykey();
    */
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
        rlutil::locate(28,9);
        cout << (char)175 << (char)175 << " LANZAR LOS DADOS";
        rlutil::anykey();
      //DEMORA EN MILISEGUNDOS DE LA EJECUCIONS DE LA SIGUIENTE LINEA.
        rlutil::msleep(400);
        cargarVectorAleatorio(dados, tam); // carga el vector aleatorio en memoria
    }
    else
    {
        cargarVectorManual(dados, tam);
    }
}


void mostrarPuntaje(int puntaje)
{

    rlutil::locate(25,20);
    cout << "SUMATORIA DE LOS DADOS " << puntaje << " PUNTOS" << endl;

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










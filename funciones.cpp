#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "rlutil.h"
#include "funciones.h"
using namespace std;

void mostrarUltimasPartidas(std::string ultimaPartida)
{

    cout << "Partidas anteriores: " << endl;
    string partidasAnteriores = "";
    partidasAnteriores += ultimaPartida;
//    rlutil::anykey();
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
    rlutil::locate(33,10);
    cout << "Hola, " << nombre << "!!!"<<endl;
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
        cout << endl << endl << "                        " << (char)175 << (char)175 << " LANZAR LOS DADOS" << endl << endl;
        rlutil::anykey();
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










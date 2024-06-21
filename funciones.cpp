#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "funciones.h"

void mostrarUltimasPartidas(string ultimaPartida)
{

    cout << "Partidas anteriores: " << endl;
    string partidasAnteriores = "";
    partidasAnteriores += ultimaPartida;
//    system("pause");
}

void cargarNombre(string &nombre)
{

    cout << endl;
    cout << "Ingrese su nombre: ";
    cin >> nombre;
    system("cls");
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
    system("pause");
    system("cls");
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
        system("pause");
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
        return "ON";
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
    system("pause");
    system ("cls");
    return puntaje;

    //
}
//
//int sumaLanzamiento(int v[], int tam)
//{
//
//  cargarVectorAleatorio(vec,tam);
//  mostrarVector(vec,tam);
//  int sumaVector = sumaVector(vec,tam);
//  // ANTES DE RETORNAR, HACER UNA FX, CON UNA SERIE DE REGLAS, PARA SI: EL LANZAMIENTO ES ESCALERA, SEXTERO6, SEXTETO.
//  return sumaVector;
//
//}
//}
//
//int devolverMax_porRonda (int v[], int tam ,int puntaje)
//{
//  int puntaje;
//  int maxPuntaje;
//  for ( int i = 0 ; i < 3 ; i++)
//  {
//    puntaje = sumaLanzamiento(vec, tam);
//      if ( i == 0)
//      {
//        maxPuntaje = puntaje;
//      }
//      else
//      {
//        if ( puntaje > maxPuntaje)
//        {
//          maxPuntaje = puntaje;
//        }
//      }
//  }
//  return maxPuntaje;
//}









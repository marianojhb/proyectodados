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

    system("cls");
    cout << "Ingrese su nombre: ";
    cin >> nombre;
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

bool lanzar()
{
    bool l=false;
    char boton;
    cout << "Apriete (L) para lanzar los dados: ";
    cin >> boton;
    while (boton !='l' && boton !='L')
    {
        cout << "Apriete (L) para lanzar los dados: ";
        cin >> boton;
    }
    if(boton =='l' && boton =='L')
    {

        l=true;
        return l;
    }
    return l;
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
  int TAM = 6;
  int sumar;
  int vec[TAM];
  cargarVectorAleatorio(vec,TAM);
  mostrarVector(vec,TAM);
  sumar = sumaVector (vec,TAM);
  cout << endl;
  cout << "SUMASTE: " << sumar << endl;

  system("pause");
  system ("cls");
  return sumar;
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









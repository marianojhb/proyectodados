#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


void mostrarUltimasPartidas(string ultimaPartida) {

    cout << "Partidas anteriores: " << endl;
    string partidasAnteriores = "";
    partidasAnteriores += ultimaPartida;
//    system("pause");
}

void cargarNombre(string &nombre) {
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
}

int sumaPuntaje (int puntaje, int &puntajeTotal) {
    puntajeTotal += puntaje;
    return puntajeTotal;
}

bool lanzar(){
    bool l=false;
    char boton;
    cout << "Apriete L para lanzar los dados: ";
    cin >> boton;
    while (boton !='l' && boton !='L') {
        cout << "Apriete L para lanzar los dados: ";
        cin >> boton;
    }
    if(boton =='l' && boton =='L')
    {

        l=true;
        return l;
    }
    return l;
}

void mostrarPuntaje(int &puntaje){
      cout << endl;
      cout << endl;
      cout << endl;
      cout << "                            ";
      cout << endl;
      cout << "Sumo " << puntaje << " puntos." << endl;
      cout << endl;
}

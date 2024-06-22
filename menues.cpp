#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "rlutil.h"
using namespace std;
#include "funciones.h"

void mostrarMenu(bool simulado)
{
    //DIUJAMOS EL CUADRO:
    dibujo_cuadrado();
    //CAMBIAMOS EL COLOR DE TEXTO:
    rlutil::setColor(rlutil::COLOR::WHITE);
    //CAMBIAMOS LA POSICION DE LA COLUMNA:
    rlutil::locate(22,6);
    cout << " ---- ESCALERA O CIEN ---- " << endl;
    rlutil::locate(22,7);
    cout << "COMENZAR UN JUGADOR" << endl;
    rlutil::locate(22,8);
    cout << "COMENZAR DOS JUGADORES" << endl;
    rlutil::locate(22,9);
    cout << "COMENZAR MULTIJUGADOR " << endl;
    rlutil::locate(22,10);
    cout << "MOSTRAR MAYORES PUNTUACIONES" << endl;
    rlutil::locate(22,11);
    cout << "MODO SIMULADO " << labelSimulado(simulado) << endl;
    rlutil::locate(22,12);
    cout << "CREDITOS" << endl;
    rlutil::locate(22,13);
    cout << "SALIR" << endl;
}


void menuJuegoSolitario(int puntajeTotal,
                        string nombre,
                        int ronda,
                        int lanzamiento,
                        int maximoPorRonda,
                        bool simulado)
{
    rlutil::cls();
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << "JUGADOR: " << nombre << " | MODO DE JUEGO SIMULADO: " << labelSimulado(simulado) << endl;
    cout << "JUEGO SOLITARIO | RONDA No "<< ronda <<" | PUNTAJE TOTAL: " << puntajeTotal << " PUNTOS" << endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << "MAXIMO PUNTAJE DE LA RONDA: "<< maximoPorRonda <<"  PUNTOS" << endl;
    cout << "LANZAMIENTO No " << lanzamiento << endl;
    cout << "---------------------------------------------------------------------------------" << endl;
}

void menuJuegoMultijugador(int puntajeTotal,
                           string jugador,
                           int ronda,
                           int lanzamiento,
                           int maximoPorRonda,
                           bool simulado
                          )
{
    rlutil::cls();
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << "TURNO DE: " << jugador << " | MODO DE JUEGO SIMULADO: " << labelSimulado(simulado) << endl;
    cout << "JUEGO MULTIJUGADOR | RONDA No "<< ronda <<" | PUNTAJE TOTAL: " << puntajeTotal << " PUNTOS" << endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << "MAXIMO PUNTAJE DE LA RONDA: "<< maximoPorRonda <<"  PUNTOS" << endl;
    cout << "LANZAMIENTO No " << lanzamiento << endl;
    cout << "---------------------------------------------------------------------------------" << endl;
}

// INTERFAS_FIN_PARTIDA.
void interfas_entre_turnos( int ronda, string proxTurno, string antTurno, int puntajeTotal_ant, int puntajeTotal_prox )
{
    dibujo_cuadrado();
    rlutil::locate(30,6);
    cout << "RONDA N" << (char)248 << " " << ronda << endl;
    rlutil::locate(23,7);
    cout << "PROXIMO TURNO: " << proxTurno << endl;
    cout << endl;
    rlutil::locate(23,9);
    cout << "PUNTAJE " << antTurno << ": "<< puntajeTotal_ant << endl;
    rlutil::locate(23,10);
    cout << "PUNTAJE " << proxTurno << ": "<< puntajeTotal_prox << endl;
    cout << endl;
    rlutil::locate(18,12);
    rlutil::anykey();
    rlutil::cls();
}
// INTERFAS_FIN_RONDA.
void interfas_fin_ronda( int ronda, int maxPuntajeRonda, int puntajeTotal)
{
    rlutil::cls();

    cout << endl;
    cout << "FIN DE DE LA RONDA " << ronda << endl;
    cout << "SUMASTE: " << maxPuntajeRonda << " PUNTOS." << endl;
    cout << "PUNTAJE TOTAL: " << puntajeTotal << " PUNTOS." << endl;
    rlutil::anykey();
    rlutil::cls();

}

void interfas_parteUP ( int ronda, string nombre, int puntajeTotal)
{

    cout << "TURNO DE " << nombre << " | RONDA N" << (char)248 << ronda << " | PUNTAJE TOTAL: " << puntajeTotal << " PUNTOS" << endl;
}

void interfas_parteMiD(int lanzamiento, int maxPuntajeRonda)
{
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << "MAXIMO PUNTAJE DE LA RONDA: " << maxPuntajeRonda << " PUNTOS" << endl;
    cout << "LAMZAMIENTO N" <<  (char)248 << " " << lanzamiento << endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    rlutil::anykey();
    //BORRA LO QUE VENGA POR DEBAJO:
    // rlutil::cls();
}


void dibujo_cuadrado()
{
    rlutil::setColor(rlutil::COLOR::WHITE);

    //DIBUJANDO EL CUADRADO
    // LINEA SUPERIOR: X1=30  X2=82 | Y1 = 4
    rlutil::locate(10,4);
    cout << (char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 <<  " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " ";
    cout << (char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 <<  " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " ;
    cout << (char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 <<  " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " ";
    // LINEA INFERIOS: X1=30  X2=82 | Y = 15
    rlutil::locate(10,15);
    cout << (char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 <<  " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " ";
    cout << (char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 <<  " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " ;
    cout << (char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 <<  " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " ";
    //LINEA VERTICAL IZQUIERDA:
    rlutil::locate(10,5);
    cout << (char)223;
    rlutil::locate(10,6);
    cout << (char)223;
    rlutil::locate(10,7);
    cout << (char)223;
    rlutil::locate(10,8);
    cout << (char)223;
    rlutil::locate(10,9);
    cout << (char)223;
    rlutil::locate(10,10);
    cout << (char)223;
    rlutil::locate(10,11);
    cout << (char)223;
    rlutil::locate(10,12);
    cout << (char)223;
    rlutil::locate(10,13);
    cout << (char)223;
    rlutil::locate(10,14);
    cout << (char)223;
    //LINEA VERTICAL DERECHA:
    rlutil::locate(62,5);
    cout << (char)223;
    rlutil::locate(62,6);
    cout << (char)223;
    rlutil::locate(62,7);
    cout << (char)223;
    rlutil::locate(62,8);
    cout << (char)223;
    rlutil::locate(62,9);
    cout << (char)223;
    rlutil::locate(62,10);
    cout << (char)223;
    rlutil::locate(62,11);
    cout << (char)223;
    rlutil::locate(62,12);
    cout << (char)223;
    rlutil::locate(62,13);
    cout << (char)223;
    rlutil::locate(62,14);
    cout << (char)223;
}


void creditos()
{

    rlutil::cls();
    dibujo_cuadrado();
    rlutil::locate(26,7);
    cout << "CREDITOS" << endl;
    rlutil::locate(26,8);
    cout << "********" << endl;
    rlutil::locate(22,9);
    cout << "BELGRANO MARIANO" << endl;
    rlutil::locate(22,10);
    cout << "PISANO MATEO" << endl;
    rlutil::locate(22,11);
    cout << "ZUBILETE CARLOS" << endl;
    rlutil::locate(22,13);
    cout << "RUTIL Copyright (C) 2010 Tapio Vierros" << endl;
    rlutil::anykey();
    rlutil::cls();
}



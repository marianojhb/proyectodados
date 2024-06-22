#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "rlutil.h"
using namespace std;
#include "funciones.h"

void mostrarMenu(bool simulado)
{
//    rlutil::cls();
//DIUJAMOS EL CUADRO:
    dibujo_cuadrado();
    //CAMBIAMOS EL COLOR DE TEXTO:
    rlutil::setColor(rlutil::COLOR::WHITE);
    //CAMBIAMOS LA POSICION DE LA COLUMNA:
    rlutil::locate(42,6);
    cout << " ---- ESCALERA O CIEN ---- " << endl;
    rlutil::locate(42,7);
    cout << "COMENZAR UN JUGADOR" << endl;
    rlutil::locate(42,8);
    cout << "COMENZAR DOS JUGADORES" << endl;
    rlutil::locate(42,9);
    cout << "COMENZAR MULTIJUGADOR " << endl;
    rlutil::locate(42,10);
    cout << "MOSTRAR MAYORES PUNTUACIONES" << endl;
    rlutil::locate(42,11);
    cout << "MODO SIMULADO " << labelSimulado(simulado) << endl;
    rlutil::locate(42,12);
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
    rlutil::locate(50,6);
    cout << "RONDA N" << (char)248 << " " << ronda << endl;
    rlutil::locate(43,7);
    cout << "PROXIMO TURNO: " << proxTurno << endl;
    cout << endl;
    rlutil::locate(43,9);
    cout << "PUNTAJE " << antTurno << ": "<< puntajeTotal_ant << endl;
    rlutil::locate(43,10);
    cout << "PUNTAJE " << proxTurno << ": "<< puntajeTotal_prox << endl;
    cout << endl;
    rlutil::locate(38,12);
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
    rlutil::locate(30,4);
    cout << (char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 <<  " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " ";
    cout << (char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 <<  " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " ;
    cout << (char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 <<  " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " ";
    // LINEA INFERIOS: X1=30  X2=82 | Y = 14
    rlutil::locate(30,14);
    cout << (char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 <<  " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " ";
    cout << (char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 <<  " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " ;
    cout << (char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 <<  " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " ";
    //LINEA VERTICAL DERECHA:
    rlutil::locate(30,5);
    cout << (char)223;
    rlutil::locate(30,6);
    cout << (char)223;
    rlutil::locate(30,7);
    cout << (char)223;
    rlutil::locate(30,8);
    cout << (char)223;
    rlutil::locate(30,9);
    cout << (char)223;
    rlutil::locate(30,10);
    cout << (char)223;
    rlutil::locate(30,11);
    cout << (char)223;
    rlutil::locate(30,12);
    cout << (char)223;
    rlutil::locate(30,13);
    cout << (char)223;
    //LINEA VERTICAL IZQUIERDA:
    rlutil::locate(82,5);
    cout << (char)223;
    rlutil::locate(82,6);
    cout << (char)223;
    rlutil::locate(82,7);
    cout << (char)223;
    rlutil::locate(82,8);
    cout << (char)223;
    rlutil::locate(82,9);
    cout << (char)223;
    rlutil::locate(82,10);
    cout << (char)223;
    rlutil::locate(82,11);
    cout << (char)223;
    rlutil::locate(82,12);
    cout << (char)223;
    rlutil::locate(82,13);
    cout << (char)223;
}







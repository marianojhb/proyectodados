#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "rlutil.h"
#include "funciones.h"
using namespace std;


// MENU PRINCIPAL
void mostrarMenu(bool simulado)
{
    //DIUJAMOS EL CUADRO:
    dibujo_cuadrado();
    int alineacion_menu = 28;
    //CAMBIAMOS EL COLOR DE TEXTO:
    rlutil::setColor(rlutil::COLOR::WHITE);
    //CAMBIAMOS LA POSICION DE LA COLUMNA:
    rlutil::locate(alineacion_menu,6);
    cout << " ---- ESCALERA O CIEN ---- " << endl;
    rlutil::locate(alineacion_menu,7);
    cout << "COMENZAR UN JUGADOR" << endl;
    rlutil::locate(alineacion_menu,8);
    cout << "COMENZAR DOS JUGADORES" << endl;
    rlutil::locate(alineacion_menu,9);
    cout << "COMENZAR DOS JUGADORES RONDAS FIJAS" << endl;
    rlutil::locate(alineacion_menu,10);
    cout << "COMENZAR MULTIJUGADOR" << endl;
    rlutil::locate(alineacion_menu,11);
    cout << "RANKING" << endl;
    rlutil::locate(alineacion_menu,12);
    cout << "MODO SIMULADO " << labelSimulado(simulado) << endl;
    rlutil::locate(alineacion_menu,13);
    cout << "CREDITOS" << endl;
    rlutil::locate(alineacion_menu,14);
    cout << "SALIR" << endl;
}

// SUBMENU JUEGO SOLITARIO
void menuJuegoSolitario(int puntajeTotal,
                        std::string nombre,
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

// SUBMENU JUEGO MULTIJUADOR
void menuJuegoMultijugador(int puntajeTotal,
                           std::string jugador,
                           int ronda,
                           int lanzamiento,
                           int maximoPorRonda,
                           bool simulado
                          )
{
    rlutil::cls();
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << "TURNO DE: " << jugador << " | MODO DE JUEGO SIMULADO: " << labelSimulado(simulado) << endl;
    cout << "JUEGO MULTIJUGADOR | RONDA N" <<(char)248<< ronda <<" | PUNTAJE TOTAL: " << puntajeTotal << " PUNTOS" << endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << "MAXIMO PUNTAJE DE LA RONDA: "<< maximoPorRonda <<"  PUNTOS" << endl;
    cout << "LANZAMIENTO N" << (char)248 << lanzamiento << endl;
    cout << "---------------------------------------------------------------------------------" << endl;
}

// PANTALLA ENTRE TURNOS
void interfas_entre_turnos( int ronda, string proxTurno, string antTurno, int puntajeTotal_ant, int puntajeTotal_prox )
{
    dibujo_cuadrado();
    rlutil::locate(35,6);
    cout << "RONDA N" << (char)248 << " " << ronda << endl;
    rlutil::locate(30,9);
    cout << "PUNTAJE " << antTurno << ": "<< puntajeTotal_ant << endl;
    rlutil::locate(30,10);
    cout << "PUNTAJE " << proxTurno << ": "<< puntajeTotal_prox << endl;
    rlutil::locate(30,12);
    cout << "PROXIMO TURNO: " << proxTurno << endl;
    rlutil::anykey();
    rlutil::cls();
}
// PANTALLA FIN RONDA
void interfas_fin_ronda( int ronda, int maxPuntajeRonda, int puntajeTotal)
{
    rlutil::cls();
    dibujo_cuadrado();
    rlutil::locate(30,8);
    cout << "FIN DE DE LA RONDA " << ronda << endl;
    rlutil::locate(30,9);
    cout << "SUMASTE: " << maxPuntajeRonda << " PUNTOS." << endl;
    rlutil::locate(30,10);
    cout << "PUNTAJE TOTAL: " << puntajeTotal << " PUNTOS." << endl;
    rlutil::anykey();
    rlutil::cls();

}

// PANTALLA CAMBIO DE TURNO
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
}

void subMenu_rondas_prederminadas ( bool &rondas)
{

    rlutil::setColor(rlutil::COLOR::WHITE);
    dibujo_cuadrado();
    int key;
    int offset_y =0;

    bool finWhile = true;
    while(finWhile)
    {
      rlutil::locate(25,10);
      cout << " JUGAR CON RONDAS PREDERMINADAS: ";
      rlutil::locate(25,11);
      cout << " NO" << endl;
      rlutil::locate(25,12);
      cout << " SI" << endl;

      //COLOCAMOS LA FIGURA " >> " EN LA OPCION SI:
      rlutil::locate(22,11+offset_y);
      cout << (char)175 << (char)175 << endl;
      key = rlutil::getkey();

      switch(key)
      {
        case 14: // FLECHA PARA ARRIBA

              rlutil::locate(22,11+offset_y);

              //BORRAMOS EL CURSOS ANTERIOR
              cout << "  " << endl;;
              offset_y--;

              // PONEMOS LIMITE SUPERIOR A LA FIGURA " << "
              if ( offset_y < 0)
              {
                  // PARAMETROS PARA HACER UN BUCLE INFINITO DEL MENU
                  offset_y = 1;
                  rlutil::locate(22,11+offset_y);
              }
            break;
         case 15: // FLECHA-ABAJO

              rlutil::locate(22,11+offset_y);

              //BORRAMOS EL CURSOS ANTERIOR
              cout << "  " << endl;
              offset_y++;

              // PONEMOS LIMITE INFERIOR A LA FIGURA " << "
              if ( offset_y > 1 )
              {
                  // PARAMETROS PARA HACER UN BUCLE INFINITO DEL MENU
                  offset_y = 0;
                  rlutil::locate(22,7+offset_y);
              }
            break;
         case 1:
            //TENEMOS QUE ANALIZAR A offset_y QUE CORRESPONDE CON LA OPCION ELEGIDA
              switch (offset_y)
              {
                case 0:
                  // SE ELIJIO UNA OPCION
                    finWhile = false;
                    rlutil::cls();
                    rondas = false;
                    break;
                case 1:
                   // SE ELIJIO UNA OPCION
                    finWhile = false;
                    rlutil::cls();
                    rondas = true;
                  break;
                default:
                  break;
              }

          break;
          default:
          break;

      } // FIN DE KEY

    }

}
// FONDO DEL MENU PRINCIPAL
void dibujo_cuadrado()
{
    // ELEJIMOS EL COLOR DE LOS CARACTERES
    rlutil::setColor(rlutil::COLOR::WHITE);

    //DIBUJANDO EL CUADRADO
    // LINEA SUPERIOR: X1=30  X2=82 | Y1 = 4
    int columna_izquierda = 15;
    int columna_derecha = 67;
    rlutil::locate(columna_izquierda,4);
    cout << (char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 <<  " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " ";
    cout << (char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 <<  " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " ;
    cout << (char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 <<  " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " ";
    // LINEA INFERIOS: X1=30  X2=82 | Y = 15
    rlutil::locate(columna_izquierda,16);
    cout << (char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 <<  " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " ";
    cout << (char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 <<  " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " ;
    cout << (char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 <<  " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " " <<(char)223 << " ";
    //LINEA VERTICAL IZQUIERDA:
    rlutil::locate(columna_izquierda,5);
    cout << (char)223;
    rlutil::locate(columna_izquierda,6);
    cout << (char)223;
    rlutil::locate(columna_izquierda,7);
    cout << (char)223;
    rlutil::locate(columna_izquierda,8);
    cout << (char)223;
    rlutil::locate(columna_izquierda,9);
    cout << (char)223;
    rlutil::locate(columna_izquierda,10);
    cout << (char)223;
    rlutil::locate(columna_izquierda,11);
    cout << (char)223;
    rlutil::locate(columna_izquierda,12);
    cout << (char)223;
    rlutil::locate(columna_izquierda,13);
    cout << (char)223;
    rlutil::locate(columna_izquierda,14);
    cout << (char)223;
    rlutil::locate(columna_izquierda,15);
    cout << (char)223;
    //LINEA VERTICAL DERECHA:
    rlutil::locate(columna_derecha,5);
    cout << (char)223;
    rlutil::locate(columna_derecha,6);
    cout << (char)223;
    rlutil::locate(columna_derecha,7);
    cout << (char)223;
    rlutil::locate(columna_derecha,8);
    cout << (char)223;
    rlutil::locate(columna_derecha,9);
    cout << (char)223;
    rlutil::locate(columna_derecha,10);
    cout << (char)223;
    rlutil::locate(columna_derecha,11);
    cout << (char)223;
    rlutil::locate(columna_derecha,12);
    cout << (char)223;
    rlutil::locate(columna_derecha,13);
    cout << (char)223;
    rlutil::locate(columna_derecha,14);
    cout << (char)223;
    rlutil::locate(columna_derecha,15);
    cout << (char)223;
}

// SUBMENU CREDITOS
void creditos()
{

    rlutil::cls();
    dibujo_cuadrado();
    rlutil::locate(36,6);
    cout << "CREDITOS" << endl;
    rlutil::locate(36,7);
    cout << "********" << endl;
    rlutil::locate(32,8);
    cout << "BELGRANO MARIANO" << endl;
    rlutil::locate(32,9);
    cout << "PISANO MATEO" << endl;
    rlutil::locate(32,10);
    cout << "ZUBILETE CARLOS" << endl;
    rlutil::locate(32,12);
    cout << "BIBLIOTECA:" << endl;
    rlutil::locate(32,13);
    cout << "RLUTIL - TAPIO VIERROS" << endl;
    rlutil::anykey();
    rlutil::cls();
}

//SUBMENU RANKING
void menuRanking(std::string vec[], int tam)
{
    rlutil::cls();
//    dibujo_cuadrado();
    rlutil::locate(25,6);
    cout << "RANKING ULTIMAS 10 PARTIDAS" << endl;
    mostrarVectorString(vec, tam-1,25,8);
    rlutil::anykey();
    rlutil::cls();
}


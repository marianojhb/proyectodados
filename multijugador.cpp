#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "rlutil.h"
#include "funciones.h"
using namespace std;

void multijugador(bool simulado, std::string vec_ranking[], int cantidadJugadores, bool rondasPredeterminadas)
{

  // PREGUNTA CANTIDAD DE JUGADORES
    if (cantidadJugadores == 0)
    {
      //LIMPIAMOS LA PANTALLA
        rlutil::cls();
        rlutil::locate(25, 8);
        cout << "INGRESE LA CANTIDAD DE JUGADORES ";
      //MOSTRAMOS EL CURSOR.
        rlutil::showcursor();
        rlutil::locate(40, 10);
        cin >> cantidadJugadores;
      //OCUALTAMOS EL CURSOR
        rlutil::hidecursor();
    }

  // DECLARAMOS UN VECTOR DE DESEMPATE
    int vec_desempate[cantidadJugadores];
    ponerVectorEn0(vec_desempate, cantidadJugadores);

  //VECTOR QUE VA A CONTENER LOS NOMBRES DE LOS JUGADORES
    string jugador[cantidadJugadores];

    for (int i=0; i<cantidadJugadores; i++)
    {
      //LIMPIAMOS LA PANTALLA
        rlutil::cls();
        rlutil::locate(20, 12);
        cout << "INGRESE EL NOMBRE DEL JUGADOR  " << i+1 << ": ";
      //MOSTRAMOS EL CURSOR.
        rlutil::showcursor();
        rlutil::locate(54, 12);
        cin >> jugador[i];
      //OCUALTAMOS EL CURSOR
        rlutil::hidecursor();

    }
  //UNA VEZ INGRESADOS LOS NOMBRE DE LOS JUEGADORES, LIMPIAMOS LA PANTALLA
    rlutil::cls();

  // VARIABLES JUEGO MULTIJUGADOR
    int const tam = 6; // TAMAÑO DEL VECTOR DADOS
    int dados[tam]; // DECLARACION DEL VECTOR, PARA ALMACENAR LOS VALORES DE LOS DADOS
    int lanzamiento; // CONTADOR DE LANZAMIENTOS
    int ronda = 1; // CONTADOR DE RONDAS
    int puntajeTotal[cantidadJugadores];// VECTOR PARA ALMACENAR EL PUNTAJE DE CADA JUGADOR.
    ponerVectorEn0(puntajeTotal, cantidadJugadores);
    int maximoPorRonda; // VA A CONTENER EL MAXIMO POR RONDA, DE CADA JUGADOR.
    int puntaje =0; // VA A CONTENER EL PUNTAJE DE CADA LANZAMIENTO.
    bool escalera = false; // INDICADOR PARA VERIFICAR SI SACO ESCALERA.
    bool alcanzo100 = false; // INDICADOR PARA VERICAR QUIEN LLEGO A CIEN.
    int jugadorGanador; // VA A CONTENER EL PUNTAJE DEL GANADOR DEL PARTIDO.
    int rondaPredeterminada = 1; // VA A CONTENER LA CANTIDAD DE RONDAS PREDEFINIDAS

    while ( (alcanzo100 == false) && ( (rondasPredeterminadas == true) && (ronda <= rondaPredeterminada) ) )// ALCANZO 100 O ES POR RONDA FIJA (BOOL) +
    {
    //INICIO RONDA
      //DIBUJO EL CUADRADO PARA QUE VA A CONTENER EL MENSAJE.
        dibujo_cuadrado();
        rlutil::locate(35,9);
        cout << "RONDA N" << (char)248 << " " << ronda;
      //ESPERAMOS CUALQUIER TECAL PARA CONTINUAR
        rlutil::anykey();
      //LIMPIAMOS CONSOLA
        rlutil::cls();

      //TURNO DE JUGADORES
        for(int i=0; i<cantidadJugadores; i++)
        {
            maximoPorRonda = 0;

          //TURNO DEL JUGADOR
            rlutil::cls();
            dibujo_cuadrado();
            rlutil::locate(33,9);
            cout << "TURNO DE " << jugador[i];
            rlutil::anykey();
            rlutil::cls();

            // LANZAMIENTOS
            for(lanzamiento=1; lanzamiento<=3; lanzamiento++)
            {
                menuJuegoMultijugador(puntajeTotal[i], jugador[i], ronda, lanzamiento, maximoPorRonda, simulado);
                lanzar2(simulado,dados,tam);

              //GRAFICAMOS LOS DADOS, RECORRES MANUALMENTE CADA POSICION DEL VECTOR Y
              //GRAFICAMOS SU VALOR.
                mostrarDado(dados[0],1,14);
                mostrarDado(dados[1],15,14);
                mostrarDado(dados[2],29,14);
                mostrarDado(dados[3],43,14);
                mostrarDado(dados[4],57,14);
                mostrarDado(dados[5],71,14);

              //SUMA LOS VALORES DEL VECTOS, Y LO GUARDAMOS EN LA VARIABLE PUNTJE
                puntaje=sumaVector(dados, tam);

              //VERIFICAMOS LAS CONDICIONES
                if (esEscalera(dados,tam,puntaje))
                {
                  //SI ENTRAMOS A LA CONDICION, ES ESCALERA
                    escalera=true;
                    rlutil::locate(25,22);
                    cout << "Saco escalera y GANO EL JUEGO!!" << endl;
                    rlutil::anykey();
                  //ACTUALIZAMOS EL RANKING
                    actualizaRanking(vec_ranking,jugador[i],100);
                    rlutil::cls();
                    return;
                }
                else
                {
                  //GENERALA DE 1-5, MULTIPLICA VALOR DEL DADO X 10
                    generala(dados,tam,puntaje);
                  //GENERALA DE 6, VUELVE A 0 EL PUNTAJE TOTAL
                    seisSeis(puntaje,puntajeTotal[i]);
                }
                //UNA VEZ FINALIZADOS LOS 3 LANZAMIENTOS, ACTUALIZAMOS LOS MAXIMOS POR RONDA
                if(puntaje>maximoPorRonda)
                {
                    maximoPorRonda=puntaje;

                    if (lanzamiento == 1 )
                    {
                      vec_desempate[i] = maximoPorRonda + 300;
                    }
                    else if ( lanzamiento == 2)
                    {
                      vec_desempate[i] = maximoPorRonda + 200;
                    }
                    else
                    {
                      vec_desempate[i] = maximoPorRonda + 100;
                    }
                }
                //SI EL LANZAMIENTO NO ES 3
                if(lanzamiento!=3)
                {
                    mostrarPuntaje(puntaje);
                    rlutil::anykey();

                }
                else
                {
                  //FIN DE LA RONDA
                    mostrarPuntaje(puntaje);
                    rlutil::anykey();
                    rlutil::cls();
                    dibujo_cuadrado();
                    rlutil::locate(25,9);
                    cout << jugador[i] << " SUMO " << maximoPorRonda << " PUNTOS EN LA RONDA " << ronda;
                    sumaPuntaje(maximoPorRonda, puntajeTotal[i]);
                    rlutil::anykey();
                }
            }// FIN DE LOS LANZAMIENTOS

        }// FIN DEL TURNO DE CADA JUGADOR

         // ALCANZO 100 , FIN DEL PARTIDO, CHEQUEO PUNTAJES PARA AVERIGUAR
        for(int i=0; i<cantidadJugadores; i++)
        {
            if (puntajeTotal[i]>=100)
            {
                alcanzo100 = true;
            }
        }

        // FIN DE LA PARTIDA CUANDO ALCANZA 100 O SON RONDAS PREDEFINIDAS
        if ((alcanzo100) && ((ronda == rondaPredeterminada) && (rondasPredeterminadas==true)))
        {

            rlutil::cls();
            dibujo_cuadrado();
            rlutil::locate(30,6);
            cout << "RESULTADO FINAL: ";
            // MOSTRAMOS LOS PUNTOS FINALES DE LOS JUGADORES DE LA PARTIDA:
            for(int i=0; i<cantidadJugadores; i++)
            {
                rlutil::locate(30,8+i);
                cout << jugador[i] << " " << puntajeTotal[i] << " PUNTOS" << endl;
            }
            rlutil::anykey();
            //OBTENEMOS LA POSICION EN EL VECTOR DEL MAXIMO PUNTAJE
            jugadorGanador = maximoVectorIndice(puntajeTotal, cantidadJugadores, vec_desempate);




            rlutil::cls();
            dibujo_cuadrado();
            rlutil::locate(24,10);
            cout << "EL GANADOR ES " << jugador[jugadorGanador] << " CON " << puntajeTotal[jugadorGanador] << " PUNTOS."<< endl;

            actualizaRanking(vec_ranking,jugador[jugadorGanador],puntajeTotal[jugadorGanador]);

            rlutil::anykey();
            rlutil::cls();
        }
        else
        {

            // RONDA SIGUIENTE
            rlutil::cls();
            dibujo_cuadrado();
            rlutil::locate(30,7);
            cout << "FIN DE DE LA RONDA " << ronda << endl;
            rlutil::locate(30,9);
            cout << "PUNTAJES: "<< endl;
            for(int i=0; i<cantidadJugadores; i++)
            {
                rlutil::locate(30,10+i);
                cout << jugador[i] << " " << puntajeTotal[i] << " PUNTOS";
            }
            rlutil::anykey();
            rlutil::cls();
        }
        ronda++;

    }

}

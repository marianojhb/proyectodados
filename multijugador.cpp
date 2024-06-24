#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "rlutil.h"
#include "funciones.h"
using namespace std;

void multijugador(bool simulado, std::string vec_ranking[], int cantidadJugadores)
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
      //OCULTAMOS EL CURSOR
        rlutil::hidecursor();
    }

  // DECLARAMOS UN VECTOR DE DESEMPATE DONDE CADA POSICION ES NRO DE JUGADOR
  // Y SU CONTENIDO SERA EL MAYOR VALOR OBTENIDO DE LA RONDA Y SERA PONDERADO
  // DE ACUERDO AL NUMERO DE LANZAMIENTO, SUMANDO 300 SI ES LANZAMIENTO 1,
  // 200 SI ES LANZAMIENTO 2 Y 100 SI ES LANZAMIENTO 3. LUEGO SE COMPARARA
  // VER FUNCION maximoVectorIndice
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
  //UNA VEZ INGRESADOS LOS NOMBRE DE LOS JUGADORES, LIMPIAMOS LA PANTALLA
    rlutil::cls();

  // VARIABLES JUEGO MULTIJUGADOR
    int const tam = 6; // TAMAÑO DEL VECTOR DADOS
    int dados[tam]; // DECLARACION DEL VECTOR, PARA ALMACENAR LOS VALORES DE LOS DADOS
    int lanzamiento; // CONTADOR DE LANZAMIENTOS
    int ronda = 1; // CONTADOR DE RONDAS
    int puntajeTotal[cantidadJugadores];// VECTOR PARA ALMACENAR EL PUNTAJE DE CADA JUGADOR.
    ponerVectorEn0(puntajeTotal, cantidadJugadores); // INICIALIZAMOS EL VECTOR EN 0
    int maximoPorRonda; // VA A CONTENER EL MAXIMO POR RONDA, DE CADA JUGADOR.
    int puntaje =0; // VA A CONTENER EL PUNTAJE DE CADA LANZAMIENTO.
    bool escalera = false; // INDICADOR PARA VERIFICAR SI SACO ESCALERA.
    bool concluyePartida = false; // INDICADOR PARA VERICAR QUIEN LLEGO A CIEN.
    int jugadorGanador; // VA A CONTENER EL PUNTAJE DEL GANADOR DEL PARTIDO.
    int rondaPredeterminada; // VA A CONTENER LA CANTIDAD DE RONDAS PREDEFINIDAS

   //INDICADOR DE RONDAS PREDEFINIDAS
    bool rondasPredeterminadas;
  // PREGUNTA CANTIDAD DE RONDAS
    subMenu_rondas_prederminadas(rondasPredeterminadas);

    if (rondasPredeterminadas == true)
    {
      //LIMPIAMOS LA PANTALLA
        rlutil::cls();
        rlutil::locate(25, 8);
        cout << "INGRESE LA CANTIDAD DE RONDAS ";
      //MOSTRAMOS EL CURSOR.
        rlutil::showcursor();
        rlutil::locate(40, 10);
        cin >> rondaPredeterminada;
      //OCULTAMOS EL CURSOR
        rlutil::hidecursor();
    }

        while ( concluyePartida == false )// ALCANZO 100 O ES POR RONDA FIJA (BOOL) +
        {
        //INICIO RONDA
          //DIBUJO EL CUADRADO PARA QUE VA A CONTENER EL MENSAJE.
            rlutil::cls();
            dibujo_cuadrado();
            rlutil::locate(33,9);
            cout << "RONDA N" << (char)248 << " " << ronda;
          //ESPERAMOS CUALQUIER TECAL PARA CONTINUAR
            rlutil::anykey();
          //LIMPIAMOS CONSOLA
            rlutil::cls();

          //TURNO DE JUGADORES
            for(int i=0; i<cantidadJugadores; i++)
            {
                maximoPorRonda = 0;

              // CARTEL TURNO DEL JUGADOR
                rlutil::cls();
                dibujo_cuadrado();
                rlutil::locate(33,9);
                cout << "TURNO DE " << jugador[i];
                rlutil::anykey();
                rlutil::cls();

                // LANZAMIENTOS
                for(lanzamiento=1; lanzamiento<=3; lanzamiento++)
                {
                    // MENU ENCABEZADO POR CADA LANZAMIENTO
                    menuJuegoMultijugador(puntajeTotal[i], jugador[i], ronda, lanzamiento, maximoPorRonda, simulado);

                    // LANZAMOS LOS DADOS
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
                        cout << "SACO ESCALERA Y GANO EL JUEGO!!" << endl;
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
                        // CARTEL PUNTAJE DE CADA LANZAMIENTO
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


             // PREGUNTO SI CONCLUYO CUANDO ALGUNO ALCANZA 100 PUNTOS
            for(int i=0; i<cantidadJugadores; i++)
            {
                if (puntajeTotal[i]>=100)
                {
                    concluyePartida = true;
                }
            }

            // PREGUNTO SI CONCLUYO POR RONDA PREDEFINIDAS
            if (rondasPredeterminadas == true)
            {
                if (ronda+1>rondaPredeterminada)
                concluyePartida=true;

            }


            // FIN DE LA PARTIDA Y DESEMPATES
            if (concluyePartida)
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
                // OBTENEMOS EL INDICE DEL JUGADOR GANADOR
                jugadorGanador = maximoVectorIndice(puntajeTotal, cantidadJugadores, vec_desempate);



                // CARTEL DEL GANADOR
                rlutil::cls();
                dibujo_cuadrado();
                rlutil::locate(24,10);
                cout << "EL GANADOR ES " << jugador[jugadorGanador] << " CON " << puntajeTotal[jugadorGanador] << " PUNTOS"<< endl;

                // ACTUALIZA EL RANKING
                actualizaRanking(vec_ranking,jugador[jugadorGanador],puntajeTotal[jugadorGanador]);

                rlutil::anykey();
                rlutil::cls();
            }
            else
            {


                // CARTEL FIN DE RONDA Y RESUMEN DE PUNTAJES
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

            // SIGUIENTE RONDA
            ronda++;

        } // FIN DEL WHILE





}

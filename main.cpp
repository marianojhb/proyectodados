#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
#include "funciones.h"

int main() {
    srand(time(NULL));
    const int TAM=6;
    int opcion=1;
    int dados[TAM]= {1,2,3,4,5,6};
    string nombre="";

    while(opcion!=0) {
        mostrarMenu();
        cin>>opcion;
        switch (opcion) {
        case 1:
            cout << endl;
            cout << endl;
            cargarNombre(nombre);
            break;
        case 3:
            // mostrarVector(dados, TAM);
            break;

        case 0:
            cout<<"Saliendo del programa..."<<endl;
            break;

        default:
            cout<<"Ingrese una opcion correcta."<<endl;
            system("pause");
            break;
        }
        // OPCION UNICO JUGADOR
            int ronda = 1;
        if (opcion==1) {
            int puntajeTotal=0; // suma del juego
            int maximoPorRonda=0;
            bool escalera=false;
            puntajeTotal=0;

            while(puntajeTotal<100 || escalera==true) {
                int puntaje=0; // suma de cada vector
                int lanzamiento = 1;
                maximoPorRonda=0;

                menuJuegoSolitario(puntajeTotal, nombre, ronda, lanzamiento, maximoPorRonda);
                if(lanzar()) {}

                while (lanzamiento<=3) {
                    cargarVectorAleatorio(dados, TAM);
                    puntaje=sumaVector(dados, TAM);
                    if (puntaje>maximoPorRonda) {
                        maximoPorRonda = puntaje;
                    }
                    menuJuegoSolitario(puntajeTotal, nombre, ronda, lanzamiento, maximoPorRonda);
                    mostrarVector(dados, TAM);
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << "                            ";
                    cout << endl;
                    cout << "Sumo " << puntaje << " puntos." << endl;
                    cout << endl;
//                    system("pause");
                    if(lanzar()) {}
                    lanzamiento++; //

                }
                cout << endl;
                cout << "Fin de la ronda. Sumo " << maximoPorRonda << " puntos." << endl;
                system("pause");
                sumaPuntaje(maximoPorRonda, puntajeTotal);
                ronda++;
            }
            system("cls");
            cout << endl;
            cout << "Llego a " << puntajeTotal << " puntos. Uso " << ronda << " rondas." << endl;
            cout << endl;            cout << endl;            cout << endl;            cout << endl;            cout << endl;            cout << endl;            cout << endl;            cout << endl;            cout << endl;
            system("pause");
        }
    }


    return 0;
}

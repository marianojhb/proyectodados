#include<iostream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void mostrarMenu(){
    system("cls");
    cout<<" ---- Escalera o Cien ---- "<<endl;
    cout<<" 1 - Comenzar 1 JUGADOR "<<endl;
    cout<<" 2 - Comenzar 2 JUGADORES "<<endl;
    cout<<" 3 - Mostrar mayores puntuaciones "<<endl;
    cout<<" 0 - Salir "<<endl;
    cout<<" Ingrese la opcion deseada: ";
}

void cargarVectorAleatorio(int vec[], int tam){
    int i;
    for (i=0;i<tam ;i++ ){
        vec[i]=rand()%6+1;
    }
//    cout<<"Vector correctamente cargado con numeros aleatorios..."<<endl;
}

void cargarVectorManual(int vec[],int tam ){
    int i;
    for (i=0;i<tam ;i++ ){
        cout<<"Ingrese el elemento "<<i+1<<" del vector: ";
        cin>>vec[i];
    }
    cout<<"Vector correctamente cargado..."<<endl;
}

void ponerVectorEn0(int vec[],int tam ){
    int i;
    for (i=0;i<tam ;i++ ){
        vec[i]=0;
    }
//    cout<<"Vector correctamente seteado en 0..."<<endl;
}

int sumaVector(int vec[], int tam){
    int i;
    int suma=0;
    for (i=0;i<tam;i++) {
        suma += vec[i];
    }
    return suma;
}
void mostrarVector(int vec[],int tam ){
    int i;
    for (i=0;i<tam ;i++ ){
        cout << vec[i] <<  " ";
    }
    cout << endl;
//    system("pause");
}

void mostrarUltimasPartidas(string ultimaPartida) {

    cout << "Partidas anteriores: " << endl;
    string partidasAnteriores = "";
    partidasAnteriores += ultimaPartida;
//    system("pause");
}

void cargarNombre(string &nombre) {
    cout << "Ingrese su nombre: ";
    nombre="Mariano";
    system("cls");
    cout << endl;    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;    cout << "                          Hola, " << nombre << endl;
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


void menuJuegoSolitario(int puntajeTotal, string nombre, int ronda, int lanzamiento, int maximoPorRonda){
     system("cls");
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << "JUGADOR: " << nombre << endl;
    cout << "JUEGO SOLITARIO | RONDA No "<< ronda <<" | PUNTAJE TOTAL: " << puntajeTotal << " PUNTOS" << endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << "MAXIMO PUNTAJE DE LA RONDA: "<< maximoPorRonda <<"  PUNTOS" << endl;
    cout << "LANZAMIENTO No " << lanzamiento << endl;
    cout << "---------------------------------------------------------------------------------" << endl;
//    cout << "1  2  3  4  5  6" << endl;
//    cout << "ESCALERA, GANASTE LA PARTIDA" << endl;
//    system("pause");
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
        l=true;
        return l;
}

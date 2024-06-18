#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "funciones.h"

void cargarVectorAleatorio(int vec[], int tam){
    srand(time(NULL));
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


void ponerVectorEnVacio(string vec[], int n)
{
    for (int i=0;i<n;i++)
    {
        vec[i]="000 Vacio";
    }
}

void mostrarVectorString(string vec[],int tam ){
    int i;
    cout << endl;
    for (i=0;i<tam ;i++ ){
        cout << "           " <<  vec[i] <<  " " << endl;
    }
    cout << endl;
    system("pause");
}

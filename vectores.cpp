#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "rlutil.h"
using namespace std;
#include "funciones.h"

void cargarVectorAleatorio(int vec[], int tam)
{
    int i;
    for (i=0; i<tam ; i++ )
    {
        vec[i]=rand()%6+1;
    }
//    cout<<"Vector correctamente cargado con numeros aleatorios..."<<endl;
}

void cargarVectorManual(int vec[],int tam )
{
    int i;
    for (i=0; i<tam ; i++ )
    {
        cout<<"Ingrese el elemento "<<i+1<<" del vector: ";
        cin>>vec[i];
        while (vec[i]>6)
        {
            cout << "Ingrese un nuevo numero: ";
            cin >> vec[i];
        }
    }
    cout<<"Vector correctamente cargado..."<<endl;
}

void ponerVectorEn0(int vec[],int tam )
{
    int i;
    for (i=0; i<tam ; i++ )
    {
        vec[i]=0;
    }
//    cout<<"Vector correctamente seteado en 0..."<<endl;
}

int sumaVector(int vec[], int tam)
{
    int i;
    int suma=0;
    for (i=0; i<tam; i++)
    {
        suma += vec[i];
    }
    return suma;
}
void mostrarVector(int vec[],int tam )
{
    int i;
    for (i=0; i<tam ; i++ )
    {
        cout << vec[i] <<  " ";
    }
    cout << endl;
//    rlutil::anykey();
}


void ponerVectorEnVacio(std::string vec[], int n)
{
    for (int i=0; i<n; i++)
    {
        vec[i]="000 Vacio";
    }
}

void mostrarVectorString(std::string vec[],int tam, int cursorx, int cursory)
{
    int i;
    for (i=0; i<tam ; i++ )
    {
        rlutil::locate(cursorx,cursory+i);
        cout << i+1 << ". ..... "<< vec[i];
    }
}

int maximoVectorIndice(int vec[], int tam)
{
    int maximo;
    for (int i=0; i<tam; i++)
    {
        if (i==0)
        {
            maximo = 0;
        }
        else
        {
            if (vec[i]>vec[i-1])
            {
                maximo = i;
            }
        }
    }
    return maximo;
}

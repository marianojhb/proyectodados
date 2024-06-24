#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "rlutil.h"
#include "funciones.h"
using namespace std;

void cargarVectorAleatorio(int vec[], int tam)
{
    int i;
    for (i=0; i<tam ; i++ )
    {
        vec[i]=rand()%6+1;
    }
}

void cargarVectorManual(int vec[],int tam )
{
    int i;
    for (i=0; i<tam ; i++ )
    {
        cout<<"INGRESE EL DADO N" << (char)248 << " "<< i+1 << " : ";
        cin>>vec[i];
        // SI EL DATO INGRESAO ES MAYOR A 6, SE REPITE LA INSTRUCCION.
        while (vec[i]>6)
        {
            cout<<"INGRESE EL DADO N" << (char)248 << " "<< i+1 << " : ";
            cin >> vec[i];
        }
    }
    // cout<<"Vector correctamente cargado..."<<endl;
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
        vec[i]="";
    }
}

void mostrarVectorString(std::string vec[],int tam, int cursorx, int cursory)
{
    int i;
    for (i=0; i<tam ; i++ )
    {
        if (vec[i]!="")
        {
            if(i<9)
            {
                rlutil::locate(cursorx,cursory+i);
                cout << i+1 << ". ..... "<< vec[i];
            }
            else
            {
                rlutil::locate(cursorx,cursory+i);
                cout << i+1 << ". .... "<< vec[i];

            }


        }
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
            else if ( vec[i] == vec[i-1])
            {

            }
        }
    }
    return maximo;
}


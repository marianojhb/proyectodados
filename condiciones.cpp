#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


// ESCALERA 613632
bool esEscalera(int vec[], int tam, int puntaje)
{
    bool resultado;
    int uno=0,dos=0,tres=0,cuatro=0,cinco=0,seis=0;
    if (puntaje !=21)
    {
        resultado = false;
    }
    else
    {
        for (int i = 0 ; i < tam; i++ )
        {
            switch(vec[i])
            {
            case 1:
                uno++;
                break;
            case 2:
                dos++;
                break;
            case 3:
                tres++;
                break;
            case 4:
                cuatro++;
                break;
            case 5:
                cinco++;
                break;
            case 6:
                seis++;
                break;
            }
        }
        if (uno == dos == tres == cuatro == cinco == seis == 1)
        {
            resultado = true;
        }
        else
        {
          resultado = false;
        }

    }
    return resultado;
}

// 6 dados 6 reincia el puntaje total
void seisSeis(int &puntaje, int &puntajeTotal, int &lanzamiento)
{
    if (puntaje==36)
    {
        puntajeTotal = 0;
        puntaje = 0;
        cout << "6 dados 6 reinicia el puntaje total a 0 " << endl;
    }
}

// 6 dados iguales (que no sean 6), multiplica por 10 el valor
void generala(int vec[], int tam, int &puntaje)
{

    if (vec[0]!=6)
    {
        bool generala = true;
        for (int i=1; i<tam; i++)
        {
            if (vec[0] != vec[i])
            {
                generala = false;
            }

        if (generala)
            puntaje = vec[0]*10;

        }
    }
}

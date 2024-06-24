#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "rlutil.h"
#include "funciones.h"
using namespace std;


void mostrarDado(int dado, int x, int y)
{
  rlutil::setColor(rlutil::COLOR::WHITE);
  /*
    CHAR:
      -218 , LINEA SIMPLE ESQUINA , PARECIDO A UNA r
      -196, LINEA SIMPLE HORIZONTAL , -
      -191,
  */
    switch(dado)
    {
    case 1:
        rlutil::locate(x,y);
        cout << char(218) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(191) << endl;
        rlutil::locate(x,y+1);
        cout << char(179) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(179) << endl;
        rlutil::locate(x,y+2);
        cout << char(179) << char(32) << char(32) << char(32) << char(32) << char(250) << char(32) << char(32) << char(32) << char(32) << char(179) << endl;
        rlutil::locate(x,y+3);
        cout << char(179) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(179) << endl;
        rlutil::locate(x,y+4);
        cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(217) << endl;
        break;
    case 2:
        rlutil::locate(x,y);
        cout << char(218) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(191) << endl;
        rlutil::locate(x,y+1);
        cout << char(179) << char(250) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(179) << endl;
        rlutil::locate(x,y+2);
        cout << char(179) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(179) << endl;
        rlutil::locate(x,y+3);
        cout << char(179) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(250) << char(179) << endl;
        rlutil::locate(x,y+4);
        cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(217) << endl;
        break;
    case 3:
        rlutil::locate(x,y);
        cout << char(218) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(191) << endl;
        rlutil::locate(x,y+1);
        cout << char(179) << char(250) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(179) << endl;
        rlutil::locate(x,y+2);
        cout << char(179) << char(32) << char(32) << char(32) << char(32) << char(250) << char(32) << char(32) << char(32) << char(32) << char(179) << endl;
        rlutil::locate(x,y+3);
        cout << char(179) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(250) << char(179) << endl;
        rlutil::locate(x,y+4);
        cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(217) << endl;
        break;
    case 4:
        rlutil::locate(x,y);
        cout << char(218) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(191) << endl;
        rlutil::locate(x,y+1);
        cout << char(179) << char(250) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(250) << char(179) << endl;
        rlutil::locate(x,y+2);
        cout << char(179) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(179) << endl;
        rlutil::locate(x,y+3);
        cout << char(179) << char(250) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(250) << char(179) << endl;
        rlutil::locate(x,y+4);
        cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(217) << endl;
        break;
    case 5:
        rlutil::locate(x,y);
        cout << char(218) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(191) << endl;
        rlutil::locate(x,y+1);
        cout << char(179) << char(250) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(250) << char(179) << endl;
        rlutil::locate(x,y+2);
        cout << char(179) << char(32) << char(32) << char(32) << char(32) << char(250) << char(32) << char(32) << char(32) << char(32) << char(179) << endl;
        rlutil::locate(x,y+3);
        cout << char(179) << char(250) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(250) << char(179) << endl;
        rlutil::locate(x,y+4);
        cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(217) << endl;
        break;
    case 6:
        rlutil::locate(x,y);
        cout << char(218) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(191) << endl;
        rlutil::locate(x,y+1);
        cout << char(179) << char(250) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(250) << char(179) << endl;
        rlutil::locate(x,y+2);
        cout << char(179) << char(250) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(250) << char(179) << endl;
        rlutil::locate(x,y+3);
        cout << char(179) << char(250) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(32) << char(250) << char(179) << endl;
        rlutil::locate(x,y+4);
        cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(217) << endl;
        break;
    }
}

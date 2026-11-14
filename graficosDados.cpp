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
        cout << "┏━━━━━━━━━┓" << endl;
        rlutil::locate(x,y+1);
        cout << "┃         ┃" << endl;
        rlutil::locate(x,y+2);
        cout << "┃    ●    ┃" << endl;
        rlutil::locate(x,y+3);
        cout << "┃         ┃" << endl;
        rlutil::locate(x,y+4);
        cout << "┗━━━━━━━━━┛" << endl;
        break;
    case 2:
        rlutil::locate(x,y);
        cout << "┏━━━━━━━━━┓" << endl;
        rlutil::locate(x,y+1);
        cout << "┃●        ┃" << endl;
        rlutil::locate(x,y+2);
        cout << "┃         ┃" << endl;
        rlutil::locate(x,y+3);
        cout << "┃        ●┃" << endl;
        rlutil::locate(x,y+4);
        cout << "┗━━━━━━━━━┛" << endl;
        break;
    case 3:
        rlutil::locate(x,y);
        cout << "┏━━━━━━━━━┓" << endl;
        rlutil::locate(x,y+1);
        cout << "┃●        ┃" << endl;
        rlutil::locate(x,y+2);
        cout << "┃    ●    ┃" << endl;
        rlutil::locate(x,y+3);
        cout << "┃        ●┃" << endl;
        rlutil::locate(x,y+4);
        cout << "┗━━━━━━━━━┛" << endl;
        break;
    case 4:
        rlutil::locate(x,y);
        cout << "┏━━━━━━━━━┓" << endl;
        rlutil::locate(x,y+1);
        cout << "┃●       ●┃" << endl;
        rlutil::locate(x,y+2);
        cout << "┃         ┃" << endl;
        rlutil::locate(x,y+3);
        cout << "┃●       ●┃" << endl;
        rlutil::locate(x,y+4);
        cout << "┗━━━━━━━━━┛" << endl;
        break;
    case 5:
        rlutil::locate(x,y);
        cout << "┏━━━━━━━━━┓" << endl;
        rlutil::locate(x,y+1);
        cout << "┃●       ●┃" << endl;
        rlutil::locate(x,y+2);
        cout << "┃    ●    ┃" << endl;
        rlutil::locate(x,y+3);
        cout << "┃●       ●┃" << endl;
        rlutil::locate(x,y+4);
        cout << "┗━━━━━━━━━┛" << endl;
        break;
    case 6:
        rlutil::locate(x,y);
        cout << "┏━━━━━━━━━┓" << endl;
        rlutil::locate(x,y+1);
        cout << "┃●       ●┃" << endl;
        rlutil::locate(x,y+2);
        cout << "┃●       ●┃" << endl;
        rlutil::locate(x,y+3);
        cout << "┃●       ●┃" << endl;
        rlutil::locate(x,y+4);
        cout << "┗━━━━━━━━━┛" << endl;
        break;
    }
}

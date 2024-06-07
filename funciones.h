#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void cargarVectorManual(int vec[], int tam);
void cargarVectorAleatorio(int vec[], int tam);
void mostrarVector(int vec[], int tam);
void ponerVectorEn0(int vec[], int tam);
void mostrarUltimasPartidas(string ultimaPartida);
void cargarNombre(string &nombre);
void menuJuegoSolitario(int puntajeTotal, string nombre, int ronda, int lanzamiento, int maximoPorRonda);
int sumaVector(int vec[], int tam);
int sumaPuntaje (int puntaje, int &puntajeTotal);
bool lanzar();
void mostrarMenu();
void otraFuncion();



#endif // FUNCIONES_H_INCLUDED

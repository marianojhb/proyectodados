#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

// menues.cpp
void mostrarMenu();
void menuJuegoSolitario(int puntajeTotal, string nombre, int ronda, int lanzamiento, int maximoPorRonda);

// modo_solitario.cpp
void modoSolitario();

// vectores.cpp
void mostrarVector(int vec[], int tam);
void cargarVectorManual(int vec[], int tam);
void cargarVectorAleatorio(int vec[], int tam);
void ponerVectorEn0(int vec[], int tam);
int sumaVector(int vec[], int tam);

// funciones.cpp
void mostrarUltimasPartidas(string ultimaPartida);
void cargarNombre(string &nombre);
int sumaPuntaje (int puntaje, int &puntajeTotal);
bool lanzar();
void mostrarPuntaje(int &puntaje);


#endif // FUNCIONES_H_INCLUDED

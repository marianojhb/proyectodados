#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

// menues.cpp
void mostrarMenu(bool simulado);
void menuJuegoSolitario(int puntajeTotal, string nombre, int ronda, int lanzamiento, int maximoPorRonda, bool simulado);

// modo_solitario.cpp
void modoSolitario(bool simulado);

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
void mostrarPuntaje(int puntaje);
void toggleSimulado(bool &simulado);
string labelSimulado(bool simulado);

// condiciones.cpp
bool esEscalera(int vec[], int tam, int puntaje);
void seisSeis(int &puntaje, int &puntajeTotal, int &lanzamiento);
void generala(int vec[], int tam, int &puntaje);


#endif // FUNCIONES_H_INCLUDED

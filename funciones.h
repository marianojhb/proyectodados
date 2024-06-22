#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

// menues.cpp
void mostrarMenu(bool simulado);
void menuJuegoSolitario(int puntajeTotal, string nombre, int ronda, int lanzamiento, int maximoPorRonda, bool simulado);
void menuJuegoMultijugador(int puntajeTotal, string jugador, int ronda, int lanzamiento, int maximoPorRonda, bool simulado);
void interfas_fin_ronda( int ronda, int maxPuntajeRonda, int puntajeTotal);
void interfas_entre_turnos( int ronda, string proxTurno, string antTurno, int puntajeTotal_ant, int puntajeTotal_prox);
void interfas_parteUP ( int ronda, string nombre , int puntajeTotal);
void interfas_parteMiD(int lanzamiento, int maxPuntajeRonda);
void dibujo_cuadrado();
void creditos();

// modo_solitario.cpp
void modoSolitario(bool simulado, std::string r[]);

// modo_dosjugadores.cpp
void dosjugadores(bool simulado, std::string r[]);

// multijugador.cpp
void multijugador(bool simulado, std::string r[]);

// vectores.cpp
void mostrarVector(int vec[], int tam);
void cargarVectorManual(int vec[], int tam);
void cargarVectorAleatorio(int vec[], int tam);
void ponerVectorEn0(int vec[], int tam);
int sumaVector(int vec[], int tam);
void ponerVectorEnVacio(std::string vec[], int n);
void mostrarVectorString(std::string vec[],int tam );
int maximoVectorIndice(int vec[], int tam);

// funciones.cpp
void mostrarUltimasPartidas(string ultimaPartida);
void cargarNombre(string &nombre);
int sumaPuntaje (int puntaje, int &puntajeTotal);
void lanzar();
void lanzar2(bool simulado, int dados[], int tam);
void mostrarPuntaje(int puntaje);
void toggleSimulado(bool &simulado);
string labelSimulado(bool simulado);
int tirar_sumar_mostrar_dados ( int v[], int tam);
//int sumaLanzamiento(int v[], int tam);
//int devolverMax_porRonda (int v[], int tam ,int puntaje);

// condiciones.cpp
bool esEscalera(int vec[], int tam, int puntaje);
void seisSeis(int &puntaje, int &puntajeTotal);
void generala(int vec[], int tam, int &puntaje);

// ranking.cpp
void actualizaRanking(std::string r[], string n, int p); // graba el ranking y advierte record
int stringToInt(string s);
int charToInt(char c);
string intToString(int n);

#endif // FUNCIONES_H_INCLUDED

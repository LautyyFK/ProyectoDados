#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
// Menu
void juegoUnJugador(string &Player, int &scoreSolo, string &scoreNameSolo);
void juegoDosJugadores(string Players[], int &scoreDuo, string &scoreNameDuo);
void mostrarPuntuacionMasAlta(int scoreSolo, string scoreNameSolo, int scoreDuo, string scoreNameDuo);

// Combinaciones

int combinacionesCheck(int DadosAle[], const int tam);
void dadosManuales (int DadosAle[], const int tam);
void dadosAleatorios (int DadosAle[], const int tam);
bool CombSexteto6 (int DadosAle[], const int tam);
bool CombSextetoX (int DadosAle[], const int tam);
bool CombEscalera (int DadosAle[], const int tam);

// Player

void InicioPlayer(string Player, int &scoreSolo, string &scoreNameSolo, int ModoId);
bool RondasPlayer(int DadosAle[], const int tam, int CantLanzamientos, int &PuntajeTotalPartida, string Player, int &RondaWin, bool &DetectEscalera, int ModoId);

// Dados

void dadosAleatorios (int DadosAle[], const int tam, int ModoId);
void mostrarDados (int DadosAle[], const int tam);
int numEstetica (int num);

// Player Duo

void InicioPlayerDuo(string Players[], int &scoreDuo, string &scoreNameDuo, int ModoId);
int RondasPlayerDuo(int DadosAle[], const int tam, int CantLanzamientos, int PuntajeTotalPartida[], string Players[], int CantRondas, int &RondaWin, int DetectEscalera[], int ModoId);
int CheckEmpate100(int PuntajeTotalPartida[], int PuntajeXLanzamientoP1[], int PuntajeXLanzamientoP2[], int CantLanzamientos);
int CheckEmpate (int PuntajeTotalPartida[]);
bool RondaXJugador(int JugadorId, int DadosAle[], const int tam, int CantLanzamientos, int PuntajeTotalPartida[], int PuntajeXLanzamiento[], string Players[], int DetectEscalera[], int Ronda, int ModoId);

// Puntaje

void sumarPuntaje (int DadosAle[], const int tam, int PuntajeXLanzamiento[], int Ronda);
void multPuntaje (int DadosAle[], int PuntajeXLanzamiento[], int Ronda);
void resetPuntaje (int &PuntajeTotalPartida);

// Puntuaciones
void scoreDuoF(int scoreDuo, string scoreNameDuo);
void menuPuntuaciones(int scoreSolo, string scoreNameSolo, int scoreDuo, string scoreNameDuo);
void scoreSolitario(int scoreSolo, string scoreNameSolo);

#endif // MENU_H_INCLUDED

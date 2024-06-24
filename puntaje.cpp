#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

#include "menu.h"

void sumarPuntaje (int DadosAle[], const int tam, int PuntajeXLanzamiento[], int Lanzamiento) {
    int PuntajeTotal = 0;
    for (int i = 0; i < tam; i++) {
        PuntajeTotal += DadosAle[i];
    }

    PuntajeXLanzamiento[Lanzamiento] = PuntajeTotal;
}

void multPuntaje (int DadosAle[], int PuntajeXLanzamiento[], int Lanzamiento) {
    PuntajeXLanzamiento[Lanzamiento] = DadosAle[0] * 10;
}

void resetPuntaje (int &PuntajeTotalPartida) {
    PuntajeTotalPartida = 0;
}

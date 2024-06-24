#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

#include "menu.h"

bool RondaXJugador(int JugadorId, int DadosAle[], const int tam, int CantLanzamientos, int PuntajeTotalPartida[], int PuntajeXLanzamiento[], string Players[], int DetectEscalera[], int Ronda, int ModoId) {
        system("cls");

        int anchoMarco = 50;
        string linea(anchoMarco, '-');

        int Jugador2ID;

        if (JugadorId == 0) {
            Jugador2ID = 1;
        } else {
            Jugador2ID = 0;
        }

        int MaxPos = 0;

        cout<<linea<<endl;
        cout<<"|                 RONDA N"<<Ronda + 1;
        cout<<string(anchoMarco - 27, ' ')<<"|"<<endl;
        cout<<"|          PROXIMO TURNO: "<<Players[JugadorId];
        cout<<string(anchoMarco - 27 - Players[JugadorId].length(), ' ')<<"|"<<endl;
        cout<<"|          PUNTAJE "<<Players[JugadorId]<<": "<<PuntajeTotalPartida[JugadorId];
        cout<<string(anchoMarco - 22 - Players[JugadorId].length() - numEstetica(PuntajeTotalPartida[JugadorId]), ' ')<<"|"<<endl;
        cout<<"|          PUNTAJE "<<Players[Jugador2ID]<<": "<<PuntajeTotalPartida[Jugador2ID];
        cout<<string(anchoMarco - 22 - Players[Jugador2ID].length() - numEstetica(PuntajeTotalPartida[Jugador2ID]), ' ')<<"|"<<endl;
        cout<<linea<<endl<<endl;
        system("pause");

    for(int i = 0; i < CantLanzamientos; i++) {

        dadosAleatorios(DadosAle, tam, ModoId);

        int Comb = combinacionesCheck(DadosAle, tam);

        switch (Comb) {
                case 1:
                    resetPuntaje(PuntajeTotalPartida[JugadorId]);
                    break;
                case 2:
                    multPuntaje(DadosAle, PuntajeXLanzamiento, i);
                    break;
                case 4:
                    sumarPuntaje(DadosAle, tam, PuntajeXLanzamiento, i);
                    break;
            }

            system("cls");
            cout<<"TURNO DE "<<Players[JugadorId]<<" | Ronda N "<<Ronda + 1<<" | PUNTAJE TOTAL: "<<PuntajeTotalPartida[JugadorId]<<endl;
            cout<<"----------------------------------------------------------------------"<<endl;

            for (int Max = 0; Max < CantLanzamientos; Max++) {
                if (PuntajeXLanzamiento[MaxPos] < PuntajeXLanzamiento[Max]) {
                    MaxPos = Max;
                }
            }

            cout<<"MAXIMO PUNTAJE DE LA RONDA: "<<PuntajeXLanzamiento[MaxPos]<<endl;
            cout<<"LANZAMIENTO N "<<i + 1<<endl;
            cout<<"----------------------------------------------------------------------"<<endl<<endl;
            mostrarDados(DadosAle, tam);
            cout<<endl<<endl;

            switch (Comb) {
                case 1:
                    cout<<"Sextete 6"<<endl;
                    break;
                case 2:
                    cout<<"Sextete X"<<endl;
                    break;
                case 4:
                    cout<<"Suma de Dados."<<endl;
                    break;
            }

            if (Comb == 3) {
                cout<<"ESCALERA! GANASTE LA PARTIDA!"<<endl;

                system("pause");
                    PuntajeTotalPartida[JugadorId] = 100;
                    DetectEscalera[JugadorId] = 1;
                    return false;
            }

            cout<<endl;
            system("pause");
            system("cls");
    }


    PuntajeTotalPartida[JugadorId] += PuntajeXLanzamiento[MaxPos];

    return true;
}

int CheckEmpate (int PuntajeTotalPartida[]) {

    if ((PuntajeTotalPartida[0] >= 100) && (PuntajeTotalPartida[1] >= 100)) {
            return 2;
    }

    for (int PuntajeCheck = 0; PuntajeCheck < 2; PuntajeCheck++) {
            if (PuntajeTotalPartida[PuntajeCheck] >= 100) {
                    return PuntajeCheck;
            }
    }

    return -1;
}

int CheckEmpate100(int PuntajeTotalPartida[], int PuntajeXLanzamientoP1[], int PuntajeXLanzamientoP2[], int CantLanzamientos) {
    int Puntos100[2] = {};
    int PuntosRonda[2] = {};
    int MaxPosJ1 = 0, MaxPosJ2 = 0;

    // Puntaje Antes de la Ronda Jugador 1
    for (int Max = 0; Max < CantLanzamientos; Max++) {
        if (PuntajeXLanzamientoP1[MaxPosJ1] < PuntajeXLanzamientoP1[Max]) {
            MaxPosJ1 = Max;
        }
    }

    // Puntaje Antes de la Ronda Jugador 2
    for (int Max = 0; Max < CantLanzamientos; Max++) {
        if (PuntajeXLanzamientoP2[MaxPosJ2] < PuntajeXLanzamientoP2[Max]) {
            MaxPosJ2 = Max;
        }
    }

    PuntosRonda[0] = PuntajeXLanzamientoP1[MaxPosJ1];
    PuntosRonda[1] = PuntajeXLanzamientoP2[MaxPosJ2];

    int WinLanzamiento[2] = {};

    for (int JugadorId = 0; JugadorId < 2; JugadorId++) {
        bool BandPuntos = false;

        Puntos100[JugadorId] = PuntajeTotalPartida[JugadorId] - PuntosRonda[JugadorId];

        for (int Check = 0; Check < CantLanzamientos; Check++) {
            if (JugadorId == 0) { // Jugador 1
                if (!BandPuntos) {
                    Puntos100[JugadorId] += PuntajeXLanzamientoP1[Check];
                    if (Puntos100[JugadorId] >= 100) {
                        BandPuntos = true;
                    }
                    Puntos100[JugadorId] -= PuntajeXLanzamientoP1[Check];
                    WinLanzamiento[JugadorId]++;
                }
            } else if (JugadorId == 1) { // Jugador 2
                if (!BandPuntos) {
                    Puntos100[JugadorId] += PuntajeXLanzamientoP2[Check];
                    if (Puntos100[JugadorId] >= 100) {
                        BandPuntos = true;
                    }
                    Puntos100[JugadorId] -= PuntajeXLanzamientoP2[Check];
                    WinLanzamiento[JugadorId]++;
                }
            }
        }
    }

    if (WinLanzamiento[0] < WinLanzamiento[1]) {
        return 0;
    } else if (WinLanzamiento[1] < WinLanzamiento[0]) {
        return 1;
    } else {
        if (PuntajeTotalPartida[0] > PuntajeTotalPartida[1]) {
            return 0;
        } else {
            return 1;
        }
    }
}

int RondasPlayerDuo(int DadosAle[], const int tam, int CantLanzamientos, int PuntajeTotalPartida[], string Players[], int CantRondas, int &RondaWin, int DetectEscalera[], int ModoId) {

    system("cls");

    int anchoMarco = 50;
    int anchoMarco2 = 35;
    string linea(anchoMarco, '-');
    string linea2(anchoMarco2, '-');
    cout<<linea<<endl;
    cout<<"|          LA PARTIDA ESTA POR COMENZAR!";
    cout<<string(anchoMarco - 41, ' ')<<"|"<<endl;
    cout<<"|          JUGADOR 1: "<<Players[0];
    cout<<string(anchoMarco - 23 - Players[0].length(), ' ')<<"|"<<endl;
    cout<<"|          JUGADOR 2: "<<Players[1];
    cout<<string(anchoMarco - 23 - Players[1].length(), ' ')<<"|"<<endl;
    cout<<"|          RONDAS X JUGAR : "<<CantRondas;
    cout<<string(anchoMarco - 29 - numEstetica(CantRondas), ' ')<<"|"<<endl;
    cout<<linea<<endl<<endl;

    system("pause");
    system("cls");

    for (int Ronda = 0; Ronda < CantRondas; Ronda++) {
        system("cls");
        int PuntajeXLanzamientoP1[CantLanzamientos] = {};
        int PuntajeXLanzamientoP2[CantLanzamientos] = {};

        RondaWin = Ronda + 1;


        if (!RondaXJugador(0, DadosAle, tam, CantLanzamientos, PuntajeTotalPartida, PuntajeXLanzamientoP1, Players, DetectEscalera, Ronda, ModoId)) {
            return 0; // Jugador 1 Win Escalera
        }

        if (!RondaXJugador(1, DadosAle, tam, CantLanzamientos, PuntajeTotalPartida, PuntajeXLanzamientoP2, Players, DetectEscalera, Ronda, ModoId)) {
            return 1; // Jugador 2 Win Escalera
        }

        switch (CheckEmpate(PuntajeTotalPartida)) {
            case 0:
                return 0; // Win Jugador 1
                break;
            case 1:
                return 1; // Win Jugador 2
                break;
            case 2: // Empate
                cout<<linea2<<endl;
                cout<<"|          EMPATE!";
                cout<<string(anchoMarco2 - 19, ' ')<<"|"<<endl;
                cout<<linea2<<endl<<endl;
                system("pause");

                if (CheckEmpate100(PuntajeTotalPartida, PuntajeXLanzamientoP1, PuntajeXLanzamientoP2, CantLanzamientos) == 0) {
                    cout<<endl;
                    cout<<"Win Jugador 1"<<endl;
                    system("pause");
                    return 0;
                } else {
                    cout<<endl;
                    cout<<"Win Jugador 2"<<endl;
                    system("pause");
                    return 1;
                }

                break;
        }
    }

    if (PuntajeTotalPartida[0] > PuntajeTotalPartida[1]) {
        return 0;
    } else {
        return 1;
    }
}

int numEstetica (int num) {
    int cont = 0;

    while (num != 0) {
        num /= 10; // num = num / 10;
        cont++;
    }

    if (cont == 0) {
        cont++;
    }

    return cont;
}

void InicioPlayerDuo(string Players[], int &scoreDuo, string &scoreNameDuo, int ModoId) {
    const int tam = 6;
    int DadosAle[tam];
    int CantLanzamientos = 3;
    int PuntajeTotalPartida[2] = {};
    int CantRondas;
    int RondaWin = 0;
    int DetectEscalera[2] = {};

    cout<<"Ingrese la cantidad de Rondas a jugar: ";
    cin>>CantRondas;

    system("cls");

    int JugadorWin = RondasPlayerDuo(DadosAle, tam, CantLanzamientos, PuntajeTotalPartida, Players, CantRondas, RondaWin, DetectEscalera, ModoId);
    //En este archivo Arriba

    int anchoMarco = 50;
    string linea(anchoMarco, '-');

    system("cls");

    cout<<linea<<endl;
    cout<<"|          Partida Finalizada!";
    cout<<string(anchoMarco - 31, ' ')<<"|"<<endl;
    cout<<"|          PUNTAJE "<<Players[0]<<" : "<<PuntajeTotalPartida[0];
    cout<<string(anchoMarco - 23 - Players[0].length() - numEstetica(PuntajeTotalPartida[0]), ' ')<<"|"<<endl;
    cout<<"|          PUNTAJE "<<Players[1]<<" : "<<PuntajeTotalPartida[1];
    cout<<string(anchoMarco - 23 - Players[1].length() - numEstetica(PuntajeTotalPartida[1]), ' ')<<"|"<<endl;
    cout<<linea<<endl<<endl;

    system("pause");
    system("cls");

    cout<<linea<<endl;
    if (DetectEscalera[JugadorWin] == 1) {
        cout<<"|          "<<Players[JugadorWin]<<" SACO ESCALERA!";
        cout<<string(anchoMarco - 27 - Players[JugadorWin].length(), ' ')<<"|"<<endl;
    } else {
        cout<<"|          "<<Players[JugadorWin]<<" GANASTE!";
        cout<<string(anchoMarco - 21 - Players[JugadorWin].length(), ' ')<<"|"<<endl;
    }
    cout<<"|          PUNTAJE : "<<PuntajeTotalPartida[JugadorWin];
    cout<<string(anchoMarco - 22 - numEstetica(PuntajeTotalPartida[JugadorWin]), ' ')<<"|"<<endl;
    cout<<"|          RONDA GANADORA : "<<RondaWin;
    cout<<string(anchoMarco - 29 - numEstetica(RondaWin), ' ')<<"|"<<endl;
    cout<<linea<<endl;

    system("pause");

    for (int CheckPuntos = 0; CheckPuntos < 2; CheckPuntos++) {
        if (PuntajeTotalPartida[CheckPuntos] > scoreDuo) {
            scoreDuo = PuntajeTotalPartida[CheckPuntos];
            scoreNameDuo = Players[CheckPuntos];
        }
    }
}

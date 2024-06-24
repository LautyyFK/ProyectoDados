#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

#include "menu.h"

void dadosAleatorios (int DadosAle[], const int tam, int ModoId) {
    system("cls");
    for (int i = 0; i < tam; i++) {
        if (ModoId == 1) {
            cout<<"Dado "<<i + 1<<": ";
            cin>>DadosAle[i];
            if (i == tam - 1) {
                system("cls");
            }
        } else {
            DadosAle[i] = rand() % 6 + 1;
        }
    }
    cout<<endl;
}

void mostrarDados (int DadosAle[], const int tam) {
    for (int i = 0; i < tam; i++) {
        cout<<DadosAle[i]<<" ";
    }
}

bool RondasPlayer(int DadosAle[], const int tam, int CantLanzamientos, int &PuntajeTotalPartida, string Player, int &RondaWin, bool &DetectEscalera, int ModoId) {

    system("cls");

    int anchoMarco = 50;
    string linea(anchoMarco, '-');

    cout<<linea<<endl;
    cout<<"|          LA PARTIDA ESTA POR COMENZAR!";
    cout<<string(anchoMarco - 41, ' ')<<"|"<<endl;
    cout<<linea<<endl<<endl;
    system("pause");
    system("cls");

    int Ronda = 0;
        while (true) {
        int PuntajeXLanzamiento[CantLanzamientos] = {};
        int MaxPos = 0, Lanzamiento;

        for (Lanzamiento = 0; Lanzamiento < CantLanzamientos; Lanzamiento++) {
                dadosAleatorios(DadosAle, tam, ModoId);
                int Comb = combinacionesCheck(DadosAle, tam);

            switch (Comb) {
                case 1:
                    resetPuntaje(PuntajeTotalPartida);
                    break;
                case 2:
                    multPuntaje(DadosAle, PuntajeXLanzamiento, Lanzamiento);
                    break;
                case 4:
                    sumarPuntaje(DadosAle, tam, PuntajeXLanzamiento, Lanzamiento);
                    break;
            }

            system("cls");
            cout<<"TURNO DE "<<Player<<" | Ronda N "<<Ronda + 1<<" | PUNTAJE TOTAL: "<<PuntajeTotalPartida<<endl;
            cout<<"----------------------------------------------------------------------"<<endl;

            for (int Max = 0; Max < CantLanzamientos; Max++) {
                if (PuntajeXLanzamiento[MaxPos] < PuntajeXLanzamiento[Max]) {
                    MaxPos = Max;
                }
            }

            cout<<"MAXIMO PUNTAJE DE LA RONDA: "<<PuntajeXLanzamiento[MaxPos]<<endl;
            cout<<"LANZAMIENTO N "<<Lanzamiento + 1<<endl;
            cout<<"----------------------------------------------------------------------"<<endl;
            mostrarDados(DadosAle, tam); // En este mismo archivo Arriba
            cout<<endl;

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
                cout<<endl;
                cout<<"ESCALERA! GANASTE LA PARTIDA!"<<endl;

                system("pause");
                    RondaWin = Ronda + 1;
                    PuntajeTotalPartida = 100;
                    DetectEscalera = true;
                    return true;
            }

            cout<<endl;
            system("pause");
            system("cls");
        }

        PuntajeTotalPartida += PuntajeXLanzamiento[MaxPos];

        if (PuntajeTotalPartida >= 100) {
                    RondaWin = Ronda + 1;
                    return true;
        }

            cout<<linea<<endl;
            cout<<"|          Siguiente Ronda: "<<Ronda + 2;
            cout<<string(anchoMarco - 29 - numEstetica(Ronda), ' ')<<"|"<<endl;
            cout<<"|          PUNTAJE : "<<PuntajeTotalPartida;
            cout<<string(anchoMarco - 22 - numEstetica(PuntajeTotalPartida), ' ')<<"|"<<endl;
            cout<<linea<<endl;

            cout<<endl<<endl;
            system("pause");
            system("cls");
            Ronda++;
    }
}

void InicioPlayer(string Player, int &scoreSolo, string &scoreNameSolo, int ModoId) {
    const int tam = 6;
    int DadosAle[tam];
    int CantLanzamientos = 3;
    int PuntajeTotalPartida = 0;
    int CantRondas;
    int RondaWin = 0;
    bool DetectEscalera = false;

    int anchoMarco = 50;
    string linea(anchoMarco, '-');

    RondasPlayer(DadosAle, tam, CantLanzamientos, PuntajeTotalPartida, Player, RondaWin, DetectEscalera, ModoId);

    system("cls");

    cout<<linea<<endl;
    cout<<"|          Partida Finalizada!";
    cout<<string(anchoMarco - 31, ' ')<<"|"<<endl;
    cout<<"|          PUNTAJE : "<<PuntajeTotalPartida;
    cout<<string(anchoMarco - 22 - numEstetica(PuntajeTotalPartida), ' ')<<"|"<<endl;
    cout<<linea<<endl<<endl;

    system("pause");
    system("cls");


    cout<<linea<<endl;
    if (DetectEscalera) {
        cout<<"|          GANASTE CON ESCALERA! "<<Player;
        cout<<string(anchoMarco - 34 - Player.length(), ' ')<<"|"<<endl;
    } else {
        cout<<"|          "<<Player<<" GANASTE!";
        cout<<string(anchoMarco - 21 - Player.length(), ' ')<<"|"<<endl;
    }

    cout<<"|          PUNTAJE : "<<PuntajeTotalPartida;
    cout<<string(anchoMarco - 22 - numEstetica(PuntajeTotalPartida), ' ')<<"|"<<endl;
    cout<<"|          RONDA GANADORA : "<<RondaWin;
    cout<<string(anchoMarco - 29 - numEstetica(RondaWin), ' ')<<"|"<<endl;
    cout<<linea<<endl;


    cout<<endl;
    system("pause");

    if (PuntajeTotalPartida >= scoreSolo) {
        scoreNameSolo = Player;
        scoreSolo = PuntajeTotalPartida;
    }
}

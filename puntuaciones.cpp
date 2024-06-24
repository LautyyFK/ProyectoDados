#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

#include "menu.h"

void menuPuntuaciones(int scoreSolo, string scoreNameSolo, int scoreDuo, string scoreNameDuo) {
    int opcion;

    do {
        cout << "Mostrar puntuacion mas alta." << endl<<endl;

        cout<<"1 - Modo Un Jugador."<<endl;
        cout<<"2 - Modo Dos Jugadores."<<endl;
        cout<<"3 - Salir al Menu Principal."<<endl<<endl;
        cout<<"Ingrese la opcion: ";
        cin>>opcion;
        system("cls");

        switch (opcion) {
            case 1:
            scoreSolitario(scoreSolo, scoreNameSolo);
                break;
            case 2:
            scoreDuoF(scoreDuo, scoreNameDuo);
                break;
        }
    } while (opcion != 3);
}

void scoreDuoF(int scoreDuo, string scoreNameDuo) {
    if (scoreDuo == -1) {
        cout<<"NO SE HA JUGADO NINGUNA PARTIDA."<<endl<<endl;
    } else {
        cout<<"EL JUGADOR "<<scoreNameDuo<<" tiene la maxima puntacion de juego en duo."<<endl<<endl;
        cout<<"PUNTOS: "<<scoreDuo<<endl<<endl;
    }

    system("pause");
    system("cls");
}

void scoreSolitario(int scoreSolo, string scoreNameSolo) {

    if (scoreSolo == -1) {
        cout<<"NO SE HA JUGADO NINGUNA PARTIDA."<<endl<<endl;

    } else {
        cout<<"EL JUGADOR "<<scoreNameSolo<<" tiene la maxima puntacion de juego en solitario."<<endl<<endl;
        cout<<"PUNTOS: "<<scoreSolo<<endl<<endl;
    }

    system("pause");
    system("cls");
}

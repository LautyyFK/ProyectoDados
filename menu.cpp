#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

#include "menu.h"

void juegoUnJugador(string &Player, int &scoreSolo, string &scoreNameSolo) {
    int ModoId;

    cout<<"1 - Modo Simulado"<<endl;
    cout<<"2 - Modo Aleatorio"<<endl<<endl;

    cout<<"Ingrese el modo: ";
    cin>>ModoId; // Se usa en Archivo Player para ver si los Dados son Aleatorios o Manuales

    system("cls");
    cout<<"Ingrese el nombre del jugador: ";
    cin.ignore();
    getline(cin, Player);
    cout<<endl;
    system("pause");
    system("cls");
    InicioPlayer(Player, scoreSolo, scoreNameSolo, ModoId); // Archivo Player
}

void juegoDosJugadores(string Players[], int &scoreDuo, string &scoreNameDuo) {
    int ModoId;

    cout<<"1 - Modo Simulado"<<endl;
    cout<<"2 - Modo Aleatorio"<<endl<<endl;

    cout<<"Ingrese el modo: ";
    cin>>ModoId; // Archivo Player

    system("cls");

    cin.ignore();
    for(int i = 0; i < 2; i++) {
        cout<<"Ingrese el nombre del jugador "<<i + 1<<": ";
        getline(cin, Players[i]);
    }

    cout<<endl;

    InicioPlayerDuo(Players, scoreDuo, scoreNameDuo, ModoId); // Archivo Playerduo
}

void mostrarPuntuacionMasAlta(int scoreSolo, string scoreNameSolo, int scoreDuo, string scoreNameDuo) {

    menuPuntuaciones(scoreSolo, scoreNameSolo, scoreDuo, scoreNameDuo);
}

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

#include "menu.h"

int main() {
    srand(time(NULL));

    int opcion;
    string Player;
    string Players[2];
    int scoreSolo = -1;
    int scoreDuo = -1;
    string scoreNameSolo, scoreNameDuo;

    do {
        cout << "----- CIEN o ESCALERA -----" << endl;
        cout << "1. Juego nuevo para un jugador" << endl;
        cout << "2. Juego nuevo para dos jugadores" << endl;
        cout << "3. Mostrar puntuacion mas alta" << endl;
        cout << "4. Salir" << endl;
        cout << "---------- * * * ----------" << endl;
        cout << "Eliga una opcion: ";
        cin >> opcion;

        system("cls");

        switch (opcion) {
            case 1:
                juegoUnJugador(Player, scoreSolo, scoreNameSolo); // Archivo Menu
                break;
            case 2:
                juegoDosJugadores(Players, scoreDuo, scoreNameDuo); // Archivo Menu
                break;
            case 3:
                mostrarPuntuacionMasAlta(scoreSolo, scoreNameSolo, scoreDuo, scoreNameDuo); // Archivo Menu
                break;
            case 4:
                cout << "Saliendo del juego..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                system("pause");
                break;
        }
        system("cls");
    } while (opcion != 4);

    return 0;
}


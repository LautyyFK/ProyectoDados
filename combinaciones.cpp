#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

#include "menu.h"

bool CombSextetoX (int DadosAle[], const int tam) {
    int numComp;
    int DadosIguales = 0;

    for (int i = 0; i < tam; i++) {
        if (i == 0) {
            numComp = DadosAle[i];
            DadosIguales++;
        } else if (DadosAle[i] == numComp){
            DadosIguales++;
        }
    }

    if (DadosIguales == 6) {
        return true;
    }

    return false;
}

bool CombSexteto6 (int DadosAle[], const int tam) {
    int DadosIguales = 0;

    for (int i = 0; i < tam; i++) {
        if (DadosAle[i] == 6){
            DadosIguales++;
        }
    }

    if (DadosIguales == 6) {
        return true;
    }

    return false;
}

bool CombEscalera (int DadosAle[], const int tam) {
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            if (i != j) {
                if (DadosAle[i] == DadosAle[j]) {
                    return false;
                }
            }
        }
    }

    return true;
}

int combinacionesCheck(int DadosAle[], const int tam) {
    int CombCheck = 0;
    int CombFinal;
    bool Check = false;

    while (!Check) {
    CombCheck++;

        if (CombCheck == 1) { // Seis Dados Iguales con el Numero 6
            Check = CombSexteto6(DadosAle, tam);
            CombFinal = 1;
        } else if (CombCheck == 2) { // Seis Dados Iguales (No incluye al 6)
            Check = CombSextetoX(DadosAle, tam);
            CombFinal = 2;
        } else if (CombCheck == 3) { // Escalera
            Check = CombEscalera(DadosAle, tam);
            CombFinal = 3;
        } else { // Suma de Dados
            Check = true;
            CombFinal = 4;
        }
    }

    return CombFinal;
}


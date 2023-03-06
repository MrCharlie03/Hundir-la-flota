#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    char tablero[6][6] = {{'~','~','~','~','~','~'},
                          {'~','~','~','~','~','~'},
                          {'~','~','~','~','~','~'},
                          {'~','~','~','~','~','~'},
                          {'~','~','~','~','~','~'},
                          {'~','~','~','~','~','~'}};
    srand(time(0));
    int posiciones[3][2];
    int barcos = 0, disparos = 0, aciertos = 0;

    // Generar aleatoriamente las posiciones de los barcos
    while(barcos < 3) {
        int fila, columna;
        fila = rand() % 6;
        columna = rand() % 6;
        bool disponible = true;
        for(int i = 0; i < barcos; i++) {
            if(fila == posiciones[i][0] && columna == posiciones[i][1]) {
                disponible = false;
                break;
            }
        }
        if(disponible) {
            posiciones[barcos][0] = fila;
            posiciones[barcos][1] = columna;
            barcos++;
        }
    }

    do {
        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 6; j++) {
                cout << tablero[i][j] << " ";
            }
            cout << endl;
        }
        cout << "Introduce la fila (1-6): ";
        int fila;
        cin >> fila;
        cout << "Introduce la columna (1-6): ";
        int columna;
        cin >> columna;
        fila--;
        columna--;
        bool acierto = false;
        for(int i = 0; i < barcos; i++) {
            if(fila == posiciones[i][0] && columna == posiciones[i][1]) {
                cout << "¡Has acertado!" << endl;
                acierto = true;
                aciertos++;
                break;
            }
        }
        if(acierto) {
            tablero[fila][columna] = 'X';
        } else if(tablero[fila][columna] == '~') {
            cout << "Has fallado" << endl;
            tablero[fila][columna] = 'O';
        } else {
            cout << "Ya has disparado en esa casilla" << endl;
        }
        disparos++;
    } while(aciertos < 3);
    cout << "¡Felicidades, has hundido todos los barcos en " << disparos << " disparos!" << endl;
    return 0;
}

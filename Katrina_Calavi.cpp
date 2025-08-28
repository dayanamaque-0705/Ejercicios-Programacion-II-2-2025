#include <iostream>
using namespace std;

void FilasRecursivo(int* fila, int columnas, int index) {
    if (index >= columnas) return;  // caso base

    cout << *(fila + index);
    FilasRecursivo(fila, columnas, index + 1);
}

int main() {

    int filas = 5;
    int columnas = 5;

    int* matriz = new int[filas * columnas];

    for (int i = 0; i < filas; i++) {
        int numDecrement = (i <= 2) ? 3 - i : i - 1;  // números decrecientes
        int ceros = columnas - numDecrement;         // ceros a la izquierda

        for (int j = 0; j < columnas; j++) {
            *(matriz + i * columnas + j) = 0;
        }

        int val = numDecrement;
        for (int j = ceros; j < columnas; j++) {
            *(matriz + i * columnas + j) = val--;
        }
    }

    cout << "MATRIZ SEGUN EL PATRON:" << endl;
    for (int i = 0; i < filas; i++) {
        FilasRecursivo(matriz + i * columnas, columnas, 0);
        cout << endl;
    }

    delete[] matriz;

    return 0;
}

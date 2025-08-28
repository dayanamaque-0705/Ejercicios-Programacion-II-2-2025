#include <iostream>
#include <conio.h>
using namespace std;

void imprimirE(int** matriz, int filas, int* columnas, int i = 0) {
    if (i >= filas) return; 

    for (int j = columnas[i] - 1; j >= 0; j--) {
        cout << matriz[i][j] << " ";
    }
    cout << endl;

    imprimirE(matriz, filas, columnas, i + 1); 
}

int main() {
    int filas = 5; 
    int columnasPorFila[5] = {3, 2, 1, 2, 3};

    int** matrix = new int*[filas];
    for (int i = 0; i < filas; i++) {
        *(matrix + i) = new int[columnasPorFila[i]];
    }

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnasPorFila[i]; j++) {
            ((matrix + i) + j) = j + 1;
        }
    }

    imprimirE(matrix, filas, columnasPorFila);

    for (int i = 0; i < filas; i++) {
        delete[] *(matrix + i);
    }
    delete[] matrix;

    return 0;
}

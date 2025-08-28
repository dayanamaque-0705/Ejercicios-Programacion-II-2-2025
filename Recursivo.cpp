#include <iostream>
using namespace std;

void imprimirColumnasMatrix(int** matrix, int fila, int col, int contadorColumnas) {
    if (col < 0) return;
    if (col < contadorColumnas) {
        *(*(matrix + fila) + col) = col + 1;
        cout << *(*(matrix + fila) + col) << " ";
    }
    imprimirColumnasMatrix(matrix, fila, col - 1, contadorColumnas); 
}

void imprimirMatrix(int** matrix, int fila, int rows, int cols, int mitad, int contadorColumnas, string espacios) {
    if (fila >= rows) return; 

    cout << espacios;
    imprimirColumnasMatrix(matrix, fila, cols - 1, contadorColumnas);
    cout << endl;

    if (fila >= (mitad - 1)) {
        contadorColumnas++;
        if (!espacios.empty()) {
            espacios.pop_back();
            espacios.pop_back();
        }
    } else {
        contadorColumnas--;
        espacios += "  ";
    }

    imprimirMatrix(matrix, fila + 1, rows, cols, mitad, contadorColumnas, espacios); 
}

int main() {
    int size = 15;
    int** matrix = new int*[size];

    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size]; 
    }

    int mitad = (size + 1) / 2;
    int contadorColumnas = mitad;
    string espacios = "";

    cout << " ----------------- Imprimir con recursión" << endl;
    imprimirMatrix(matrix, 0, size, size, mitad, contadorColumnas, espacios);

    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

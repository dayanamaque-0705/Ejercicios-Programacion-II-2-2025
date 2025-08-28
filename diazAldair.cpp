#include <iostream>
#include <conio.h>
using namespace std;

// Imprimir columnas de manera recursiva
void imprimirColumnasMatrix(int** matrix, int i, int j, int cols, int contadorColumnas) {
    // Caso base para columnas
    if (j < 0) {
        return;
    }

    if (j < contadorColumnas) {
        *(*(matrix + i) + j) = j + 1;
        cout << *(*(matrix + i) + j) << " ";
    }

    imprimirColumnasMatrix(matrix, i, j - 1, cols, contadorColumnas);
}

// Imprimir filas de manera recursiva
void imprimirMatrix(int** matrix, int i, int rows, int cols, int mitad, int contadorColumnas, string contadorEspacios) {
    // Caso base para filas
    if (i >= rows) {
        return;
    }

    // Imprimir espacios
    cout << contadorEspacios;

    // Llamada para imprimir columnas de la fila i
    imprimirColumnasMatrix(matrix, i, cols - 1, cols, contadorColumnas);
    cout << endl;

    // Actualizar contadores para la siguiente fila
    if (i >= (mitad - 1)) {
        contadorColumnas++;
        if (!contadorEspacios.empty()) {
            contadorEspacios.pop_back();
            contadorEspacios.pop_back();
        }
    }
    else {
        contadorColumnas--;
        contadorEspacios = contadorEspacios + "  ";
    }

    // Llamada recursiva para la siguiente fila
    imprimirMatrix(matrix, i + 1, rows, cols, mitad, contadorColumnas, contadorEspacios);
}

int main() {
    int size = 15;
    // Creación
    int** matrix = new int* [size];

    int rows = size;
    int cols = size;

    cout << " ----------------- Imprimir con recursión" << endl;
    int mitad = (size + 1) / 2;
    int contadorColumnas = mitad;
    string contadorEspacios = "";

    imprimirMatrix(matrix, 0, rows, cols, mitad, contadorColumnas, contadorEspacios);

    // Liberar memoria
    for (int i = 0; i < size; i++) {
        delete[] *(matrix + i);
    }
    delete[] matrix;

    return 0;
}

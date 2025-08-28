#include <iostream>
using namespace std;

// Función recursiva para imprimir las columnas de una fila
void imprimirColumnasMatrix(int** matrix, int i, int j, int contadorColumnas) {
    // Caso base para columnas
    if (j >= contadorColumnas) {
        return;
    }

    // Asignar valor e imprimir
    *(*(matrix + i) + j) = j + 1;
    cout << *(*(matrix + i) + j) << " ";

    // Llamada recursiva para la siguiente columna
    imprimirColumnasMatrix(matrix, i, j + 1, contadorColumnas);
}

// Función recursiva para imprimir la matriz fila por fila
void imprimirMatrix(int** matrix, int i, int rows, int cols, int mitad, int contadorColumnas, string contadorEspacios) {
    // Caso base para filas
    if (i >= rows) {
        return;
    }

    // Imprimir espacios antes de las columnas
    cout << contadorEspacios;

    // Llamar a la función recursiva para imprimir las columnas de la fila actual
    imprimirColumnasMatrix(matrix, i, 0, contadorColumnas);
    cout << endl;

    // Ajustar el contador de columnas y espacios según la fila actual
    if (i >= (mitad - 1)) {
        contadorColumnas++;
        if (!contadorEspacios.empty()) {
            contadorEspacios.pop_back();
            contadorEspacios.pop_back();
        }
    } else {
        contadorColumnas--;
        contadorEspacios += "  ";
    }

    // Llamada recursiva para la siguiente fila
    imprimirMatrix(matrix, i + 1, rows, cols, mitad, contadorColumnas, contadorEspacios);
}

int main() {
    int size = 15;

    // Creacion de la matriz
    int** matrix = new int*[size];

    // Inicializar las filas de la matriz
    for (int i = 0; i < size; i++) {
        *(matrix + i) = new int[size];
    }

    // Asignar valores
    int rows = size; // filas
    int cols = size; // columnas

    // Logica
    cout << " ----------------- Imprimir con recursión" << endl;
    int mitad = (size + 1) / 2;
    int contadorColumnas = mitad;
    string contadorEspacios = string((mitad - 1) * 2, ' ');

    // Llamar a la funcion recursiva para imprimir la matriz
    imprimirMatrix(matrix, 0, rows, cols, mitad, contadorColumnas, contadorEspacios);

    // Liberar memoria
    for (int i = 0; i < size; i++) {
        delete[] *(matrix + i);
    }
    delete[] matrix;

    return 0;
}
#include <iostream>
#include <conio.h>
using namespace std;

// Función recursiva para imprimir columnas de una fila
void imprimirColumnasMatrix(int** matrix, int i, int j, int contadorColumnas) {
    if (j >= contadorColumnas) {
        return;
    }
    *(*(matrix + i) + j) = j + 1;
    cout << *(*(matrix + i) + j) << " ";
    imprimirColumnasMatrix(matrix, i, j + 1, contadorColumnas);
}

// Función recursiva para imprimir la matriz con patrón
void imprimirMatrix(int** matrix, int i, int rows, int cols, int mitad, int contadorColumnas, string contadorEspacios, int size) {
    // Caso base para filas
    if (i >= rows) {
        return;
    }

    *(matrix + i) = new int[contadorColumnas];
    cout << contadorEspacios;

    // Imprimir columnas de la fila actual
    imprimirColumnasMatrix(matrix, i, 0, contadorColumnas);
    cout << endl;

    // Ajustar valores para la siguiente fila
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

    // Llamada recursiva a la siguiente fila
    imprimirMatrix(matrix, i + 1, rows, cols, mitad, contadorColumnas, contadorEspacios, size);
}

int main() {
    int size = 15;

    // Crear matriz dinámicamente
    int** matrix = new int* [size];

    // Lógica: primera impresión (forma normal)
    cout << " -----------------" << endl;
    int rows = size;
    int cols = size;
    int mitad = (size + 1) / 2;
    int contadorColumnas = mitad;

    for (int i = 0; i < rows; i++) {
        *(matrix + i) = new int[contadorColumnas];
        for (int j = 0; j < cols; j++) {
            if (j < contadorColumnas) {
                *(*(matrix + i) + j) = j + 1;
                cout << *(*(matrix + i) + j) << " ";
            }
        }
        cout << endl;

        if (i >= (mitad - 1)) {
            contadorColumnas++;
        }
        else {
            contadorColumnas--;
        }
    }

    // Lógica: impresión invertida (con espacios)
    cout << " ----------------- invertido" << endl;
    mitad = (size + 1) / 2;
    contadorColumnas = mitad;
    string contadorEspacios = "";

    for (int i = 0; i < rows; i++) {
        *(matrix + i) = new int[contadorColumnas];
        cout << contadorEspacios;
        for (int j = cols; j >= 0; j--) {
            if (j < contadorColumnas) {
                *(*(matrix + i) + j) = j + 1;
                cout << *(*(matrix + i) + j) << " ";
            }
        }
        cout << endl;

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
    }

    // Lógica: impresión con recursión
    cout << " ----------------- Imprimir con recursion" << endl;
    mitad = (size + 1) / 2;
    contadorColumnas = mitad;
    contadorEspacios = "";
    imprimirMatrix(matrix, 0, rows, cols, mitad, contadorColumnas, contadorEspacios, size);

    // Liberar memoria
    for (int i = 0; i < size; i++) {
        delete[] * (matrix + i);
    }
    delete[] matrix;

    return 0;
}

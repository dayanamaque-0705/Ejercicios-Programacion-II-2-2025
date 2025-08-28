#include <iostream>
#include <conio.h>
using namespace std;

void imprimirColumnasMatrix(int** matrix, int i, int j, int cols, int contadorColumnas) {
    if (j >= cols) return;
    if (j < contadorColumnas) {
        *(*(matrix + i) + j) = j + 1;
        cout << *(*(matrix + i) + j) << " ";
    }
    imprimirColumnasMatrix(matrix, i, j + 1, cols, contadorColumnas);
}

void imprimirMatrix(int** matrix, int i, int rows, int cols, int mitad, int contadorColumnas) {
    if (i >= rows) return;

    *(matrix + i) = new int[contadorColumnas];
    imprimirColumnasMatrix(matrix, i, 0, cols, contadorColumnas);
    cout << endl;

    if (i >= (mitad - 1)) {
        contadorColumnas++;
    }
    else {
        contadorColumnas--;
    }
    imprimirMatrix(matrix, i + 1, rows, cols, mitad, contadorColumnas);
}

void imprimirColumnasMatrixInvertido(int** matrix, int i, int j, int contadorColumnas) {
    if (j < 0) return;
    if (j < contadorColumnas) {
        *(*(matrix + i) + j) = j + 1;
        cout << *(*(matrix + i) + j) << " ";
    }
    imprimirColumnasMatrixInvertido(matrix, i, j - 1, contadorColumnas);
}

void imprimirMatrixInvertido(int** matrix, int i, int rows, int cols, int mitad, int contadorColumnas, string contadorEspacios) {
    if (i >= rows) return;

    *(matrix + i) = new int[contadorColumnas];
    cout << contadorEspacios;
    imprimirColumnasMatrixInvertido(matrix, i, cols, contadorColumnas);
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
        contadorEspacios = contadorEspacios + " " + " ";
    }
    imprimirMatrixInvertido(matrix, i + 1, rows, cols, mitad, contadorColumnas, contadorEspacios);
}

int main()
{
    int size = 15;
    int** matrix = new int* [size];
    int rows = size;
    int cols = size;

    cout << " -----------------" << endl;
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
            contadorEspacios = contadorEspacios + " " + " ";
        }
    }

    cout << " ----------------- Imprimir con recursion" << endl;
    mitad = (size + 1) / 2;
    contadorColumnas = mitad;
    imprimirMatrix(matrix, 0, rows, cols, mitad, contadorColumnas);

    cout << " ----------------- Imprimir invertido con recursion" << endl;
    mitad = (size + 1) / 2;
    contadorColumnas = mitad;
    contadorEspacios = "";
    imprimirMatrixInvertido(matrix, 0, rows, cols, mitad, contadorColumnas, contadorEspacios);

    // Liberar memoria
    for (int i = 0; i < size; i++) {
        delete[] * (matrix + i);
    }
    delete[] matrix;

    return 0;
}

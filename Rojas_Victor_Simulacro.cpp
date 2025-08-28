
#include <iostream>
using namespace std;

void crearMatriz(int**& matrix, int size) {
    matrix = new int* [size];
    for (int i = 0; i < size; ++i) {
        // *(matrix + i) es el equivalente a matrix[i]
        *(matrix + i) = new int[size];
    }
}

void llenarMatrizConContador(int** matrix, int size, int& counter) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            // *(*(matrix + i) + j) es el equivalente a matrix[i][j]
            *(*(matrix + i) + j) = counter++;
        }
    }
}

void imprimirMatrizOriginal(int** matrix, int size) {
    cout << "\n*** Matriz Original ***" << endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << *(*(matrix + i) + j) << "\t";
        }
        cout << endl;
    }
}

void imprimirMatrizVolteada(int** matrix, int size) {
    cout << "\n*** Matriz Resultado Volteada ***" << endl;
    for (int i = 0; i < size; ++i) {
        for (int j = size - 1; j >= 0; --j) {
            cout << *(*(matrix + i) + j) << "\t";
        }
        cout << endl;
    }
}

void liberarMemoria(int** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        delete[] * (matrix + i);
    }
    delete[] matrix;
    cout << "\nMemoria liberada! ." << endl;
}

void ejecutarSimulacro() {
    int matrixSize = 5;
    int counter = 1;
    int** matrix = nullptr;
    crearMatriz(matrix, matrixSize);
    llenarMatrizConContador(matrix, matrixSize, counter);
    imprimirMatrizOriginal(matrix, matrixSize);
    imprimirMatrizVolteada(matrix, matrixSize);
    liberarMemoria(matrix, matrixSize);
}


int main() {
    ejecutarSimulacro();
    return 0;
}
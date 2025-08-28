#include <iostream>
using namespace std;

void imprimirFilaRecursiva(int** matrix, int fila, int col, int& contador) {
    if (col < 0) return;  
    cout << matrix[fila][col] << " ";
    contador++;
    imprimirFilaRecursiva(matrix, fila, col - 1, contador); 
}

int main() {
    int size = 15;
    int contador = 0;

    int** matrix = new int*[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }

    int valor = 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = valor++;
        }
    }

    for (int i = 0; i < size; i++) {
        imprimirFilaRecursiva(matrix, i, size - 1, contador);
        cout << endl;
    }
    cout << "\nTotal de elementos impresos: " << contador << endl;

    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

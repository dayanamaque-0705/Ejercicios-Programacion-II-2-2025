#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    int size = 5;

    // Creación
    int** matrix = new int* [size];

    int rows = size; // filas
    int cols = size; // columnas

    int N = size;     // 5 columnas para filas 0, 1 y 2
    int M = size - 2; // 3 columnas para filas 3 y 4

    // Asignar valores
    for (int i = 0; i < rows; i++) {
        if (i < 3) {
            *(matrix + i) = new int[N];
        }
        else {
            *(matrix + i) = new int[M];
        }

        for (int j = 0; j < ((i < 3) ? N : M); j++) {
            if (j == 0) {
                *(*(matrix + i) + j) = 1;
            }
            else if (j == 1) {
                *(*(matrix + i) + j) = 2;
            }
            else {
                if (i == 2 || i >= 3) {
                    *(*(matrix + i) + j) = 3;
                }
                else {
                    *(*(matrix + i) + j) = 2;
                }
            }
        }
    }

    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < ((i < 3) ? N : M); j++) {
            cout << *(*(matrix + i) + j) << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < size; i++) {
        delete[] * (matrix + i);
    }
    delete[] matrix;

    return 0;
}

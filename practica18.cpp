#include <iostream>
#include <conio.h>
using namespace std;

void asignarValores(int** matrix, int cols, int rows, int N, int M)
{
        int valor_inicial = 1;
        for (int i = 0; i < rows; i++) {
        if(i<N){
          *(matrix + i) = new int[N];
        }else{
          *(matrix + i) = new int[M];
        }

        for (int j = 0; j < cols; j++) {
            if ( i < M || j < M){
                *(*(matrix + i) + j) = valor_inicial;
            }
            if (j < i) {
                matrix[i][j] = j + 1;
            } else {
                matrix[i][j] = i + 1;
            }
        }
    }
}

int main()
{
    int size = 5;

    // Creación
    int** matrix = new int* [size];
   // int* array = new int[size];

    // Asignar valores
    int rows = size; // filas
    int cols = size; // columnas


    int N = size;     // 5
    int M = size - 2;  // 3

    // Asignar valores 1
    asignarValores(matrix, cols, rows, N, M);
    // Printear valores
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // cout << matrix[i][j] << " ";
            cout << *(*(matrix + i) + j) << " ";
        }
        cout << endl;
    }

    // Liberar memoria
    for (int i = 0; i < size; i++) {
        //delete[] matrix[i];
        delete[] *(matrix + i);
    }
    delete[] matrix;

    return 0;
}



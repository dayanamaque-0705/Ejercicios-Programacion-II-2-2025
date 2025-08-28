#include <iostream>
using namespace std;

int** crearMatriz(int size) {
    int** matrix = new int* [size];
    for (int i = 0; i < size; ++i) {
        *(matrix + i) = new int[size];
    }
    return matrix;
}

void inicializarPatron(int** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            *(*(matrix + i) + j) = 0;
    int mid = rows / 2;
    for (int i = 0; i < rows; ++i) 
    {
        if (i == 0 || i == rows - 1) 
        {
            *(*(matrix + i) + (mid - 1)) = 1;
            *(*(matrix + i) + mid) = 1;
            *(*(matrix + i) + (mid + 1)) = 1;
        }
        else if (i == 1 || i == rows - 2) 
        {
            *(*(matrix + i) + mid) = 1;
            *(*(matrix + i) + (mid + 1)) = 1;
        }
        else if (i == mid)
        {
            *(*(matrix + i) + (mid + 1)) = 1;
        }
    }
}


void mostrarSinCeros(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (*(*(matrix + i) + j) == 1) cout << '1';
            else cout << ' ';
        }
        cout <<endl;
    }
}

void liberarMatriz(int** matrix, int size) {
    for (int i = 0; i < size; ++i) delete[] * (matrix + i);
    delete[] matrix;
}

int main() {
    int size = 5;
    int** matrix = crearMatriz(size);
    inicializarPatron(matrix, size, size);
    mostrarSinCeros(matrix, size, size);
    liberarMatriz(matrix, size);
    return 0;
}

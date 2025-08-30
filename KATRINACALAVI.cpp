#include <iostream>
using namespace std;

int main()
{
    int size = 5;

    int** matrix = new int* [size];

    int rows = size;
    int cols = size;

    int N = size;
    int M = size - 2;

    // Llenado de la matriz
    for(int i = 0; i < rows; i++){
        if(i < N){
            *(matrix + i) = new int[N];
        }else{
            *(matrix + i) = new int[M];
        }
        for(int j = 0; j < cols; j++){
            if(i < M || j < M){
                *(*(matrix + i) + j) = 1;
            }
        }
    }

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << "Matriz[" << i << "][" << j << "]: " << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Liberar memoria
    for(int i = 0; i < size; i++){
        delete[]*(matrix + i);
    }
    delete[] matrix;
    
    return 0;
}

#include <iostream>
#include <conio.h>
using namespace std;

void printMatrixRecursive(int **matrix,int rows,int cols, int i = 0 ,int j = 0)
{
    if (i == rows )
    return;
    if(j == i +1)
    {
        cout << endl;
        printMatrixRecursive(matrix,rows, cols,i+1,0);
        return;

    }
    cout << *(*(matrix + i)+j)<< " ";
    printMatrixRecursive(matrix, rows, cols , i , j+1);


}

void freeMatrixRecursive(int **matrix, int size , int i=0)
{
    if (i==size)
    {
        delete[] matrix;
        return;
    }
    delete[] *(matrix + 1);
    freeMatrixRecursive(matrix,size,i+1);
}

int main()
{
    int size = 8;

    // Creación
    int** matrix = new int* [size];
   // int* array = new int[size];
   
    

    for (int i = 0; i < size; i++) {
        //matrix[i] = new int[size];
        *(matrix + i) = new int[i +1 ];
        
        //int array = new int[size];
    }

    // Asignar valores
    int rows = size; // filas
    int cols = size; // columnas
    //ascendente
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if(i == j)
            *(*(matrix + i) + j) = 1;
            else
             *(*(matrix +i)+j)=0;
        }
        cout << endl;
    }




    printMatrixRecursive(matrix,rows, cols,0,0);
    freeMatrixRecursive(matrix,size,0);


    return 0;
}

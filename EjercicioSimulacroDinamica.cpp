#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
void ImprPiramideInv(int** matrix, int size)
{
    for (int i = 0; i < size; i++) 
    {
        for (int h = 0; h < i; h++) 
        {
            cout << "  ";
        }
        for (int j = 0; j < size - i; j++) 
        {
            cout << *(*(matrix)+j) << " ";
        }
        cout << endl;
    }
    for (int i = size - 2; i >= 0; i--) 
    {
        for (int h = 0; h < i; h++) 
        {
            cout << "  ";
        }
        for (int j = 0; j < size - i; j++) 
        {
            cout << *(*(matrix)+j) << " ";
        }
        cout << endl;
    }
}
    
int main()
{
    int size;
    cout << "ingrese el tamano de la piramide" << endl;
        cin >> size;
        system("cls");
    int** matrix = new int* [size];
    

    for (int i = 0; i < size; i++) {
        *(matrix + i) = new int[size];
    }

    int rows = size;
    int cols = size;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(*(matrix+i) + j) = j+1;
        }
    }

    for (int i = size; i>0; i--) {
        for (int j = 0; j < i; j++) {
            cout << *(*(matrix) + j) << " ";
        }
        cout << endl;
    }
    for (int i = 2; i <= size; i++) {
        for (int j = 0; j < i; j++) {
            cout << *(*(matrix)+j) << " ";
        }
        cout << endl;
    }
    cout << "--------------------------------" << endl;
        cout << "piramide invertida" << endl;
    ImprPiramideInv(matrix, size);
    for (int i = 0; i < size; i++) {
        delete[] * (matrix + i);
    }
    delete[] matrix;

    return 0;
}

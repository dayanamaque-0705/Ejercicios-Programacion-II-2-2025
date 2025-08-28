#include <iostream>
#include <conio.h>
using namespace std;

void imprimirColumnas(int** matrix, int i, int j, int contadorColumnas)
{
    if (j >= contadorColumnas) 
    {
        return;
    }
    *(*(matrix + i) + j) = j + 1;
    cout << *(*(matrix + i) + j) << " ";

    imprimirColumnas(matrix, i, j + 1, contadorColumnas);
}

void imprimirFilas(int** matrix, int i, int rows, int cols, int mitad, int contadorColumnas, string espacios)
{
    if (i >= rows)
    {
        return;
    }

    cout << espacios;
    *(matrix + i) = new int[contadorColumnas];
    imprimirColumnas(matrix, i, 0, contadorColumnas);
    cout << endl;
    if (i >= (mitad - 1))
    {
        contadorColumnas++;
        if (!espacios.empty())
        {
            espacios.pop_back();
            espacios.pop_back();
        }
    }
    else
    {
        contadorColumnas--;

        espacios += "  ";
    }

    imprimirFilas(matrix, i + 1, rows, cols, mitad, contadorColumnas, espacios);
}

int main()
{
    int size = 15;
    int** matrix = new int* [size];

    int rows = size;


    int cols = size;
    int mitad = (size + 1) / 2;
    int contadorColumnas = mitad;

    cout << "--------------- " << endl;
    imprimirFilas(matrix, 0, rows, cols, mitad, contadorColumnas, "");
    cout << "--------------- " << endl;

    for (int i = 0; i < size; i++) 
    {

        delete[] * (matrix + i);
    }

    delete[] matrix;

    return 0;
}

// tarea recur.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

void printRow(int* row, int cols, int j = 0)
{
    if (j == cols) return;          
    cout << row[j] << " ";          
    printRow(row, cols, j + 1);     
}


void printMatrix(int** matrix, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printRow(matrix[i], size);   
        cout << endl;
    }
}


void flipHorizontal(int** matrix, int size) 
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size / 2; j++) 
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][size - 1 - j];
            matrix[i][size - 1 - j] = temp;
        }
    }
}

int main()
{
    int size = 5;
    int contador = 1;

    
    int** matrix = new int* [size];
    for (int i = 0; i < size; i++) 
    {
        matrix[i] = new int[size];
        for (int j = 0; j < size; j++) 
        {
            matrix[i][j] = contador++;  
        }
    }

   
    cout << "Matriz original:\n";
    printMatrix(matrix, size);

  
    flipHorizontal(matrix, size);

    
    cout << "\nMatriz volteada:\n";
    printMatrix(matrix, size);

    
    for (int i = 0; i < size; i++) 
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}





// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln

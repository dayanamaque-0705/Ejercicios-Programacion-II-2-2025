// ejercicio 18.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int size = 5;

    // Creación
    int** matrix = new int* [size];

    int rows = size; // filas
    int cols = size; // columnas

    int N = size;     // 5
    int M = size - 2; // 3

    int contador = 1; // 🔹 Numerador

    // Asignar valores
    for (int i = 0; i < rows; i++) {
        if (i < N) {
            *(matrix + i) = new int[N];
        }
        else {
            *(matrix + i) = new int[M];
        }

        for (int j = 0; j < cols; j++) {
            if (i < M || j < M) {
                *(*(matrix + i) + j) = contador++; // 🔹 Numerador creciente
            }
            else {
                *(*(matrix + i) + j) = 0; // Mantener 0 donde no aplica
            }
        }
    }

    // Printear valores
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << *(*(matrix + i) + j) << " ";
        }
        cout << endl;
    }

    // Liberar memoria
    for (int i = 0; i < size; i++) {
        delete[] * (matrix + i);
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

// ejercicio simulacro.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

// Voltear horizontalmente (invertir cada fila)
void voltearHorizontal(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols / 2; j++) {
            int temp = *(*(matrix + i) + j);
            *(*(matrix + i) + j) = *(*(matrix + i) + (cols - 1 - j));
            *(*(matrix + i) + (cols - 1 - j)) = temp;
        }
    }
}

// Función recursiva para imprimir fila
void imprimirFila(int** matrix, int fila, int col, int cols) {
    if (col == cols) return;
    cout << *(*(matrix + fila) + col) << " ";
    imprimirFila(matrix, fila, col + 1, cols);
}

// Función recursiva para imprimir matriz
void imprimirMatriz(int** matrix, int fila, int rows, int cols) {
    if (fila == rows) return;
    imprimirFila(matrix, fila, 0, cols);
    cout << endl;
    imprimirMatriz(matrix, fila + 1, rows, cols);
}

int main() {
    int rows = 5, cols = 3;

    // Crear matriz dinámica
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        *(matrix + i) = new int[cols];
    }
    // Llenar matriz 
    int valores[5][3] = {
        {1, 2, 3},
        {1, 2, 0},
        {1, 0, 0},
        {1, 2, 0},
        {1, 2, 3}
    };

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(*(matrix + i) + j) = valores[i][j];
        }
    }

    cout << "matriz antes"<<endl;
    imprimirMatriz(matrix, 0, rows, cols);

    voltearHorizontal(matrix, rows, cols);

    cout << "matriz despues"<<endl;
    imprimirMatriz(matrix, 0, rows, cols);

    // Liberar memoria
    for (int i = 0; i < rows; i++) {
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

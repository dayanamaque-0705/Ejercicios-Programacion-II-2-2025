#include <iostream>
#include <string>
using namespace std;

// Función recursiva para imprimir columnas
void imprimirColumnasMatrix(int** matrix, int i, int j, int cols, int contadorColumnas)
{
    // Caso base: si nos pasamos de columnas, detenernos
    if (j >= contadorColumnas) {
        return;
    }

    // Asignar valor y mostrar
    *(*(matrix + i) + j) = j + 1;
    cout << *(*(matrix + i) + j) << " ";

    // Llamada recursiva a la siguiente columna
    imprimirColumnasMatrix(matrix, i, j + 1, cols, contadorColumnas);
}

// Funcion recursiva para imprimir filas
void imprimirMatrix(int** matrix, int i, int rows, int cols, int mitad, int contadorColumnas, string contadorEspacios) 
{
    // Caso base: si ya imprimimos todas las filas, detenernos
    if (i >= rows) {
        return;
    }

    // Crear fila dinamica
    *(matrix + i) = new int[contadorColumnas];

    // Imprimir espacios
    cout << contadorEspacios;

    // Imprimir columnas recursivamente
    imprimirColumnasMatrix(matrix, i, 0, cols, contadorColumnas);
    cout << endl;

    // Actualizar valores para la siguiente fila
    if (i >= (mitad - 1)) {
        contadorColumnas++;
        if (!contadorEspacios.empty()) {
            contadorEspacios.pop_back();
            contadorEspacios.pop_back();
        }
    }
    else {
        contadorColumnas--;
        contadorEspacios += "  ";
    }

    // Llamada recursiva a la siguiente fila
    imprimirMatrix(matrix, i + 1, rows, cols, mitad, contadorColumnas, contadorEspacios);
}

int main() 
{
    int size = 15;

    // Creación de la matriz dinamica
    int** matrix = new int* [size];

    // Asignar valores iniciales
    int rows = size; // filas
    int cols = size; // columnas
    int mitad = (size + 1) / 2;
    int contadorColumnas = mitad;

    cout << " ----------------- Imprimir con recursion -----------------" << endl;

    // Llamada inicial a la función recursiva
    imprimirMatrix(matrix, 0, rows, cols, mitad, contadorColumnas, "");

    // Liberar memoria
    for (int i = 0; i < size; i++) {
        delete[] * (matrix + i);
    }
    delete[] matrix;

    return 0;
}

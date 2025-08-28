#include <iostream>
#include <string>
using namespace std;

void imprimirColumnasMatrix(int** matrix, int i, int j, int rows, int cols, int mitad, int contadorColumnas) {
    // Caso base para columnas
    if (j < 0) {
        return;
    }
    if (j < contadorColumnas) {
        *(*(matrix + i) + j) = j + 1;
        cout << *(*(matrix + i) + j) << " ";
    }
}

// --------------------------

void imprimirMatrixRec(int** matrix, int currentRow, int rows, int contadorColumnas, int mitad, string contadorEspacios) {
    if (currentRow >= rows) { // Caso base
        return;
    }
    // Imprimir la indentación
    cout << contadorEspacios;
    // Imprimir las columnas de la fila actual
    for (int j = 0; j < contadorColumnas; j++) {
        cout << matrix[currentRow][j] << " ";
    }
    cout << endl;
    
    // Actualizar contadorColumnas y espacios según el patrón
    if (currentRow >= (mitad - 1)) {
        contadorColumnas++;
        if (!contadorEspacios.empty() && contadorEspacios.size() >= 2)
            contadorEspacios.erase(contadorEspacios.size() - 2, 2);
    }
    else {
        contadorColumnas--;
        contadorEspacios += "  ";
    }
    // Llamada recursiva a la siguiente fila
    imprimirMatrixRec(matrix, currentRow + 1, rows, contadorColumnas, mitad, contadorEspacios);
}


void imprimirMatrix(int** matrix, int rows, int mitad) {
    int contadorColumnas = mitad;
    string contadorEspacios = "";
    imprimirMatrixRec(matrix, 0, rows, contadorColumnas, mitad, contadorEspacios);
}
// --------------------------

int main()
{
    int size = 15;
    // Creación
    int** matrix = new int* [size];

    // Asignar valores
    int rows = size; // filas
    int cols = size; // columnas

    // Logica: Impresión iterativa del patrón normal
    cout << " -----------------" << endl;
    int mitad = (size + 1) / 2;
    int contadorColumnas = mitad;
    for (int i = 0; i < rows; i++) {

        *(matrix + i) = new int[contadorColumnas];

        for (int j = 0; j < cols; j++) { // j < i
            if (j < contadorColumnas) {
                *(*(matrix + i) + j) = j + 1;
                cout << *(*(matrix + i) + j) << " ";
            }
        }
        cout << endl;

        if ( i >= (mitad - 1)) {
            contadorColumnas++;
        }
        else {
            contadorColumnas--;
        }
    }

    // Logica: Impresión iterativa del patrón invertido
    cout << " ----------------- invertido" << endl;
    mitad = (size + 1) / 2;
    contadorColumnas = mitad;
    string contadorEspacios = "";
    for (int i = 0; i < rows; i++) {

        // Reutilizamos la misma matriz para la impresión
        cout << contadorEspacios;
        for (int j = cols; j >= 0; j--) { // j < i
            if (j < contadorColumnas) {
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;

        if (i >= (mitad - 1)) {
            contadorColumnas++;
            if (!contadorEspacios.empty() && contadorEspacios.size() >= 2) {
                contadorEspacios.pop_back();
                contadorEspacios.pop_back();
            }
        }
        else {
            contadorColumnas--;
            contadorEspacios = contadorEspacios + "  ";
        }
    }

    // Llamada a la versión recursiva del patrón
    cout << " ----------------- Imprimir con recursión" << endl;
    imprimirMatrix(matrix, rows, mitad);

    // Liberar memoria
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
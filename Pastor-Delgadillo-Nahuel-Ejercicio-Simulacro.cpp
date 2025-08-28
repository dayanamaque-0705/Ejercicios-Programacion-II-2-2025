#include <iostream>
using namespace std;

// Función recursiva para llenar el patrón triangular
void llenarPatronTriangularRecursivo(int** matrix, int fila, int col, int size, int& contador) {
    if (fila >= size) return; // Caso base: todas las filas procesadas

    if (col <= fila && col < size) { // Solo llenar hasta la diagonal
        matrix[fila][col] = col + 1; // Valores: 1, 2, 3, ...
        llenarPatronTriangularRecursivo(matrix, fila, col + 1, size, contador);
    } else {
        llenarPatronTriangularRecursivo(matrix, fila + 1, 0, size, contador);
    }
}

// Función recursiva para imprimir la matriz volteada horizontalmente
void imprimirMatrizVolteadaRecursiva(int** matrix, int fila, int col, int size) {
    if (fila >= size) return;

    if (col < size) {
        // Voltear horizontalmente: acceder a columnas en orden inverso
        if (matrix[fila][size - 1 - col] == 0) {
            cout << "  "; // Espacios para ceros
        } else {
            cout << matrix[fila][size - 1 - col] << " ";
        }
        imprimirMatrizVolteadaRecursiva(matrix, fila, col + 1, size);
    } else {
        cout << endl;
        imprimirMatrizVolteadaRecursiva(matrix, fila + 1, 0, size);
    }
}

int main() {
    int size = 15; // Tamaño para coincidir con la imagen
    int contador = 0;

    // Creación optimizada de matriz
    int** matrix = new int*[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size]{0}; // Inicializar con ceros
        contador++;
    }

    // Llenar patrón triangular usando recursividad
    llenarPatronTriangularRecursivo(matrix, 0, 0, size, contador);

    cout << "Matriz con patron triangular:" << endl;
    // Imprimir matriz normal para referencia
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] == 0) {
                cout << "  ";
            } else {
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }

    cout << "\nMatriz volteada horizontalmente (como la imagen):" << endl;
    // Imprimir volteada usando recursividad
    imprimirMatrizVolteadaRecursiva(matrix, 0, 0, size);

    // Contador de operaciones
    cout << "\nTotal de filas creadas: " << contador << endl;
    cout << "Total de celdas: " << size * size << endl;

    // Liberar memoria optimizado
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}

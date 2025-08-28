#include <iostream>
#include <conio.h>
using namespace std;

void crearMatriz(int**& matrix, int size)
{
    // Creación
    matrix = new int* [size];
    // int* array = new int[size];

    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
        //*(matrix + i) = new int[size];
        //int array = new int[size];
    }
}

void iniciarMatriz(int** matrix, int rows, int cols)
{

    // Asignar valores
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // matrix[i][j] = 0;
            *(*(matrix + i) + j) = 0;
        }
    }
}

void printearMatriz(int** matrix, int cols, int rows)
{
    // Printear valores
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            //cout << matrix[i][j] << " ";
            cout << *(*(matrix + i) + j) << " ";
        }
        cout << endl;
    }
}

void ejercicioMatrizVertical(int** matrix, int cols, int rows, int size)
{
    int mitad = (size + 1) / 2;
    int contadorMitadRows = mitad;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (j < contadorMitadRows) {
                //Añadí ahora a las 07:57 28-08-2025 el j + 1 en lugar de 1 porque se me olvidó por completo el contador, pensé que el contador era de tiempo :c
                *(*(matrix + i) + j) = j + 1;

            }
        }

        if ((mitad - 1) <= i)
        {
            contadorMitadRows++;
        }
        else
        {
            contadorMitadRows--;
        }
    }

}
void ejercicioMatrizHorizontal(int** matrix, int cols, int rows, int size)
{
    int mitad = (size + 1) / 2;
    int contadorMitadRows = mitad;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (j < contadorMitadRows) {
                //Añadí ahora a las 07:57 28-08-2025 el j + 1 en lugar de 1 porque se me olvidó por completo el contador, pensé que el contador era de tiempo :c
                *(*(matrix + j) + i) = 1;

            }
        }

        if ((mitad - 1) <= i)
        {
            contadorMitadRows++;
        }
        else
        {
            contadorMitadRows--;
        }
    }

}

void ejercicioMatrizRecursiva(int** matrix, int cols, int rows, int size, int i, int j)
{
    if (i >= rows) {
        return;
    }
    //Este no tomé en cuenta que habia que añadir un contador y por eso trabajé con ceros y unos, mil disculpas :c, aunque tiene recursividad 
    int uno;
    int ceros;

    if (i < size / 2) {
        uno = 2 * i + 1;
    }
    else {
        uno = 2 * (size - i - 1) + 1;
    }
    if (size % 2 == 0) { // Si el tamaño es par
        if (i == size / 2) {
            uno = size - 1;
        }
        else if (i > size / 2) {
            uno = 2 * (size - i) - 1;
        }
    }
    ceros = (size - uno) / 2;

    if (j >= ceros && j < ceros + uno) {
        matrix[i][j] = 1;
    }
    else {
        matrix[i][j] = 0;
    }

    if (j + 1 < cols) {
        ejercicioMatrizRecursiva(matrix, cols, rows, size, i, j + 1);
    }
    else {
        ejercicioMatrizRecursiva(matrix, cols, rows, size, i + 1, 0);
    }
}


void borrarMatriz(int** matrix, int size)
{
    // Liberar memoria
    for (int i = 0; i < size; i++) {
        //delete[] matrix[i];
        delete[] * (matrix + i);
    }
    delete[] matrix;
}

int main()
{
    int** matrix;
    int size;
    cout << "Introduzca el tamaño de la matriz cuadrada: " << endl;
    cin >> size;
    int rows = size; // filas
    int cols = size; // columnas
    int opcion;
    do {
        cout << "-----------------------Ejercicios de matrices-----------------------" << endl;
        cout << "------------Elija la opcion con el numero del ejercicio:------------" << endl;
        cout << "-----1. Matriz Vertical---------------------------------------------" << endl;
        cout << "-----2. Matriz horizontal-------------------------------------------" << endl;
        cout << "-----3. Matriz en diamante con RECURSIVIDAD-------------------------" << endl;
        cout << "-----4. Cerra el menu-----------------------------------------------" << endl;
        cin >> opcion;
        //----------------------------------------------------------------------------------------
        crearMatriz(matrix, size);
        iniciarMatriz(matrix, size, size);

        switch (opcion)
        {
        case 1:
            cout << "Opcion elegida: Matriz Vertical" << endl;
            cout << "----------------------------------------------------------------" << endl;
            iniciarMatriz(matrix, size, size);
            ejercicioMatrizVertical(matrix, cols, rows, size);
            printearMatriz(matrix, size, size);
            cout << "----------------------------------------------------------------" << endl;
            break;
        case 2:
            cout << "Opcion elegida: Matriz Horizontal" << endl;
            cout << "----------------------------------------------------------------" << endl;
            iniciarMatriz(matrix, size, size);
            ejercicioMatrizHorizontal(matrix, cols, rows, size);
            printearMatriz(matrix, size, size);
            cout << "----------------------------------------------------------------" << endl;
            break;
        case 3:
            cout << "Opcion elegida: Matriz en diamante CON RECURSIVIDAD" << endl;
            cout << "----------------------------------------------------------------" << endl;
            iniciarMatriz(matrix, size, size);
            ejercicioMatrizRecursiva(matrix, size, size, size, 0, 0);
            printearMatriz(matrix, size, size);
            cout << "----------------------------------------------------------------" << endl;
            break;
        case 4:
            cout << "Cerrando el menu..." << endl;
            cout << "----------------------------------------------------------------" << endl;
            break;
        }
    } while (opcion != 4);


    borrarMatriz(matrix, size);


    return 0;
}

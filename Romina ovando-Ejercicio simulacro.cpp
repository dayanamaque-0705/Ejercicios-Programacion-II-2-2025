#include <iostream>
using namespace std;

int** crearMatrizIrregular(int cantidadFilas, int*& datos, int* cantidadColumnasPorFila)
{
    int** matriz = new int* [cantidadFilas];
    int cantidadTotalElementos = 0;

    for (int i = 0; i < cantidadFilas; i++)
    {
        cantidadTotalElementos += cantidadColumnasPorFila[i];
    }

    datos = new int[cantidadTotalElementos];

    int posicion = 0;
    for (int i = 0; i < cantidadFilas; i++) 
    {
        matriz[i] = datos + posicion;
        posicion += cantidadColumnasPorFila[i];
    }

    return matriz;
}

void llenarMatrizIrregular(int** matriz, int cantidadFilas, int* cantidadColumnasPorFila) 
{
    for (int i = 0; i < cantidadFilas; i++) {
        for (int j = 0; j < cantidadColumnasPorFila[i]; j++) {
            matriz[i][j] = j + 1;
        }
    }
}

int imprimirMatrizIrregular(int** matriz, int cantidadFilas, int* cantidadColumnasPorFila) 
{
    int contadorElementos = 0;
    for (int i = 0; i < cantidadFilas; i++) {
        for (int j = 0; j < cantidadColumnasPorFila[i]; j++)
        {
            cout << matriz[i][j] << " ";
            contadorElementos++;
        }
        cout << endl;
    }
    return contadorElementos;
}

int imprimirMatrizIrregularVolteada(int** matriz, int cantidadFilas, int* cantidadColumnasPorFila) 
{
    int contadorElementos = 0;
    for (int i = 0; i < cantidadFilas; i++) {
        for (int j = cantidadColumnasPorFila[i] - 1; j >= 0; j--) 
        {
            cout << matriz[i][j] << " ";
            contadorElementos++;
        }
        cout << endl;
    }
    return contadorElementos;
}

void liberarMatrizIrregular(int** matriz, int* datos) 
{
    delete[] datos;
    delete[] matriz;
}

int main() 
{
    int cantidadFilas = 5;
    int cantidadColumnasPorFila[5] = { 3, 2, 1, 2, 3 }; 
    int* datos = nullptr;
    int** matriz = crearMatrizIrregular(cantidadFilas, datos, cantidadColumnasPorFila);
    llenarMatrizIrregular(matriz, cantidadFilas, cantidadColumnasPorFila);
    cout << "Figura :" << endl;
    int contadorOriginal = imprimirMatrizIrregular(matriz, cantidadFilas, cantidadColumnasPorFila);

    cout << "\nFigura volteada horizontalmente:" << endl;
    int contadorVolteada = imprimirMatrizIrregularVolteada(matriz, cantidadFilas, cantidadColumnasPorFila);
    cout << "\nCantidad de elementos en la figura: " << contadorOriginal << endl;
    cout << "Cantidad de elementos en la figura volteada: " << contadorVolteada << endl;

    liberarMatrizIrregular(matriz, datos);

    return 0;
}

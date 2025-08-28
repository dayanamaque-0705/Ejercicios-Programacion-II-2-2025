#include <iostream>
using namespace std;

// Función recursiva para imprimir una fila
void imprimirFila(int limite, int actual = 1) {
    if (actual > limite) return;
    cout << actual << " ";
    imprimirFila(limite, actual + 1);
}

int main() {
    int N;
    cout << "Ingrese un numero impar: ";
    cin >> N;

    // Viendo si el numero es impar
    if (N % 2 == 0 || N <= 0) {
        cout << " senor usuario ingrese un numero impar." << endl;
        return 1;
    }

    // Calculando cuántas filas habra
    int mitad = N / 2;
    int contador = 0;

    // Creación dinámica un array de punteros para cada fila
    int** figura = new int*[N];
    for (int i = 0; i < N; i++) {

        int tamFila = (i <= mitad) ? (i + 1) : (N - i);
        figura[i] = new int[tamFila];


        for (int j = 0; j < tamFila; j++) {
            figura[i][j] = j + 1;
            contador++;
        }
    }
// usando recursividad para imprimir
    cout << " Figura original:\n";
    for (int i = 0; i < N; i++) {
        int tamFila = (i <= mitad) ? (i + 1) : (N - i);
        imprimirFila(tamFila);
        cout << endl;
    }

    cout << " Figura horizontal:\n";
    for (int i = 0; i < N; i++) {
        int tamFila = (i <= mitad) ? (i + 1) : (N - i);
        for (int j = tamFila - 1; j >= 0; j--) {
            cout << figura[i][j] << " ";
        }
        cout << endl;
    }

    cout << " Cantidad de numeros: " << contador << endl;

    // Liberar memoria
    for (int i = 0; i < N; i++) {
        delete[] figura[i];
    }
    delete[] figura;

    return 0;
}

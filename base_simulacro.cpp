#include <iostream>
using namespace std;

void llenarcasillas(int** matriz, int fila, int N) {
    static int contador;
    if (fila == 0) contador = 1;
    if (fila == N) return;

    int m = N / 2;

    if (fila < m) {
        int espace = fila;
        for (int j = 0; j < N - espace; j++)
            matriz[fila][j + espace] = contador++;
    } else if (fila == m) {
        matriz[fila][m] = contador++;
    } else {
        int sim = N - fila - 1;
        int espace = sim;
        for (int j = 0; j < N - espace; j++)
            matriz[fila][j + espace] = contador++;
    }

    llenarcasillas(matriz, fila + 1, N);
}

void imprimircasillas(int** matriz, int fila, int N) {
    for (int i = fila; i < N; i++) {
        for (int j = N - 1; j >= 0; j--) {
            if (matriz[i][j] == 0)
                cout << "   ";
            else
                cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int N;
    cout << "Ingrese un numero impar N: ";
    cin >> N;

    if (N <= 0 || N % 2 == 0) {
        cout << "N debe ser un numero entero positivo e impar" << endl;
        return 1;
    }

    int** mat = new int*[N];
    int* block = new int[N * N];
    for (int i = 0; i < N; i++)
        mat[i] = block + i * N;

    for (int i = 0; i < N * N; i++)
        block[i] = 0;

    llenarcasillas(mat, 0, N);
    imprimircasillas(mat, 0, N);

    delete[] block;
    delete[] mat;

    return 0;
}

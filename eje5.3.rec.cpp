#include <iostream>
using namespace std;

int contador = 0;


void imprimirLinea(int actual, int n) {
    if (actual > n) return;
    cout << actual << " ";
    contador++;
    imprimirLinea(actual + 1, n);
}


void imprimirFigura(int fila, int N) {
    if (fila >= N) return;

    int tam;
    if (fila <= N / 2)
        tam = N / 2 + 1 - fila;
    else
        tam = fila - N / 2 + 1;

    imprimirLinea(1, tam);
    cout << endl;

    imprimirFigura(fila + 1, N);
}

int main() {
    int N;

   
    do {
        cout << "Ingrese un numero impar positivo: ";
        cin >> N;
    } while (N % 2 == 0 || N <= 0);

    
    imprimirFigura(0, N);

   
    cout << "Total de numeros impresos: " << contador << endl;

    return 0;
}

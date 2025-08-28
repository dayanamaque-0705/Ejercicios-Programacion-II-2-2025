#include <iostream>
using namespace std;

int main() {
    int N;

    
    do {
        cout << "Ingrese un numero impar: ";
        cin >> N;
    } while (N % 2 == 0 || N <= 0);

    
    int** matriz = new int*[N];

    
    for (int i = 0; i < N; i++) {
        int tam = i < N / 2 ? N / 2 + 1 - i : i - N / 2 + 1;  

        
        matriz[i] = new int[tam];

        
        for (int j = 0; j < tam; j++) {
            matriz[i][j] = j + 1;
        }
    }

   
    for (int i = 0; i < N; i++) {
        int tam = i < N / 2 ? N / 2 + 1 - i : i - N / 2 + 1;
        for (int j = 0; j < tam; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    
    for (int i = 0; i < N; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}

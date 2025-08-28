
#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Ingrese un número impar N: ";
    cin >> N;

    if (N % 2 == 0 || N < 1) {
        cout << "N debe ser un número impar positivo." << endl;
        return 1;
    }

  
    int** matrix = new int*[N];
    int* cols = new int[N]; 

   
    for (int i = 0; i < N; i++) {
        int num = (i <= N/2) ? (N/2 + 1 - i) + i : (i - N/2 + 1);
        cols[i] = N/2 + 1 - abs(N/2 - i);
        matrix[i] = new int[cols[i]];
    }

   
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < cols[i]; j++) {
            matrix[i][j] = j + 1;
        }
    }

    
    for (int i = 0; i < N; i++) {
       
        int espacios = N/2 - min(i, N-1-i);
        for (int e = 0; e < espacios; e++) cout << "  ";
        for (int j = 0; j < cols[i]; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    
    for (int i = 0; i < N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] cols;

    return 0;
}

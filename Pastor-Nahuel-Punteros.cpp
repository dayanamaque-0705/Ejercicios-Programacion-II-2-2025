#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Ingrese el tamanio del vector: ";
    cin >> n;
    int* vec = new int[n];
    cout << "Ingrese los elementos del vector:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> *(vec + i);   
   } 
    int* ini = vec;       
    int* f = vec + n - 1;   
    while (inicio < f) {
        int temp = *ini;
        *ini = *f;
        *f = temp;
        ini++;
        f--;
    }
    cout << "El vector invertido es: ";
    for (int i = 0; i < n; i++) {
        cout << *(vec + i) << " ";
   } 
    delete[] vec;
    return 0;
}

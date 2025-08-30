#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int n = 5;

    int** a = new int* [n];
    for (int i = 0; i < n; ++i) {
        a[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            a[i][j] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i >= 3 && j >= 3) {
                a[i][j] = 0;
            }
            else {
                int d = i;
                if (j < d) d = j;
                if (2 < d) d = 2;
                a[i][j] = 1 + d;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 0) cout << "   ";
            else cout << setw(2) << a[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < n; ++i) delete[] a[i];
    delete[] a;

    return 0;
}

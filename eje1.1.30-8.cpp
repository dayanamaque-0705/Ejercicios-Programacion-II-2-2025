


#include <iostream>
using namespace std;
int main()
{
    int rows = 5, cols = 5;
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i < 3) {
                if (j < i + 1)
                    matrix[i][j] = j + 1;
                else
                    matrix[i][j] = i + 1;
            } else {
                if (j < 3)
                    matrix[i][j] = j + 1;
                else
                    matrix[i][j] = 0; 
            }
        }
    }

    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i < 3 || j < 3) {
                cout << matrix[i][j];
                if (j < cols - 1 && (i < 3 || j < 2)) cout << " ";
            }
        }
        cout << endl;
    }

   
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
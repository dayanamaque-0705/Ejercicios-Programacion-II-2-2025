#include <iostream>

using namespace std;

int main()
{
    int size = 15;

 
    int** matrix = new int*[size];

    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }


    int rows = size; 
    int cols = size; 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }

   
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;

}

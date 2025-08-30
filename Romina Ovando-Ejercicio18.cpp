// clase 1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//Romina

#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int size = 5;

    int** matrix = new int* [size];
    for (int i = 0; i < size; i++) {
        *(matrix + i) = new int[size]; 
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i < 3) { 
                if (j <= i) {
                    ((matrix + i) + j) = j + 1;
                }
                else {
                    ((matrix + i) + j) = i + 1;
                }
            }
            else { 
                if (j < 3) {
                    ((matrix + i) + j) = j + 1;
                }
                else {
                    ((matrix + i) + j) = 0;
                }
            }
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << ((matrix + i) + j) << " ";
        }
        cout << endl;
    }

  
    for (int i = 0; i < size; i++) {
        delete[] * (matrix + i);
    }
    delete[] matrix;

    return 0;
}






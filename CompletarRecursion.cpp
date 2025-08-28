
#include <iostream>
#include <conio.h>
using namespace std;

void imprimirColumnasMatrix(int** matrix, int i, int j, int rows, int cols, int mitad, int contadorColumnas) {
	// Caso base para columnas
	if (j < 0) {
		return;
	}

	if (j < contadorColumnas) {
		*(*(matrix + i) + j) = j + 1;
		cout << *(*(matrix + i) + j) << " ";
	}

}

void imprimirMatrix(int** matrix, int i, int j, int rows, int cols, int mitad, int contadorColumnas, string contadorEspacios, int size) {
	// Caso base para filas
	if (i >= rows) {
		return;
	}
	imprimirColumnasMatrix(matrix, i+ 1, 0 , rows, cols, mitad, contadorColumnas);
	imprimirColumnasMatrix(matrix, 0, j + 1, rows, cols, mitad, contadorColumnas);

	cout << endl;

	if (i >= (mitad - 1)) {
		contadorColumnas++;
		if (!contadorEspacios.empty()) {
			contadorEspacios.pop_back();
			contadorEspacios.pop_back();
		}
	}
	else {
		contadorColumnas--;
		contadorEspacios = contadorEspacios + " " + " ";
	}
	// --------------------------------------
	mitad = (size + 1) / 2;
	contadorColumnas = mitad;
	string contadorEspacios = "";
	for (int i = 0; i < rows; i++) {

		*(matrix + i) = new int[contadorColumnas];
		cout << contadorEspacios;
		for (int j = cols; j >= 0; j--) { // j < i
			if (j < contadorColumnas) {
				*(*(matrix + i) + j) = j + 1;
				cout << *(*(matrix + i) + j) << " ";
			}
		}
		cout << endl;

		if (i >= (mitad - 1)) {
			contadorColumnas++;
			if (!contadorEspacios.empty()) {
				contadorEspacios.pop_back();
				contadorEspacios.pop_back();
			}
		}
		else {
			contadorColumnas--;
			contadorEspacios = contadorEspacios + " " + " ";
		}

	}
}


int main()
{
	int size = 15;
	// Creación
	int** matrix = new int* [size];

	// Asignar valores
	int rows = size; // filas
	int cols = size; // columnas

	// Logica
	cout << " -----------------" << endl;
	int mitad = (size + 1) / 2;
	int contadorColumnas = mitad;
	for (int i = 0; i < rows; i++) {

		*(matrix + i) = new int[contadorColumnas];

		for (int j = 0; j < cols; j++) { // j < i
			if (j < contadorColumnas) {
				*(*(matrix + i) + j) = j + 1;
				cout << *(*(matrix + i) + j) << " ";
			}
		}
		cout << endl;

		if (i >= (mitad - 1)) {
			contadorColumnas++;
		}
		else {
			contadorColumnas--;
		}

	}

	// Logica
	cout << " ----------------- invertido" << endl;
	mitad = (size + 1) / 2;
	contadorColumnas = mitad;
	string contadorEspacios = "";
	for (int i = 0; i < rows; i++) {

		*(matrix + i) = new int[contadorColumnas];
		cout << contadorEspacios;
		for (int j = cols; j >= 0; j--) { // j < i
			if (j < contadorColumnas) {
				*(*(matrix + i) + j) = j + 1;
				cout << *(*(matrix + i) + j) << " ";
			}
		}
		cout << endl;

		if (i >= (mitad - 1)) {
			contadorColumnas++;
			if (!contadorEspacios.empty()) {
				contadorEspacios.pop_back();
				contadorEspacios.pop_back();
			}
		}
		else {
			contadorColumnas--;
			contadorEspacios = contadorEspacios + " " + " ";
		}

	}

	cout << " ----------------- Imprimir con recursión" << endl;
	//Mil disculpas que este mal puesto, el tiempo me ganó
	imprimirMatrix(matrix, 0, rows, cols, mitad, contadorColumnas, contadorEspacios, size);


	// Liberar memoria
	for (int i = 0; i < size; i++) {
		//delete[] matrix[i];
		delete[] * (matrix + i);
	}
	delete[] matrix;

	return 0;
}
	delete[] matrix;

	return 0;
}

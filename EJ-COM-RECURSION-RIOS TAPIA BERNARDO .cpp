#include <iostream>

#include <conio.h> 

using namespace std;

// --- AÑADIDO: Declaraciones de funciones actualizadas ---
void imprimirPatronRomboIzquierdo(int** matriz, int filaActual, int numFilas, int mitad, int columnasAImprimir);
// --- MODIFICADO: El ultimo parámetro ahora es un 'int' en lugar de 'string' ---
void imprimirPatronRomboCentrado(int** matriz, int filaActual, int numFilas, int mitad, int columnasAImprimir, int numParesDeEspacios);


// --- Sin cambios en estas funciones ---
void imprimirColumnasPatron1(int** matriz, int filaActual, int columnaActual, int columnasTotales) {
	if (columnaActual >= columnasTotales) {
		return;
	}
	*(*(matriz + filaActual) + columnaActual) = columnaActual + 1;
	cout << *(*(matriz + filaActual) + columnaActual) << " ";
	imprimirColumnasPatron1(matriz, filaActual, columnaActual + 1, columnasTotales);
}

void imprimirPatronRomboIzquierdo(int** matriz, int filaActual, int numFilas, int mitad, int columnasAImprimir) {
	if (filaActual >= numFilas) {
		return;
	}
	imprimirColumnasPatron1(matriz, filaActual, 0, columnasAImprimir);
	cout << endl;
	int siguientesColumnas;
	if (filaActual >= (mitad - 1)) {
		siguientesColumnas = columnasAImprimir + 1;
	}
	else {
		siguientesColumnas = columnasAImprimir - 1;
	}
	imprimirPatronRomboIzquierdo(matriz, filaActual + 1, numFilas, mitad, siguientesColumnas);
}

void imprimirColumnasPatron2(int** matriz, int filaActual, int columnaActual) {
	if (columnaActual < 0) {
		return;
	}
	*(*(matriz + filaActual) + columnaActual) = columnaActual + 1;
	cout << *(*(matriz + filaActual) + columnaActual) << " ";
	imprimirColumnasPatron2(matriz, filaActual, columnaActual - 1);
}

// --- AÑADIDO: Funcion recursiva para imprimir espacios sin usar string ---
// Esta función imprime "  " (dos espacios) un número determinado de veces
void imprimirEspacios(int cantidad) {
	// Caso base: si no quedan espacios por imprimir, terminamos
	if (cantidad <= 0) {
		return;
	}
	// Acción y llamada recursiva: imprime dos espacios y llama para el resto
	cout << "  ";
	imprimirEspacios(cantidad - 1);
}


// --- MODIFICADO Y COMPLETADO: Función recursiva principal para el segundo patron ---
// Ahora usa un contador de enteros para los espacios
void imprimirPatronRomboCentrado(int** matriz, int filaActual, int numFilas, int mitad, int columnasAImprimir, int numParesDeEspacios) {
	// Caso base: si ya hemos procesado todas las filas, terminamos
	if (filaActual >= numFilas) {
		return;
	}

	// Accion: Llamar a la nueva función para imprimir los espacios
	imprimirEspacios(numParesDeEspacios);

	// La impresion de los números no cambia
	imprimirColumnasPatron2(matriz, filaActual, columnasAImprimir - 1);
	cout << endl;

	// Logica para determinar los parametros para la siguiente fila
	int siguientesColumnas;
	int siguientesParesDeEspacios;

	if (filaActual >= (mitad - 1)) {
		siguientesColumnas = columnasAImprimir + 1;
		siguientesParesDeEspacios = numParesDeEspacios - 1; // Quitar un par de espacios
	}
	else {
		siguientesColumnas = columnasAImprimir - 1;
		siguientesParesDeEspacios = numParesDeEspacios + 1; // Añadir un par de espacios
	}

	// Llamada recursiva: pasar a la siguiente fila
	imprimirPatronRomboCentrado(matriz, filaActual + 1, numFilas, mitad, siguientesColumnas, siguientesParesDeEspacios);
}


int main()
{
	int size = 15;
	if (size % 2 == 0) size++;

	int** matrix = new int* [size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
	}

	int rows = size;
	int mitad = (size + 1) / 2;

	cout << " ----------------- Rombo izquierdo con recursión" << endl;
	imprimirPatronRomboIzquierdo(matrix, 0, rows, mitad, mitad);


	cout << "\n ----------------- Rombo centrado e invertido con recursión" << endl;
	// --- MODIFICADO: La llamada inicial ahora pasa un 0 para el contador de espacios ---
	imprimirPatronRomboCentrado(matrix, 0, rows, mitad, mitad, 0);


	for (int i = 0; i < size; i++) {
		delete[] * (matrix + i);
	}
	delete[] matrix;

	return 0;
}

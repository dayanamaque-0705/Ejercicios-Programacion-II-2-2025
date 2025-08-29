#include <iostream>
using namespace std;
void factorial(int n, int resultado =1)
{
	if (n == 0 || n == 1) {
		cout << "El factorial es: " << resultado << endl;
		return;
	}
	factorial(n - 1, resultado * n); 
}
void calcularPromedio(int v[], int n, int i, int suma=0) {
	if (i == n) 
	{
		float promedio = (float)suma / n;
		cout << "El promedio del vector es: " << promedio << endl;
		return;
	}
	calcularPromedio(v, n, i + 1, suma + v[i]);
}

int main()
{
	cout << "====================" << endl;
	cout << "EJERCICIO 1 HALLAR PROMEDIO" << endl;
	cout << "====================" << endl;
	const int tam = 100;
	int n;
	int numfact;
	cout << "ingrese el tamano del vector" << endl;
	cin >> n;
	
	int vec[tam];
	for (int i = 0; i < n; i++)
	{
		cout << "ingrese un valor para el vector" << endl;
		cin >> vec[i];
	}
	calcularPromedio(vec, n, 0, 0);
	
		cout << "====================" << endl;
	cout << "EJERCICIO 2 HALLAR FACTORIAL" << endl;
		cout << "====================" << endl;
		cout << "ingrese un numero del que quiera averiguar su factorial" << endl;
		cin >> numfact;
		int resultado = 1;
		factorial(numfact,resultado);
}

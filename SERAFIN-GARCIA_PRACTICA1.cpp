1.-
int* enterodinamico = new int;
*enterodinamico = 12;
cout << "Entero dinámico: " << *enterodinamico << endl;
delete enterodinamico;
2.-

#include <iostream>
using namespace std;

int main() {
 
    int n;
    cout << "diga el tamaño n: " << endl;
    cin >> n;
    int* arrain = new int[n];
    for (int i = 0; i < n; i++)
    {
        arrain[i] = (i + 1);
    }
    for (int i = 0; i < n; i++)
    {
        cout << arrain[i] << "--";
    }
    delete[] arrain;
    return 0;
}

3.-

#include <iostream>
using namespace std;

int main() {

    int n, contador = 0;
    int suma = 0;
    cout << "diga el tamaño n: " << endl;
    cin >> n;
    int* arrain = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> contador;
        *(arrain + i) = contador;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arrain[i] << "--";
    }

    for (int i = 0; i < n; i++)
    {
        suma += *(arrain + i);
    }
    cout << suma << endl;

    delete[] arrain;
    return 0;
}

4.-
#include <iostream>
using namespace std;

int main() {

    int n, contador = 0;
    int suma = 0;
    cout << "diga el tamaño n: " << endl;
    cin >> n;

    int* arrai = new int[n];

    for (int i = 0; i < n; i++)
    {
        *(arrai + i) = i + 1;
    }


    // inicializar
    int maximo = *arrai;
    int minimo = *arrai;

    // recorrer
    for (int i = 1; i < n; i++) {
        if (*(arrai + i) > maximo) maximo = *(arrai + i);
        if (*(arrai + i) < minimo) minimo = *(arrai + i);
    }

    cout << "Maximo = " << maximo << endl;
    cout << "Minimo = " << minimo << endl;

    delete[] arrai;
    return 0;
}

5.-

#include <iostream>
using namespace std;

int main() {
    int n;
    float sumartodo = 0;

    cout << "Escriba el tamaño que sea: ";
    cin >> n;

    float* arrai = new float[n];

    for (int i = 0; i < n; i++) {
        *(arrai + i) = i + 1; // llenado con valores de ejemplo
    }

    for (int i = 0; i < n; i++) {
        sumartodo += *(arrai + i);
    }

    cout << "El promedio es: " << sumartodo / n << endl;

    delete[] arrai; // liberar memoria

    return 0;
}


6.-

#include <iostream>
using namespace std;

int devolvernumerospares(int arrai[], int tam,int pares)
{
	for (int i = 0; i < tam; i++)
	{
		if (*(arrai+i)%2==0)
		{
			pares++;
		}
	}
	return pares;
}



int main() {

	int tam = 0, pares=0;
	cout << "escriba tamaño: " << endl;
	cin >> tam;
	int* arrai = new int[tam];
	for (int i = 0; i < tam; i++)
	{
		*(arrai + i) = i*2;
	}
	cout << "hay la siguiente cantidad de pares: " << devolvernumerospares(arrai, tam, pares);

    return 0;
}

7.-

#include <iostream>
using namespace std;

void mostrar(int arrai[], int tam)
{
	for (int i = 0; i < tam; i++)
	{
		cout << *(arrai + i) << "--";
	}
}

void duplicar(int arrai[], int tam)
{
	for (int i = 0; i < tam; i++)
	{
		*(arrai + i) = *(arrai + i) * 2;
	}
	mostrar(arrai, tam);
}



int main() {

	int tam = 0;
	cout << "escriba tamaño: " << endl;
	cin >> tam;
	int* arrai = new int[tam];
	for (int i = 0; i < tam; i++)
	{
		*(arrai + i) = i+1;
	}
	duplicar(arrai, tam);

    return 0;
}

8.-

#include <iostream>
using namespace std;

int* voltear(int arrai[], int tam)
{
    int descontador = tam-1;
    int* volteadoarrai = new int[tam];
    for (int i = 0; i < tam; i++)
    {
        *(volteadoarrai + i) = *(arrai + descontador);
        descontador--;
    }

    return volteadoarrai;
}

int main() {

    int tam;
    cout << "tamaño ingresar: " << endl;
    cin >> tam;

    int* arrai = new int[tam];
    for (int i = 0; i < tam; i++)
    {
        *(arrai + i) = i + 1;
    }

    int* volteadoarrai = voltear(arrai, tam);

    for (int i = 0; i < tam; i++)
    {
        cout << *(volteadoarrai + i) << "--";
    }

delete[] arrai;
delete[] volteadoarrai;

    return 0;
}

9.-

#include <iostream>
#include <conio.h>
using namespace std;

void llenar(int* arrei, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        *(arrei + i) = i + 1;
    }
}

void mostrar(int arrei[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        cout<< *(arrei + i) << "--";
    }
}

int encontrar(int arrei[], int tam, int numero)
{
    int posicion = 0;
    for (int i = 0; i < tam; i++)
    {
        if (numero == *(arrei + i))
        {
            return posicion;
        }
        else
            posicion++;
    }
}
int main() {

    int tam, numero;
    cout << "escriba el tamaño porfavor: " << endl;
    cin >> tam;
    int* arrei = new int[tam];

    llenar(arrei, tam);

    mostrar(arrei, tam);
    cout << endl;

    cout << "ingrese el numero a encontrar: " << endl;

    cin >> numero;

    cout<< "la posicion es: "<<encontrar(arrei, tam, numero);

    return 0;
}






10.-


#include <iostream>
#include <conio.h>
using namespace std;

void llenar(int* arrei, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        *(arrei + i) = i + 1;
    }
}

void mostrar(int arrei[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        cout<< *(arrei + i) << "--";
    }
}

int* sumar(int arrai1[], int arrai2[], int tam)
{
    int* suma = new int[tam];
    for (int i = 0; i < tam; i++)
    {
        *(suma + i) = *(arrai1 + i) + *(arrai2 + i);
    }
    return suma;
}

int main() {

    int tam;
    cout << "escriba el tamaño 1 porfavor: " << endl;
    cin >> tam;

    int* arrai1 = new int[tam];
    int* arrai2 = new int[tam];

    llenar(arrai1, tam);
    llenar(arrai2, tam);

    int* sumararrai = sumar(arrai1, arrai2, tam);

    mostrar(sumararrai, tam);
    
    delete[] arrai1;
    delete[] arrai2;
    delete[] sumararrai;
    return 0;
}


11.-


#include <iostream>
#include <conio.h>
using namespace std;

void llenar(int** matrix, int filas, int columnas)
{
    int numeros = 1;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            *(*(matrix + i) + j) = numeros;
            numeros++;
        }

    }
}

void mostrar(int** matrix, int filas, int columnas)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << *(*(matrix + i) + j)<<"-";
        }
        cout << endl;
    }

}

int main() {
    int filas = 2, columnas = 3;
    int** matrix = new int* [2];
    for (int i = 0; i < filas; i++)
    {
        matrix[i] = new int[columnas];
    }

    llenar(matrix, filas, columnas);

    mostrar(matrix, filas, columnas);
    
    return 0;
}


12.-

#include <iostream>
#include <conio.h>
using namespace std;

void llenar(int** matrix, int filas, int columnas)
{
    int numeros = 1;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            *(*(matrix + i) + j) = numeros;
            numeros++;
        }

    }
}

void mostrar(int** matrix, int filas, int columnas)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << *(*(matrix + i) + j)<<"-";
        }
        cout << endl;
    }

}

int* sumarfilas(int** matrix, int fila, int columnas)
{
    int contadorfila = 0;
    int* vectorsum = new int[fila];
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columnas; j++) 
        {
            contadorfila += *(*(matrix + i) + j);
        }
        *(vectorsum + i) = contadorfila;
        contadorfila = 0;
    }
    return vectorsum;
}


int main() {
    int filas = 2, columnas = 3;
    int** matrix = new int* [filas];
    for (int i = 0; i < filas; i++)
    {
        *(matrix + i) = new int[columnas];
    }
    llenar(matrix, filas, columnas);

    mostrar(matrix, filas, columnas);
    cout << endl;
    int* vectorsuma = sumarfilas(matrix, filas, columnas);
    for (int i = 0; i < filas; i++)
    {
        cout << *(vectorsuma + i)<<"--";
    }

    for (int i = 0; i < filas; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] vectorsuma;

    return 0;
}

13.-


#include <iostream>
#include <conio.h>
using namespace std;

void llenar(int** matrix, int filas, int columnas)
{
    int numeros = 1;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            *(*(matrix + i) + j) = numeros;
            numeros++;
        }

    }
}

void mostrar(int** matrix, int filas, int columnas)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << *(*(matrix + i) + j) << "-";
        }
        cout << endl;
    }

}

int* sumarcolumnas(int** matrix, int fila, int columnas)
{
    int contadorfila = 0;
    int* vectorsum = new int[fila];
    for (int j = 0; j < columnas; j++)

    {
        for (int i = 0; i < fila; i++)
        {
            contadorfila += *(*(matrix + i) + j);
        }
        *(vectorsum + j) = contadorfila;
        contadorfila = 0;
    }
    return vectorsum;
}


int main() {
    int filas = 2, columnas = 3;
    int** matrix = new int* [filas];
    for (int i = 0; i < filas; i++)
    {
        *(matrix + i) = new int[columnas];
    }
    llenar(matrix, filas, columnas);

    mostrar(matrix, filas, columnas);
    cout << endl;
    int* vectorsuma = sumarcolumnas(matrix, filas, columnas);
    for (int i = 0; i < columnas; i++)
    {
        cout << *(vectorsuma + i) << "--";
    }

    for (int i = 0; i < filas; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] vectorsuma;

    return 0;
}

14.-

#include <iostream>
#include <conio.h>
using namespace std;

void llenar(int** matrix, int filas, int columnas)
{
    int numeros = 1;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            *(*(matrix + i) + j) = numeros;
            numeros++;
        }

    }
}

void mostrar(int** matrix, int filas, int columnas)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << *(*(matrix + i) + j) << "-";
        }
        cout << endl;
    }

}

int sumadiagonal(int** matrix, int fila, int columnas)
{
    int sumad = 0;
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (i == j)
            {
                sumad += *(*(matrix + i) + j);
            }
        }
        
    }
    return sumad;
}


int main() {
    int filas = 3, columnas = 3;
    int** matrix = new int* [filas];
    for (int i = 0; i < filas; i++)
    {
        *(matrix + i) = new int[columnas];
    }
    llenar(matrix, filas, columnas);

    mostrar(matrix, filas, columnas);
    cout << endl;

    cout<<sumadiagonal(matrix, filas, columnas);

    
    for (int i = 0; i < filas; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}


15.- 

#include <iostream>
#include <conio.h>
using namespace std;

void llenar(int** matrix, int filas, int columnas)
{
    int numeros = 1;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            *(*(matrix + i) + j) = numeros;
            numeros++;
        }

    }
}

void mostrar(int** matrix, int filas, int columnas)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << *(*(matrix + i) + j) << "-";
        }
        cout << endl;
    }

}

int sumadiagonal(int** matrix, int fila, int columnas)
{
    int sumad = 0;
    for (int i = 0; i < fila; i++)
    {
        // j se calcula directamente
        int j = fila - 1 - i;
        sumad += *(*(matrix + i) + j);
    }
    return sumad;
}


int main() {
    int filas = 3, columnas = 3;
    int** matrix = new int* [filas];
    for (int i = 0; i < filas; i++)
    {
        *(matrix + i) = new int[columnas];
    }
    llenar(matrix, filas, columnas);

    mostrar(matrix, filas, columnas);
    cout << endl;

    cout<<sumadiagonal(matrix, filas, columnas);

    
    for (int i = 0; i < filas; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

16.-

#include <iostream>
#include <conio.h>
using namespace std;

void llenar(int** matrix, int filas, int columnas)
{
    int numeros = 1;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            *(*(matrix + i) + j) = numeros;
            numeros++;
        }

    }
}

void mostrar(int** matrix, int filas, int columnas)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << *(*(matrix + i) + j) << "-";
        }
        cout << endl;
    }   

}

void sumadiagonal(int** matrix1, int fila, int columnas, int** matrix2, int** matrix3)
{
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            *(*(matrix3 + i) + j) = *(*(matrix1 + i) + j) + *(*(matrix2 + i) + j);
        }
        
    }
}


int main() {
    int filas = 3, columnas = 3;
    int** matrix1 = new int* [filas];
    for (int i = 0; i < filas; i++)
    {
        *(matrix1 + i) = new int[columnas];
    }
    llenar(matrix1, filas, columnas);

    mostrar(matrix1, filas, columnas);
    cout << endl;


    int** matrix2 = new int* [filas];
    for (int i = 0; i < filas; i++)
    {
        *(matrix2 + i) = new int[columnas];
    }
    llenar(matrix2, filas, columnas);

    mostrar(matrix2, filas, columnas);
    cout << endl;

    int** matrix3 = new int* [filas];
    for (int i = 0; i < filas; i++)
    {
        *(matrix3 + i) = new int[columnas];
    }
    llenar(matrix3, filas, columnas);

    sumadiagonal(matrix2, filas, columnas,matrix1,matrix3);



   
    mostrar(matrix3, filas, columnas);
    cout << endl;



    for (int i = 0; i < filas; i++) {
        delete[] matrix1[i];
    }
    delete[] matrix1;

    for (int i = 0; i < filas; i++) {
        delete[] matrix2[i];
    }
    delete[] matrix2;

    return 0;
}



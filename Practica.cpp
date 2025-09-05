
using namespace std;
#include <iostream>

//Practica 1 
 
// Para correr cualquier ejercicio solo debe eliminar los /**/ en el que desea correr y hacer lo mismo en el main.

//Ejercicio1
/*
int* entero()
{
    int* ptr = new int;
    *ptr = 42;
    cout << "Valor del entero: " << *ptr << endl;
    delete ptr;
    return 0;
}
*/
//Ejercicio2
/*
int* crearArreglo(int n) 
{
        int* arreglo = new int[n]; 
        for (int i = 0; i < n; i++) 
        {
            *(arreglo + i) = i + 1;  
        }
        return arreglo;
}
void imprimirArregloRecursivo(int* arreglo, int n, int indice = 0) 
{
    if (indice >= n) 
    {
        cout << endl;
        return;
    }
    cout << *(arreglo + indice) << " ";
    imprimirArregloRecursivo(arreglo, n, indice + 1);

    for (int i = 0; i < n; i++)
    {
        *(arreglo + i) = i + 1;
    }
    delete[] arreglo;
}
*/
//Ejercicio3
/*
int suma(int* arr, int n, int sum = 0, int i=0)
{
    if (i >= n)
    {
        return sum;
    }
    else
    {
        sum = sum + *(arr + i);
        return suma(arr, n, sum, i + 1);
    }
}
void ejercicio3()
{
    int n;
    int sum = 0;
    cout << "cual sera el tamaño" << endl;
    cin >> n;
    int* arr = new int;
    for (int i = 0; i < n; i++)
    {
        cout << "introduzca valor " << i + 1 << " ";
        cin >> *(arr + i);
    }
    cout << endl<< "la suma es: " << suma(arr, n);
}
*/
//Ejercicio4
/*
void maxMin(int* arr, int tam,int m, int max = 0, int i=0)
{
    if (i >= tam)
    {
        cout << "el numero mas grande es: " << max << endl;
        cout << "el numero mas chequeto es: " << m << endl;
        return;
        
    }
    if (*(arr + i) > max)
    {
        max = *(arr + i);
    }
    if (*(arr + i) < m)
    {
        m = *(arr + i);
    }
    maxMin(arr, tam,m, max, i + 1);   
}
void ejercicio4()
{
    int m=0;
    int n;
    cout << "cuantos numeros en el array?" << endl;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "elemento del array " << i << ": ";
        cin >> *(arr + i);
    }
    maxMin(arr, n, *(arr+0));
}
*/
//Ejercicio5
/*void promedio(int* arr, int n, float suma = 0, float prom = 0, int i = 0)
{
    if (i >= n)
    {
        prom = suma / n;
        cout << "el promedio es " << prom;
        return;
    }
    else
    {
        suma = suma + *(arr + i);
        promedio(arr, n, suma, prom, i + 1);
    }
}

void ej5()
{
    int n;
    cout<<"cuantos numeros?:" ;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "elemento: " << i << ": ";
        cin >> *(arr + i);
    }
    promedio(arr, n);
        
}
*/
//Ejercicio6
/*
void numPares(int* arr, int n, int cont=0, int i=0)
{
    if (n <= i)
    {
        cout << "hay " << cont << " pares";
        return;
    }
    else
    {
        if (*(arr + i) % 2 == 0)
        {
            cont=cont + 1;
        }
        numPares(arr, n, cont, i + 1);
    }
}
void ej6()
{
    int n;
    cout << "cuantos numeros en el array?" << endl;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "elemento del array " << i << ": ";
        cin >> *(arr + i);
    }
    numPares(arr, n);
}
*/
//Ejercicio7
/*
void duplicarArray(int* arr, int n, int i=0)
{
    if (n <= i)
    {
        for (int i = 0; i < n; i++)
        {
            cout << *(arr+i) << " ,";
        }
        return;
    }
    else
    {
        *(arr + i) = *(arr + i) * 2;
        duplicarArray(arr, n, i + 1);
    }
}
void ej7()
{
    int n;
    cout << "cuantos numeros en el array?" << endl;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "elemento del array " << i << ": ";
        cin >> *(arr + i);
    }
    duplicarArray(arr, n);
}
*/
//Ejercicio8
/*
void invertirArray(int* arr,int* arrinver, int tam, int i2, int i=0)
{
    if (i >= tam)
    {
        for (int i = 0; i < tam; i++)
        {
            cout << *(arrinver + i)<<", ";
        }
        return;
    }
    else
    {
        *(arrinver + i) = *(arr + i2);
        invertirArray(arr, arrinver, tam, i2 - 1, i + 1);
    }

}
void ej8()
{
    int n;
    cout << "tam de array: ";
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "elemento " << i << endl;
        cin >> *(arr + i);
    }
    int* arrin = new int[n];
    int i2 = n - 1;
    invertirArray(arr, arrin, n, i2);
}
*/
//Ejercicio9
/*
void devolverPosicion(int* arr, int tam, int num, int i=0)
{
    if (*(arr + i) == num)
    {
        cout << "el numero esta en la posicion " << i + 1;
        return;
    }
    if (i >= tam)
    {
        cout << "no se encontro el numero";
        return;
    }
    else
    {
        devolverPosicion(arr, tam, num, i + 1);
    }
}
void ej9()
{
    int n;
    cout << "tam de array: ";
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "elemento " << i << endl;
        cin >> *(arr + i);
    }
    int num;
    cout << "que numero quiere buscar?: ";
    cin >> num;
    cout << endl;
    devolverPosicion(arr, n, num);
}
*/
//Ejercicio10
/*
void arraySuma(int* arr, int* arr2, int* arr3, int tam, int i=0)
{
    if (i >= tam)
    {
        cout << "La suma total: "<<endl;
        for (int i = 0; i < tam; i++)
        {
            cout << *(arr3 + i) << ", ";
        }
        return;
    }
    else
    {
        *(arr3 + i) = *(arr + i) + *(arr2 + i);
        arraySuma(arr, arr2, arr3, tam, i + 1);
    }
}
void ej10()
{
    int n;
    cout << "tam de array: ";
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "elemento " << i << endl;
        cin >> *(arr + i);
    }
    int* arr2 = new int[n];
    cout << endl << "Segundo array..."<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << "elemento " << i << endl;
        cin >> *(arr2 + i);
    }
    int* arr3 = new int[n];
    arraySuma(arr, arr2, arr3, n);
}
*/
//Ejercicio 11
/*
void llenarMatriz(int** m, int f, int c, int i=0, int j=0, int cont=1)
{
    if (i >= f)
    {
        for (int i = 0; i < f; i++) 
        {
                for (int j = 0; j < c; j++) 
                {
                    cout << *(*(m + i) + j) << ", ";
                }
                cout << endl;
        }
        
        return;
    }
    if (j == c)
    {
        *(*(m + i) + j) = cont;
        llenarMatriz(m, f, c, i + 1, 0, cont);
    }
    else
    {
        *(*(m + i) + j) = cont;
        llenarMatriz(m, f, c, i, j+1, cont + 1);
    }
}
void ej11()
{
    int filas, columnas;
    cout << "Ingrese el número de filas (n): ";
    cin >> filas;
    cout << "Ingrese el número de columnas (m): ";
    cin >> columnas;
    int** matriz = new int* [filas];
    for (int i = 0; i < filas; i++) 
    {
        matriz[i] = new int[columnas];
    }
    llenarMatriz(matriz, filas, columnas);
}
*/
//Ejercicio 12
/*
void sumarFilas(int** m, int* v, int f, int c, int i = 0, int j = 0, int suma=0)
{
    if (i >= f)
    {
        cout << " Las sumas totales son: " << endl;
        for (int i = 0; i < f; i++)
        {
            cout << *(v+i) << ", ";           
        }
        cout << endl;
        return;
    }
    if (j == c)
    {
        *(v + i) = suma;
        sumarFilas(m, v, f, c, i + 1, 0, 0);
    }
    else
    {
        suma = suma + *(*(m + i) + j);
        sumarFilas(m, v, f, c, i, j+1, suma);
    }
}

void ej12()
{
    int filas;
    int columnas;
    cout << "cuantas filas? " << endl;
    cin >> filas;
    cout << "cuantas columnas? " << endl;
    cin >> columnas;
    int** matriz = new int* [filas];
    for (int i = 0; i < filas; i++)
    {
        *(matriz + i) = new int[columnas];
    }
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << "Posición " << i + 1 << ", " << j + 1 << ": ";
            cin >> *(*(matriz + i) + j);
        }
    }
    int* arr = new int[filas];
    sumarFilas(matriz, arr, filas, columnas);
}
*/
//Ejercicio 13
/*
void sumaColumnas(int** m,int* v, int f, int c, int i=0, int j=0, int suma=0 )
{
    if (j >= c)
    {
        cout << " Las sumas totales son: " << endl;
        for (int j = 0; j < c; j++)
        {
            cout << *(v + j) << ", ";
        }
        cout << endl;
        return;
    }
    if (i == f)
    {
        *(v + j) = suma;
        sumaColumnas(m, v, f, c, 0, j+1, 0);
    }
    else
    {
        suma = suma + *(*(m + i) + j);
        sumaColumnas(m, v, f, c, i+1, j, suma);
    }

}
void ej13()
{
    int filas;
    int columnas;
    cout << "cuantas filas? " << endl;
    cin >> filas;
    cout << "cuantas columnas? " << endl;
    cin >> columnas;
    int** matriz = new int* [filas];
    for (int i = 0; i < filas; i++)
    {
        *(matriz + i) = new int[columnas];
    }
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << "Posición " << i + 1 << ", " << j + 1 << ": ";
            cin >> *(*(matriz + i) + j);
        }
    }
    int* arr = new int[columnas];
    sumaColumnas(matriz, arr, filas, columnas);
}
*/
//Ejercicio 14
/*
void sumaDiagonalPrincipal(int** m, int tam, int i=0, int suma=0, int j=0)
{
    if (i >= tam)
    {
        cout << "La suma total de la diagonal principal es: " << suma;
        return;
    }
    else
    {
        if (j == tam)
        {
            sumaDiagonalPrincipal(m, tam, i + 1, suma, 0);
        }
        if (i == j)
        {
            suma = suma + *(*(m + i) + j);
            if (j == tam)
            {
                sumaDiagonalPrincipal(m, tam, i + 1, suma, 0);
            }
            sumaDiagonalPrincipal(m, tam, i, suma, j + 1);
        }
        else
        {
            sumaDiagonalPrincipal(m, tam, i, suma, j + 1);
        }
            
    }
}
void ej14()
{
    int tam;
    cout << "Cual es el tamanio? " << endl;
    cin >> tam;
    int** matriz = new int* [tam];
    for (int i = 0; i < tam; i++)
    {
        *(matriz + i) = new int [tam];  
    }
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            cout << "Posición " << i + 1 << ", " << j + 1 << ": ";
            cin >> *(*(matriz + i) + j);
        }
    }

    sumaDiagonalPrincipal(matriz, tam);
}
*/
//Ejercicio 15
/*
void sumaDiagonalSecundaria(int** m, int tam, int j, int i = 0, int suma = 0)
{
    if (i >= tam)
    {
        cout << "La suma total es: " << suma << endl;
        return;
    }  
    else
    {
        suma = suma + *(*(m + i) + j);
        sumaDiagonalSecundaria(m, tam, j - 1, i + 1, suma);
    }
}
void ej15()
{
    int tam;
    cout << "tamanio " << endl;
    cin >> tam;
    int** matriz = new int* [tam];
    for (int i = 0; i < tam; i++)
    {
        *(matriz + i) = new int [tam];
    }
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0 ; j < tam; j++)
        {
            cout << "ingrese prosicion " << i << ", " << j << endl;
            cin >> *(*(matriz + i) + j);
        }
    }
    int j = tam-1;
    sumaDiagonalSecundaria(matriz, tam, j);
}
*/
//Ejercicio 16
/*
void sumaMatrices(int** m1, int** m2,int** m3, int f, int c, int i = 0, int j = 0)
{
    if(i>=f)
    {
        for (int x = 0; x < f; x++)
        {
            for (int y = 0; y < c; y++)
            {
                cout << *(*(m3 + x) + y) << ", ";
            }
            cout << endl;
        }
        return;
    }
    else
    {
        if (j >= c)
        {
            *(*(m3 + i) + j) = *(*(m1 + i) + j) + *(*(m2 + i) + j);
            sumaMatrices(m1, m2,m3, f, c, i + 1, 0);
            return;
        }
        *(*(m3 + i) + j) = *(*(m1 + i) + j) + *(*(m2 + i) + j);
        sumaMatrices(m1, m2, m3, f, c, i, j+1);
        
    }
}

void ej16()
{
    int filas;
    int columnas;
    cin >> filas;
    cin >> columnas;
    int** m = new int* [filas];
    for (int i = 0; i < filas; i++)
    {
        *(m + i) = new int[columnas];
    }
    cout << "matriz 1"<<endl;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << "ingrese el elemento " << i << ", " << j << endl;
            cin >> *(*(m + i) + j);
        }
    }
    int** m2 = new int* [filas];
    for (int i = 0; i < filas; i++)
    {
        *(m2 + i) = new int[columnas];
    }
    cout << "matriz 2" << endl;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << "ingrese el elemento " << i << ", " << j << endl;
            cin >> *(*(m2 + i) + j);
        }
    }
    int** m3 = new int* [filas];
    for (int i = 0; i < filas; i++)
    {
        *(m3+ i) = new int[columnas];
    }
    sumaMatrices(m, m2, m3, filas, columnas);  
}
*/
//Ejercicio 17  
/*
void ej17() {
    int N;
    cout << "Ingrese valor de N (impar): ";
    cin >> N;

    if (N % 2 == 0) {
        cout << "Error: N debe ser impar!" << endl;
        return;
    }

    int mitad = N / 2;
    int** m = new int* [N];
    for (int i = 0; i < N; i++) {
        int columnas;
        if (i <= mitad) {
            columnas = mitad + 1 - i;
        }
        else {
            columnas = i - mitad + 1;
        }
        *(m + i) = new int[columnas];
    }
    for (int i = 0; i < N; i++) {
        int columnas;
        if (i <= mitad) {
            columnas = mitad + 1 - i;
        }
        else {
            columnas = i - mitad + 1;
        }

        for (int j = 0; j < columnas; j++) {
            *(*(m + i) + j) = j + 1;
        }
    }
    cout << "\nEstructura generada:" << endl;
    for (int i = 0; i < N; i++) {
        int columnas;
        if (i <= mitad) {
            columnas = mitad + 1 - i;
        }
        else {
            columnas = i - mitad + 1;
        }

        for (int j = 0; j < columnas; j++) {
            cout << *(*(m + i) + j) << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < N; i++) {
        delete[] * (m + i);
    }
    delete[] m;
}
*/
//Ejercicio 18
/*
void LlenarMatriz(int** m, int N, int M, int mitad, int num = 1, int i=0, int j=0)
{
    if (i >= N)
    {
        return;
    }
    else
    {
        //segunda parte 
            if (i >= M)
            {
                if (j == M - 1)
                {
                    *(*(m + i) + j) = num;
                    LlenarMatriz(m, N, M, mitad, num + 1, i + 1, 0);
                    return;
                }
                else
                {
                    *(*(m + i) + j) = num;
                    LlenarMatriz(m, N, M, mitad, num, i, j + 1);
                    return;
                }
            }
        //segunda parte
        if (j >= N - 1)
        {
            *(*(m + i) + j) = num;
            LlenarMatriz(m, N, M, mitad, num+1, i+1, 0);
            return;
        }
        *(*(m + i) + j) = num;
        LlenarMatriz(m, N, M, mitad, num, i, j + 1);
        return;
    }
}
void ej18()
{
    int N;
    int M;
    cout << "ingrese el valor de N"<<endl;
    cin >> N;
    cout<<"ingrese el valor de M" << endl;
    cin >> M;
    int mitad = N / 2;
    int** matriz = new int* [N];
    //Reservar espacio
    for (int i = 0; i <= mitad; i++)
    {
        *(matriz+i) = new int[N];
    }
    for (int i = mitad + 1; i < N; i++)
    {
        *(matriz + i) = new int[M];
    }
    LlenarMatriz(matriz, N, M, mitad);
    //Mostrar
    for (int i = 0; i <= mitad; i++)
    {
        for (int j = 0; j <N; j++)
        {
            cout << " " << *(*(matriz + i) + j) << " ";
        }
        cout << endl;
    }
    for (int i = mitad+1; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << " " << *(*(matriz + i) + j) << " ";
        }
        cout << endl;
    }
}
*/
int main()
{
    //Ejercicio1 entero();
    //Ejercicio2 imprimirArregloRecursivo(crearArreglo(4), 4);
    //Ejercicio 3 ejercicio3();
    //Ejercicio 4 ejercicio4();
    //Ejercicios 5 ej5();
    //Ejercicio 6 ej6();
    //Ejercicio 7 ej7();
    //Ejercicio 8 ej8();
    //Ejercicio 9 ej9();
    //Ejercicio 10 ej10();
    //Ejercicio 11 ej11();
    //Ejercicio 12 ej12();
    //Ejercicio 13 ej13();
    //Ejercicio 14 ej14();
    //Ejercicio 15 ej15();
    //Ejercicio 16 ej16();
    //Ejercicio 17 ej17();
    //Ejercicio 18 ej18();
}



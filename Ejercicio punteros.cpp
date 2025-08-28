#include <iostream>
using namespace std;

void printUpper(int n) 
{
    for (int i = n; i >= 1; i--)
    {
        int* row = new int[i]; 
        for (int j = 0; j < i; j++)
        {
            *(row + j) = j + 1;
        }
       
        for (int j = i - 1; j >= 0; j--) 
        {
            cout << *(row + j);
        }
        cout << endl;
        delete[] row; 
    }
}

void printLower(int n) 
{
    for (int i = 2; i <= n; i++)
    {
        int* row = new int[i]; 
        for (int j = 0; j < i; j++) 
        {
            *(row + j) = j + 1;
        }

        for (int j = i - 1; j >= 0; j--) 
        {
            cout << *(row + j);
        }
        cout << endl;
        delete[] row; 
    }
}

int main()
{
    int n = 3; 
    printUpper(n);
    printLower(n);
    return 0;
}

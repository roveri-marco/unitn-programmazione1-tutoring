// Scrivere una funzione che prende in ingresso
// una matrice 3x5 e un array di 5 elementi e
// somma l’array ad ogni riga della matrice,
// elemento per elemento.

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void fun(int mat[3][5], int *arr) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            mat[i][j] += arr[j];
        }
    }
}

int main() {
    int arr[5];
    int mat[3][5];
    srand(time(NULL));

    cout << "matrix:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            mat[i][j] = rand() % 10;
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    cout << "array:" << endl;
    for (int i = 0; i < 5; i++) {
        arr[i] = rand() % 10;
        cout << arr[i] << ' ';
    }
    cout << endl << endl;

    fun(mat, arr);

    cout << "final matrix:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}

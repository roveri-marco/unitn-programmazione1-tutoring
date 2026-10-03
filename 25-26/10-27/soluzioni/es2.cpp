/*
 * Scrivere un programma che crea un array di
 * dimensione 10, lo riempie di valori casuali
 * tra 0 e 100 e lo stampa.
 * Poi calcola somma e prodotto tra tutti i valori
 * con delle funzioni, sia in modo iterativo che in
 * modo ricorsivo.
 */

#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int iter_sum(int *arr) {
    int s = 0;
    for (int i = 0; i < 10; i++) {
        s += arr[i];
    }
    return s;
}

long long int iter_mul(int *arr) {
    int m = 1;
    for (int i = 0; i < 10; i++) {
        m *= arr[i];
    }
    return m;
}

int rec_sum(int *arr, int i) {
    if (i == 10) {
        return 0;
    }
    return arr[i] + rec_sum(arr, i + 1);
}

long long int rec_mul(int *arr, int i) {
    if (i == 10) {
        return 1;
    }
    return arr[i] * rec_mul(arr, i + 1);
}

int main() {
    int arr[10];
    srand(time(NULL));

    cout << "[ ";
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << ' ';
    }
    cout << ']' << endl;

    cout << "Iter Sum: " << iter_sum(arr) << endl;
    cout << "Iter Mul: " << iter_mul(arr) << endl;
    cout << "Rec Sum:  " << rec_sum(arr, 0) << endl;
    cout << "Rec Mul:  " << rec_mul(arr, 0) << endl;

    return 0;
}

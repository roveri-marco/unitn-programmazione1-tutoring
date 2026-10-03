// Scrivere un programma che crea un array di
// dimensione 10 e lo riempie di valori casuali
// tra 0 e 100.
// Poi ne trova il minimo e il massimo tramite
// delle funzioni e li stampa a video.

#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

// include sia soluzioni iterative che ricorsive

int min_iter(int *arr) {
    int m = 1000;
    for (int i = 0; i < 10; i++) {
        m = min(m, arr[i]);
    }
    return m;
}

int max_iter(int *arr) {
    int M = 0;
    for (int i = 0; i < 10; i++) {
        M = max(M, arr[i]);
    }
    return M;
}

int min_rec(int *arr, int i) {
    if (i == 10) {
        return 1000;
    }
    return min(arr[i], min_rec(arr, i + 1));
}

int max_rec(int *arr, int i) {
    if (i == 10) {
        return 0;
    }
    return max(arr[i], max_rec(arr, i + 1));
}

int main() {
    int arr[10];
    srand(time(NULL));

    cout << "[ ";
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 10;
        cout << arr[i] << ' ';
    }
    cout << ']' << endl;

    cout << "Min: " << min_iter(arr) << endl;
    cout << "Max: " << max_iter(arr) << endl;
    cout << "Min (rec): " << min_rec(arr, 0) << endl;
    cout << "Max (rec): " << max_rec(arr, 0) << endl;

    return 0;
}

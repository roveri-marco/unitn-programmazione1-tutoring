// Scrivere un programma che crea un array di
// dimensione 10 e lo riempie di valori casuali
// tra 0 e 10.
// Poi chiede all’utente un numero tra 0 e 10
// e tramite una funzione lo cerca all’interno
// dell’array.
// La funzione ritorna l’indice della prima
// occorrenza del valore, altrimenti -1.
// Stampare quindi il risultato e anche l’array.
// (la funzione puo’ essere iterativa o ricorsiva a
// piacere)

#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int find_iter(int *arr, int x) {
    for (int i = 0; i < 10; i++) {
        if (arr[i] == x) {
            return i;
        }
    }

    return -1;
}

int find_rec(int *arr, int i, int x) {
    if (i == 10) {
        return -1;
    } else if (arr[i] == x) {
        return i;
    }

    return find_rec(arr, i + 1, x);
}

int main() {
    int x;
    int arr[10];
    srand(time(NULL));

    cout << "[ ";
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 10;
        cout << arr[i] << ' ';
    }
    cout << ']' << endl;

    cout << "Inserisci valore da ricercare: ";
    cin >> x;

    cout << "Indice: " << find_iter(arr, x) << endl;
    // oppure
    cout << "Indice, ricorsivo: " << find_rec(arr, 0, x) << endl;

    return 0;
}

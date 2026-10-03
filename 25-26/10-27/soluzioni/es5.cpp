// Implementare l’algoritmo di ordinamento
// BubbleSort per un array inizializzato con
// numeri casuali.

#define N 50

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>

using namespace std;

// 2 funzioni di esempio, iterativa e ricorsiva, che ordinano
// rispettivamente in ordine decrescente e crescente

// implementazione 'classica' di BubbleSort:
// si porta l'elemento piu' grande (o piccolo) alla fine
// e si continua considerando sottoinsiemi sempre piu' piccoli.
void bubblesort_iter(int *arr) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// versione ricorsiva, si capisce un po' meglio
void bubblesort_rec(int *arr, int i) {
    if (i == 0) {
        return;
    }

    // muove piu' grande alla fine
    for (int j = 0; j < i; j++) {
        if (arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]);
        }
    }

    // stessa operazione su sottoinsieme non ordinato
    bubblesort_rec(arr, i - 1);
}

int main() {
    int arr[N];
    srand(time(NULL));

    cout << "[ ";
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << ' ';
    }
    cout << ']' << endl;

    bubblesort_iter(arr);

    cout << "metodo iterativo:\n[ ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }
    cout << ']' << endl;

    bubblesort_rec(arr, N - 1);

    cout << "metodo ricorsivo:\n[ ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }
    cout << ']' << endl;

    return 0;
}

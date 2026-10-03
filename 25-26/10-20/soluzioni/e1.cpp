/*
Scrivi una funzione ricorsiva che stampa i
numeri interi da 0 a N, dato N in input.
*/

#include <iostream>

void stampaDaZeroAN(int n, int current = 0) {
    if (current > n) {
        return;
    }
    std::cout << current << std::endl;
    stampaDaZeroAN(n, current + 1);
}

int main() {
    int N;
    std::cout << "Inserisci un numero intero N: ";
    std::cin >> N;

    std::cout << "Numeri da 0 a " << N << ":" << std::endl;
    stampaDaZeroAN(N);

    return 0;
}
/*
Scrivi un programma che prende in input un
intero N e tramite una funzione ricorsiva
stampa una sequenza di numeri da 0 a N,
dove prima ci sono i numeri pari in ordine
crescente e poi i numeri dispari in ordine
decrescente.
*/

#include <iostream>

void stampaSequenza(int n, int current = 0) {
    if (current > n) {
        return;
    }
    if (current % 2 == 0) {
        std::cout << current << std::endl;
    }
    stampaSequenza(n, current + 1);
    if (current % 2 != 0) {
        std::cout << current << std::endl;
    }
}

int main() {
    int N;
    std::cout << "Inserisci un numero intero N: ";
    std::cin >> N;

    std::cout << "Sequenza da 0 a " << N << " (pari in ordine crescente, dispari in ordine decrescente):" << std::endl;
    stampaSequenza(N);

    return 0;
}

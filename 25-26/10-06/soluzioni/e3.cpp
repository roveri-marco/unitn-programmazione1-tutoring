#include <iostream>

/*
Scrivere un programma che prende in input
un numero intero e stampa a video se e’
un numero primo.
*/

int main () {
    int n;
    std::cout << "Digita un numero per scoprire se è primo: ";
    std::cin >> n;
    bool isPrime = true;
    if (n <= 1) {
        isPrime = false; // I numeri minori o uguali a 1 non sono primi
    } else {
        for (int i = 2; i <= n / 2; ++i) { // Controlla i divisori da 2 a n/2
            if (n % i == 0) {
                isPrime = false; // Trovato un divisore, quindi non è primo
                break;
            }
        }
    }

    if(isPrime) {
        std::cout << n << " è un numero primo." << std::endl;
    } else {
        std::cout << n << " non è un numero primo." << std::endl;
    }

    return 0;
}
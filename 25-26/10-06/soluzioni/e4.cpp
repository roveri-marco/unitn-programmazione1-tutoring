#include <iostream>

/*
Scrivere un programma che prende in input
un numero intero e stampa a video se e’
un numero perfetto.
Un numero si dice ‘perfetto’ quando la
somma di tutti i suoi divisori propri (tutti
tranne se stesso), e’ uguale al numero stesso.
*/

int main () {
    int n;
    std::cout << "Digita un numero per scoprire se è \"perfetto\": ";
    std::cin >> n;
    int sommaDivisori = 0;
    
    for (int i = 1; i <= n / 2; ++i) { // Trova i divisori propri fino a n/2
        if (n % i == 0) {
            sommaDivisori += i; // Aggiungi il divisore alla somma
        }
    }

    if(sommaDivisori == n && n != 1) {
        std::cout << n << " è un numero \"perfetto\"." << std::endl;
    } else {
        std::cout << n << " non è un numero \"perfetto\"." << std::endl;
    }

    return 0;
}
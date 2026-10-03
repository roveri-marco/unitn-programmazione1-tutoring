#include <iostream>

/*
Scrivere un programma che implementi una
calcolatrice per numeri interi, ossia che
prenda in ingresso due numeri e un carattere
('+','-','*','/') e che calcoli poi il risultato
dell'operazione.
*/

int main () {
    int n;
    double m, risultato;
    char operazione;
    std::cout << "Digita l'operazione (che usa questi operandi: +,-,*,/): ";
    std::cin >> n >> operazione >> m;
    
    if (operazione == '+') {
        risultato = n + m;
    } else if (operazione == '-') {
        risultato = n - m;
    } else if (operazione == '*') {
        risultato = n * m;
    } else if (operazione == '/') {
        if (m != 0) {
            risultato = n / m;
        } else {
            std::cout << "Errore: divisione per zero!" << std::endl;
            return 1; // Exit with error code
        }
    } else {
        std::cout << "Operazione non valida!" << std::endl;
        return 1; // Exit with error code
    }

    std::cout << "Risultato: " << risultato << std::endl;

    return 0;
}
#include <iostream>
/*
L'esercizio chiede di stampare i bordi di un triangolo con i 2 cateti di dimensione n, dove n e' un numero intero positivo
*/
int main() {
    int dimensione;
    std::cout << "Digita la dimensione dei 2 cateti del triangolo che vuoi stampare: ";
    std::cin >> dimensione;

    // ciclo esterno per le righe
    for (int i = 0; i < dimensione; ++i) {
        // ciclo interno per le colonne
        for (int j = 0; j < dimensione; ++j) {

            // queste 3 condizioni definiscono il fatto di dover stampare solo quando j e i sono rispettivamente 0 e dimension-1 (il che sono i 2 cateti del triangolo) e quando i è uguale a j, che è l'ipotenusa
            if(j==0 || i==dimensione-1 || i==j) std::cout << "X";
            else std::cout << " ";

        }
        std::cout << std::endl;
    }

    return 0;
}
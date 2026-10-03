#include <iostream>
/*
L'esercizio chiede di stampare i bordi di un quadrato di dimensione n, dove n e' un numero intero positivo
*/
int main() {
    int dimension;
    std::cout << "Enter the dimension of the square to be print: ";
    std::cin >> dimension;

    // ciclo esterno per le righe
    for (int i = 0; i < dimension; ++i) {
        // ciclo interno per le colonne
        for (int j = 0; j < dimension; ++j) {

            // queste 2 condizioni definiscono il fatto di dover stampare solo quando i e j sono 0 o dimension-1, quindi i bordi del quadrato
            if(i%(dimension-1)==0 || j%(dimension-1)==0) std::cout << "X";
            else std::cout << " ";

        }
        std::cout << std::endl;
    }

    return 0;
}
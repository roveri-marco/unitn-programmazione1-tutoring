#include <iostream>
/*
L'esercizio chiede di stampare un rombo di dimensioni n, dove n e' un numero intero positivo
Il rombo deve rispettare le seguenti condizioni:
-1 avere come caratteri per la sua punta ^ e come caratteri per la sua base v
-2 avere come caratteri per i suoi lati / e \
-3 avere come carattere per i suoi estremi destro e sinistro |
-4 il rombo deve avere come caratteri per la sua diagonale orizzontale - e come caratteri per la sua diagonale verticale |
-5 spazi vuoti al suo interno
*/
int main() {
    int dimensione;
    std::cout << "Digita la dimensione del quadrato che vuoi stampare: ";
    std::cin >> dimensione;

    // ciclo esterno per le righe
    for (int i = 0; i < dimensione; ++i) {
        // ciclo interno per le colonne
        for (int j = 0; j < dimensione; ++j) {

            if(i==0 && j==dimensione/2) std::cout << "^";
            else if(i==dimensione-1 && j==dimensione/2) std::cout << "v";
             else if(j%(dimensione-1)==0 && i==dimensione/2) std::cout << "|";
            else if(i==dimensione/2) std::cout << "-";
            else if(j==dimensione/2) std::cout << "|";
            else if(i+j==dimensione/2) std::cout << "/";
            else if(j-i==dimensione/2) std::cout << "\\";
            else if(i-j==dimensione/2) std::cout << "\\";
            else if(i+j==dimensione-1+dimensione/2) std::cout << "/";
            else std::cout << " ";

        }
        std::cout << std::endl;
    }

    return 0;
}
#include <iostream>

/*
L'esercizio chiede di stampare una piramide dei multipli di 2 di altezza n, dove n e' un numero intero positivo
*/

int main () {
    int dimensione;
    std::cout << "Digita la dimensione della piramide che vuoi stampare: ";
    std::cin >> dimensione;
    int numero=1;
    // ciclo esterno per le righe
    for (int i = 0; i < dimensione; ++i) {
        numero = 1; // resetto il numero a 1 ad ogni nuova riga
        // ciclo interno per le colonne
        for (int j = 0; j <= dimensione*2; ++j) {
            
            // stampa quando j+i è maggiore o uguale a dimensione (per far si che la piramide inizi a stampare dopo un certo numero di spazi) e j è minore di dimensione (per far si che la piramide smetta di stampare al centro), oppure quando j+i è maggiore o uguale a dimensione e j è minore o uguale a dimensione+i (per far si che la piramide smetta di stampare dopo un certo numero di spazi)
            if(j+i>=dimensione && j<dimensione) {
                std::cout << numero << " ";
                numero*=2;
            }
            else if(j+i>=dimensione && j<=dimensione+i) {
                std::cout << numero << " ";
                numero/=2;
            }
            else std::cout << "  "; // 2 spazi perche' i numeri sono separati da uno spazio
        }
        std::cout << std::endl;
    }


    return 0;
}
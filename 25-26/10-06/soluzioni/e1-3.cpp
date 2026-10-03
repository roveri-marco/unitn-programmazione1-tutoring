#include <iostream>
/*
L'esercizio chiede di stampare i bordi di un quadrato di dimensione n e le sue diagonali, dove n e' un numero intero positivo
*/
int main() {
    int dimensione;
    std::cout << "Digita la dimensione del quadrato che vuoi stampare: ";
    std::cin >> dimensione;

    // ciclo esterno per le righe
    for (int i = 0; i < dimensione; ++i) {
        // ciclo interno per le colonne
        for (int j = 0; j < dimensione; ++j) {

            // le prime 2 condizioni definiscono il fatto di dover stampare solo quando i e j sono 0 o dimension-1, quindi i bordi del quadrato, invece le 2 condizioni successive definiscono le diagonali (questo può essere pensato anche come la funzione della retta y=x e y=-x in un piano cartesiano)
            if(j%(dimensione-1)==0 || i%(dimensione-1)==0 || i==j || i==(dimensione-1-j)) std::cout << "X";
            else std::cout << " ";

        }
        std::cout << std::endl;
    }

    return 0;
}
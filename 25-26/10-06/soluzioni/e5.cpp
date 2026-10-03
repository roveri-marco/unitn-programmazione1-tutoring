#include <iostream>

/*
Scrivere un programma che prende prende in
input un double.
Poi lo raddoppia usando un puntatore a quella
variabile (double*).
E poi lo divide per 5 usando un puntatore al
puntatore (double**)
E infine lo stampa.
*/

int main () {
    double n;
    std::cout << "Digita un numero decimale: ";
    std::cin >> n;
    
    double* ptr = &n; // Puntatore a n
    *ptr *= 2; // Raddoppia il valore di n usando il puntatore
    double** ptr2 = &ptr; // Puntatore al puntatore
    **ptr2 /= 5; // Divide il valore di n per 5 usando il puntatore al puntatore

    std::cout << "Il risultato finale e': " << n << std::endl;

    return 0;
}
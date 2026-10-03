#include <iostream>

/*
Scrivi una funzione che stampa i numeri
abbondanti in un intervallo [A,B] deciso
dall’utente.
Un numero abbondante è un numero intero
positivo per il quale la somma dei suoi
divisori propri (divisori escluso il numero
stesso) è maggiore del numero stesso.
Ad esempio, 12 è abbondante perché la
somma dei suoi divisori propri (1, 2, 3, 4 e 6)
è 16, che è maggiore di 12.
*/

int main() {
    int A, B;
    std::cout << "Inserisci l'intervallo [A,B]: ";
    std::cin >> A >> B;

    for (int n = A; n <= B; n++) {
        int sumDivisors = 0;
        for (int i = 1; i <= n / 2; i++) {
            if (n % i == 0) {
                sumDivisors += i;
            }
        }
        if (sumDivisors > n) {
            std::cout << n << " è un numero abbondante.\n";
        }
    }

    return 0;
}

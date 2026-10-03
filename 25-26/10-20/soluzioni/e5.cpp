/*
Scrivere una funzione ricorsiva che calcoli il
fattoriale di un numero intero positivo.
Riscrivere poi la sua versione iterativa, quale
delle due è più efficiente?
Bonus:
Usare la libreria chrono (#include <chrono>)
per misurare quanto dura l’esecuzione di
ogni funzione.
*/

#include <iostream>
#include <chrono>

int factorial_recursive(int n);
int factorial_iterative(int n);

int main() {
    int n;
    std::cout << "Inserisci un numero intero positivo: ";
    std::cin >> n;
    if (n < 0) {
        std::cout << "Per favore, inserisci un numero intero positivo." << std::endl;
        return 1;
    }

    int x1, x2;
    // Misurazione del tempo per la versione ricorsiva
    auto start_recursive = std::chrono::high_resolution_clock::now();
    x1 = factorial_recursive(n);
    auto end_recursive = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration_recursive = end_recursive - start_recursive;
    std::cout << "Fattoriale (ricorsivo) di " << n << " è " << x1 << std::endl;
    std::cout << "Tempo di esecuzione (ricorsivo): " << duration_recursive.count() << " ms" << std::endl;

    // Misurazione del tempo per la versione iterativa
    auto start_iterative = std::chrono::high_resolution_clock::now();
    x2 = factorial_iterative(n);
    auto end_iterative = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration_iterative = end_iterative - start_iterative;
    std::cout << "Fattoriale (iterativo) di " << n << " è " << x2 << std::endl;
    std::cout << "Tempo di esecuzione (iterativo): " << duration_iterative.count() << " ms" << std::endl;

    return 0;
}

int factorial_recursive(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial_recursive(n - 1);
}

int factorial_iterative(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

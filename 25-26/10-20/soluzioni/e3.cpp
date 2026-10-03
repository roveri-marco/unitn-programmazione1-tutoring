/*
Scrivere una funzione che, dato in input un
intero N, per N volte ricorsivamente chieda
all’utente di inserire un carattere.
Le lettere minuscole valgono 5 punti, quelle
maiuscole 10 e tutti gli altri caratteri 1.
La funzione deve ritornare la somma dei
punteggi, stamparla poi a video.
*/

#include <iostream>

int calcolaPunteggio(int n, int current = 0) {
    if (current >= n) {
        return 0;
    }

    char carattere;
    std::cout << "Inserisci un carattere: ";
    std::cin >> carattere;

    int punteggio;
    if (carattere >= 'a' && carattere <= 'z') {
        punteggio = 5;
    } else if (carattere >= 'A' && carattere <= 'Z') {
        punteggio = 10;
    } else {
        punteggio = 1;
    }

    return punteggio + calcolaPunteggio(n, current + 1);
}

int main() {
    int N;
    std::cout << "Inserisci un numero intero N: ";
    std::cin >> N;

    int punteggioTotale = calcolaPunteggio(N);
    std::cout << "Il punteggio totale e': " << punteggioTotale << std::endl;

    return 0;
}


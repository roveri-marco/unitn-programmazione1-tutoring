#include <iostream>

/*
Riprendere la calcolatrice di prima, ma ora
una volta fatta la prima operazione, il
programma continua a richiedere un nuovo
operatore e un nuovo numero fintanto che
non viene inserito il simbolo $.
Ogni volta il programma esegue l'operazione
usando come primo operando il risultato
ottenuto precedentemente e come secondo il
nuovo numero.
*/

int main () {
    double n, m, risultato;
    char operazione;
    std::cout << "Digita l'operazione (che usa questi operandi: +,-,*,/): ";
    std::cin >> n >> operazione >> m;
    
    while (operazione != '$') {
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
        n = risultato; // Update n to be the last result
        std::cout << "Digita l'operando (+,-,*,/ e $ per uscire): ";
        std::cin >> operazione;
        if (operazione != '$') {
            std::cout << "Digita il numero: ";
            std::cin >> m;
        }
    }
    std::cout << "Fine calcolatrice." << std::endl;

    return 0;
}
/*
Scrivi un programma che simuli un attacco
n contro m a RisiKo!
1. Dare in input n e m, compresi tra 1 e 10.
2. Chiedi all'utente con quanti carri-armati
 vuole attaccare (max 3), mentre il
 difensore difende sempre con il massimo
 disponibile (max 3).
3. Confronta il dado più alto dell'attaccante
 con il più alto del difensore e così via.
4. Stampa il risultato dell’attacco.
5. Ripete l'attacco finchè o l'attaccante non
 può più attaccare (attaccante con un solo
 carroarmato) oppure il difensore è sconfitto
 (rimane con zero carroarmati).
Note implementative:
- Scrivere una funzione che simuli il singolo
 lancio di un dado.
- Scrivere una funzione che gestisca un turno
 di attacco
attack(n_dadi_att, n_dadi_def, lost_attack, lost_def)
 (pensate bene a quali parametri passare per
 puntatore/riferimento e quali no).
*/

#include <iostream>

int roll_dice();
void attack(int, int, int &, int &);
void sort(int, int &, int &, int &);

int main() {
    srand(static_cast<unsigned int>(time(0))); // Inizializza il generatore di numeri casuali

    int n, m;
    std::cout << "Inserisci il numero di carri-armati dell'attaccante (1-10): ";
    std::cin >> n;
    std::cout << "Inserisci il numero di carri-armati del difensore (1-10): ";
    std::cin >> m;

    while (n < 1 || n > 10 || m < 1 || m > 10) {
        std::cout << "I numeri devono essere compresi tra 1 e 10." << std::endl;

        std::cout << "Inserisci il numero di carri-armati dell'attaccante (1-10): ";
        std::cin >> n;
        std::cout << "Inserisci il numero di carri-armati del difensore (1-10): ";
        std::cin >> m;
    }

    while (n > 1 && m > 0) {
        int attack_dice;
        std::cout << "Quanti carri-armati vuoi usare per l'attacco? (max 3): ";
        std::cin >> attack_dice;
        if (attack_dice < 1 || attack_dice > 3 || attack_dice >= n) {
            std::cout << "Numero di carri-armati non valido per l'attacco." << std::endl;
            continue;
        }

        int defense_dice = std::min(3, m);
        int lost_att = 0, lost_def = 0;

        attack(attack_dice, defense_dice, lost_att, lost_def);

        n -= lost_att;
        m -= lost_def;

        std::cout << "Risultato dell'attacco: Attaccante ha perso " << lost_att << ", Difensore ha perso " << lost_def << "." << std::endl;
        std::cout << "Carri-armati rimanenti - Attaccante: " << n << ", Difensore: " << m << "." << std::endl;
    }

    if (m == 0) {
        std::cout << "L'attaccante ha vinto!" << std::endl;
    } else {
        std::cout << "Il difensore ha resistito!" << std::endl;
    }

    return 0;
}

int roll_die() {
    return rand() % 6 + 1; // Simula il lancio di un dado a 6 facce
}

void sort(int n, int &a, int &b, int &c) {
    int temp;
    if (n >= 2 && a < b) {
        temp = a; a = b; b = temp;
    }
    if (n == 3) {
        if (a < c) {
            temp = a; a = c; c = temp;
        }
        if (b < c) {
            temp = b; b = c; c = temp;
        }
    }
}

void attack(int n_dice_att, int n_dice_def, int &lost_att, int &lost_def) {
    int a1, b1, c1, a2, b2, c2;

    // Lancia i dadi per l'attaccante
    switch (n_dice_att) {
        case 3:
            c1 = roll_die();
        case 2:
            b1 = roll_die();
        case 1:
            a1 = roll_die();
            break;
    }
    // Lancia i dadi per il difensore
    switch (n_dice_def) {
        case 3:
            c2 = roll_die();
        case 2:
            b2 = roll_die();
        case 1:
            a2 = roll_die();
            break;
    }

    // Ordina i risultati in ordine decrescente
    sort(n_dice_att, a1, b1, c1);
    sort(n_dice_def, a2, b2, c2);

    // Confronta i dadi
    int comparisons = std::min(n_dice_att, n_dice_def);
    switch (comparisons) {
        case 3:
            if (c1 > c2) {
                lost_def++;
            } else {
                lost_att++;
            }
        case 2:
            if (b1 > b2) {
                lost_def++;
            } else {
                lost_att++;
            }
        case 1:
            if (a1 > a2) {
                lost_def++;
            } else {
                lost_att++;
            }
            break;
    }
}

#include <iostream>

/*
Scrivere un programma che simula una
partita di “sasso, carta, forbice” di 3 round
tra utente e computer.
L’utente sceglie tra 3 opzioni:
1 – sasso
2 – carta
3 – forbice
E poi il computer risponde con una risposta
casuale.
Vince la partita chi vince 3 round.
Se si pareggia, il round si ripete.
Usare una funzione
bool round(int A, int B);
che ritorna il risultato del round.
E una funzione
int computer();
che ritorna la giocata del computer.
Opzionale:
Se sono stati spiegati, usare gli enum.
Se non sono stati spiegati e vi sentite
fighi, cercate cosa sono e usateli.
*/

int main() {
    int user_score = 0;
    int computer_score = 0;
    int choice;
    std::cout << "Benvenuto a sasso, carta, forbice!" << std::endl;
    std::cout << "Scegli 1 per sasso, 2 per carta, 3 per forbice." << std::endl;
    while (user_score < 3 && computer_score < 3) {
        std::cout << "Punteggio: Utente " << user_score << " - Computer " << computer_score << std::endl;
        std::cout << "Fai la tua scelta: ";
        std::cin >> choice;
        if (choice < 1 || choice > 3) {
            std::cout << "Scelta non valida. Riprova." << std::endl;
            continue;
        }
        int computer_choice = computer();
        std::cout << "Il computer ha scelto: " << (computer_choice == 1 ? "sasso" : computer_choice == 2 ? "carta" : "forbice") << std::endl;
        if (round(choice, computer_choice)) {
            user_score++;
            std::cout << "Hai vinto questo round!" << std::endl;
        } else if (round(computer_choice, choice)) {
            computer_score++;
            std::cout << "Il computer ha vinto questo round!" << std::endl;
        } else {
            std::cout << "Pareggio! Il round si ripete." << std::endl;
        }
    }
    if (user_score == 3) {
        std::cout << "Complimenti! Hai vinto la partita!" << std::endl;
    } else {
        std::cout << "Il computer ha vinto la partita. Riprova!" << std::endl;
    }

}

bool round(int A, int B) {
    // A e B sono le scelte di due giocatori
    // 1 = sasso, 2 = carta, 3 = forbice
    if (A == B) return false; // pareggio
    if ((A == 1 && B == 3) || (A == 2 && B == 1) || (A == 3 && B == 2)) {
        return true; // A vince
    }
    return false; // B vince
}

#include <cstdlib>
#include <ctime>
int computer() {
    std::srand(std::time(0)); // inizializza il generatore di numeri casuali
    return std::rand() % 3 + 1; // ritorna un numero casuale tra 1 e 3
}



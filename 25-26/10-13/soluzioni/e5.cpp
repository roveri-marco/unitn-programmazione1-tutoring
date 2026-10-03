#include <iostream>

/*
Scrivere un programma che simula una
gara di salto.
3 atleti saltano in 10 round.
Il vincitore di ogni singolo round e’ chi
dei 3 salta piu’ in alto, e prende 1 punto.
Vince chi fa piu’ punti.
(non considerare il caso in cui ci siano parita’
di altezze di salto)
Stampare il risultato di ogni round e, alla fine,
stampare il podio (considerare che ci possono
essere dei pareggi).
Il “salto” e’ un valore casuale di tipo double
tra 1.0 e 3.0 metri.
Scrivere delle funzioni:
double jump();
int round(double, double, double);
void podium(int, int, int);
che, rispettivamente:
- ritorna l’altezza di un salto.
- ritorna l’atleta che ha vinto
- stampa il podio.
continua sotto
L’implementazione e’ la seguente:
- Ogni atleta (A, B, C) e’ rappresentato
 da un intero che segna quanti round ha
 vinto.
- La funzione round ritorna l’id dell’atleta che
 ha vinto in ordine. (1: A, 2: B, 3: C)
 e i parametri in input sono le altezze saltate,
 in ordine.
- I parametri di podium sono i round vinti dagli
 atleti
*/

int main() {
    srand(time(NULL));
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < 10; i++) {
        double jumpA = jump();
        double jumpB = jump();
        double jumpC = jump();
        int winner = round(jumpA, jumpB, jumpC);
        if (winner == 1) a++;
        else if (winner == 2) b++;
        else c++;
        std::cout << "Round " << i + 1 << ": A=" << jumpA << " B=" << jumpB << " C=" << jumpC << " Winner: " << (winner == 1 ? "A" : (winner == 2 ? "B" : "C")) << std::endl;
    }
    podium(a, b, c);
    return 0;
}

double jump() {
    return (double)(rand() % 201 + 100) / 100; // random double between 1.0 and 3.0
}

int round(double a, double b, double c) {
    if (a > b && a > c) return 1;
    else if (b > a && b > c) return 2;
    else return 3;
}

void podium(int a, int b, int c) {
    std::cout << "Podium:" << std::endl;
    if (a >= b) {
        if (a >= c) {
            std::cout << "1st: A with " << a << " points" << std::endl;
            if (b >= c) {
                std::cout << "2nd: B with " << b << " points" << std::endl;
                std::cout << "3rd: C with " << c << " points" << std::endl;
            } else {
                std::cout << "2nd: C with " << c << " points" << std::endl;
                std::cout << "3rd: B with " << b << " points" << std::endl;
            }
        } else {
            std::cout << "1st: C with " << c << " points" << std::endl;
            std::cout << "2nd: A with " << a << " points" << std::endl;
            std::cout << "3rd: B with " << b << " points" << std::endl;
        }
    } else {
        if (b >= c) {
            std::cout << "1st: B with " << b << " points" << std::endl;
            if (a >= c) {
                std::cout << "2nd: A with " << a << " points" << std::endl;
                std::cout << "3rd: C with " << c << " points" << std::endl;
            } else {
                std::cout << "2nd: C with " << c << " points" << std::endl;
                std::cout << "3rd: A with " << a << " points" << std::endl;
            }
        } else {
            std::cout << "1st: C with " << c << " points" << std::endl;
            std::cout << "2nd: B with " << b << " points" << std::endl;
            std::cout << "3rd: A with " << a << " points" << std::endl;
        }
    }
}
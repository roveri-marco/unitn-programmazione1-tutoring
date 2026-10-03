#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

void riempiCartella(int cartella[3][9]) {
    for (int j = 0; j < 9; j++) {
        bool check;

        do {
            // riempie la colonna
            for (int i = 0; i < 3; i++) {
                if (rand() % 2) {
                    cartella[i][j] = (rand() % 10) + 10 * j;
                } else {
                    cartella[i][j] = -1;
                }
            }

            check = false;
            // controlla se e' vuota
            if (cartella[0][j] + cartella[1][j] + cartella[2][j] == -3) {
                check = true;
            }
            // controlla duplicati
            if (cartella[0][j] == cartella[1][j] && cartella[0][j] != -1 ||
                cartella[0][j] == cartella[2][j] && cartella[0][j] != -1 ||
                cartella[1][j] == cartella[2][j] && cartella[0][j] != -1) {
                check = true;
            }
        } while (check);
    }
}

// aggiorna la bitmask
void segnaCartella(int cartella[3][9], bool mask[3][9], int num) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 9; j++) {
            if (cartella[i][j] == num) {
                mask[i][j] = true;
            }
        }
    }
}

void stampaCartella(int cartella[3][9], bool mask[3][9]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 9; j++) {
            if (cartella[i][j] == -1) {
                cout << setw(4) << ' ';
            } else if (mask[i][j]) {
                cout << "\033[1;31m" << setw(4) << cartella[i][j] << "\033[0m";
            } else {
                cout << setw(4) << cartella[i][j];
            }
        }
        cout << endl;
    }
}

// ritorna quale 'score' segna la tabella
int check(int cartella[3][9], bool mask[3][9]) {
    int checked_amt = 0;
    int total_amt = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 9; j++) {
            if (cartella[i][j] != -1) {
                total_amt++;
                if (mask[i][j]) {
                    checked_amt++;
                }
            }
        }
    }

    if (total_amt == checked_amt) {
        return 6;
    } else if (checked_amt > 5) {
        return 5;
    }
    return checked_amt;
}

int main() {
    srand(time(NULL));

    int cartella[3][9];
    bool mask[3][9];

    riempiCartella(cartella);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 9; j++) {
            mask[i][j] = false;
        }
    }

    int score = 0;
    // esce quando fa tombola,
    // mantenendo l'ultimo score fatto,
    // cosi' non stampa piu' volte lo stesso valore
    do {
        stampaCartella(cartella, mask);

        // input
        int num;
        do {
            cout << "Inserisci un numero tra 0 e 89: ";
            cin >> num;
            if (num < 0 || num > 89) {
                cout << "riprova" << endl;
            }
        } while (num < 0 || num > 89);

        segnaCartella(cartella, mask, num);
        cout << "--------------------------" << endl;

        int tmp = check(cartella, mask);
        if (score != tmp) {
            score = tmp;
            switch (score) {
            case 2:
                cout << "Ambo" << endl;
                break;
            case 3:
                cout << "Terna" << endl;
                break;
            case 4:
                cout << "Quaterna" << endl;
                break;
            case 5:
                cout << "Cinquina" << endl;
                break;
            case 6:
                cout << "Tombola!" << endl;
            }
            cout << "--------------------------" << endl;
        }
        cout << endl;

    } while (score != 6);

    return 0;
}

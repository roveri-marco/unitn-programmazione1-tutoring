#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <utility>

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

int main(int argc, char *argv[]) {
    int limite;
    if (argc > 1) {
        limite = atoi(argv[1]);
    } else {
        limite = 25;
    }

    srand(time(NULL));

    // la ripetiione puo' venire implementata in diversi modi,
    // in questo caso ho fatto un array di 90 interi da 0 a 89
    // che rappresenta la sequenza di estrazioni sul quale
    // viene fatto uno 'shuffle' (riordinamento casuale)
    // e vengono estratti dal primo all'ultimo.
    // esistono diversi algoritmi di shuffle, questo
    // semplicemente fa 100 swap tra 2 elementi a caso.
    int ordine[90];
    for (int i = 0; i < 90; i++) {
        ordine[i] = i;
    }
    for (int i = 0; i < 100; i++) {
        swap(ordine[rand() % 90], ordine[rand() % 90]);
    }

    const int N = 4;
    int cartelle[N][3][9];
    bool mask[N][3][9];
    int score[N];

    for (int i = 0; i < N; i++) {
        score[i] = 0;
        riempiCartella(cartelle[i]);
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 9; k++) {
                mask[i][j][k] = false;
            }
        }
    }

    // funziona esattamente come prima, solo che la exit condition
    // ora dipende anche dal numero di estrazioni
    bool fatto_tombola = false;
    int estrazione = 0;
    do {
        int num = ordine[estrazione];
        estrazione++;
        cout << "Estratto il numero " << num << endl;

        for (int i = 0; i < N; i++) {
            segnaCartella(cartelle[i], mask[i], num);
            cout << "Cartella " << i + 1 << ":" << endl;
            stampaCartella(cartelle[i], mask[i]);
            cout << endl;
        }

        cout << "--------------------------" << endl;

        for (int i = 0; i < N; i++) {
            int tmp = check(cartelle[i], mask[i]);
            if (score[i] != tmp && tmp > 1) {
                score[i] = tmp;
                switch (score[i]) {
                case 2:
                    cout << "Ambo ";
                    break;
                case 3:
                    cout << "Terna ";
                    break;
                case 4:
                    cout << "Quaterna ";
                    break;
                case 5:
                    cout << "Cinquina ";
                    break;
                case 6:
                    fatto_tombola = true;
                    cout << "Tombola! ";
                }
                cout << "in cartella " << i + 1 << endl;
            }
        }
        cout << endl;
        cout << "--------------------------" << endl;
        // aspetta per un 'invio'
        cin.get();
    } while (!fatto_tombola && estrazione < limite);

    return 0;
}

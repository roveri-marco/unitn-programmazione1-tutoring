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

int main() {
    srand(time(NULL));

    int cartella[3][9];

    riempiCartella(cartella);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 9; j++) {
            cout << setw(3) << cartella[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}

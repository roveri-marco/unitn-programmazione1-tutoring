#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

void placeShips(int[9][9]);
// svolgimento di un turno
void turn(int[9][9]);
// stampa il campo di gioco
void print(int[9][9]);
// parsing delle coordinate inserite,
// ritorna true se sono valide, false altrimenti
bool parseCoordinates(int &, int &);
// colpisce una cella;
void hit(int[9][9], int, int);
// ritorna true se la partita e' finita
bool end(int[9][9]);

int main() {
    int field[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            field[i][j] = 0;
        }
    }

    placeShips(field);

    while (!end(field)) {
        turn(field);
    }

    print(field);
    cout << endl;

    return 0;
}

// ritorna quanti navi sono disponibili in tutto (per lunghezza).
// navi disponibili di default:
// 1: #####
// 2: ####
// 2: ###
// 3: ##
// e' possibile modificare questa funzione a piacimento.
// la lunghezza massima e' tanto quanto la grandezza del campo.
int availableShips(int length) {
    switch (length) {
    case 5:
        return 1;
    case 4:
        return 2;
    case 3:
        return 2;
    case 2:
        return 3;
    default:
        return 0;
    }
}

// controlla se una nave puo' venire piazzata dati
// la sua posizione, lunghezza e rotazione
// (rotazione e' un bool dove falso e' inteso come orizzontale
// e vero come verticale)
bool checkShipPosition(int field[9][9], int x, int y, int length,
                       bool rotation) {
    if (rotation) {
        if (y + length > 9) {
            return false;
        }
        for (int j = y; j < y + length; j++) {
            if (field[x][j] != 0) {
                return false;
            }
        }
    } else {
        if (x + length > 9) {
            return false;
        }
        for (int i = x; i < x + length; i++) {
            if (field[i][y] != 0) {
                return false;
            }
        }
    }

    return true;
}

// piazza prima quelle piu' grandi,
// usando un algoritmo naive dove sceglie
// posizione e rotazione a caso della nave.
// Se ci sta, la mette, altrimenti riprova.
void placeShips(int field[9][9]) {
    srand(time(NULL));

    int ship_id = 2;

    for (int len = 8; len > 0; len--) {
        for (int amt = 0; amt < availableShips(len); amt++) {
            bool placed, rot;
            int x, y;

            do {
                x = rand() % 9;
                y = rand() % 9;
                rot = rand() % 2;
                placed = checkShipPosition(field, x, y, len, rot);

                if (placed) {
                    if (rot) {
                        for (int j = y; j < y + len; j++) {
                            field[x][j] = ship_id;
                        }
                    } else {
                        for (int i = x; i < x + len; i++) {
                            field[i][y] = ship_id;
                        }
                    }
                }

            } while (!placed);

            ship_id++;
        }
    }
}

void turn(int field[9][9]) {
    cout << "------------------------------------" << endl;
    print(field);

    cout << endl << "Insert Cell: ";
    bool c = false;
    int i, j;
    do {
        c = parseCoordinates(i, j);
        if (!c) {
            cout << "Invalid value, re-insert it: ";
        }
    } while (!c);

    hit(field, i, j);
}

void print(int field[9][9]) {
    cout << " |";
    for (int i = 0; i < 9; i++) {
        cout << (char)('A' + i) << '|';
    }
    cout << endl;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j <= 9; j++) {
            cout << "-+";
        }
        cout << endl << i + 1 << '|';
        for (int j = 0; j < 9; j++) {
            if (field[i][j] == 1) {
                cout << "o|";
            } else if (field[i][j] == -1) {
                cout << "#|";
            } else if (field[i][j] < -1) {
                cout << "x|";
            } else {
                cout << " |";
            }
        }
        cout << endl;
    }

    for (int j = 0; j <= 9; j++) {
        cout << "-+";
    }
}

bool parseCoordinates(int &i, int &j) {
    string c;
    cin >> c;

    if (c.length() != 2 || c[0] < 'A' || c[0] > 'Z' || c[1] < '1' ||
        c[1] > '9') {
        return false;
    }

    i = c[1] - '1';
    j = c[0] - 'A';

    return true;
}

void hit(int field[9][9], int r, int c) {
    if (field[r][c] == 0) {
        field[r][c] = 1;
        cout << "Missed!" << endl;
        return;
    }

    // metodo naive: se colpisce una nave, controlla se ci
    // sono altre parti di quella nave non colpite:
    // se ci sono e' ancora a galla, altrimenti
    // li setta tutti a -1 (affondata)
    if (field[r][c] > 1) {
        int ship = field[r][c];
        field[r][c] = -ship;

        bool check = false;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (field[i][j] == ship) {
                    check = true;
                }
            }
        }

        if (!check) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (field[i][j] == -ship) {
                        field[i][j] = -1;
                    }
                }
            }
            cout << "Sunk!" << endl;
        } else {
            cout << "Hit!" << endl;
        }
    }
}

bool end(int field[9][9]) {
    // se ci sono navi non affondate (celle > 1)
    // ritorna false (continua il gioco)
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (field[i][j] > 1) {
                return false;
            }
        }
    }

    return true;
}

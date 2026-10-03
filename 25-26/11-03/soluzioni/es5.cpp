#include <iostream>
#include <string>

using namespace std;

// svolgimento di un turno
void turn(int[4][4]);
// stampa il campo di gioco
void print(int[4][4]);
// parsing delle coordinate inserite,
// ritorna true se sono valide, false altrimenti
bool parseCoordinates(int &, int &);
// colpisce una cella;
void hit(int[4][4], int, int);
// ritorna true se la partita e' finita
bool end(int[4][4]);

int main() {
    int field[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 3},
        {0, 2, 2, 3},
        {0, 0, 0, 3},
    };

    while (!end(field)) {
        turn(field);
    }

    print(field);
    cout << endl;

    return 0;
}

void turn(int field[4][4]) {
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

void print(int field[4][4]) {
    cout << " |";
    for (int i = 0; i < 4; i++) {
        cout << (char)('A' + i) << '|';
    }
    cout << endl;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j <= 4; j++) {
            cout << "-+";
        }
        cout << endl << i + 1 << '|';
        for (int j = 0; j < 4; j++) {
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

    for (int j = 0; j <= 4; j++) {
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

void hit(int field[4][4], int r, int c) {
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
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (field[i][j] == ship) {
                    check = true;
                }
            }
        }

        if (!check) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
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

bool end(int field[4][4]) {
    // se ci sono navi non affondate (celle > 1)
    // ritorna false (continua il gioco)
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (field[i][j] > 1) {
                return false;
            }
        }
    }

    return true;
}

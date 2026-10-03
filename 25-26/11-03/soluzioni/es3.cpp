/*
    Scrivere un programma che genera una
    matrice e ne normalizza i valori,
    scalandoli nel range [0,1].
    La formula da usare e’ la seguente:
    x' = (x - min) / (max - min)
 */

#include <climits>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    srand(time(NULL));

    float mat[3][3];
    float max_val = 0;
    float min_val = INT_MAX;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mat[i][j] = rand() % 10;
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    // trova min e max
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            min_val = min(min_val, mat[i][j]);
            max_val = max(max_val, mat[i][j]);
        }
    }

    // normalizza e stampa
    cout << endl << "Normalizzata: " << endl;
    cout.precision(1);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mat[i][j] = (mat[i][j] - min_val) / (max_val - min_val);
            cout << setw(5) << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

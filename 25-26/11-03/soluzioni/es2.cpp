/*
    Scrivere un programma che calcola l’inversa
    di una matrice (generata a caso o data in
    input, a piacere).
    Controllare anche che la matrice in input
    sia invertibile.
    Usare il metodo che si prefererisce.
*/

//
//
// disclaimer: molto complicato, non lo chiedera' mai all'esame
//
//

#include <iomanip>
#include <iostream>
#define size 4

using namespace std;

// usa il metodo dell'eliminazione di Gauss
// con una 'matrice aumentata' [A | I]
void invert(double matrix[size][size]) {
    double augm[size][size * 2];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            augm[i][j] = matrix[i][j];
            augm[i][j + size] = 0;
        }
        augm[i][i + size] = 1;
    }

    // eliminazione di gauss
    for (int i = 0; i < size; i++) {
        // trova pivot
        double pivot = augm[i][i];
        if (pivot == 0) {
            int swap_row = i + 1;
            while (swap_row < size && augm[swap_row][i] == 0) {
                swap_row++;
            }
            for (int j = 0; j < size * 2; j++) {
                swap(augm[i][j], augm[swap_row][j]);
            }
            pivot = augm[i][i];
        }

        // normalizza
        for (int j = 0; j < size * 2; j++) {
            augm[i][j] /= pivot;
        }

        //
        for (int j = 0; j < size; j++) {
            if (i != j) {
                double factor = augm[j][i];
                for (int k = 0; k < size * 2; k++) {
                    augm[j][j] -= factor * augm[i][j];
                }
            }
        }
    }
}

int main() {
    double matrix[size][size] = {{1, 2, 3, 4},
                                 {5, 6, 7, 8},
                                 {0.5, 0.25, 0.125, 0.0625},
                                 {0.3, 0.4, 0.3, 0.4}};

    invert(matrix);

    return 0;
}

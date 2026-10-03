#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
    srand(time(NULL));
    int mat[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mat[i][j] = rand() % 10;
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    // usa la regola di Sarrus
    int det =
        mat[0][0] * mat[1][1] * mat[2][2] +
        mat[0][1] * mat[1][2] * mat[2][0] +
        mat[0][2] * mat[1][0] * mat[2][1] - (
            mat[0][2] * mat[1][1] * mat[2][0] +
            mat[0][1] * mat[1][0] * mat[2][2] +
            mat[0][0] * mat[1][2] * mat[2][1]
        );

    cout << endl << "Determinante: " << det << endl;

    return 0;
}

/*
 * Scrivere una funzione che calcola il modulo
 * tra 2 numeri interi in modo ricorsivo, senza
 * usare l’operatore %.
 */


#include <iostream>

using namespace std;


int mod(int n, int d) {
    if (n < d) {
        return n;
    }

    return mod(n-d, d);
}

int main() {
    int n, d;

    cout << "Inserisci numeratore e denominatore: ";
    cin >> n >> d;

    cout << "Modulo: " << mod(n,d) << endl;

    return 0;
}


/*
 *  Semplicemente, la funzione mod sottrare
 *  il denominatore dal numeratore finche'
 *  non e' piu' possibile farlo senza entrare
 *  nel campo dei numeri negativi.
 */

/*
	Scrivere un programma che stampi il risultato
	dell’espressione booleana:
	(A OR B OR C) AND (NOT (B AND C))
*/

#include <iostream>

using namespace std;


int main() {
    bool A, B, C, res;
    
    //input A, B e C
    cout << "Inserisci A: ";
    cin >> A;
    cout << "Inserisci B: ";
    cin >> B;
    cout << "Inserisci C: ";
    cin >> C;
    
    //calcola espressione
    res = (A || B || C) && (! (B && C));

    cout << "Il risultato e': " << res << endl;

    return 0;
}

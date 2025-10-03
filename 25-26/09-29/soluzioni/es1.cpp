/*
	Scrivere un programma che stampi il risultato
	dell’espressione booleana:
	(A OR B) AND (NOT B XOR A)
*/

#include <iostream>

using namespace std;


int main() {
    bool A, B, res;
    
    //input A e B
    cout << "Inserisci A: ";
    cin >> A;
    cout << "Inserisci B: ";
    cin >> B;
    
    //calcola espressione
    res = (A || B) && (!B ^ A);

    cout << "Il risultato e': " << res << endl;

    return 0;
}

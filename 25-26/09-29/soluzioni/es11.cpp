/*
	Ora scrivi un programma che lo stampa in base
	esadecimale (16).
	
	le cifre [10, 11, 12, 13, 14, 15] si rappresentano
	rispettivamente con [A, B, C, D, E, F]
*/

#include <iostream>

using namespace std;


int main() {
    int N, N2;
    
    cout << "Inserisci un numero intero: ";
    cin >> N;
    N2 = N;
    


    // soluzione con switch:
    while (N != 0) {
	int resto = N % 16;
	
	cout << "| ";

	if (resto < 10) {
	    cout << resto << endl;
	} else {
	    switch (resto) {
		case 10:
		    cout << 'a' << endl;
		    break;
		case 11:
		    cout << 'b' << endl;
		    break;
		case 12:
		    cout << 'c' << endl;
		    break;
		case 13:
		    cout << 'd' << endl;
		    break;
		case 14:
		    cout << 'e' << endl;
		    break;
		case 15:
		    cout << 'f' << endl;
		    break;
	    }
	}
	
	N = N / 16;
    }



    cout << endl << endl;



    // soluzione piu' elegante:
    while (N2) {
	int r = N2 % 16;
	cout << "| " << (char)(r < 10 ? r + '0' : 'a' + r - 10) << endl;
	N2 /= 16;
    }


    return 0;
}



/*	SPIEGAZIONE
 *
 *	Esattamente come l'esercizio precedente,
 *	devo soltanto rappresentare i numeri da 10 a 15 come lettere.
 *
 * */

/*
	Usando un ciclo, scrivi un programma che
	richieda un numero intero e lo stampi in base 2
	cifra per cifra.
	    Ad esempio, il numero 23:
	    | 1
	    | 1	
	    | 1
	    | 0
	    | 1
*/

#include <iostream>

using namespace std;


int main() {
    int N;
    
    cout << "Inserisci un numero intero: ";
    cin >> N;

    
    while (N != 0) {
	    int resto = N % 2;
	    cout << "| " << resto << endl;	
	    N = N / 2;
    }


    return 0;
}



/*	SPIEGAZIONE
 *
 *	Il procedimento e' esattamente lo stesso per stampare le cifre in base 10:
 *
 *	- trovo il resto della divisione per 10
 *	- stampo il resto
 *	- divido il numero per 10
 *	- continuo finche'  il numero non e' 0
 *
 *	
 *	Semplicemente, posto in base 2:
 *
 *	
 *	- trovo il resto della divisione per 2
 *	- stampo il resto
 *	- divido il numero per 2
 *	- continuo finche'  il numero non e' 0
 *
 *
 * */

/*
    Scrivi un programma che stampi a video i
    primi N numeri della sequenza di Fibonacci.
*/

#include <iostream>

using namespace std;


int main() {
    int N, a, b, c;
    
    // Caso base della sequenza di fibonacci
    a = 1;
    b = 1;

    // Input
    cout << "Inserisci N: ";
    cin >> N;


    // Sequenza
    cout << "1: 1\n2: 1\n";
    for (int i = 2; i < N; i++) {
	c = a + b;
	a = b;
	b = c;
	cout << i+1 << ": " << c << endl;
    }


    return 0;
}



    /* 	SPIEGAZIONE
     *
     *	la sequenza di fibonacci f(N) e' definita come:
     *	
     *	f(1) = 1
     *	f(2) = 1
     *	f(i) = f(i-2) + f(i-1)
     *
     *
     *
     *	Ora, sarebbe meglio spiegarlo con una ricorsione, ma in questo punto del corso
     *	non e' ancora stata insegnata, quindi useremo un approccio diverso:
     *
     *
     *	se immaginiamo una sequenza di fibonacci:
     *	1 1 2 3 5 8 13 21 34 55
     *
     *	possiamo vedere come ogni numero dal 3^ in poi sia uguale alla somma di quelli 2 prima (per definizione) .
     *
     *	quindi una soluzione e' quella di tenersi in 3 variabili gli ultimi 3 numeri, "spostandoli in avanti"
     *	ad ogni iterazione.
     *
     *
     *
     *	partendo da a = 1, b = 1
     *		calcolo c = a + b = 2
     *	e poi sposto in avanti:
     *		a = b = 1
     *		b = c = 2
     *
     *	e ripeto:
     *		c = a + b = 3
     *		a = b = 2
     *		b = c = 3
     *
     *		c = a + b = 5
     *		a = b = 3
     *		b = c = 5
     *
     *		c = a + b = 8
     *		a = b = 5
     *		b = c = 8
     *
     *	e cosi' via...
     *
     */

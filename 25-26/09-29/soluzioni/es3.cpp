/*
	Date cinque variabili di tipo intero, chiedi
	all'utente di inserire un valore per ciascuna di
	esse e calcola la media dei numeri.
		1. Stampa a video la media.
		2. Ora prova con delle variabili di double
		   come input. Cambia il risultato? Perché?
*/

#include <iostream>

using namespace std;


int main() {
    int    a, b, c, d, e;
    double d_a, d_b, d_c, d_d, d_e;
    double avg;

    cout << "Inserisci 5 numeri interi: ";
    cin >> a >> b >> c >> d >> e;
    avg = (a + b + c + d + e) / 5;
    cout << "La media e': " << avg << endl;

    cout << "Ora inserisci 5 numeri decimali: ";
    cin >> d_a >> d_b >> d_c >> d_d >> d_e;
    avg = (d_a + d_b + d_c + d_d + d_e) / 5;
    cout << "La media ora e': " << avg << endl; 
    

    return 0;
}


    /*	SPIEGAZIONE:
     *
     *
     *  Notare che per come funziona l'operatore divisione (/) in C++,
     *	dividere 2 interi ritorna sempre un intero,
     *	e se divido ALMENO un double allora ritorna sempre un double.
     *
     *
     *	Nel nostro primo caso, a riga 22, viene diviso un intero (la somma dei numeri)
     *	con il numero 5 (intero) e infatti ritorna un numero intero.
     *	(che sarebbe la media reale, arrotondata per difetto)
     *	Anche se la variable avg e' di tipo double, il risultato della divisione
     *	e' un int, di conseguenza il valore contenuto in avg ha una parte decimale = 0 
     *	
     *
     *	Nel secondo caso invece, divide sempre per 5 che e' intero, ma il dividendo e'
     *	double (perche' e' una somma di double).
     *		
     *
     *	E se avessi dichiarato avg di tipo int?
     *	Allora il risultato della divisione sarebbe stato castato ad un intero,
     *	a prescindere se ritorna int o double.
     *
     *
     *	Notare anche che se avessi diviso per 5.0 invece che per 5,
     *	avrei il divisore di tipo double, di conseguenza anche la prima divisione
     *	avrebbe ritornato un double! (provare per credere)
     */


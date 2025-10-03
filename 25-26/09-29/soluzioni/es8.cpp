/*
	Scrivi un programma che "indovina" un numero
	compreso tra 0 e 10 ponendo una serie di
	domande Y/N all'utente
	hint: chiedere se il numero e’ minore o maggiore.
*/





    /*
     *		DISCLAIMER:
     *
     *		il programma indovina, quindi l'utente deve pensare al numero.
     *		e allo stesso tempo all'utente vengono chieste solo domande Y/N.
     *
     *		e' un po' formulato male, ma e' fattibile se chiedo due domande:
     *
     * 			"il tuo numero e' <N> ?"
     *		 	yes -> indovina e termina
     *		 	no  -> altra domanda:
     *		 		"il tuo numero e' minore di <N> ?"
     *		 		yes -> meta' inferiore
     *				no  -> meta' superiore
     *
     *
     *		
     *		ci sono esercizi simili: far pensare il numero al computer ad esempio
     *		oppure chiedere all'utente < > = invece di y/n
     *
     *
     *
     *
     *		ALTRO DISCLAIMER:
     *
     *		tutti i controlli vari di sanitizzazione non sono stati aggiunti semplicemente per
     *		mantenere il codice pulito e semplice da capire,
     *		ad esempio verificare che il numero pensato sia compreso tra 0 e 10, 
     *		controllo su input diverso da 'y' o 'n' ed altro.
     *		
     *		Se nella vostra soluzione li avete messi meglio.
     *
     * */




#include <iostream>

using namespace std;




int main() {
    int low = 0;
    int high = 11;
    int guess;
    char choice;

    
    cout << "Pensa ad un numero tra 0 e 10." << endl;
    

    do {
	guess = (low + high) / 2;

	cout << "Il tuo numero e' " << guess << " ? (y/n)  ";
	cin >> choice;
	
	if (choice == 'n') {
	    cout << "Il tuo numero e' minore di " << guess << " ? (y/n)  ";
	    cin >> choice;
	    
	    if (choice == 'y') {
		high = guess;
	    } else {
		low = guess;
	    }

	    choice = ' ';
	}

    } while (choice != 'y');
    
    
    cout << "Hai pensato al numero " << guess << endl;

   
    return 0;
}




/*	SPIEGAZIONE
 *
 *
 *	si tiene traccia dell'insieme dove sto indovinando il mio numero
 *	tramite due puntatori low e high (incluso/escluso)
 *	rispettivamente 0 e 11 (ma funziona anche genericamente su i e k);
 *
 *	guess sta al centro, arrotondato per difetto.
 *	in questo caso 5 (genericamente (i+k)/2)
 *
 *
 *	se il numero che penso e' maggiore di guess, allora sara' per forza
 *	compreso tra guess e high.
 *	altrimenti sara' compreso tra low e guess.
 *
 *
 *	quindi restringo il mio dominio di ricerca:
 *		low = guess 
 *		(se guess minore di numero)
 *
 *		high = guess
 *		(se guess maggiore di numero)
 *
 *
 *	e ricalcolo guess.
 *
 *
 *	finche' non giungo al punto in cui guess = numero.
 *	
 *
 *
 *
 *
 *	SPOILER:
 *
 *	Questo non e' altro che un algoritmo di ricerca chiamato "Binary Search"
 *	che si usa per trovare la posizione di un elemento in un vettore ordinato.
 *
 *	E' una cosa che viene insegnata al corso di algoritmi, ma se avete voglia controllate
 *	pure la wiki, e' molto intuitiva come cosa.
 *
 *	E magari provate pure ad implementarlo.
 *
 *
 */

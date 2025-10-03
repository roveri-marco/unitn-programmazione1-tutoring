/*
	Usa una variabile int short come indice di un
	ciclo for. Esegui un ciclo fino a 40000 e stampala
	(usa un incremento di qualche centinaio).
	    Cosa succede?
	    (spoiler alert: se si blocca il programma
	    terminarlo con CTRL+C)
*/

#include <iostream>

using namespace std;


int main() {
    
    for (short int i = 0; i < 40000; i += 200) {
	cout << i << endl;
    }
    
    return 0;
}




/*	SPIEGAZIONE
 *
 *	
 *	A differenza del normale int rappresentato da 32 bit,
 *	il tipo short e' un intero rappresentato da 16 bit.
 *
 *	Quindi puo' rappresentare valori (con segno) in un intervallo
 *	tra [- 2^15, 2^15 - 1]	quindi tra [-32768, 32767]
 *
 *	
 *	Quando supero questo intervallo avviene quello che si chiama "Overflow"
 *	Che mi fa "tornare dall'altra parte" dell'intervallo.
 *	
 *	Ad esempio, sommando 1 avrei una sequenza del genere:
 *
 *	1, 2, 3, ......, 32765, 32766, 32767, -32768, -32767, -32766 ....
 *
 *	(E allo stesso modo sottraendo 1)
 *
 *
 *	
 *	Anche questa e' una cosa che verra' insegnata piu' avanti
 *	nel corso di Calcolatori, ma resta comunque carina da scoprire prima. 
 *
 * */

/*
	Considerate il seguente codice:
	
	int sum = 0;
	for (int i=0; i<10; i++){
	    sum += i;
	}
	cout << sum << endl;
	
	Riscrivete il for com come un ciclo while.
*/

#include <iostream>

using namespace std;


int main() {
    int sum = 0;
    int i;

    
    //tradotto in while:
    i = 0;
    while (i < 10) {
	    sum += i;
	    i++;
    }
    cout << sum << endl;

    
    
    //una soluzione piu' elegante:
    sum = 0;
    i = 10;
    while (i) {
	    sum += --i;
    }
    cout << sum << endl;

    
    
    return 0;
}

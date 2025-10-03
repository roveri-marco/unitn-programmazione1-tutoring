/*
	Scrivere un programma che risolva una
	equazione di secondo grado, dando in input i
	parametri A,B e C.
*/

#include <iostream>
#include <math.h>

using namespace std;


int main() {
    double a, b, c;
    
    // Input
    cout << "Inserisci A: ";
    cin >> a;
    cout << "Inserisci B: ";
    cin >> b;
    cout << "Inserisci C: ";
    cin >> c;
    
    // Caso in cui non e' di secondo grado
    if (a == 0.0) {
	cerr << "il parametro a e' uguale a zero!" << endl; 
	return 1;
    }

    double delta = b*b - 4*a*c;

    // Caso in cui il risultato sia in campo complesso
    if (delta < 0.0) {
	cerr << "delta e' negativo!" << endl;
	return 2;
    }

    double x1 = (b - sqrt(delta)) / (2*a);
    double x2 = (b + sqrt(delta)) / (2*a); 

    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;

    return 0;
}

#include <iostream>

/*
Scrivere una funzione
double sconta(double p, int s);
Che prende in input prezzo e sconto
e ritorna il prezzo scontato.
Scrivere la funzione 3 volte, per ognuna usare
passaggio per valore, riferimento ed indirizzo.
Tenere in considerazione che lo sconto e’ un
intero.
*/

double sconta_valore(double p, int s) {
    return p * (100 - s) / 100;
}

void sconta_riferimento(double& p, int& s) {
    p = p * (100 - s) / 100;
}

void sconta_indirizzo(double* p, int* s) {
    *p = (*p) * (100 - (*s)) / 100;
}

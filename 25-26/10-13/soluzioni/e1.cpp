#include <iostream>

/*
Scrivere una funzione:
void mySwap (int*, int*)
che esegua lo scambio dei valori di due
variabili di tipo int.
*/


void mySwap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
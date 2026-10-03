#include <iostream>

/*
Scrivere una funzione:
void genericSwap (void*, void*, bool)
che esegue un controllo sul parametro
booleano e decide se eseguire uno scambio
tra puntatori di tipo int (se true) o di tipo char
(se false).
*/

void genericSwap(void* a, void* b, bool isInt) {
    if (isInt) {
        int temp = *(int*)a;
        *(int*)a = *(int*)b;
        *(int*)b = temp;
    } else {
        char temp = *(char*)a;
        *(char*)a = *(char*)b;
        *(char*)b = temp;
    }
}

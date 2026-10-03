/*
    Scrivere un programma che prende una
    stringa da riga di comando e la inverte,
    ricorsivamente.
*/

#include <cstring>
#include <iostream>

using namespace std;

// per invertire una stringa, ho un indice che aumento che indica il prossimo
// carattere 'in fondo' da invertire con il primo.
// Nella chiamata ricorsva aumento il puntatore della stringa di 1, che scorre
// in avanti al prossimo carattere
void invert(char *str, int i) {
    if (strlen(str) > 2) {
        swap(str[0], str[strlen(str) - i]);
        invert(str + 1, i + 1);
    }
}

int main(int argc, char *argv[]) {
    invert(argv[1], 1);
    cout << argv[1] << endl;

    return 0;
}

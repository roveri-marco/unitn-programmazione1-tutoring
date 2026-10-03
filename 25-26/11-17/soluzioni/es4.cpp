#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Numero di argomenti errato" << endl;
        return 1;
    }

    fstream str;
    char buf[16];

    str.open(argv[1], ios::in);
    if (str.fail()) {
        cout << "Errore nel leggere il file di input" << endl;
        return 1;
    }

    float *arr = new float[100];

    // legge carattere per carattere inserendoli in una stringa
    // finche' non trova una virgola per trovare il singolo numero.
    // tenendo traccia dell'indice nell'array e dell'indice nella stringa.
    int n_arr = 0;
    int n_str = 0;
    while (!str.eof()) {
        char c;
        str.get(c);

        if (c != ',') {
            buf[n_str] = c;
            n_str++;
        } else {
            buf[n_str] = '\0';
            n_str = 0;
            arr[n_arr] = atof(buf);
            n_arr++;
        }
    }
    // se l'ultimo carattere non e' una virgola l'ultimo
    // numero non viene contato
    if (n_str != 0) {
        arr[n_arr] = atof(buf);
        n_arr++;
    }

    // trova somma e media
    float sum;
    for (int i = 0; i < n_arr; i++) {
        sum += arr[i];
    }
    float avg = sum / n_arr;

    cout << "Somma: " << sum << "  Media: " << avg << endl;

    str.close();
    delete[] arr;

    return 0;
}

#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 4) {
        cout << "Numero di argomenti errato" << endl;
        return 1;
    }

    fstream str;
    char buf[256][256];

    // apre il file in read mode
    str.open(argv[1], ios::in);
    if (str.fail()) {
        cout << "Errore nel leggere il file" << endl;
        return 1;
    }

    // legge dal file e copia nel buffer.
    int n = 0;
    while (!str.eof()) {
        str >> buf[n];
        n++;
    }

    str.close();

    // sostituisce le occorrenze
    for (int i = 0; i < n; i++) {
        if (strcmp(buf[i], argv[2]) == 0) {
            strcpy(buf[i], argv[3]);
        }
    }

    // scrive il buffer nel file
    str.open(argv[1], ios::out);
    for (int i = 0; i < n; i++) {
        str << buf[i] << ' ';
    }
    str.close();

    return 0;
}

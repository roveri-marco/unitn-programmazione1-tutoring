#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "Numero di argomenti errato" << endl;
        return 1;
    }

    fstream in_str, out_str;
    char c;

    in_str.open(argv[1], ios::in);
    if (in_str.fail()) {
        cout << "Errore nel leggere il file di input" << endl;
        return 1;
    }

    out_str.open(argv[2], ios::out | ios::app);

    // legge carattere per carattere e lo appende all'altro file
    while (!in_str.eof()) {
        in_str.get(c);
        out_str.put(c);
    }

    in_str.close();
    out_str.close();

    return 0;
}

#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 4) {
        cout << "Numero di argomenti errato" << endl;
        return 1;
    }

    fstream in_str1, in_str2, out_str;

    in_str1.open(argv[1], ios::in);
    if (in_str1.fail()) {
        cout << "Errore nel leggere il primo file di input" << endl;
        return 1;
    }
    in_str2.open(argv[2], ios::in);
    if (in_str2.fail()) {
        cout << "Errore nel leggere il secondo file di input" << endl;
        return 1;
    }

    out_str.open(argv[3], ios::out);

    while (!in_str1.eof() && !in_str2.eof()) {
        char c;
        in_str1.get(c);
        out_str.put(c);
        in_str2.get(c);
        out_str.put(c);
    }

    in_str1.close();
    in_str2.close();
    out_str.close();

    return 0;
}

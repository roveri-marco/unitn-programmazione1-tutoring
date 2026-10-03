#include <cstring>
#include <fstream>
#include <iostream>
#include <utility>

using namespace std;

void invert(char *str) {
    int i = 0;
    int j = strlen(str) - 1;

    while (i < j) {
        swap(str[i], str[j]);
        i++;
        j--;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Numero di argomenti errato" << endl;
        return 1;
    }

    fstream str;
    char buf[256];

    str.open(argv[1], ios::in);
    if (str.fail()) {
        cout << "Errore nel leggere il file di input" << endl;
        return 1;
    }

    while (!str.eof()) {
        str >> buf;
        invert(buf);
        cout << buf << ' ';
    }
    cout << endl;

    str.close();

    return 0;
}

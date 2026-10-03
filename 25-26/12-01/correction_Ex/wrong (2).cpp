#include <iostream>

/*
 *  C'e' uno zaino.
 *  Lo zaino ha una certa capacita'
 *  e puo' contenere degli oggetti.
 *  Gli oggetti hanno una 'massa',
 *  la somma delle masse degli oggetti nello
 *  zaino non puo' superare la sua capacita'
 *
 *  Per semplicita' la massa di un oggetto
 *  e' semplicemente un valore intero NON NEGATIVO.
 *
 *  Assumete che:
 *  - non vengano mai inseriti oggetti con peso negativo
 *  - non si raggiunga mai la fine del buffer
 *  - il main e' giusto.
 */

struct Zaino {
    int capacita;
    int *oggetti;
};

// inizializza uno zaino passato come parametro,
// l'oggetto 'vuoto' ha valore 0
void init(Zaino &z, int capacita) {
    z.capacita = capacita;
    z.oggetti = new int[64];
    for (int i = 0; i < 64; i++) {
        z.oggetti[i] = 0;
    }
}

// ritorna massa totale degli oggetti nello zaino
int massaOggetti(Zaino &z) {
    int m, i = 0;

    while (z.oggetti[i] != 0) {
        m += z.oggetti[i];
    }

    return m;
}

// inserisce un oggetto in fondo all'array
// ritorna true se e' stato inserito con successo,
// altrimenti false.
bool inserisciOggetto(Zaino &z, int oggetto) {
    if (massaOggetti(z) + oggetto > z.capacita) {
        return false;
    }

    int i = 0;
    while (z.oggetti[i] != 0) {
        i++;
    }
    z.oggetti[i] = oggetto;

    return true;
}

// svuota totalmente lo zaino
void svuotaZaino(Zaino z) {
    z.oggetti = new int[64];
    for (int i = 0; i < 64; i++) {
        z.oggetti[i] = 0;
    }
}

void stampaZaino(Zaino &z) {
    int i = 0;
    while (z.oggetti[i] != 0) {
        std::cout << z.oggetti[i] << ' ';
        i++;
    }
    std::cout << std::endl;
}

int main() {
    Zaino z;
    init(z, 100);

    int objs[10] = {10, 10, 34, 1, 14, 13, 4, 0, 2, 3};

    for (int i = 0; i < 10; i++) {
        if (!inserisciOggetto(z, objs[i])) {
            std::cout << "Oggetto " << objs[i] << " non inserito." << std::endl;
        }
    }

    std::cout << "Oggetti nello zaino:" << std::endl;
    stampaZaino(z);

    delete[] z.oggetti;

    return 0;
}

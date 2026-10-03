#include <iostream>
#include <cstring>

using namespace std;
// Non modificare la firma delle funzioni
char* reverse(char*);
char* check_palindrome(char*, bool&);
void print_story();

int main(int argc, char* argv[]) {
    // Non modificare il main, è corretto così com'è
    char name[100];
    bool is_palindrome;
    print_story();
    cout << "Enter your name: ";
    cin >> name;
    // converti il nome in minuscolo, non ci interessa la differenza tra maiuscole e minuscole
    for (int i = 0; name[i]; i++) {
        name[i] = tolower(name[i]);
    }
    char* combined = check_palindrome(name, is_palindrome);
    // Rimuovere il commento per una stampa di debug
    cout << combined << " this is your name and its reverse!" << endl;
    if (is_palindrome) {
        cout << "Wow! Your name is a palindrome!" << endl;
    } else {
        cout << "Sorry, your name is not a palindrome." << endl;
    }
    cout << endl << "What do you think? Should I believe in the legend? Or should I start studying harder?" << endl;
    delete[] combined;
    return 0;
}

char* reverse(char* name) {
    // La funzione restituisce una nuova stringa che è la versione invertita di name
    int n = strlen(name);
    // Primo errore: nella versione originale stavo eseguendo una cosiddetta "shallow copy"
    // restituendo un puntatore alla stessa stringa di input, invece di creare una nuova stringa
    // di conseguenza, modificavo la stringa originale durante l'inversione
    char* rev = new char[n + 1];
    for (int i = 0; i < n; i++) {
        // Secondo errore: senza il -1, mettevo il carattere '\0' all'inizio della stringa invertita
        // causando la stampa di una stringa vuota ogni volta
        rev[i] = name[n-i-1];
    }
    // Aggiungo il terminatore di stringa
    rev[n] = '\0';
    return rev;
}

char* check_palindrome(char* name, bool& is_palindrome) {
    // La funzione confronta il nome con la sua versione invertita
    // Il risultato del confronto viene memorizzato in is_palindrome
    // Ai fini di debug, la funzione restituisce una stringa che combina
    // il nome originale e quello invertito separati da uno spazio
    int n = strlen(name);
    char* rev = reverse(name);
    is_palindrome = (strcmp(name, rev) == 0);
    // Terzo errore: nella versione originale stavo creando un array locale
    // che veniva deallocato alla fine della funzione
    // quindi il puntatore restituito puntava a memoria non più valida
    char* combined = new char[201];
    for (int i = 0; i < n; i++) {
        combined[i] = name[i];
        combined[i + n + 1] = rev[i];
    }
    // Ritornando direttamente combined, il compilatore si accorgeva dell'errore
    // però usando una variabile di appoggio è stato facile ingannarlo :)
    char* result = combined;
    // Aggiungo lo spazio tra le due stringhe
    result[n] = ' ';
    // Posso già deallocare rev, non mi serve più e il suo contenuto è stato copiato
    delete[] rev;
    return result;
}

void print_story() {
    cout << "Pssst... Do you want to hear a secret?" << endl;
    cout << "There's an old legend that says who has a palindrome name will pass the C++ exam with full marks!" << endl;
    cout << "And so I created this program to check if my name is a palindrome." << endl;
    cout << "And I found out that's true!" << endl;
    cout << "Can you believe it? I didn't know that LudovicoSamueleGiorge was a palindrome!" << endl;
    // Mettere più ; a fine istruzione non causa errori, ma è una cattiva pratica
    cout << "Try it yourself!" << endl << endl;
}
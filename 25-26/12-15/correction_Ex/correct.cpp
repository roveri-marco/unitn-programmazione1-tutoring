#include <iostream>
#include <fstream>
#include <string>

/*
 * OBIETTIVO DELL'ESERCIZIO:
 * Il programma deve leggere una serie di numeri interi da un file 'dati.txt'
 * e caricarli su una struttura dati Stack implementata manualmente.
 * Successivamente, deve processare gli elementi dello stack:
 * - Se un numero è dispari, viene sommato a un totale.
 * - Se un numero è pari, viene rimosso e la sua metà viene aggiunta allo stack
 *   per essere processata in seguito.
 *
 * Questa è la versione finale e corretta del codice, che risolve anche
 * il bug del ciclo infinito.
*/

// --- Definizione della nostra struttura Stack personalizzata ---

struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* head;
};

// --- Funzioni di gestione dello Stack ---

void initStack(Stack* s) {
    s->head = nullptr;
}

bool isEmpty(Stack* s) {
    return s->head == nullptr;
}

void push(Stack* s, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = s->head;
    s->head = newNode;
}

// Rimuove l'elemento in cima allo stack (pop).
void pop(Stack* s) {
    if (!isEmpty(s)) {
        // CORREZIONE (Memory Leak): Deallocare la memoria del nodo rimosso.
        Node* temp = s->head;
        s->head = s->head->next;
        delete temp;
    }
}

// Legge il valore dell'elemento in cima allo stack senza rimuoverlo (top).
int top(Stack* s) {
    // CORREZIONE (Crash): Gestire il caso di stack vuoto.
    if (isEmpty(s)) {
        std::cout << "Attenzione: chiamata a top() su uno stack vuoto. Ritorno -1." << std::endl;
        return -1;
    }
    return s->head->data;
}

// Funzione che carica i dati dal file e li inserisce nello stack.
// CORREZIONE (Logica): Passare lo stack per PUNTATORE (*mioStack).
void caricaDati(std::string nomeFile, Stack* mioStack) {
    std::ifstream file(nomeFile);
    if (!file.is_open()) {
        std::cout << "Errore: impossibile aprire il file " << nomeFile << std::endl;
        return;
    }
    int numero;
    std::cout << "Tentativo di caricamento dati dal file..." << std::endl;
    while (file >> numero) {
        push(mioStack, numero);
    }
    file.close();   //file chiuso dopo la lettura
    std::cout << "Caricamento dati completato." << std::endl;
}

// Funzione che processa gli elementi dello stack secondo le regole.
void processaStack(Stack* mioStack) {
    // CORREZIONE (Dato non inizializzato): Inizializzare la somma a 0.
    int somma_elementi_dispari = 0;
    
    std::cout << "\nInizio processamento..." << std::endl;

    // CORREZIONE (Logica del ciclo): Usare 'while' per processare tutti gli elementi.
    while (!isEmpty(mioStack)) {
        int elemento_corrente = top(mioStack);
        pop(mioStack);

        std::cout << "Processo l'elemento: " << elemento_corrente << std::endl;

        // CORREZIONE LOGICA (Ciclo Infinito): Se il numero è pari, lo processiamo,
        // ma aggiungiamo la sua metà solo se il numero non è 0, per evitare
        // di inserire all'infinito 0 nello stack.
        if (elemento_corrente % 2 == 0 && elemento_corrente != 0) {
            int nuovo_elemento = elemento_corrente / 2;
            std::cout << "  -> Numero pari. Aggiungo " << nuovo_elemento << " allo stack." << std::endl;
            push(mioStack, nuovo_elemento);
        } else if (elemento_corrente % 2 != 0) { // Se è dispari
            somma_elementi_dispari += elemento_corrente;
        }
        // Se l'elemento è 0, non facciamo nulla (viene solo rimosso).
    }

    std::cout << "\nCiclo di processamento terminato." << std::endl;
    std::cout << "La somma finale degli elementi dispari e': " << somma_elementi_dispari << std::endl;
}

// Libera tutta la memoria allocata per i nodi dello stack.
void deallocaStack(Stack* s) {
    std::cout << "\nDeallocazione dello stack..." << std::endl;
    while (!isEmpty(s)) {
        pop(s);
    }
}

int main() {
    Stack stack_dati;
    initStack(&stack_dati);

    caricaDati("dati.txt", &stack_dati);
    
    if (isEmpty(&stack_dati)) {
        std::cout << "Attenzione: Lo stack risulta vuoto. Controllare il file dati.txt" << std::endl;
        return 1;
    }

    processaStack(&stack_dati);
    
    std::cout << "\nStato finale dello stack:" << std::endl;
    if (isEmpty(&stack_dati)) {
        std::cout << "Lo stack e' correttamente vuoto." << std::endl;
    } else {
        std::cout << "ERRORE LOGICO: Sono rimasti elementi non processati!" << std::endl;
    }
    
    deallocaStack(&stack_dati);

    std::cout << "\nProgramma terminato correttamente." << std::endl;
    
    return 0;
}
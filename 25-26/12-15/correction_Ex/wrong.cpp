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
 * Il codice fornito non funziona correttamente. L'obiettivo è identificare
 * e correggere tutti i bug presenti.
*/

// --- Definizione della nostra struttura Stack personalizzata ---

// Il nodo della nostra lista concatenata
struct Node {
    int data;
    Node* next;
};

// La struttura Stack che contiene il puntatore alla testa della lista
struct Stack {
    Node* head;
};

// --- Funzioni di gestione dello Stack ---

// Inizializza uno stack vuoto.
void initStack(Stack* s) {
    s->head = nullptr;
}

// Controlla se lo stack è vuoto.
bool isEmpty(Stack* s) {
    return s->head == nullptr;
}

// Aggiunge un elemento in cima allo stack (push).
void push(Stack* s, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = s->head;

    s->head = newNode;
}

// Rimuove l'elemento in cima allo stack (pop).
void pop(Stack* s) {
    if (!isEmpty(s)) {
        s->head = s->head->next;
    }
}

// Legge il valore dell'elemento in cima allo stack senza rimuoverlo (top).
int top(Stack* s) {
    return s->head->data;
}

// Funzione che carica i dati dal file e li inserisce nello stack.
void caricaDati(std::string nomeFile, Stack mioStack) {
    std::ifstream file(nomeFile);
    int numero;

    std::cout << "Tentativo di caricamento dati dal file..." << std::endl;
    while (file >> numero) {
        push(&mioStack, numero);
    }
    std::cout << "Caricamento dati completato." << std::endl;
}

// Funzione che processa gli elementi dello stack secondo le regole.
void processaStack(Stack* mioStack) {
    int somma_elementi_dispari;
    int dimensione_iniziale = 0;
    
    // Calcoliamo la dimensione iniziale per il ciclo.
    Node* current = mioStack->head;
    while(current != nullptr) {
        dimensione_iniziale++;
        current = current->next;
    }
    
    std::cout << "\nInizio processamento. Numero di elementi da processare: " << dimensione_iniziale << std::endl;

    for (int i = 0; i < dimensione_iniziale; ++i) {
        int elemento_corrente = top(mioStack);
        pop(mioStack);

        std::cout << "Processo l'elemento: " << elemento_corrente << std::endl;

        if (elemento_corrente % 2 == 0) {
            int nuovo_elemento = elemento_corrente / 2;
            std::cout << "  -> Numero pari. Aggiungo " << nuovo_elemento << " allo stack." << std::endl;
            push(mioStack, nuovo_elemento);
        } else {
            somma_elementi_dispari += elemento_corrente;
        }
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

    caricaDati("dati.txt", stack_dati);

    processaStack(&stack_dati);
    
    std::cout << "\nStato finale dello stack:" << std::endl;
    if (isEmpty(&stack_dati)) {
        std::cout << "Lo stack e' vuoto." << std::endl;
    } else {
        std::cout << "Nello stack sono rimasti degli elementi non processati:" << std::endl;
        Node* current = stack_dati.head;
        while (current != nullptr) {
            std::cout << "- " << current->data << std::endl;
            current = current->next;
        }
    }
    
    deallocaStack(&stack_dati);
    std::cout << "\nProgramma terminato." << std::endl;
    
    return 0;
}
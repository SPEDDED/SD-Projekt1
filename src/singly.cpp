#include "singly.h"
#include <iostream>

using namespace std;

singly::singly() : head(nullptr), tail(nullptr), size(0) {}

// Destruktor usuwa wszystkie elementy
singly::~singly() {
    while (head) usun_poczatek();
}

void singly::dod_poczatek(int wartosc) {
    Node* newNode = new Node{wartosc, head}; // Nowy węzeł wskazuje na obecny head
    head = newNode;                          // Nowy węzeł staje się głową
    if (!tail) tail = head;                  // Jeśli lista była pusta, head = tail
    size++;
}

void singly::dod_koniec(int wartosc) {
    Node* newNode = new Node{wartosc, nullptr};
    if (tail) {
        tail->next = newNode; // Obecny ogon wskazuje na nowy element
        tail = newNode;       // Nowy element staje się ogonem
    } else {
        head = tail = newNode; // Jeśli lista była pusta
    }
    size++;
}

void singly::dod_index(int wartosc, int indeks) {
    if (indeks <= 0) { dod_poczatek(wartosc); return; }
    if (indeks >= size) { dod_koniec(wartosc); return; }

    Node* temp = head;
    // Przejście do elementu poprzedzającego miejsce wstawienia
    for (int i = 0; i < indeks - 1; i++) temp = temp->next;
    
    Node* newNode = new Node{wartosc, temp->next}; // Nowy węzeł przejmuje wskaźnik 'next' poprzednika
    temp->next = newNode;                          // Poprzednik wskazuje na nowy węzeł
    size++;
}







void singly::usun_poczatek() {
    if (!head) return;
    Node* temp = head;     // Zapamiętanie elementu do usunięcia
    head = head->next;     // Przesunięcie głowy na następny element
    delete temp;           // Zwolnienie pamięci
    size--;
    if (size == 0) tail = nullptr; // Jeśli lista stała się pusta
}

void singly::usun_koniec() {
    if (size <= 1) { usun_poczatek(); return; }
    Node* temp = head;
    // Szukanie przedostatniego elementu
    while (temp->next != tail) temp = temp->next;
    
    delete tail;           // Usunięcie ostatniego elementu
    tail = temp;           // Przedostatni element staje się nowym ogonem
    tail->next = nullptr;
    size--;
}

void singly::usun_element(int indeks) {
    if (indeks <= 0) { usun_poczatek(); return; }
    if (indeks >= size - 1) { usun_koniec(); return; }

    Node* temp = head;
    // Przejście do elementu przed tym, który chcemy usunąć
    for (int i = 0; i < indeks - 1; i++) temp = temp->next;
    
    Node* lota = temp->next;
    temp->next = lota->next; // Ominięcie usuwanego węzła w łańcuchu
    delete lota;             // Zwolnienie pamięci
    size--;
}







int singly::znajdz(int wartosc) {
    Node* temp = head;
    int idx = 0;
    while (temp) { // Iteracja po wszystkich węzłach
        if (temp->data == wartosc) return idx; // Zwrócenie indeksu po znalezieniu
        temp = temp->next;
        idx++;
    }
    return -1; // Nie znaleziono
}

void singly::wyswietl() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

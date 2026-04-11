#include "SinglyLinkedList.h"
#include <iostream>

using namespace std;

// Inicjalizacja pustej listy
SinglyLinkedList::SinglyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

// Destruktor usuwa wszystkie elementy, aby zwolnić pamięć
SinglyLinkedList::~SinglyLinkedList() {
    while (head) usunPoczatek();
}

void SinglyLinkedList::dodajPoczatek(int wartosc) {
    Node* newNode = new Node{wartosc, head}; // Nowy węzeł wskazuje na obecny head
    head = newNode;                          // Nowy węzeł staje się głową
    if (!tail) tail = head;                  // Jeśli lista była pusta, head jest też ogonem
    size++;
}

void SinglyLinkedList::dodajKoniec(int wartosc) {
    Node* newNode = new Node{wartosc, nullptr};
    if (tail) {
        tail->next = newNode; // Obecny ogon wskazuje na nowy element
        tail = newNode;       // Nowy element staje się ogonem
    } else {
        head = tail = newNode; // Jeśli lista była pusta
    }
    size++;
}

void SinglyLinkedList::dodajNaMiejsce(int wartosc, int indeks) {
    if (indeks <= 0) { dodajPoczatek(wartosc); return; }
    if (indeks >= size) { dodajKoniec(wartosc); return; }

    Node* temp = head;
    // Przejście do elementu poprzedzającego miejsce wstawienia
    for (int i = 0; i < indeks - 1; i++) temp = temp->next;
    
    Node* newNode = new Node{wartosc, temp->next}; // Nowy węzeł przejmuje wskaźnik 'next' poprzednika
    temp->next = newNode;                          // Poprzednik wskazuje na nowy węzeł
    size++;
}

void SinglyLinkedList::usunPoczatek() {
    if (!head) return;
    Node* temp = head;     // Zapamiętanie elementu do usunięcia
    head = head->next;     // Przesunięcie głowy na następny element
    delete temp;           // Zwolnienie pamięci
    size--;
    if (size == 0) tail = nullptr; // Jeśli lista stała się pusta
}

void SinglyLinkedList::usunKoniec() {
    if (size <= 1) { usunPoczatek(); return; }
    Node* temp = head;
    // Szukanie przedostatniego elementu
    while (temp->next != tail) temp = temp->next;
    
    delete tail;           // Usunięcie ostatniego elementu
    tail = temp;           // Przedostatni element staje się nowym ogonem
    tail->next = nullptr;
    size--;
}

void SinglyLinkedList::usunElement(int indeks) {
    if (indeks <= 0) { usunPoczatek(); return; }
    if (indeks >= size - 1) { usunKoniec(); return; }

    Node* temp = head;
    // Przejście do elementu przed tym, który chcemy usunąć
    for (int i = 0; i < indeks - 1; i++) temp = temp->next;
    
    Node* doUsuniecia = temp->next;
    temp->next = doUsuniecia->next; // Ominięcie usuwanego węzła w łańcuchu
    delete doUsuniecia;             // Zwolnienie pamięci
    size--;
}

int SinglyLinkedList::znajdz(int wartosc) {
    Node* temp = head;
    int idx = 0;
    while (temp) { // Iteracja po wszystkich węzłach
        if (temp->data == wartosc) return idx; // Zwrócenie indeksu po znalezieniu
        temp = temp->next;
        idx++;
    }
    return -1; // Nie znaleziono
}

void SinglyLinkedList::wyswietl() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
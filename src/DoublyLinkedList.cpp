#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

DoublyLinkedList::~DoublyLinkedList() {
    while (head) usunPoczatek();
}

void DoublyLinkedList::dodajPoczatek(int wartosc) {
    DNode* newNode = new DNode{wartosc, head, nullptr}; // prev jest nullem
    if (head) head->prev = newNode; // Jeśli była głowa, teraz jej poprzednikiem jest nowy węzeł
    head = newNode;
    if (!tail) tail = head;
    size++;
}

void DoublyLinkedList::dodajKoniec(int wartosc) {
    DNode* newNode = new DNode{wartosc, nullptr, tail}; // next jest nullem
    if (tail) tail->next = newNode; // Obecny ogon wskazuje w przód na nowy węzeł
    tail = newNode;
    if (!head) head = tail;
    size++;
}

void DoublyLinkedList::dodajNaMiejsce(int wartosc, int indeks) {
    if (indeks <= 0) { dodajPoczatek(wartosc); return; }
    if (indeks >= size) { dodajKoniec(wartosc); return; }

    DNode* temp = head;
    for (int i = 0; i < indeks; i++) temp = temp->next; // Dojście bezpośrednio do węzła na indeksie

    // Wstawienie nowego węzła między temp->prev a temp
    DNode* newNode = new DNode{wartosc, temp, temp->prev};
    temp->prev->next = newNode;
    temp->prev = newNode;
    size++;
}

void DoublyLinkedList::usunPoczatek() {
    if (!head) return;
    DNode* temp = head;
    head = head->next;
    if (head) head->prev = nullptr; // Nowa głowa nie ma poprzednika
    else tail = nullptr;            // Lista pusta
    delete temp;
    size--;
}

void DoublyLinkedList::usunKoniec() {
    if (!tail) return;
    DNode* temp = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr; // Nowy ogon nie ma następnika
    else head = nullptr;
    delete temp;
    size--;
}

void DoublyLinkedList::usunElement(int indeks) {
    if (indeks <= 0) { usunPoczatek(); return; }
    if (indeks >= size - 1) { usunKoniec(); return; }

    DNode* temp = head;
    for (int i = 0; i < indeks; i++) temp = temp->next;

    // Przepięcie sąsiadów tak, aby wskazywali na siebie nawzajem z pominięciem 'temp'
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    size--;
}

int DoublyLinkedList::znajdz(int wartosc) {
    DNode* temp = head;
    int idx = 0;
    while (temp) {
        if (temp->data == wartosc) return idx;
        temp = temp->next;
        idx++;
    }
    return -1;
}

void DoublyLinkedList::wyswietl() {
    DNode* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

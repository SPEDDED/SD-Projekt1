#include "doubly.h"
#include <iostream>

using namespace std;

doubly::doubly() : head(nullptr), tail(nullptr), size(0) {}

doubly::~doubly() {
    while (head) usun_poczatek();
}

void doubly::dod_poczatek(int wartosc) {
    DNode* newNode = new DNode{wartosc, head, nullptr};  
    if (head) head->prev = newNode; // Jeśli była głowa, teraz jej poprzednikiem jest nowy węzeł
    head = newNode;
    if (!tail) tail = head;
    size++;
}

void doubly::dod_koniec(int wartosc) {
    DNode* newNode = new DNode{wartosc, nullptr, tail}; // next jest nullem
    if (tail) tail->next = newNode; // Obecny ogon wskazuje w przód 
    tail = newNode;
    if (!head) head = tail;
    size++;
}

void doubly::dod_index(int wartosc, int indeks) {
    if (indeks <= 0) { dod_poczatek(wartosc); return; }
    if (indeks >= size) { dod_koniec(wartosc); return; }

    DNode* temp = head;
    for (int i = 0; i < indeks; i++) temp = temp->next; // Dojście bezpośrednio do węzła na indeksie

    // Wstawienie nowego węzła między temp->prev a temp
    DNode* newNode = new DNode{wartosc, temp, temp->prev};
    temp->prev->next = newNode;
    temp->prev = newNode;
    size++;
}







void doubly::usun_poczatek() {
    if (!head) return;
    DNode* temp = head;
    head = head->next;
    if (head) head->prev = nullptr; // Nowa głowa nie ma poprzednika
    else tail = nullptr;            // Lista pusta
    delete temp;
    size--;
}

void doubly::usun_koniec() {
    if (!tail) return;
    DNode* temp = tail;
    tail = tail->prev; 
    if (tail) tail->next = nullptr; 
    else head = nullptr;
    delete temp;
    size--;
}

void doubly::usun_element(int indeks) {
    if (indeks <= 0) { usun_poczatek(); return; }
    if (indeks >= size - 1) { usun_koniec(); return; }

    DNode* temp = head;
    for (int i = 0; i < indeks; i++) temp = temp->next; // Iteracja do elementu na indeksie

    // zmiana wskaźników sąsiadów
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    size--;
}





int doubly::znajdz(int wartosc) {
    DNode* temp = head;
    int idx = 0;
    while (temp) {
        if (temp->data == wartosc) return idx;
        temp = temp->next;
        idx++;
    }
    return -1;
}

void doubly::wyswietl() {
    DNode* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

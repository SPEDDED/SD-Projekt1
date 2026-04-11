#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

// Węzeł z dwoma wskaźnikami: na następny i poprzedni element
struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};

class DoublyLinkedList {
private:
    DNode* head;
    DNode* tail;
    int size;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void dodajPoczatek(int wartosc);
    void dodajKoniec(int wartosc);
    void dodajNaMiejsce(int wartosc, int indeks);

    void usunPoczatek();
    void usunKoniec();
    void usunElement(int indeks);

    int znajdz(int wartosc);
    void wyswietl();
};

#endif
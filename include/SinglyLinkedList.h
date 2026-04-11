#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

// Struktura reprezentująca pojedynczy element listy
struct Node {
    int data;     
    Node* next;   
};
// wskaźniki na pierwszy i ostatni element listy oraz liczba elementów
class SinglyLinkedList {
private:
    Node* head;   
    Node* tail;   
    int size;     

public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    
    void dodajPoczatek(int wartosc);
    void dodajKoniec(int wartosc);
    void dodajNaMiejsce(int wartosc, int indeks);

    void usunPoczatek();
    void usunKoniec();
    void usunElement(int indeks);

    int znajdz(int wartosc);
    void wyswietl();
    int getSize() const { return size; }
};

#endif
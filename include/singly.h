#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

// Struktura reprezentująca pojedynczy element listy
struct Node {
    int data;     
    Node* next;   
};
// wskaźniki na pierwszy i ostatni element listy oraz liczba elementów
class singly {
private:
    Node* head;   
    Node* tail;   
    int size;     

public:
    singly();
    ~singly();
    
    void dod_poczatek(int wartosc);
    void dod_koniec(int wartosc);
    void dod_index(int wartosc, int indeks);

    void usun_poczatek();
    void usun_koniec();
    void usun_element(int indeks);

    int znajdz(int wartosc);
    void wyswietl();
    int Size() const { return size; }
};

#endif

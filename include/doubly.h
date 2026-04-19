#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

// Węzeł z dwoma wskaźnikami: na następny i poprzedni element
struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};

class doubly {
private:
    DNode* head;
    DNode* tail;
    int size;

public:
    doubly();
    ~doubly();

    void dod_poczatek(int wartosc);
    void dod_koniec(int wartosc);
    void dod_index(int wartosc, int indeks);

    void usun_poczatek();
    void usun_koniec();
    void usun_element(int indeks);

    int znajdz(int wartosc);
    void wyswietl();
};

#endif

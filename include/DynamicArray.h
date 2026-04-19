#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

class DynamicArray {
private:
    int* tab;
    int rozmiar;
    int pojemnosc;

    void zmien_rozmiar(int nowaPojemnosc); //Metoda co zmienia rozmiar tablicy

public:

DynamicArray(); // Konstruktor
~DynamicArray(); // Destruktor

// Metody do dodawania elementów
void dod_poczatek(int wartosc);
void dod_koniec(int wartosc);
void dod_index(int wartosc, int indeks);


// Metody do usuwania elementów
void usun_koniec();
void usun_poczatek();
void usun_element(int indeks);



int znajdz(int wartosc);
void wyswietl(); // Wyświetla zawwartość tablicy

};

#endif

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

class DynamicArray {
private:
    int* tab;
    int rozmiar;
    int pojemnosc;

    void zmienRozmiar(int nowaPojemnosc); //Metoda co zmienia rozmiar tablicy

public:

DynamicArray(); // Konstruktor
~DynamicArray(); // Destruktor

// Metody do dodawania elementów
void dodajKoniec(int wartosc);
void dodajPoczatek(int wartosc);
void dodajNaMiejsce(int wartosc, int indeks);


// Metody do usuwania elementów
void usunKoniec();
void usunPoczatek();
void usunElement(int indeks);



int znajdz(int wartosc);
void wyswietl(); // Wyświetla zawwartość tablicy

};

#endif
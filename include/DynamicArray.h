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

void dodajKoniec(int wartosc);
void dodajPoczatek(int wartosc);



void usunKoniec();
void usunPoczatek();

};

#endif
#include "DynamicArray.h"
#include <iostream>

DynamicArray::DynamicArray() { //Tworzony jest nowy obiekt z pustą tablicą
    tab = nullptr;
    rozmiar =0;
    pojemnosc=0;
}

DynamicArray::~DynamicArray() { //Destruktor do zwalniania pamięci
    delete[] tab;
}

void DynamicArray::zmienRozmiar(int nowaPojemnosc) {
    int* nowaTablica = new int[nowaPojemnosc]; //nowa tablica z nową pojemnością


    for (int i = 0; i < rozmiar; i++) {
        nowaTablica[i] = tab[i];
    }


    delete[] tab; // Usunięcie starej tablicy żeby pamięć zwolnić
    tab = nowaTablica;
    pojemnosc = nowaPojemnosc;
}


void DynamicArray::dodajKoniec(int wartosc){
    if (rozmiar == pojemnosc)
    {
        if (pojemnosc==0) //jak pojemność jest równa 0 to trzeba zrobić jedno miejsce bo inaczej będzie mnożenie przez zero
        {
            zmienRozmiar(1);

        }
        else{
            zmienRozmiar(pojemnosc*2);
        }
    }

    tab[rozmiar++]= wartosc;
}

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

void DynamicArray::dodajPoczatek(int wartosc){
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
        // Teraz przeniesienei danych o jedno miejsce w prawo aby zwolnić pierwsze miejsce
    for (int i = rozmiar; i > 0; i--)
    {
        tab[i] = tab[i-1];
    }

    tab[0] = wartosc; // No i tutaj dodanie wartości na to zwolnione miejsce
    rozmiar++;   
}





void DynamicArray::usunKoniec(){
    if (rozmiar>0)
    {
        rozmiar--;
        if (rozmiar < (pojemnosc/2) && pojemnosc>0)
        {
            zmienRozmiar(pojemnosc/2); // Zmiana rozmiaru dopiero gdy zajmowane jest mniej niż połowa obecnej pamięci / pojemności
        }
        
    }
    
}

void DynamicArray::usunPoczatek(){
    if (rozmiar>0)
    {
        //nadpisanie danych na pierwszej pozycji w tablicy i nie trzeba nic usuwać dzięki temu

        for (int i = 0; i < rozmiar-1; i++)
        {
            tab[i] = tab[i+1];
        }

        rozmiar--;

        if (rozmiar<(pojemnosc/2) && pojemnosc >0)
        {
            zmienRozmiar(pojemnosc/2); // Zmiana rozmiaru dopiero gdy zajmowane jest mniej niż połowa obecnej pamięci / pojemności
        }
    }

}


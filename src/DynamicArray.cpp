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





// Metody do dodawania elementów


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

void DynamicArray::dodajNaMiejsce(int wartosc, int indeks){
    if (indeks <0 || indeks > rozmiar) {
        std::cout << "Blad: Podano nieprawidlowy indeks." << std::endl;
        return;
    }

    if (rozmiar == pojemnosc) {
        if (pojemnosc == 0) {
            zmienRozmiar(1);//jak pojemność jest równa 0 to trzeba zrobić jedno miejsce bo inaczej będzie mnożenie przez zero
        } 
        else 
        {
            zmienRozmiar(pojemnosc * 2);
        }
    }

    for (int i= rozmiar; i> indeks; i--) // Teraz przeniesienei danych o jedno miejsce w prawo aby zwolnić miejsce
    { 
        tab[i] = tab[i-1];
    }

    tab[indeks]= wartosc;
    rozmiar++;
}




// Metody do usuwania elementów




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

void DynamicArray::usunElement(int indeks){
    if (indeks <0 || indeks>= rozmiar) 
    {
        std::cout << "Blad: Podano nieprawidlowy indeks." << std::endl;
        return;
    }
    for (int i =indeks; i < rozmiar-1; i++)
    {
        tab[i] = tab[i+1];
    }

    rozmiar--;

    if (rozmiar < (pojemnosc/2) && pojemnosc >0)
    {
        zmienRozmiar(pojemnosc/2); // Zmiana rozmiaru dopiero gdy zajmowane jest mniej niż połowa obecnej pamięci / pojemności
    }
}


// Pozostałe metody



int DynamicArray::znajdz(int wartosc){
    for (int i=0; i< rozmiar; i++)
    {
        if (tab[i] == wartosc)
        {
            return i; // Zwraca indeks pierwszego znalezionego elementu
        }
    }
    std::cout << "Nie znaleziono elementu." << std::endl;
    return -1; // Zwraca -1 jeśli element nie został znaleziony
}

void DynamicArray::wyswietl() {
    for (int i = 0; i < rozmiar; i++)
    {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
}
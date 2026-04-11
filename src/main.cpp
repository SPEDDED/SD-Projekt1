#include <iostream>
#include <fstream>
#include <chrono> // Biblioteka do precyzyjnego pomiaru czasu
#include <string>
#include "DataGenerator.h"
#include "DynamicArray.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"

using namespace std;
using namespace std::chrono;

// Funkcja pomocnicza wypisujÄ…ca czas w nanosekundach
void Czas(nanoseconds duration) {
    cout << ">>> Czas operacji: " << duration.count() << " ns" << endl;
}

int main() {
    DynamicArray d;
    SinglyLinkedList s;
    DoublyLinkedList dl;
    int wyborStruktury = 0;
    bool daneWczytane = false;

    do {
        // GĹĂ“WNE MENU WYBORU
        cout << "\n=== MENU GLOWNE ===" << endl;
        cout << "1. Generuj i wczytaj nowe dane (5000)" << endl;
        cout << "2. Generuj i wczytaj nowe dane (10000)" << endl;
        cout << "3. Generuj i wczytaj nowe dane (20000)" << endl;
        cout << "4. Generuj i wczytaj nowe dane (30000)" << endl;
        cout << "5. Generuj i wczytaj nowe dane (40000)" << endl;
        cout << "6. Generuj i wczytaj nowe dane (50000)" << endl;
        cout << "7. Wczytaj z istniejacego juz pliku" << endl;
        if (daneWczytane) {
            cout << "8. Zostaw obecne dane i zmien strukture" << endl;
        }
        cout << "0. Wyjscie" << endl;
        cout << "Wybor: ";
        int opcjaStartowa;
        cin >> opcjaStartowa;

        if (opcjaStartowa == 0) break;

        string nazwaPliku = "";

        // GENEROWANIE NOWYCH DANYCH
        if (opcjaStartowa >= 1 && opcjaStartowa <= 6) {
            int n = 0;
            if (opcjaStartowa == 1) n = 5000;
            else if (opcjaStartowa == 2) n = 10000;
            else if (opcjaStartowa == 3) n = 20000;
            else if (opcjaStartowa == 4) n = 30000;
            else if (opcjaStartowa == 5) n = 40000;
            else if (opcjaStartowa == 6) n = 50000;

            nazwaPliku = "data_" + to_string(n) + ".txt";
            DataGenerator::generateRandomData(n, 12345, nazwaPliku);
        } 
        // WCZYTYWANIE ISTNIEJÄ„CEGO PLIKU
        else if (opcjaStartowa == 7) {
            cout << "Podaj nazwe pliku (np. data_5000.txt): ";
            cin >> nazwaPliku;
        }
        // ZMIANA STRUKTURY DLA OBECNYCH DANYCH
        else if (opcjaStartowa == 8 && daneWczytane) {
            cout << "\nWYBIERZ NOWA STRUKTURE:" << endl;
            cout << "1. Tablica dynamiczna" << endl;
            cout << "2. Lista jednokierunkowa" << endl;
            cout << "3. Lista dwukierunkowa" << endl;
            cin >> wyborStruktury;
        }

        // PROCES WCZYTYWANIA (jeĹ›li wybrano opcje 1-7)
        if (opcjaStartowa >= 1 && opcjaStartowa <= 7) {
            cout << "\nWYBIERZ STRUKTURE DO TESTOW:" << endl;
            cout << "1. Tablica dynamiczna" << endl;
            cout << "2. Lista jednokierunkowa" << endl;
            cout << "3. Lista dwukierunkowa" << endl;
            cin >> wyborStruktury;

            d = DynamicArray(); 
            s = SinglyLinkedList(); 
            dl = DoublyLinkedList();

            ifstream plik(nazwaPliku);
            if (plik.is_open()) {
                int ile, liczba;
                plik >> ile; 
                auto tStart = high_resolution_clock::now();
                for (int i = 0; i < ile; i++) {
                    if (!(plik >> liczba)) break;
                    if (wyborStruktury == 1) d.dodajKoniec(liczba);
                    else if (wyborStruktury == 2) s.dodajKoniec(liczba);
                    else if (wyborStruktury == 3) dl.dodajKoniec(liczba);
                }
                auto tEnd = high_resolution_clock::now();
                cout << "\nZakonczono wczytywanie pliku: " << nazwaPliku;
                Czas(duration_cast<nanoseconds>(tEnd - tStart));
                plik.close();
                daneWczytane = true;
            } else {
                cout << "Blad: Nie znaleziono pliku " << nazwaPliku << endl;
                continue;
            }
        }

        // MENU OPERACJI DLA WYBRANEJ STRUKTURY
        int wyborMenu;
        do {
            cout << "\n--- OPERACJE NA STRUKTURZE (Wybrano: " << wyborStruktury << ") ---" << endl;
            cout << "1. Dodaj na poczatek" << endl;
            cout << "2. Dodaj na koniec" << endl;
            cout << "3. Dodaj na miejsce (indeks)" << endl;
            cout << "4. Usun z poczatku" << endl;
            cout << "5. Usun z konca" << endl;
            cout << "6. Usun z miejsca (indeks)" << endl;
            cout << "7. Wyszukaj wartosc" << endl;
            cout << "8. Wyswietl zawartosc" << endl;
            cout << "0. Powrot do menu glownego" << endl;
            cout << "Wybor: ";
            cin >> wyborMenu;

            if (wyborMenu == 0) break;

            int val = 0, idx = 0;
            high_resolution_clock::time_point t1, t2;

            if (wyborMenu >= 1 && wyborMenu <= 3) { cout << "Podaj wartosc: "; cin >> val; }
            if (wyborMenu == 3 || wyborMenu == 6) { cout << "Podaj indeks: "; cin >> idx; }
            if (wyborMenu == 7) { cout << "Podaj szukana wartosc: "; cin >> val; }

            t1 = high_resolution_clock::now();

            if (wyborStruktury == 1) { // Tablica
                if (wyborMenu == 1) d.dodajPoczatek(val);
                else if (wyborMenu == 2) d.dodajKoniec(val);
                else if (wyborMenu == 3) d.dodajNaMiejsce(val, idx);
                else if (wyborMenu == 4) d.usunPoczatek();
                else if (wyborMenu == 5) d.usunKoniec();
                else if (wyborMenu == 6) d.usunElement(idx);
                else if (wyborMenu == 7) d.znajdz(val);
                else if (wyborMenu == 8) d.wyswietl();
            } 
            else if (wyborStruktury == 2) { // SLL
                if (wyborMenu == 1) s.dodajPoczatek(val);
                else if (wyborMenu == 2) s.dodajKoniec(val);
                else if (wyborMenu == 3) s.dodajNaMiejsce(val, idx);
                else if (wyborMenu == 4) s.usunPoczatek();
                else if (wyborMenu == 5) s.usunKoniec();
                else if (wyborMenu == 6) s.usunElement(idx);
                else if (wyborMenu == 7) s.znajdz(val);
                else if (wyborMenu == 8) s.wyswietl();
            }
            else if (wyborStruktury == 3) { // DLL
                if (wyborMenu == 1) dl.dodajPoczatek(val);
                else if (wyborMenu == 2) dl.dodajKoniec(val);
                else if (wyborMenu == 3) dl.dodajNaMiejsce(val, idx);
                else if (wyborMenu == 4) dl.usunPoczatek();
                else if (wyborMenu == 5) dl.usunKoniec();
                else if (wyborMenu == 6) dl.usunElement(idx);
                else if (wyborMenu == 7) dl.znajdz(val);
                else if (wyborMenu == 8) dl.wyswietl();
            }

            t2 = high_resolution_clock::now();
            if (wyborMenu >= 1 && wyborMenu <= 7) Czas(duration_cast<nanoseconds>(t2 - t1));

        } while (wyborMenu != 0);

    } while (true);

    return 0;
}

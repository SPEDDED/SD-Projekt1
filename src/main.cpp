#include "SinglyLinkedList.h"
#include "DynamicArray.h"
#include "DoublyLinkedList.h"
#include "DataGenerator.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;

void Czas(nanoseconds duration) {
    cout << ">>> Sredni czas: " << duration.count() << " ns" << endl;
}

int main() {
    DynamicArray d;
    SinglyLinkedList s;
    DoublyLinkedList dl;
    int wyborStruktury = 0;
    bool daneWczytane = false;

    do {
        cout << "\n--- MENU GLOWNE ---" << endl;
        cout << "1. Generuj i wczytaj nowe dane (5000)" << endl;
        cout << "2. Generuj i wczytaj nowe dane (10000)" << endl;
        cout << "3. Generuj i wczytaj nowe dane (20000)" << endl;
        cout << "4. Generuj i wczytaj nowe dane (40000)" << endl;
        cout << "5. Generuj i wczytaj nowe dane (60000)" << endl;
        cout << "6. Generuj i wczytaj nowe dane (80000)" << endl;
        cout << "7. Generuj i wczytaj nowe dane (100000)" << endl;
        cout << "8. Generuj i wczytaj nowe dane (120000)" << endl;
        cout << "9. Wczytaj z istniejacego juz pliku" << endl;
        if (daneWczytane) {
            cout << "10. Zostaw obecne dane i zmien strukture" << endl;
        }
        cout << "0. Wyjscie" << endl;
        cout << "Wybor: ";
        int opcjaStartowa;
        cin >> opcjaStartowa;

        if (opcjaStartowa == 0) break;

        string nazwaPliku = "";

        if (opcjaStartowa >= 1 && opcjaStartowa <= 8) {
            int n = 0;
            if (opcjaStartowa == 1) n = 5000;
            else if (opcjaStartowa == 2) n = 10000;
            else if (opcjaStartowa == 3) n = 20000;
            else if (opcjaStartowa == 4) n = 40000;
            else if (opcjaStartowa == 5) n = 60000;
            else if (opcjaStartowa == 6) n = 80000;
            else if (opcjaStartowa == 7) n = 100000;
            else if (opcjaStartowa == 8) n = 120000;

            nazwaPliku = "data_" + to_string(n) + ".txt";
            DataGenerator::generateRandomData(n, 12345, nazwaPliku);
        } 
        else if (opcjaStartowa == 9) {
            cout << "Podaj nazwe pliku: ";
            cin >> nazwaPliku;
        }
        else if (opcjaStartowa == 10 && daneWczytane) {
            cout << "\nWYBIERZ NOWA STRUKTURE:" << endl;
            cout << "1. Tablica dynamiczna" << endl;
            cout << "2. Lista jednokierunkowa" << endl;
            cout << "3. Lista dwukierunkowa" << endl;
            cin >> wyborStruktury;
        }

        if (opcjaStartowa >= 1 && opcjaStartowa <= 9) {
            cout << "\nWYBIERZ STRUKTURE DO TESTOW:" << endl;
            cout << "1. Tablica dynamiczna" << endl;
            cout << "2. Lista jednokierunkowa" << endl;
            cout << "3. Lista dwukierunkowa" << endl;
            cout << "Wybor: ";
            cin >> wyborStruktury;

            d = DynamicArray(); 
            s = SinglyLinkedList(); 
            dl = DoublyLinkedList();

            ifstream plik(nazwaPliku);
            if (plik.is_open()) {
                int ile, liczba;
                plik >> ile; 
                for (int i = 0; i < ile; i++) {
                    if (!(plik >> liczba)) break;
                    if (wyborStruktury == 1) d.dodajKoniec(liczba);
                    else if (wyborStruktury == 2) s.dodajKoniec(liczba);
                    else if (wyborStruktury == 3) dl.dodajKoniec(liczba);
                }
                cout << "\nZakonczono wczytywanie pliku: " << nazwaPliku << endl;
                plik.close();
                daneWczytane = true;
            } else {
                cout << "Blad: Nie znaleziono pliku " << nazwaPliku << endl;
                continue;
            }
        }

        int wyborMenu;
        do {
            cout << "\n--- OPERACJE NA STRUKTURZE ---" << endl;
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
            if (wyborMenu >= 1 && wyborMenu <= 3) { cout << "Podaj wartosc: "; cin >> val; }
            if (wyborMenu == 3 || wyborMenu == 6) { cout << "Podaj indeks: "; cin >> idx; }
            if (wyborMenu == 7) { cout << "Podaj szukana wartosc: "; cin >> val; }

            if (wyborMenu >= 1 && wyborMenu <= 7) {
                long long sumaCzasu = 0;
                const int PROBY = 100;

                for (int i = 0; i < PROBY; i++) {
                    auto t1 = high_resolution_clock::now();

                    if (wyborStruktury == 1) {
                        if (wyborMenu == 1) { d.dodajPoczatek(val); d.usunPoczatek(); }
                        else if (wyborMenu == 2) { d.dodajKoniec(val); d.usunKoniec(); }
                        else if (wyborMenu == 3) { d.dodajNaMiejsce(val, idx); d.usunElement(idx); }
                        else if (wyborMenu == 4) { d.usunPoczatek(); d.dodajPoczatek(val); }
                        else if (wyborMenu == 5) { d.usunKoniec(); d.dodajKoniec(val); }
                        else if (wyborMenu == 6) { d.usunElement(idx); d.dodajNaMiejsce(val, idx); }
                        else if (wyborMenu == 7) d.znajdz(val);
                    } 
                    else if (wyborStruktury == 2) {
                        if (wyborMenu == 1) { s.dodajPoczatek(val); s.usunPoczatek(); }
                        else if (wyborMenu == 2) { s.dodajKoniec(val); s.usunKoniec(); }
                        else if (wyborMenu == 3) { s.dodajNaMiejsce(val, idx); s.usunElement(idx); }
                        else if (wyborMenu == 4) { s.usunPoczatek(); s.dodajPoczatek(val); }
                        else if (wyborMenu == 5) { s.usunKoniec(); s.dodajKoniec(val); }
                        else if (wyborMenu == 6) { s.usunElement(idx); s.dodajNaMiejsce(val, idx); }
                        else if (wyborMenu == 7) s.znajdz(val);
                    }
                    else if (wyborStruktury == 3) {
                        if (wyborMenu == 1) { dl.dodajPoczatek(val); dl.usunPoczatek(); }
                        else if (wyborMenu == 2) { dl.dodajKoniec(val); dl.usunKoniec(); }
                        else if (wyborMenu == 3) { dl.dodajNaMiejsce(val, idx); dl.usunElement(idx); }
                        else if (wyborMenu == 4) { dl.usunPoczatek(); dl.dodajPoczatek(val); }
                        else if (wyborMenu == 5) { dl.usunKoniec(); dl.dodajKoniec(val); }
                        else if (wyborMenu == 6) { dl.usunElement(idx); dl.dodajNaMiejsce(val, idx); }
                        else if (wyborMenu == 7) dl.znajdz(val);
                    }

                    auto t2 = high_resolution_clock::now();
                    sumaCzasu += duration_cast<nanoseconds>(t2 - t1).count();
                }
                Czas(nanoseconds(sumaCzasu / PROBY));
            } 
            else if (wyborMenu == 8) {
                if (wyborStruktury == 1) d.wyswietl();
                else if (wyborStruktury == 2) s.wyswietl();
                else if (wyborStruktury == 3) dl.wyswietl();
            }

        } while (wyborMenu != 0);

    } while (true);

    return 0;
}

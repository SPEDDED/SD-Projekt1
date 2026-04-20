#include "singly.h"
#include "DynamicArray.h"
#include "doubly.h"
#include "DataGenerator.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;


void Czas(nanoseconds duration) {
    cout << ">>> Sredni czas z 100 prob: " << duration.count() << " ns" << endl;
}

int main() {
    DynamicArray d;
    singly s;
    doubly dl;
    int struktura = 0;
    bool wczytano = false;

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
        cout << "0. Wyjscie" << endl;
        cout << "Wybor: ";
        int wyborWielkosci;
        cin >> wyborWielkosci;

        if (wyborWielkosci == 0) break;

        string nazwaPliku = "";


        if (wyborWielkosci >= 1 && wyborWielkosci <= 8) {
            int n = 0;
            if (wyborWielkosci == 1) n = 5000;
            else if (wyborWielkosci == 2) n = 10000;
            else if (wyborWielkosci == 3) n = 20000;
            else if (wyborWielkosci == 4) n = 40000;
            else if (wyborWielkosci == 5) n = 60000;
            else if (wyborWielkosci == 6) n = 80000;
            else if (wyborWielkosci == 7) n = 100000;
            else if (wyborWielkosci == 8) n = 120000;

            nazwaPliku = "data_" + to_string(n) + ".txt";

            DataGenerator::generateRandomData(n, 12345, nazwaPliku);
        } 
        else if (wyborWielkosci == 9) {
            cout << "Podaj nazwe pliku: ";
            cin >> nazwaPliku;
        }

        if (wyborWielkosci >= 1 && wyborWielkosci <= 9) {
            cout << "\nWYBIERZ STRUKTURE DO TESTOW:" << endl;
            cout << "1. Tablica dynamiczna" << endl;
            cout << "2. Lista jednokierunkowa" << endl;
            cout << "3. Lista dwukierunkowa" << endl;
            cout << "Wybor: ";
            cin >> struktura;


            d = DynamicArray(); 
            s = singly(); 
            dl = doubly();

            ifstream plik(nazwaPliku);
            if (plik.is_open()) {
                int ile, liczba;
                plik >> ile; 
                for (int i = 0; i < ile; i++) {
                    if (!(plik >> liczba)) break;
                    if (struktura == 1) d.dod_koniec(liczba);
                    else if (struktura == 2) s.dod_koniec(liczba);
                    else if (struktura == 3) dl.dod_koniec(liczba);
                }
                cout << "\nZakonczono wczytywanie pliku: " << nazwaPliku << endl;
                plik.close();
                wczytano = true;
            } else {
                cout << "Blad: Nie znaleziono pliku " << nazwaPliku << endl;
                continue;
            }
        }

        int menuOperacji;
        do {
            cout << "\n--- OPERACJE NA STRUKTURZE (POMIAR SREDNI) ---" << endl;
            cout << "1. Dodaj na poczatek" << endl;
            cout << "2. Dodaj na koniec" << endl;
            cout << "3. Dodaj na miejsce" << endl;
            cout << "4. Usun z poczatku" << endl;
            cout << "5. Usun z konca" << endl;
            cout << "6. Usun z miejsca" << endl;
            cout << "7. Wyszukaj wartosc" << endl;
            cout << "8. Wyswietl zawartosc" << endl;
            cout << "0. Powrot do menu glownego" << endl;
            cout << "Wybor: ";
            cin >> menuOperacji;

            if (menuOperacji == 0) break;

            int val = 0, idx = 0;
            if (menuOperacji >= 1 && menuOperacji <= 3) { cout << "Podaj wartosc: "; cin >> val; }
            if (menuOperacji == 3 || menuOperacji == 6) { cout << "Podaj indeks: "; cin >> idx; }
            if (menuOperacji == 7) { cout << "Podaj szukana wartosc: "; cin >> val; }

            if (menuOperacji >= 1 && menuOperacji <= 7) {
                long long sumaNanosekund = 0;
                const int proby = 100; 

                for (int i = 0; i < proby; i++) {
                    high_resolution_clock::time_point t1, t2;


                    if (struktura == 1) {
                        if (menuOperacji == 1) { 
                            t1 = high_resolution_clock::now(); d.dod_poczatek(val); t2 = high_resolution_clock::now();
                            d.usun_poczatek(); 
                        }
                        else if (menuOperacji == 2) { 
                            t1 = high_resolution_clock::now(); d.dod_koniec(val); t2 = high_resolution_clock::now();
                            d.usun_koniec(); 
                        }
                        else if (menuOperacji == 3) { 
                            t1 = high_resolution_clock::now(); d.dod_index(val, idx); t2 = high_resolution_clock::now();
                            d.usun_element(idx); 
                        }
                        else if (menuOperacji == 4) { 
                            t1 = high_resolution_clock::now(); d.usun_poczatek(); t2 = high_resolution_clock::now();
                            d.dod_poczatek(val); 
                        }
                        else if (menuOperacji == 5) { 
                            t1 = high_resolution_clock::now(); d.usun_koniec(); t2 = high_resolution_clock::now();
                            d.dod_koniec(val); 
                        }
                        else if (menuOperacji == 6) { 
                            t1 = high_resolution_clock::now(); d.usun_element(idx); t2 = high_resolution_clock::now();
                            d.dod_index(val, idx); 
                        }
                        else if (menuOperacji == 7) {
                            t1 = high_resolution_clock::now(); d.znajdz(val); t2 = high_resolution_clock::now();
                        }
                    } 

                    else if (struktura == 2) { 
                        if (menuOperacji == 1) { 
                            t1 = high_resolution_clock::now(); s.dod_poczatek(val); t2 = high_resolution_clock::now();
                            s.usun_poczatek(); 
                        }
                        else if (menuOperacji == 2) { 
                            t1 = high_resolution_clock::now(); s.dod_koniec(val); t2 = high_resolution_clock::now();
                            s.usun_koniec(); 
                        }
                        else if (menuOperacji == 3) { 
                            t1 = high_resolution_clock::now(); s.dod_index(val, idx); t2 = high_resolution_clock::now();
                            s.usun_element(idx); 
                        }
                        else if (menuOperacji == 4) { 
                            t1 = high_resolution_clock::now(); s.usun_poczatek(); t2 = high_resolution_clock::now();
                            s.dod_poczatek(val); 
                        }
                        else if (menuOperacji == 5) { 
                            t1 = high_resolution_clock::now(); s.usun_koniec(); t2 = high_resolution_clock::now();
                            s.dod_koniec(val); 
                        }
                        else if (menuOperacji == 6) { 
                            t1 = high_resolution_clock::now(); s.usun_element(idx); t2 = high_resolution_clock::now();
                            s.dod_index(val, idx); 
                        }
                        else if (menuOperacji == 7) {
                            t1 = high_resolution_clock::now(); s.znajdz(val); t2 = high_resolution_clock::now();
                        }
                    }

                    else if (struktura == 3) {
                        if (menuOperacji == 1) { 
                            t1 = high_resolution_clock::now(); dl.dod_poczatek(val); t2 = high_resolution_clock::now();
                            dl.usun_poczatek(); 
                        }
                        else if (menuOperacji == 2) { 
                            t1 = high_resolution_clock::now(); dl.dod_koniec(val); t2 = high_resolution_clock::now();
                            dl.usun_koniec(); 
                        }
                        else if (menuOperacji == 3) { 
                            t1 = high_resolution_clock::now(); dl.dod_index(val, idx); t2 = high_resolution_clock::now();
                            dl.usun_element(idx); 
                        }
                        else if (menuOperacji == 4) { 
                            t1 = high_resolution_clock::now(); dl.usun_poczatek(); t2 = high_resolution_clock::now();
                            dl.dod_poczatek(val); 
                        }
                        else if (menuOperacji == 5) { 
                            t1 = high_resolution_clock::now(); dl.usun_koniec(); t2 = high_resolution_clock::now();
                            dl.dod_koniec(val); 
                        }
                        else if (menuOperacji == 6) { 
                            t1 = high_resolution_clock::now(); dl.usun_element(idx); t2 = high_resolution_clock::now();
                            dl.dod_index(val, idx); 
                        }
                        else if (menuOperacji == 7) {
                            t1 = high_resolution_clock::now(); dl.znajdz(val); t2 = high_resolution_clock::now();
                        }
                    }

                    sumaNanosekund += duration_cast<nanoseconds>(t2 - t1).count();
                }

                Czas(nanoseconds(sumaNanosekund / proby));
            } 
            else if (menuOperacji == 8) {
                if (struktura == 1) d.wyswietl();
                else if (struktura == 2) s.wyswietl();
                else if (struktura == 3) dl.wyswietl();
            }

        } while (menuOperacji != 0);

    } while (true);

    return 0;
}
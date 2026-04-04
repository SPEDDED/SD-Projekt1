#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

class DynamicArray {
private:
    int* array;
    int size;
    int capacity;

    void resize(int newCapacity); //Metoda co zmienia rozmiar tablicy

public:

DynamicArray(); // Konstruktor
~DynamicArray(); // Destruktor




};

#endif
#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H

#include <string>


// Generuje plik z losowymi liczbami całkowitymi o wielkości 4 bajtów
class DataGenerator {
public:

    static void generateRandomData(int count, int seed, const std::string& filename);
};

#endif
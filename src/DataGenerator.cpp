#include "DataGenerator.h"
#include <fstream>
#include <cstdlib>
#include <iostream>

void DataGenerator::generateRandomData(int count, int seed, const std::string& filename) {

    srand(seed);


    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cout << "Blad: Nie mozna otworzyc pliku do zapisu: " << filename << std::endl;
        return;
    }


    outFile << count << "\n";    // W pierwszej linii w pliku wypisanie liczby wygenerowanych liczb
    for (int i = 0; i < count; ++i) {
        
        outFile << rand() << "\n";  // Generowanie liczb
    }


    outFile.close();
    std::cout << "Wygenerowano " << count << " elementow w pliku: " << filename << std::endl;
}
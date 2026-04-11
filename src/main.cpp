#include "DataGenerator.h"
int main() {
    DataGenerator::generateRandomData(5000, 12345, "data/data_5000.txt");
    DataGenerator::generateRandomData(10000, 12345, "data/data_10000.txt");
    return 0;
}
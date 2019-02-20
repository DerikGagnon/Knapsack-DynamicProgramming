#include "item.hpp"
#include "knapsack.hpp"

int main() {
    std::string filename = "test.txt";
    Item * itemArray;
    std::ifstream fin;
    fin.open(filename);
    int maxWeight = 0, numberOfItems = 0;

    fin >> maxWeight >> numberOfItems;
    itemArray = new Item[numberOfItems];

    for (int i = 0; i < numberOfItems; i++ ) {
        
    }

    std::cin.get();
    return 0;
}
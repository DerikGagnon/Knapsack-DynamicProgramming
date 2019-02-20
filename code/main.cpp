#include "item.hpp"
#include "knapsack.hpp"

int main() {
    std::string filename = "test.txt";
    std::string tempName;
    int tempValue = 0, tempWeight = 0;
    Item * itemArray;
    std::ifstream fin;
    fin.open(filename);
    int maxWeight = 0, numberOfItems = 0;

    fin >> maxWeight >> numberOfItems;
    itemArray = new Item[numberOfItems];

    for (int i = 0; i < numberOfItems; i++ ) {
        fin >> tempName >> tempWeight >> tempValue;
        itemArray[i].setName(tempName);
        itemArray[i].setWeight(tempWeight);
        itemArray[i].setValue(tempValue);
    }

    std::cin.get();
    return 0;
}
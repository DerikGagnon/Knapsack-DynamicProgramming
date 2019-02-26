#include "item.hpp"

int main() {
    std::string filename = "../resources/test3.txt";
    std::string tempName;
    int tempValue = 0, tempWeight = 0;
    Item * itemArray;
    std::ifstream fin;
    fin.open(filename);
    int maxWeight = 0, numberOfItems = 0;

    fin >> maxWeight >> numberOfItems;

    //std::cout << maxWeight << " " << numberOfItems;

    itemArray = new Item[numberOfItems];

    for (int i = 0; i < numberOfItems; i++ ) {
        fin >> tempName >> tempWeight >> tempValue;
        itemArray[i].setName(tempName);
        itemArray[i].setWeight(tempWeight);
        itemArray[i].setValue(tempValue);
        //std::cout << itemArray[i].getName() << " " << itemArray[i].getValue() << " " << itemArray[i].getWeight() << "\n";
    }

    // Tested on http://karaffeltut.com/NEWKaraffeltutCom/Knapsack/knapsack.html
    int result = dynamicProgram(numberOfItems, maxWeight, itemArray);
    std::cout << "The maximum value of loot for the " << maxWeight << " pound knapsack is $" << result << ".";

    delete [] itemArray;

    std::cout << "\nPress Enter to continue...";
    std::cin.get();
    return 0;
}
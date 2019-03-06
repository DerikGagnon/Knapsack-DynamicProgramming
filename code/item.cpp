#include "item.hpp"

/* ---------------------- Item Class  ---------------------------*/

//Constructors
Item::Item() {
    mName = "";
    mWeight = 0;
    mValue = 0;
}

Item::Item(std::string name, int weight, int value) {
    mName = name;
    mWeight = weight;
    mValue = value;
}

Item::~Item() {
    //std::cout << "\nDeleting";
}

int maxValue(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}

int dynamicProgram(int numItems, int weightLimit, Item * items) {
	int ** table;
	table = new int*[numItems + 1];
	for (int i = 0; i < numItems + 1; i++) {
		table[i] = new int[weightLimit + 1];
	}
	//int table[numItems + 1][weightLimit + 1];

    //initialize table
    for (int i = 0; i < numItems + 1; i++) {
        table[i][0] = 0;
    }
    for (int i = 0; i < weightLimit + 1; i++) {
        table[0][i] = 0;
    }

    //Iterate through the table
    for (int i = 1; i < numItems + 1; i++) {
        for (int j = 1; j < weightLimit + 1; j++) {
            //If item is less than the weight capacity
            if (items[i - 1].getWeight() <= j) {
                // https://en.wikipedia.org/wiki/Knapsack_problem#0/1_knapsack_problem
                table[i][j] = maxValue(items[i - 1].getValue() + table[i - 1][j - items[i - 1].getWeight()], table[i - 1][j]);
            } else {
                // Just use the element before
                table[i][j] = table[i - 1][j];
            }
        }
    }

    //return max Value in Table
    return table[numItems][weightLimit];
}
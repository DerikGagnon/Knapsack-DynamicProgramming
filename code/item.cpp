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
    int table[numItems + 1][weightLimit + 1];

    //initialize table
    // for (int i = 0; i < numItems + 1; i++) {
    //     table[i][0] = 0;
    // }
    // for (int i = 0; i < weightLimit + 1; i++) {
    //     table[0][i] = 0;
    // }
      
// 20     if w[i] > j:                      //item cannot fit in the bag (THIS WAS MISSING FROM THE PREVIOUS ALGORITHM)
// 21         value[i,j] = value[i-1,j]
// 22     else: 
// 23         if (value[i-1, j-w[i]] == -1) then:     //m[i-1,j-w[i]] has not been calculated, we have to call function m
// 24             value[i-1, j-w[i]] = m(i-1, j-w[i])
// 25         value[i, j] = max(value[i-1,j], value[i-1, j-w[i]] + v[i])

    for (int i = 0; i < numItems + 1; i++) {
        for (int  j = 0; j < weightLimit + 1; j++) {
            table[i][j] = -1;
        }
    }

    if (numItems == 0 || weightLimit <= 0 ) {
        return 0;
    }

    if (table[numItems - 1][weightLimit] == -1) {
        table[numItems - 1][weightLimit] = dynamicProgram(numItems - 1, weightLimit, items);
    }

    if (items[numItems].getWeight() > weightLimit) {
        table[numItems][weightLimit] = table[numItems - 1][weightLimit];
    } 
    else {
        if (table[numItems - 1][weightLimit - items[numItems].getWeight()] == -1) {
            table[numItems - 1][weightLimit - items[numItems].getWeight()] = dynamicProgram(numItems - 1, weightLimit - items[numItems].getWeight(), items);
        }
        table[numItems][weightLimit] = maxValue(table[numItems - 1][weightLimit], table[numItems - 1][weightLimit - items[numItems].getWeight()] + items[numItems].getValue());
    }

    // for (int i = 1; i <= numItems; i++) {
    //     for (int j = 1; j <= weightLimit; j++) {
    //         if (items[i - 1].getWeight() <= j) {
    //             // https://en.wikipedia.org/wiki/Knapsack_problem#0/1_knapsack_problem
    //             table[i][j] = maxValue(items[i - 1].getValue() + table[i - 1][j - items[i - 1].getWeight()], table[i - 1][j]);
    //         } else {
    //             table[i][j] = table[i - 1][j];
    //         }
    //     }
    // }

    //return max Value in Table
    return table[numItems][weightLimit];
}
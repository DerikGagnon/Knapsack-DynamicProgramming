#include "knapsack.hpp"

Knapsack::Knapsack() {
    mMaxWeight = 0;
    mArraySize = 0;
    mItemArray = NULL;
}

Knapsack::Knapsack(int weight, int size, Item * array) {
    mMaxWeight = weight;
    mArraySize = size;
    mItemArray = array;
}


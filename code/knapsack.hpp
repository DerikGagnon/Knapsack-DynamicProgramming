#ifndef KNAPSACK.HPP
#define KNAPSACK.HPP

#include "item.hpp"

class Knapsack {
    private:
        int mMaxWeight, mArraySize;
        Item * mItemArray;
    public:
        //Constructor
        Knapsack();
        Knapsack(int max, int arraySize, Item * array);
        
        //Destructor
        ~Knapsack();

        //Getters
        int getMaxWeight() {return mMaxWeight;}
        int getArraySize() {return mArraySize;}

        //Setters
        void setMaxWeight(int weight) {mMaxWeight = weight;}
        void setArraySize(int size) {mArraySize = size;}
};

#endif
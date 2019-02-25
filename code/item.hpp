#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

class Item {
    private:
        std::string mName;
        int mWeight, mValue;
    public:
        //Constructors
        Item();
        Item(std::string name, int weight, int value);

        //Destructor
        ~Item();

        //Getters
        std::string getName() {return mName;}
        int getWeight() {return mWeight;}
        int getValue() {return mValue;}

        //Setters
        void setName(std::string name) {mName = name;}
        void setWeight(int weight) {mWeight = weight;}
        void setValue(int value) {mValue = value;}

};

int dynamicProgram(int numItems, int weightLimit, Item * items);
int maxValue(int num1, int num2);

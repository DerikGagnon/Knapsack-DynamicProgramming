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
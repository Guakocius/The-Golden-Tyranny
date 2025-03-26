#include "../include/items.h"

using namespace items;

Item::Item() {
    generateRandomItem();
};

void Item::randomizeItem(float dropRate) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(0.0, 1.0);
}

void Item::generateRandomItem() {
    randomizeItem(dropRate);
}
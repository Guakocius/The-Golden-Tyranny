#include "../include/items.h"
#include "../include/player.h"

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

/*int Item::addItem(lua_State* L) {
    std::string name = lua_tostring(L, 1);
    int quantity = lua_tointeger(L, 2);



    return 0;
} */
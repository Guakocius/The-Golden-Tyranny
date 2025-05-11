#include "../include/items.h"
#include "../include/player.h"
#include "../include/entities.h"

using namespace items;

Item::Item() {
    generateRandomItem();
};

void Item::randomizeItem(float *dropRate(Rarity rarity)) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(0.0, 1.0);
}

void Item::generateRandomItem() {
    randomizeItem(dropRate);
}

std::map<items::ItemSlot, items::Item> Entity::getEquippedItems(std::map<items::ItemSlot, items::Item> equippedItems) const {
    auto idx = equippedItems.find(slot);
    if (idx != equippedItems.end()) {
        return idx->second;
    }
    return Item();
}


/*int Item::addItem(lua_State* L) {
    std::string name = lua_tostring(L, 1);
    int quantity = lua_tointeger(L, 2);



    return 0;
} */
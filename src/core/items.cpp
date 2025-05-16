#include "../include/items.hpp"
#include "../include/player.hpp"
#include "../include/entities.hpp"

using namespace items;

Item::Item() {
    randomizeItem(rarityDropRate);
};

std::string Item::rarityToString(Rarity rarity) {
    switch (rarity) {
        case Rarity::COMMON: return "Common";
        case Rarity::UNCOMMON: return "Uncommon";
        case Rarity::RARE: return "Rare";
        case Rarity::EPIC: return "Epic";
        case Rarity::LEGENDARY: return "Legendary";
        default: return "Unknown";
    }
}

void Item::randomizeItem(float rarityDrop) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(0.0, 1.0);

    rarityDrop = dropRate(rarity);
    float randomValue = dis(gen);
    if (randomValue <= rarityDrop) {
       // TODO: Implement a json file with item names as prefix, type and suffix
        name = "Random Item";
        baseValue = static_cast<int>(randomValue * 100);
        monetaryValue = static_cast<int>(randomValue * 50);
    } else {
        // Handle the case where the item is not generated
        name = "No Item";
        baseValue = 0;
        monetaryValue = 0;
    }
    std::cout << "Generated item: " << name << ", base value: " << baseValue
              << ", monetary value: " << monetaryValue << ", based on rarity: "
              << rarityToString(rarity) << ", with drop rate: "
              << rarityDrop << std::endl;
}

std::map<items::ItemSlot, items::Item> Entity::getEquippedItems(std::map<items::ItemSlot, items::Item> equippedItems) const {
    std::map<items::ItemSlot, items::Item> result;
    items::ItemSlot slot;
    auto idx = equippedItems.find(slot);
    if (idx != equippedItems.end()) {
        result[slot] = idx->second;
    }
    return result;
}


/*int Item::addItem(lua_State* L) {
    std::string name = lua_tostring(L, 1);
    int quantity = lua_tointeger(L, 2);



    return 0;
} */
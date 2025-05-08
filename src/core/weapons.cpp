#include "../include/weapons.h"

#include <fstream>
#include <iostream>

std::vector<Weapon> Weapon::loadWeapons() {
    using json = nlohmann::json;

    std::vector<Weapon> vweapons;
    std::ifstream file("/src/data/items.json");

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << &file << std::endl;
        return vweapons;
    }

    json weaponData;
    file >> weaponData;

    for (const auto& weapons : weaponData["weapons"]) {
        Weapon weapon(
            weapons["name"],
            weapons["baseValue"],
            weapons["monetaryValue"],
            static_cast<items::Rarity>(weapons["rarity"]),
            weapons["dropRate"],
            weapons["damage"]
        );
        vweapons.push_back(weapon);
    }
    return vweapons;
}
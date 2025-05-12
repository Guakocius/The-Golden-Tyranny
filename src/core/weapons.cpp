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

        items::Rarity rarity = static_cast<items::Rarity>(weapons["rarity"]);

        float dropRate = items::Item().dropRate(rarity);
        Weapon weapon(
            weapons["name"].get<std::string>(),
            weapons["baseValue"].get<int>(),
            weapons["monetaryValue"].get<int>(),
            rarity,
            dropRate,
            weapons["damage"].get<int>()
        );
        vweapons.push_back(weapon);
    }
    return vweapons;
}
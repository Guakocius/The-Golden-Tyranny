#include "../../include/enemy.h"

items::Item Item(std::string name, int baseValue, int monetaryValue, items::Rarity rarity, float dropRate);

void Enemy::dropLoot() {
    std::cout << "Loot dropped from " << getEntityName() << ":\n";
    for (const auto& loot : lootTable) {
        for (const auto& item : loot) {
            
        }
    }
}
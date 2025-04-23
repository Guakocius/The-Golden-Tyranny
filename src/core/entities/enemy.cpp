#include "../../include/enemy.h"

items::Item Item(std::string name, int baseValue, int monetaryValue, items::Rarity rarity, float dropRate);
Enemy::EnemyData EnemyData(std::string name, int health, int mana, int level,
    std::vector<items::Item> equippedItems,
    std::vector<std::pair<std::string, int>> inventory,
    std::vector<std::map<std::string, items::Item>> lootTables);

void Enemy::dropLoot() {
    std::cout << "Loot dropped from " << getEntityName() << ":\n";
    Enemy enemy(getEntityName(), getHealth(), getMana(), getLevel(),
        getEquippedItems(), getInventory(), getLootTables());

        std::map<std::string, int> loot;

    for (const auto& lootTable : enemy.lootTables) {
        for (const auto& itemPair : lootTable) {
            const std::string& itemName = itemPair.first;
            const items::Item& item = itemPair.second;

            loot[itemName]++;
        }
    }

    for (const auto& collectedLoot : loot) {
        std::cout << collectedLoot.second << "x " << collectedLoot.first << "\n";
    }
}
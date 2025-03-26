#ifndef ENEMY_H
#define ENEMY_H

#include "entities.h"

#include <iostream>

class Enemy : public Entity {
    public:
        Enemy(std::string enemyName, int health, int mana, int level,
            std::vector<items::Item> equippedItems, std::vector<std::string> inventory, std::vector<std::map<std::string, items::Item>> lootTable)
                : Entity(enemyName, health, mana, level), equippedItems(equippedItems), inventory(inventory), lootTable(lootTable) {};

        virtual ~Enemy() {};
        void dropLoot();


    private:
        std::vector<items::Item> equippedItems; // Array of items the enemy has equipped
        std::vector<std::string> inventory; // Array of items the enemy has
        std::vector<std::map<std::string, items::Item>> lootTable; // Non-fixed Array of several Loot Tables
};

#endif // !ENEMY_H
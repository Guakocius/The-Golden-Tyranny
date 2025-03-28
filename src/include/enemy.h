#ifndef ENEMY_H
#define ENEMY_H

#include "entities.h"

#include <iostream>

class Enemy : public Entity {
    public:

        struct EnemyData {
            std::string name;
            int health;
            int mana;
            int level;
            std::vector<items::Item> equippedItems;
            std::vector<std::string> inventory;
            std::vector<std::map<std::string, items::Item>> lootTables;

        }
        Enemy(EnemyData::name, EnemyData::health, EnemyData::mana, EnemyData::level,
            EnemyData::equippedItems, EnemyData::inventory, EnemyData::lootTables)
                : Entity(enemyName, health, mana, level), equippedItems(equippedItems), inventory(inventory), lootTable(lootTable) {};

        virtual ~Enemy() {};
        void dropLoot();
};



#endif // !ENEMY_H
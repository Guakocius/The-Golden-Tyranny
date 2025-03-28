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
            std::vector<std::pair<std::string, int>> inventory;
            std::vector<std::map<std::string, items::Item>> lootTables;

        };
        Enemy(const std::string name, int health, int mana, int level,
            const std::vector<items::Item>& equippedItems,
            const std::vector<std::pair<std::string, int>>& inventory,
            const std::vector<std::map<std::string, items::Item>>& lootTables);

        virtual ~Enemy() {};
        void dropLoot();
};

#endif // !ENEMY_H
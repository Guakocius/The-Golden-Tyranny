#ifndef ENTITIES_H
#define ENTITIES_H

#include "items.h"

#include <vector>
#include <map>

class Entity {
    public:
        Entity(std::string entityName, int health, int mana, int level)
            : entityName(entityName), health(health), mana(mana), level(level) {};

        virtual ~Entity() {};

        int getHealth() const { return health; }
        int getMana() const { return mana; }
        int getLevel() const { return level; }
        std::string getEntityName() const { return entityName; }
        std::vector<items::Item> getEquippedItems() const { return equippedItems; }
        std::vector<std::pair<std::string, int>> getInventory() const { return inventory; }



        void setHealth(int health) { this->health = health; }
        void setMana(int mana) { this->mana = mana; }
        void setLevel(int level) { this->level = level; }
        void setEntityName(std::string entityName) { this->entityName = entityName; }
        void setEquippedItems(std::vector<items::Item> equippedItems) { this->equippedItems = equippedItems; }
        void setInventory(std::vector<std::pair<std::string, int>> inventory) { this->inventory = inventory; }

        void attack();
        void useMagic();
        void useItem();

    protected:
        std::string entityName;
        int health;
        int mana;
        int level;
        std::vector<items::Item> equippedItems;
        std::vector<std::pair<std::string, int>> inventory;

};

#endif // !ENTITIES_H

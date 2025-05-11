#ifndef ENTITIES_H
#define ENTITIES_H

#include "items.h"


#include <vector>
#include <map>
#include <iostream>

class Entity {
    public:
        Entity(std::string entityName, int health, int mana, int level)
            : entityName(entityName), health(health), mana(mana), level(level) {};

        virtual ~Entity() {};

        int getHealth() const { return health; }
        int getMana() const { return mana; }
        int getLevel() const { return level; }
        std::string getEntityName() const { return entityName; }
        std::map<items::ItemSlot, items::Item> getEquippedItems(std::map<items::ItemSlot, items::Item> equippedItems) const;

        void equipItem(items::ItemSlot slot, const items::Item& item) { equippedItems[slot] = item; }
        void unequipItem(items::ItemSlot slot) { equippedItems.erase(slot); }
        void swapItem(items::ItemSlot slot, items::Item& equippedItem,
            items::Item& equippableItem) {
                auto idx = equippedItems.find(slot);
                if (idx != equippedItems.end()) {

                    if (idx->second.name == equippedItem.name) {
                        idx->second = equippableItem;
                        equippableItem = equippedItem;
                    } else {
                        std::cerr << "Error: The equipped item in the slot "
                            << "does not match the provided item." << std::endl;
                    }
                } else {
                    std::cerr << "No item is equipped in the specified slot"
                        << std::endl;
                }
            }

        std::vector<std::pair<std::string, int>> getInventory() const { return inventory; }


        int damage;
        int getDamage() const { return damage; }

        void setHealth(int health) { this->health = health; }
        void setMana(int mana) { this->mana = mana; }
        void setLevel(int level) { this->level = level; }
        void setEntityName(std::string entityName) { this->entityName = entityName; }
        void setEquippedItems(std::map<items::ItemSlot, items::Item> equippedItems) { this->equippedItems = equippedItems; }
        void setInventory(std::vector<std::pair<std::string, int>> inventory) { this->inventory = inventory; }

        /**
         * @brief Checks what entity type it is
         * @param Entity* entity
         * @return (entity == Player) ? 1 : 0
         */
        bool checkEntity(Entity* entity) const;

        void attack();
        void useMagic();
        void useItem();

    protected:
        std::string entityName;
        int health;
        int mana;
        int level;
        std::map<items::ItemSlot, items::Item> equippedItems;
        std::vector<std::pair<std::string, int>> inventory;

};

#endif // !ENTITIES_H

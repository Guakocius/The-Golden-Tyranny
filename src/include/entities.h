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

        void setHealth(int health) { this->health = health; }
        void setMana(int mana) { this->mana = mana; }
        void setLevel(int level) { this->level = level; }
        void setEntityName(std::string entityName) { this->entityName = entityName; }

        void attack();
        void useMagic();
        void useItem();

    protected:
        std::string entityName;
        int health;
        int mana;
        int level;

};

#endif // !ENTITIES_H

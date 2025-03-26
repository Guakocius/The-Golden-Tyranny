#ifndef PLAYER_H
#define PLAYER_H

#include "entities.h"
#include "save.h"


class Player : public Entity {
    public:

        Player(std::string playerName, int health, int mana, int level,  int experience, std::map<std::string, int> inventory);


        int getExperience() const { return experience; }
        std::map<std::string, int> getInventory() const { return inventory; }

        void setExperience(int experience) { this->experience = experience; }
        void setInventory(std::map<std::string, int> inventory) { this->inventory = inventory; }

        void gainExperience(int experience) { this->experience += experience; }
        void collectLoot(const std::string& lootItem);
        void displayInventory() const;

        SaveData getSaveData() const;
        void loadFromSave(const SaveData& save);

    private:
        int experience;
        std::map<std::string, int> inventory;
};

#endif // !PLAYER_H
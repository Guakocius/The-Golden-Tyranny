#ifndef PLAYER_H
#define PLAYER_H

#include "entities.h"
#include "save.h"
#include "items.h"
#include "character.h"


class Player : public Entity {
    public:
        PlayerClass playerClass;
        std::string className = playerClass.className;
        Player(std::string playerName, std::string playerClassName, int health, int mana, int level,  int experience,
            std::vector<std::pair<std::string, int>> inventory);

        int getExperience() const { return experience; }
        std::vector<std::pair<std::string, int>> getInventory() const { return inventory; }

        void setExperience(int experience) { this->experience = experience; }
        void setInventory(std::vector<std::pair<std::string, int>> inventory) { this->inventory = inventory; }

        void gainExperience(int experience) { this->experience += experience; }
        void collectLoot(const std::string& lootItem);
        void displayInventory() const;

        SaveData getSaveData() const;
        void loadFromSave(const SaveData& save);

    private:
        int experience;
        std::vector<std::pair<std::string, int>> inventory;
};

#endif // !PLAYER_H
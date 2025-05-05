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
        Player(std::string playerName, PlayerClass playerClass, int level,  int experience,
            std::vector<std::pair<std::string, int>> inventory)
        : Entity(playerName, playerClass.health, playerClass.mana, level),
          playerClass(playerClass), experience(experience), inventory(inventory) {
            this->stamina = playerClass.stamina;
            this->strength = playerClass.strength;
            this->dexterity = playerClass.dexterity;
            this->intelligence = playerClass.intelligence;
          };

        int getExperience() const { return experience; }
        int getStamina() const { return stamina; }
        std::vector<std::pair<std::string, int>> getInventory() const { return inventory; }
        PlayerClass getPlayerClass() const { return playerClass; }

        void setStamina(int stamina) { this->stamina = stamina; }
        void setExperience(int experience) { this->experience = experience; }
        void setInventory(std::vector<std::pair<std::string, int>> inventory) { this->inventory = inventory; }
        void setPlayerClass(PlayerClass playerClass) { this->playerClass = playerClass; }

        void gainExperience(int experience) { this->experience += experience; }
        void collectLoot(const std::string& lootItem);
        void displayInventory() const;

        SaveData getSaveData() const;
        void loadFromSave(const SaveData& save);

    private:
        int stamina;
        int strength;
        int dexterity;
        int intelligence;
        int experience;
        std::vector<std::pair<std::string, int>> inventory;
};

extern Player player;

#endif // !PLAYER_H
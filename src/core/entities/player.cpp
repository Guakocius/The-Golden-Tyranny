#include "../../include/player.h"
#include "../../include/character.h"

Player::Player(std::string playerName, std::string playerClassName, int health, int mana, int stamina, int level, int experience,
    std::vector<std::pair<std::string, int>> inventory)
    : Entity(playerName, health, mana, level), stamina(stamina), experience(experience), inventory(inventory) {
    playerClass.className = playerClassName;
}

void setClassName(PlayerClass& playerClass, std::string& className) {
    playerClass.className = className;
}
std::string& getClassName(PlayerClass& playerClass, std::string& className) {
    return playerClass.className = className;
}

/*SaveData Player::getSaveData() const {
    return SaveData(health, mana, level, entityName, experience, inventory);
}

void Player::loadFromSave(const SaveData& save) {
    health = save.health;
    mana = save.mana;
    level = save.level;
    entityName = save.playerName;
    experience = save.experience;
    inventory = save.inventory;
}*/
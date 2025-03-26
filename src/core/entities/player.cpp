#include "../../include/player.h"

Player::Player(int health, int mana, int level, std::string playerName, int experience, std::map<std::string, int> inventory)
    : Entity(health, mana, level, playerName), experience(experience), inventory(inventory) {};

SaveData Player::getSaveData() const {
    return SaveData(health, mana, level, entityName, experience, inventory);
}

void Player::loadFromSave(const SaveData& save) {
    health = save.health;
    mana = save.mana;
    level = save.level;
    entityName = save.playerName;
    experience = save.experience;
    inventory = save.inventory;
}
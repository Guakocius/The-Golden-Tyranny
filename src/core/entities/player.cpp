#include "../../include/player.h"
#include "../../include/character.h"
#include "../../include/game.h"
#include "../../include/items.h"

void Entity::attack() {
    if (checkEntity(this)) {
        
    }
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
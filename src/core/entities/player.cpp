#include "../../include/player.h"
#include "../../include/character.h"
#include "../../include/game.h"
#include "../../include/items.h"

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

int getDamage(Player player, std::map<items::ItemSlot, items::Item> equippedItems) {
            int damage = 0;
            auto weapon = equippedItems.find(items::ItemSlot::WEAPON);
            std::string className = player.getPlayerClass().className;
            int strength = player.getPlayerClass().strength;
            int dexterity = player.getPlayerClass().dexterity;
            int intelligence = player.getPlayerClass().intelligence;

            if (weapon != equippedItems.end()) {
                damage = weapon->second.baseValue;

                if (className == "Warrior") {
                    damage += strength;
                } else if (className == "Rogue") {
                    damage += dexterity;
                } else if (className == "Mage") {
                    damage += intelligence;
                }
            }
            return damage;
        }

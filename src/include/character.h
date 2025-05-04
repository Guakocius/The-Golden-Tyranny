#ifndef CHARACTER_H
#define CHARACTER_H

#include "player.h"
#include "game.h"

struct Stats {
    int strength;
    int dexterity;
    int intelligence;
};

struct PlayerClass {
    std::string className;
    int health;
    int mana;
    int stamina;
    int strength;
    int dexterity;
    int intelligence;
};

void setClassName(PlayerClass& playerClass, std::string className) { playerClass.className = className; };
std::string& getClassName(PlayerClass& playerClass, std::string& className) { return playerClass.className = className; };

#endif // !CHARACTER_H
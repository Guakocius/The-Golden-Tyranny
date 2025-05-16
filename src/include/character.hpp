#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

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

void setClassName(PlayerClass playerClass, std::string className);
std::string getClassName(PlayerClass playerClass, std::string className);

#endif // !CHARACTER_H
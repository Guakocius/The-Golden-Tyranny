#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

struct Stats {
    int strength;
    int dexterity;
    int intelligence;
};

struct PlayerClass {
    std::string className = "";
    int health = 0;
    int mana = 0;
    int stamina = 0;
    int strength = 0;
    int dexterity = 0;
    int intelligence = 0;

    PlayerClass() = default;

PlayerClass(std::string n, int h, int m, int s, int str, int  dex, int i)
    : className(n), health(h), mana(m), stamina(s), strength(str), dexterity(dex), intelligence(i) {};

};


void setClassName(PlayerClass playerClass, std::string className);
std::string getClassName(PlayerClass playerClass, std::string className);

#endif // !CHARACTER_HPP
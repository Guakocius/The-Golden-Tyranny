#ifndef SAVE_H
#define SAVE_H

#include <string>
#include <map>

struct SaveData {
    std::string playerName;
    int health;
    int mana;
    int level;
    int experience;
    std::map<std::string, int> inventory;

    SaveData() = default;

    SaveData(std::string playerName, int health, int mana, int level,
        int experience, std::map<std::string, int> inventory)
            : playerName(playerName), health(health), mana(mana), level(level),
                 experience(experience), inventory(inventory) {};
};

#endif // !SAVE_H
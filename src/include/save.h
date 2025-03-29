#ifndef SAVE_H
#define SAVE_H

#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <iostream>

struct SaveData {
    std::string playerName;
    int health;
    int mana;
    int level;
    int experience;
    std::vector<std::pair<std::string, int>> inventory;

    SaveData() = default;

    SaveData(std::string playerName, int health, int mana, int level,
        int experience, std::vector<std::pair<std::string, int>> inventory)
            : playerName(playerName), health(health), mana(mana), level(level),
                 experience(experience), inventory(inventory) {};
};

namespace save_load_game {
    void saveGame(SaveData& save);
    void loadGame(SaveData& save);
}

#endif // !SAVE_H
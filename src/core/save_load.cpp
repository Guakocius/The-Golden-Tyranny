#include "../include/save.h"

using namespace save_load_game;

void saveGame(SaveData &save)
{
    std::ofstream file("./saves/savegame.sav", std::ios::binary);

    size_t len = save.inventory.size();
    size_t lenSave = sizeof(save);

    /*if (file.is_open())
    {

        for (size_t i = 0; i < lenSave; i++)
        {
            if (save.getValues(i).toInt == 0)
            {
                std::cout << "Error: Unable to save game." << std::endl;
            }
        }

        file << save.playerName << "\n"
             << save.health << "\n"
             << save.mana << "\n"
             << save.level << "\n"
             << save.experience << std::endl;
        for (const auto &item : save.inventory)
        {
            file << item.first << " " << item.second << std::endl;
        }
        //<< save.inventory.size() << "\n";
        file.close();
        std::cout << "Game saved successfully." << std::endl;
    }
    else {
        std::cout << "Error: Unable to save game." << std::endl;
    }*/
}

/*void loadGame(SaveData &save)
{
    std::ifstream file("./saves/savegame.sav", std::ios::binary);

    if (file.is_open())
    {

        file >> save.playerName >> save.health >> save.mana >> save.level >> save.experience >> save.inventory;

        file.close();
        std::cout << "Game loaded successfully." << std::endl;
    }
    else
    {
        std::cout << "Error: Unable to load game." << std::endl;
    }
}*/

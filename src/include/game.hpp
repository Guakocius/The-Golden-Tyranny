#ifndef GAME_H
#define GAME_H

#include "player.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <nlohmann/json.hpp>

namespace game {

    class GameMenu {
    public:

        enum class GameState {
            RUNNING,
            EXPLORATION,
            COMBAT,
            PAUSE,
            SAFE,
            PLAYER_INJURED,
            PLAYER_DEAD,
            EXIT_GAME,
        };

        enum class CurrentMenu {
            MAIN_MENU,
            CLASS_SELECTION,
            GAME_MENU,
            NEW_GAME,
            LOAD_GAME,
            OPTIONS,
            EXIT_GAME,
        };

        void startMenu(GameMenu::CurrentMenu currMenu);
        void classSelection();
        void exploration();
        void playerChoice(GameMenu::CurrentMenu currMenu);
        void newGame();
        void loadGame();
        void options();
        void exitGame();

        struct PauseMenu {
            public:
                void displayMenu();
                void continueGame();
                void newGame();
                void saveGame(SaveData& save);
                void loadGame();
                void options();
                void exitGame();
        };
    };
}

#endif // !GAME_H

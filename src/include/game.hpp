#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "nlohmann/json.hpp"

namespace game {

    extern const std::string invalidChoice;
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

        typedef GameState GameState;

        enum class CurrentMenu {
            MAIN_MENU,
            CLASS_SELECTION,
            EXPLORATION_MENU,
            NEW_GAME,
            LOAD_GAME,
            OPTIONS,
            EXIT_GAME,
        };

        typedef CurrentMenu CurrentMenu;

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

#endif // !GAME_HPP

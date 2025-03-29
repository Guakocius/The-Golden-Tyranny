#ifndef GAME_H
#define GAME_H

#include "player.h"

#include <iostream>
#include <string>

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
        };

        void newGame();
        void loadGame();
        void options();
        void exitGame();

        class StartMenu {
            public:
                void startMenu(std::istream& input, const std::string& headDecision, int choice);
                void newGame();
                void loadGame();
                void options();
                void exitGame();


        };

        class PauseMenu {
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
extern GameMenu gameMenu;

}

#endif // !GAME_H

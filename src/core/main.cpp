#include "../include/game.h"

#include <cstdlib>
#include <curses.h>
#include <chrono>
#include <thread>

game::GameMenu::StartMenu startMenu;

struct GameState {

    std::string playerName;
    int level;
    int health;
};

void gameLoop() {

}
//TODO: Implement the load game function.
void saveGame(const GameState& state) {

    std::ofstream file("savegame.sav", std::ios::binary);

    if(file.is_open()) {
        file << state.playerName << "\n"
             << state.level << "\n"
             << state.health << "\n";
        file.close();
        std::cout << "Game saved." << std::endl;
    } else {
        std::cout << "Error: Unable to save game." << std::endl;
    }
}

int main() {

    std::string headDecision = "Choose an action:\n";
    int choice;
    startMenu.startMenu(std::cin, headDecision, choice);
    std::cin.ignore();

    return 0;
}
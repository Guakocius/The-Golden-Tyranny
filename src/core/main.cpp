#include "../include/game.h"

#include <cstdlib>
#include <curses.h>
#include <chrono>
#include <thread>

using namespace game;
GameMenu::StartMenu startMenu;
GameMenu::PauseMenu pauseMenu;

void gameLoop() {

}
//TODO: Implement the load game function.


int main() {

    std::string headDecision = "Choose an action:\n";
    int choice;
    startMenu.startMenu(std::cin, headDecision, choice);
    std::cin.ignore();

    return 0;
}
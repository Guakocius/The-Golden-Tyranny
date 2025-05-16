#include "../include/game.hpp"

#include <cstdlib>
#include <chrono>
#include <thread>

using namespace game;
GameMenu gameMenu;
GameMenu::PauseMenu pauseMenu;

void gameLoop() {

}

int main() {

    GameMenu::CurrentMenu currMenu = GameMenu::CurrentMenu::MAIN_MENU;
    gameMenu.playerChoice(currMenu);
    std::cin.ignore();
    return 0;
}
#include "../include/game.hpp"
#include "../include/world.hpp"

#include <cstdlib>
#include <chrono>
#include <thread>

using namespace game;
World world;
enum class World::WorldSize size;
GameMenu gameMenu;
GameMenu::PauseMenu pauseMenu;

int main() {

    GameMenu::CurrentMenu currMenu = GameMenu::CurrentMenu::MAIN_MENU;
    gameMenu.playerChoice(currMenu);
    std::cin.ignore();
    return 0;
}
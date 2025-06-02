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

    std::cout << "Small size: " << world.getSize(World::WorldSize::SMALL)
        << "\n Medium size: " << world.getSize(World::WorldSize::MEDIUM)
        << "\n Large size: " << world.getSize(World::WorldSize::LARGE)
        << std::endl;

    while(true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    GameMenu::CurrentMenu currMenu = GameMenu::CurrentMenu::MAIN_MENU;
    gameMenu.playerChoice(currMenu);
    std::cin.ignore();
    return 0;
}
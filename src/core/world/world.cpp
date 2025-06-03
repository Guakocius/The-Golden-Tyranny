#include "../../include/world.hpp"

#include <random>
#include <utility>

using namespace game;

World::WorldSize worldSize;
World world;
GameMenu menu;

void World::generateWorld() {
    int choice;
    std::cin >> choice;
    std::cin.ignore();

    World::WorldSize worldSize;
    switch (choice) {
    case 1:
        worldSize = World::WorldSize::SMALL;
        break;
    case 2:
        worldSize = World::WorldSize::MEDIUM;
        break;
    case 3:
        worldSize = World::WorldSize::LARGE;
    default:
        std::cout << invalidChoice << std::endl;
        generateWorld();
        break;
    }


    world.generateWorld(world.getSize(worldSize));

    GameMenu::GameState state = GameMenu::GameState::EXPLORATION;
    GameMenu::CurrentMenu currMenu = GameMenu::CurrentMenu::EXPLORATION_MENU;
    menu.playerChoice(currMenu);
}

void World::generateWorld(int size) {
    std::cout << "World size: " << size << std::endl;
    for (int i = 0; i <= size; i++) {

    }

}

int World::getSize(World::WorldSize size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    auto [min, max] = (size == World::WorldSize::SMALL)  ? std::make_pair(5, 10) :
                      (size == World::WorldSize::MEDIUM) ? std::make_pair(11, 20) :
                      (size == World::WorldSize::LARGE)  ? std::make_pair(21, 40) :
                                                           std::make_pair(-1, -1);
    if (min < 0 && max < 0) {
        printf("%s\n", "No world size defined!");
        return max;
    }

    std::uniform_int_distribution<> distrib(min, max);

    int randVal = distrib(gen);

    return randVal;
}
void World::setRooms(std::vector<Exploration::Room> rooms, int size) {
    size = getSize(worldSize);
}
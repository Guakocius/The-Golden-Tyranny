#include "../../include/world.hpp"

#include <random>
#include <utility>

enum class World::WorldSize worldSize;


void World::generateWorld(int size) {

}

int World::getSize(enum class World::WorldSize size) {
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

    std::cout << "Random number between " << min << " and " << max << " is "
        << randVal << std::endl;

    return randVal;
}
void World::setRooms(std::vector<Exploration::Room> rooms, int size) {
    size = getSize(worldSize);
}
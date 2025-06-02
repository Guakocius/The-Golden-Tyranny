#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>
#include "exploration.hpp"


class World {
    public:
        std::vector<Exploration::Room> rooms;

        enum class WorldSize {
            SMALL,
            MEDIUM,
            LARGE
        };


        World(std::vector<Exploration::Room> rooms, enum class WorldSize)
        : rooms(rooms), WorldSize(WorldSize) {};

        World() = default;

        void generateWorld(int size);

        void setRooms(std::vector<Exploration::Room> rooms, int size);
        int getSize(enum class WorldSize);


    private:
        WorldSize WorldSize;
};

#endif // !WORLD_HPP
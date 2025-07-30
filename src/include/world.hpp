#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>

#include "exploration.hpp"

using json = nlohmann::json;

class World {
    public:
        std::vector<Exploration::Room> rooms;

        enum class WorldSize {
            SMALL,
            MEDIUM,
            LARGE
        };

        typedef WorldSize WorldSize;


        World(std::vector<Exploration::Room> rooms, int size)
        : rooms(rooms), size(size) {};

        World() = default;

        void generateWorld();
        void generateWorld(int size);

        void setRooms(std::vector<Exploration::Room> rooms, int size);
        void setSize(WorldSize WorldSize);

        int getSize(WorldSize WorldSize);
        void from_json(const json& json, Exploration::Room& room);


    private:
        int size;
};

#endif // !WORLD_HPP

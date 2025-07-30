#ifndef EXPLORATION_HPP

#include "game.hpp"

class Exploration {
    public:
    static bool isInDialogue;

    struct Room {
        std::string name;
        int id;
        std::string description;
    };

    Exploration(Player player, Room room)
    : player(player), room(room) {};

    struct ExplorationIndoors {

    };
    struct ExplorationHeartlands {
        void explore(Exploration explore);
    };

    private:
    Room room;
    Player player;
};

#endif // !EXPLORATION_HPP

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Exploration::Room, name, id, description)

#define IN_DIALOGUE Exploration::isInDialogue


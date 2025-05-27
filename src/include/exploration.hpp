#ifndef EXPLORATION_HPP

#include "game.hpp"

class Exploration {
    public:

    Exploration(Player player, std::map<std::string, int> room)
    : player(player), room(room) {};

    struct ExplorationIndoors {

    };
    struct ExplorationHeartlands {
        void explore(Exploration explore);
    };

    private:

    Player player;
    std::map<std::string, int> room;
};

#endif // !EXPLORATION_HPP

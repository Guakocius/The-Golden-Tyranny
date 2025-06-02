#include "../../include/exploration.hpp"

bool Exploration::isInDialogue = false;

void Exploration::ExplorationHeartlands::explore(Exploration explore) {

    while (true) {
        if (!IN_DIALOGUE) {
            std::cout << "You awake from sleep with a heavy headache - bound with chains. You don't remember anything, \n"
            << "from your past, how you got here, or where you are." << std::endl;
            IN_DIALOGUE = true;


        }
    }

};

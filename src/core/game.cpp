#include "../include/game.h"

using namespace game;

    using StartMenu = GameMenu::StartMenu;
    void StartMenu::startMenu(std::istream& input, const std::string& headDecision, int choice) {

        std::cout << "1. New Game\n2. Load Game\n3. Options\n4. Exit\n" << std::endl;
        std::cout.flush();
        input >> choice;
        std::cin.ignore();
        std::cout << "\n";

        switch(choice) {
            case 1:
                newGame();
                break;
            case 2:
                //loadGame();
                break;
            case 3:
                //options();
                break;
            case 4:
                //exitGame();
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }

    }


    void StartMenu::newGame() {

        std::cout << "Welcome to the world of Apexia!\n" << std::endl;
        std::cout << "For centuries, the Sun Elves of Solarion believed themselves destined to rule. Under the divine mandate\n"
        "of the Sun God, their golden banners swept across the continent of Apexia, uniting the fractured realms\n"
        "under a single banner. At the helm of this conquest stood Sun Emperor Lotharian, a visionary ruler\n"
        "whose relentless campaigns saw the collapse of every kingdom, city-state, and freehold that once stood\n"
        "defiant.\n\n"
        "With the known world now under the Empire's dominion, the Golden Century began—a time of\n"
        "unparalleled wealth, knowledge, and progress. The marble spires of Solarion gleamed in the eternal sun,\n"
        "its scholars and artisans ushering in an age of enlightenment. The Sun Elven aristocracy flourished,\n"
        "basking in the empire's prosperity, their dominion unchallenged... or so they believed.\n\n"
        "Beyond the gilded walls of Solarion's grandeur, however, the fires of rebellion burn. The conquered\n"
        "races—humans, dwarves, orcs, and others—chafe under elven rule. Forbidden from practicing their\n"
        "ancient traditions, taxed beyond reason, and consigned to servitude, they now rise in defiance. Across\n"
        "the empire's vast lands, hidden insurgencies grow bolder, striking at garrisons, sabotaging supply lines,\n"
        "and rallying behind fallen kings and forgotten gods.\n\n"
        "For the first time in a century, the Sun Elves face a war not of conquest, but of survival. The empire\n"
        "stands at a crossroads—will it tighten its grip to crush the uprisings, or will its hubris lead to a reckoning\n"
        "that even the light of the Sun God cannot prevent?\n" << std::endl;
        std::cout.flush();

    }

    void StartMenu::loadGame() {

    }

    void GameMenu::options() {

    }

    void GameMenu::exitGame() {

    }


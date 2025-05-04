#include "../include/game.h"
#include "../include/entities.h"
#include "../include/character.h"

#include <chrono>
#include <thread>
#include <string>

using namespace game;

using PauseMenu = GameMenu::PauseMenu;

std::string chooseAnAction = "Choose an action: ";

void GameMenu::startMenu(GameMenu::CurrentMenu currMenu) {
    while (true) {
        std::cout << chooseAnAction << "\n"
                  << "1. New Game\n2. Load Game\n3. Options\n4. Exit\n"
                  << std::endl;
        std::cout.flush();

        int choice;
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice. Please try again." << std::endl;
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n";

        switch (choice) {
            case 1:
                std::cout << "Starting a new game..." << std::endl;
                std::cout.flush();
                std::this_thread::sleep_for(std::chrono::seconds(2));
                currMenu = GameMenu::CurrentMenu::NEW_GAME;
                GameMenu::playerChoice(currMenu);
                break;
            case 2:
                std::cout << "Loading game..." << std::endl;
                std::cout.flush();
                std::this_thread::sleep_for(std::chrono::seconds(2));
                currMenu = GameMenu::CurrentMenu::LOAD_GAME;
                GameMenu::playerChoice(currMenu);
                break;
            case 3:
                currMenu = GameMenu::CurrentMenu::OPTIONS;
                GameMenu::playerChoice(currMenu);
                break;
            case 4:
                currMenu = GameMenu::CurrentMenu::EXIT_GAME;
                GameMenu::playerChoice(currMenu);
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                GameMenu::startMenu(currMenu);
                break;
        }
    }
}

void GameMenu::newGame() {
    std::cout << "Welcome to the world of Apexia!\n" << std::endl;
    std::cout
        << "For centuries, the Sun Elves of Solarion believed themselves destined to rule. Under the divine mandate\n"
        << "of the Sun God, their golden banners swept across the continent of Apexia, uniting the fractured realms\n"
        << "under a single banner. At the helm of this conquest stood Sun Emperor Lotharian, a visionary ruler\n"
        << "whose relentless campaigns saw the collapse of every kingdom, city-state, and freehold that once stood\n"
        << "defiant.\n\n"
        << "With the known world now under the Empire's dominion, the Golden Century began—a time of\n"
        << "unparalleled wealth, knowledge, and progress. The marble spires of Solarion gleamed in the eternal sun,\n"
        << "its scholars and artisans ushering in an age of enlightenment. The Sun Elven aristocracy flourished,\n"
        << "basking in the empire's prosperity, their dominion unchallenged... or so they believed.\n\n"
        << "Beyond the gilded walls of Solarion's grandeur, however, the fires of rebellion burn. The conquered\n"
        << "races—humans, dwarves, orcs, and others—chafe under elven rule. Forbidden from practicing their\n"
        << "ancient traditions, taxed beyond reason, and consigned to servitude, they now rise in defiance. Across\n"
        << "the empire's vast lands, hidden insurgencies grow bolder, striking at garrisons, sabotaging supply lines,\n"
        << "and rallying behind fallen kings and forgotten gods.\n\n"
        << "For the first time in a century, the Sun Elves face a war not of conquest, but of survival. The empire\n"
        << "stands at a crossroads—will it tighten its grip to crush the uprisings, or will its hubris lead to a reckoning\n"
        << "that even the light of the Sun God cannot prevent?\n"
        << std::endl;
    std::cout.flush();

    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "Press Enter to continue..." << std::endl;
    std::cin.ignore();

    CurrentMenu currMenu = GameMenu::CurrentMenu::CLASS_SELECTION;
    playerChoice(currMenu);
}

void GameMenu::classSelection() {
    using json = nlohmann::json;

    std::string playerName;
    std::ifstream file("src/data/classes.json");

    while (!file.is_open()) {
        std::cerr << "Error opening file. Please check the file path." << std::endl;
        return;
    }

    json classData;
    file >> classData;

    std::cout << "Enter your name: ";
    std::getline(std::cin, playerName);
    std::cout << "\n";

    std::cout << "Select your class:\n" << std::endl;
    const auto& classes = classData["classes"];
    for (size_t i = 0; i < classes.size(); ++i) {
        std::cout << i + 1 << ". " << classes[i]["name"] << ":\n"
                  << classes[i]["description"] << std::endl;

        for (const auto& stat : classes[i]["stats"].items()) {
            std::cout << "   " << stat.key() << ": " << stat.value() << std::endl;
        }
        std::cout << std::endl;
    }
    int choice;
    std::cin >> choice;

    if (choice > 0 && choice <= static_cast<int>(classes.size())) {
        const auto& selectedClass = classes[choice - 1];
        std::cout << "You have selected the " << selectedClass["name"] << " class:\n"
                  << selectedClass["description"] << std::endl;

        PlayerClass playerClass {
            selectedClass["name"],
            selectedClass["health"],
            selectedClass["mana"],
            selectedClass["stamina"],
            selectedClass["strength"],
            selectedClass["dexterity"],
            selectedClass["intelligence"]
        };

        std::cout << "Stats:\n";
        for (const auto& stat : selectedClass["stats"].items()) {
            std::cout << "   " << stat.key() << ": " << stat.value() << std::endl;
        }
        Player::Player player(playerName, playerClass, )
    }
}

void GameMenu::playerChoice(GameMenu::CurrentMenu currMenu) {
    switch (currMenu) {
        case GameMenu::CurrentMenu::MAIN_MENU:
            startMenu(currMenu);
            break;
        case GameMenu::CurrentMenu::CLASS_SELECTION:
            classSelection();
            break;
        case GameMenu::CurrentMenu::NEW_GAME:
            newGame();
            break;
        case GameMenu::CurrentMenu::LOAD_GAME:
            loadGame();
            break;
        case GameMenu::CurrentMenu::OPTIONS:
            options();
            break;
        case GameMenu::CurrentMenu::EXIT_GAME:
            exitGame();
            break;
        default:
            std::cout << "Invalid game menu" << std::endl;
            break;
    }
}

void GameMenu::loadGame() {
}

void GameMenu::options() {
    std::cout << "Options Menu\n" << std::endl;
    std::cout << "1. Gameplay\n2. Audio\n3. Display\n4. Back to Main Menu\n" << std::endl;
    std::cout.flush();
    int choice;

    std::cin >> choice;
    std::cin.ignore();
    std::cout << "\n";

    // TODO: Implement the options menu's functions
    switch (choice) {
        case 1:
            // gameplayOptions();
            break;
        case 2:
            // audioOptions();
            break;
        case 3:
            // displayOptions();
            break;
        case 4:
            // backToMainMenu();
            break;
    }
}

void GameMenu::exitGame() {
    exit(0);
}

void PauseMenu::saveGame(SaveData& save) {
}

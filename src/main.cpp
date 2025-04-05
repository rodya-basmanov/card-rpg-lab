/**
 * @file main.cpp
 * @brief Main entry point of the card RPG game
 * @details Contains the main function that initializes and runs the game
 */

#include <iostream>
#include "GameManager.h"
#include "Warrior.h"
#include "Mage.h"
#include "Archer.h"
#include "Healer.h"

/**
 * @brief Main entry point of the application
 * @param argc Number of command-line arguments
 * @param argv Array of command-line arguments
 * @return Exit code, 0 on normal termination
 * @details Initializes the game and runs it in normal mode or test mode
 *          depending on command-line arguments
 */
int main(int argc, char* argv[]) {
    bool testMode = false;

    if (argc > 1 && std::string(argv[1]) == "--test") {
        testMode = true;
    }

    auto player = createPlayer(testMode);
    GameManager gameManager(player);

    if (testMode) {
        gameManager.runTestMode();
    } else {
        gameManager.run();
    }

    return 0;
}
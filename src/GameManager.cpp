/**
 * @file GameManager.cpp
 * @brief Implementation of the GameManager class
 * @details Contains the implementation of the main game controller that manages
 *          different game modes and player interactions
 */

#include "GameManager.h"
#include "BattleMode.h"
#include "TradingMode.h"
#include "DungeonMode.h"
#include "ExplorationMode.h"
#include "AttackCard.h"
#include "DefenseCard.h"
#include "Fireball.h"
#include "IceSpike.h"
#include "Poison.h"
#include "LightningCard.h"
#include "TrapCard.h"
#include "SpecialCard.h"
#include "Regeneration.h"
#include "Shield.h"
#include "Warrior.h"
#include "PvPMode.h"
#include "Mage.h"
#include "Archer.h"
#include "Healer.h"
#include "HealthPotion.h"
#include "ManaElixir.h"
#include "UI.h"
#include <iostream>

/**
 * @brief Creates a player character
 * @param testMode Whether the game is running in test mode
 * @return A shared pointer to the created Character
 * @details In test mode, returns a predefined Warrior character.
 *          In normal mode, allows the player to choose a character class
 *          and customize their name.
 */
std::shared_ptr<Character> createPlayer(bool testMode) {
    if (testMode) {
        return std::make_shared<Warrior>("TestHero", 200, 50, 20, 10);
    }

    std::cout << "Choose your class:\n";
    std::cout << "1. Warrior\n";
    std::cout << "2. Mage\n";
    std::cout << "3. Archer\n";
    std::cout << "4. Healer\n";

    int choice;
    std::cin >> choice;

    std::string name;
    std::cout << "Enter your character's name: ";
    std::cin >> name;

    switch (choice) {
        case 1:
            return std::make_shared<Warrior>(name, 200, 50, 20, 10);
        case 2:
            return std::make_shared<Mage>(name, 100, 100, 15, 5);
        case 3:
            return std::make_shared<Archer>(name, 150, 50, 18, 8);
        case 4:
            return std::make_shared<Healer>(name, 120, 80, 10, 10);
        default:
            std::cout << "Invalid choice. Defaulting to Warrior.\n";
            return std::make_shared<Warrior>(name, 200, 50, 20, 10);
    }
}

/**
 * @brief Constructor for GameManager
 * @param p Shared pointer to the player character
 * @details Initializes a GameManager with the player character and creates
 *          a trader NPC. Sets up the initial game state and welcome message.
 */
GameManager::GameManager(std::shared_ptr<Character> p)
    : player(p), currentMode(nullptr), isGameRunning(true) 
{
    trader = std::make_shared<Warrior>("Trader", 100, 0, 0, 0);
    auto traderDeck = std::make_shared<Deck>();
    traderDeck->addCard(std::make_shared<AttackCard>());
    traderDeck->addCard(std::make_shared<DefenseCard>());
    traderDeck->addCard(std::make_shared<Fireball>());
    traderDeck->addCard(std::make_shared<IceSpike>());
    traderDeck->addCard(std::make_shared<Poison>());
    traderDeck->addCard(std::make_shared<LightningCard>());
    traderDeck->addCard(std::make_shared<TrapCard>());
    traderDeck->addCard(std::make_shared<SpecialCard>());
    traderDeck->addCard(std::make_shared<Regeneration>());
    traderDeck->addCard(std::make_shared<Shield>());
    trader->setDeck(traderDeck);

    player->getInventory()->addItem(new HealthPotion());
    player->getInventory()->addItem(new ManaElixir());
}

/**
 * @brief Main game loop
 * @details Displays a menu to the player and handles mode selection.
 *          Continues running until the player chooses to exit.
 *          Allows the player to switch between different game modes:
 *          Battle, Trading, Dungeon, Exploration, and PvP.
 */
void GameManager::run() {
    while (isGameRunning) {
        UI::clearScreen();
        std::cout << COLOR_YELLOW << "===== MAIN MENU =====" << COLOR_RESET << "\n";
        std::cout << "1. Battle\n2. Trading\n3. Dungeon\n4. Exploration\n5. PvP\n6. Exit\n";
        std::cout << "Choose an option: ";       
        
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:                        
                currentMode = std::make_shared<BattleMode>(player, std::make_shared<Warrior>("Goblin", 50, 0, 10, 5));
                currentMode->start();
                break;
            case 2: {
                currentMode = std::make_shared<TradingMode>(player, trader);
                currentMode->start();
                break;
            }
            case 3:
                currentMode = std::make_shared<DungeonMode>(player);
                currentMode->start();
                break;
            case 4:
                currentMode = std::make_shared<ExplorationMode>(player);
                currentMode->start();
                break;
            case 5: {
                auto player2 = createPlayer();
                currentMode = std::make_shared<PvPMode>(player, player2);
                currentMode->start();
                break;
            }
            case 6:
                isGameRunning = false;
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
        }
    }
}

/**
 * @brief Switches the current game mode
 * @param mode Shared pointer to the new game mode
 * @details Updates the current mode to the specified one and prints
 *          a message indicating the mode switch. This allows the game
 *          to transition between different gameplay modes (battle, trading, etc.)
 */
void GameManager::switchMode(std::shared_ptr<GameMode> mode) {
    currentMode = mode;
}

/**
 * @brief Runs the game in test mode
 * @details Creates a simple battle scenario for testing purposes with a predefined enemy.
 *          At the end of the battle, reports whether the test passed or failed based on
 *          whether the player survived the encounter.
 */
void GameManager::runTestMode() {
    currentMode = std::make_shared<BattleMode>(player, std::make_shared<Warrior>("TestEnemy", 50, 0, 10, 5));
    currentMode->start();

    if (!player->isAlive()) {
        std::cout << "Test failed: Player died!" << std::endl;
    } else {
        std::cout << "Test passed: Player survived!" << std::endl;
    }
}
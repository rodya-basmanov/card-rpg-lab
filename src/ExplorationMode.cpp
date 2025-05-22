/**
 * @file ExplorationMode.cpp
 * @brief Implementation of the ExplorationMode class
 * @details Contains the implementation of the exploration game mode
 *          where players can discover and fight random encounters
 */

#include "ExplorationMode.h"
#include "BattleMode.h"
#include "AttackCard.h"
#include "DefenseCard.h"
#include "Fireball.h"
#include "IceSpike.h"
#include "Warrior.h"
#include "Mage.h"
#include "Archer.h"
#include "EasyAI.h"
#include "Shield.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

/**
 * @brief Constructor for ExplorationMode
 * @param p Shared pointer to the player character
 * @details Initializes the exploration mode with the player character
 *          and seeds the random number generator for encounter generation
 */
ExplorationMode::ExplorationMode(std::shared_ptr<Character> p)
    : player(p) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

/**
 * @brief Starts the exploration mode
 * @details Presents exploration options to the player and handles their choices.
 *          Allows players to explore different areas, encounter random enemies,
 *          engage in battle, and return to the main menu. Includes mechanics
 *          for finding treasure and restoring health/mana during exploration.
 */
void ExplorationMode::start() {
    std::cout << "You enter a dark forest... Be careful!" << std::endl;
    while (player->isAlive()) {
        std::cout << "\nChoose an action:\n1. Explore\n2. Leave the forest\n";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            generateRandomEvent();
        } else if (choice == 2) {
            std::cout << "You leave the forest.\n";
            break;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }
}

/**
 * @brief Generates a random exploration event
 * @details Creates a random event for the player during exploration.
 *          Possible events include: finding new cards, encountering enemies,
 *          discovering health potions, or nothing happening.
 *          Combat encounters are handled through the BattleMode class.
 */
void ExplorationMode::generateRandomEvent() {
    int event = std::rand() % 4;
    std::shared_ptr<Character> enemy;
    switch (event) {
        case 0: {
            std::cout << "You found an Attack Card!\n";
            player->getDeck()->addCard(std::make_shared<AttackCard>());
            break;
        }
        case 1: {
            std::cout << "You found a Defense Card!\n";
            player->getDeck()->addCard(std::make_shared<DefenseCard>());
            break;
        }
        case 2: {
            std::cout << "An enemy attacks you!\n";
            auto enemy = generateRandomEnemy();
            
            #ifdef TESTING
            // В тестовой среде используем тестовый режим для BattleMode
            BattleMode battle(player, enemy, true);
            #else
            BattleMode battle(player, enemy);
            #endif
            
            battle.start();

            if (!enemy->isAlive()) {
                std::cout << "Enemy defeated! Gained 30 EXP.\n";
                std::cout << "Total kills: " << player->getKills() << "\n";
            }

            break;
        }
        case 3: {
            std::cout << "You found a health potion!\n";
            player->heal(20);
            break;
        }
        default:
            std::cout << "Nothing happens.\n";
            break;
    }
}

/**
 * @brief Generates a random enemy for encounters
 * @return A shared pointer to a randomly generated enemy character
 * @details Creates a random enemy with appropriate stats and abilities.
 *          The enemy type (Warrior, Mage, Archer) is chosen randomly,
 *          and the enemy is equipped with a basic deck of cards.
 *          The enemy's AI is also initialized for combat.
 */
std::shared_ptr<Character> ExplorationMode::generateRandomEnemy() {
    int enemyType = std::rand() % 3;
    std::shared_ptr<Character> enemy;

    switch (enemyType) {
        case 0:
            enemy = std::make_shared<Warrior>("Goblin", 50, 0, 10, 5);
            break;
        case 1:
            enemy = std::make_shared<Mage>("Dark Mage", 40, 50, 15, 3);
            break;
        case 2:
            enemy = std::make_shared<Archer>("Forest Archer", 45, 0, 12, 4);
            break;
        default:
            enemy = std::make_shared<Warrior>("Goblin", 50, 0, 10, 5);
            break;
    }

    auto enemyDeck = std::make_shared<Deck>();
    enemyDeck->addCard(std::make_shared<AttackCard>());
    enemy->setDeck(enemyDeck);

    
    enemy->setAI(std::make_shared<EasyAI>(enemy));

    return enemy;
}

/**
 * @brief Updates the exploration mode
 * @details Restarts the exploration session.
 *          This is a simple implementation that calls the start method.
 */
void ExplorationMode::update() {
    start();
}
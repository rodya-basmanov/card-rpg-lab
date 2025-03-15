/**
 * @file DungeonMode.cpp
 * @brief Implementation of the DungeonMode class
 * @details Contains the definitions of all methods that create and manage
 *          a dungeon gameplay experience with multiple enemies and a boss
 */

#include "DungeonMode.h"
#include "Warrior.h"
#include "Mage.h"
#include "Archer.h"
#include "BattleMode.h"
#include "AttackCard.h"
#include "Fireball.h"
#include "EasyAI.h"
#include "BossAI.h"
#include "Regeneration.h"
#include "DefenseCard.h"
#include "AdvancedAI.h"
#include "LightningCard.h"
#include "Deck.h"
#include <iostream>

/**
 * @brief Constructor for DungeonMode
 * @param p Shared pointer to the player character
 * @details Initializes a dungeon with the player character and creates
 *          a set of predefined enemies with various difficulty levels and a boss
 */
DungeonMode::DungeonMode(std::shared_ptr<Character> p)
    : player(p) {}

/**
 * @brief Starts the dungeon mode
 * @details Initializes the dungeon with enemy characters and a boss.
 *          Guides the player through multiple combat encounters against
 *          increasingly difficult enemies, culminating in a boss battle.
 *          Includes narrative elements and rewards the player for progress.
 */
void DungeonMode::start() {
    std::cout << "You entered a dungeon! Prepare for battle..." << std::endl;
    generateEnemies();
    generateBoss();
    battlePhase();
    player->restoreHealth(100);
}

/**
 * @brief Generates enemies for the current dungeon stage
 * @details Creates a set of enemies with appropriate difficulty levels based on the player's level
 *          and the current dungeon stage. Different stages have different enemy compositions,
 *          with higher stages featuring stronger and more numerous enemies.
 */
void DungeonMode::generateEnemies() {
    enemies.clear();

    int basePower = player->getLevel() * 5;

    switch (currentStage) {
        case 1:
            addEnemy(
                "Goblin Scout",
                50 + basePower,
                0,
                10 + player->getLevel(),
                5 + player->getLevel() / 2,
                AI_Type::Easy
            );
            break;

        case 2:
            addEnemy(
                "Orc Warrior",
                80 + basePower,
                0,
                15 + player->getLevel(),
                8 + player->getLevel() / 2,
                AI_Type::Advanced
            );
            break;

        case 3:
            addEnemy(
                "Dark Mage",
                60 + basePower,
                100,
                20 + player->getLevel(),
                5 + player->getLevel() / 2,
                AI_Type::Advanced
            );
            addEnemy(
                "Elite Archer",
                70 + basePower,
                0,
                18 + player->getLevel(),
                10 + player->getLevel() / 2,
                AI_Type::Advanced
            );
            break;

        default:
            generateBoss();
            break;
    }

    currentStage++;
}

/**
 * @brief Adds an enemy to the dungeon
 * @param name The name of the enemy
 * @param health The initial health points of the enemy
 * @param mana The initial mana points of the enemy
 * @param attack The attack power of the enemy
 * @param defense The defense value of the enemy
 * @param aiType The type of AI to assign to the enemy
 * @details Creates an enemy of the appropriate character class based on the name,
 *          configures it with the specified attributes, and assigns an AI controller
 *          based on the AI type parameter. Adds the enemy to the list of dungeon enemies.
 */
void DungeonMode::addEnemy(const std::string& name, int health, int mana, 
                          int attack, int defense, AI_Type aiType) {
    std::shared_ptr<Character> enemy;

    if (name.find("Mage") != std::string::npos) {
        enemy = std::make_shared<Mage>(name, health, mana, attack, defense);
    } else if (name.find("Archer") != std::string::npos) {
        enemy = std::make_shared<Archer>(name, health, mana, attack, defense);
    } else {
        enemy = std::make_shared<Warrior>(name, health, mana, attack, defense);
    }

    auto deck = std::make_shared<Deck>();
    
    switch (aiType) {
        case AI_Type::Easy:
            deck->addCard(std::make_shared<AttackCard>());
            enemy->setAI(std::make_shared<EasyAI>(enemy));
            break;
        case AI_Type::Advanced:
            deck->addCard(std::make_shared<Fireball>());
            deck->addCard(std::make_shared<DefenseCard>());
            enemy->setAI(std::make_shared<AdvancedAI>(enemy, player, deck));
            break;
    }
    
    enemy->setDeck(deck);
    enemies.push_back(enemy);
}

/**
 * @brief Generates the dungeon boss
 * @details Creates a powerful boss character with a unique set of abilities.
 *          The boss is initialized as a high-level Mage with enhanced stats and
 *          a specialized deck of powerful cards. A BossAI is assigned to control
 *          the boss's behavior in battle.
 */
void DungeonMode::generateBoss() {
    boss = std::make_shared<Mage>("Dragon Lord", 200, 150, 30, 20);
    auto bossDeck = std::make_shared<Deck>();
    bossDeck->addCard(std::make_shared<Fireball>());
    bossDeck->addCard(std::make_shared<LightningCard>());
    bossDeck->addCard(std::make_shared<Regeneration>());
    boss->setDeck(bossDeck);
    boss->setAI(std::make_shared<BossAI>(boss, player, bossDeck));
}

/**
 * @brief Executes the battle phase of the dungeon
 * @details Manages the sequence of battles against regular enemies and the boss.
 *          For each enemy, creates a battle mode and executes it, checking the outcome.
 *          If the player defeats all regular enemies, initiates the boss battle.
 *          Displays appropriate messages based on battle outcomes.
 */
void DungeonMode::battlePhase() {
    std::cout << "Fighting enemies..." << std::endl;

    for (const auto& enemy : enemies) {
        if (!player->isAlive()) {
            std::cout << "Player has been defeated! Game over." << std::endl;
            return;
        }

        BattleMode battle(player, enemy);
        battle.start();

        if (!enemy->isAlive()) {
            std::cout << enemy->getName() << " has been defeated!" << std::endl;
        }
    }

    if (boss && player->isAlive()) {
        std::cout << "Final battle against the boss!" << std::endl;
        BattleMode finalBattle(player, boss);
        finalBattle.start();

        if (!boss->isAlive()) {
            std::cout << "Congratulations! You have defeated " << boss->getName() << "!" << std::endl;
        } else {
            std::cout << "You have been defeated by " << boss->getName() << ". Game over." << std::endl;
        }
    } else if (!player->isAlive()) {
        std::cout << "Player has been defeated! Game over." << std::endl;
    }
}

/**
 * @brief Updates the dungeon state
 * @details This is a placeholder method for future implementation
 *          that would update the dungeon state as part of the game loop.
 *          Currently empty as the dungeon updates through other methods.
 */
void DungeonMode::update() {}
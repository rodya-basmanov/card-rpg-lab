/**
 * @file DungeonMode.h
 * @brief Definition of the DungeonMode game mode
 * @details This file defines the DungeonMode class, which implements
 *          dungeon crawling with multiple enemy encounters and a boss battle
 */
#pragma once
#include "GameMode.h"
#include "Character.h"
#include "AI.h"
#include <vector>
#include <memory>

/**
 * @class DungeonMode
 * @brief Game mode for dungeon exploration and combat
 * @details Manages progression through a dungeon with multiple stages,
 *          enemy encounters, and culminating in a boss battle
 */
class DungeonMode : public GameMode {
public:
    /**
     * @enum AI_Type
     * @brief Types of AI controlling enemies in the dungeon
     */
    enum class AI_Type {
        Easy,     /**< Basic AI for common enemies */
        Advanced, /**< More challenging AI for elite enemies */
        Boss      /**< Sophisticated AI for boss encounters */
    };

private:
    /** @brief Pointer to the player character */
    std::shared_ptr<Character> player;
    
    /** @brief Collection of enemy characters in the dungeon */
    std::vector<std::shared_ptr<Character>> enemies;
    
    /** @brief Pointer to the dungeon boss character */
    std::shared_ptr<Character> boss;
    
    /** @brief Current dungeon stage/floor */
    int currentStage = 1;

    /**
     * @brief Add an enemy to the dungeon
     * @param name Enemy name
     * @param health Enemy health points
     * @param mana Enemy mana points
     * @param attackPower Enemy attack power
     * @param defense Enemy defense value
     * @param aiType Type of AI controlling this enemy
     * @details Creates and adds an enemy character with specified attributes
     */
    void addEnemy(const std::string& name, int health, int mana, 
                 int attackPower, int defense, AI_Type aiType);

public:
    /**
     * @brief Constructor for DungeonMode
     * @param p Pointer to the player character
     */
    DungeonMode(std::shared_ptr<Character> p);
    
    /**
     * @brief Start the dungeon mode
     * @details Initializes the dungeon and displays introductory information
     */
    void start() override;
    
    /**
     * @brief Generate the dungeon boss
     * @details Creates a powerful boss character for the final battle
     */
    void generateBoss();
    
    /**
     * @brief Update the dungeon state
     * @details Processes player progression through the dungeon
     */
    void update() override;
    
    /**
     * @brief Get the dungeon boss
     * @return A shared pointer to the boss character
     */
    std::shared_ptr<Character> getBoss() const { return boss; }

private:
    /**
     * @brief Generate enemies for the current dungeon stage
     * @details Creates appropriate enemies based on the current stage
     */
    void generateEnemies();
    
    /**
     * @brief Handle combat encounters in the dungeon
     * @details Manages battles between the player and dungeon enemies
     */
    void battlePhase();
};
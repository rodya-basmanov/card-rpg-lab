/**
 * @file ExplorationMode.h
 * @brief Definition of the ExplorationMode game mode
 * @details This file defines the ExplorationMode class, which implements
 *          open-world exploration with random encounters and events
 */
#pragma once
#include "GameMode.h"
#include "Character.h"
#include "Deck.h"
#include <vector>
#include <memory>

/**
 * @class ExplorationMode
 * @brief Game mode for open-world exploration
 * @details Handles exploration gameplay including random encounters,
 *          item discoveries, and interactive events
 */
class ExplorationMode : public GameMode {
private:
    /** @brief Pointer to the player character */
    std::shared_ptr<Character> player;
    
    /** @brief Collection of potential enemy characters */
    std::vector<std::shared_ptr<Character>> enemies;

public:
    /**
     * @brief Constructor for ExplorationMode
     * @param p Pointer to the player character
     */
    ExplorationMode(std::shared_ptr<Character> p);
    
    /**
     * @brief Start the exploration mode
     * @details Initializes the exploration environment and displays introductory information
     */
    void start() override;
    
    /**
     * @brief Generate a random event for the player
     * @details Creates various events such as enemy encounters, item discoveries,
     *          or other interactive situations
     */
    void generateRandomEvent();
    
    /**
     * @brief Update the exploration state
     * @details Processes player movement and triggers appropriate events
     */
    void update() override;
    
private:
    /**
     * @brief Generate a random enemy for encounters
     * @return A shared pointer to a randomly created enemy character
     * @details Creates enemies with varying difficulty based on player progress
     */
    std::shared_ptr<Character> generateRandomEnemy();
};
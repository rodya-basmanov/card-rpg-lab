/**
 * @file GameManager.h
 * @brief Definition of the GameManager class
 * @details This file defines the GameManager class which controls
 *          the overall flow and state of the game
 */
#pragma once

#include "GameMode.h"

// Forward declarations
class Character;

/**
 * @brief Create a new player character
 * @param testMode Whether to create a character for testing
 * @return A newly created player character
 */
std::shared_ptr<Character> createPlayer(bool testMode = false);

/**
 * @class GameManager
 * @brief Main controller for the game
 * @details Manages the game loop, switches between different game modes,
 *          and maintains references to important game entities
 */
class GameManager {
private:
    /** @brief The player character */
    std::shared_ptr<Character> player;
    
    /** @brief The current active game mode */
    std::shared_ptr<GameMode> currentMode;
    
    /** @brief NPC character for trading items and cards */
    std::shared_ptr<Character> trader;
    
    /** @brief Flag indicating if the player has won */
    bool isVictorious;
    
    /** @brief Flag indicating if the game is currently running */
    bool isGameRunning;
public:
    /**
     * @brief Constructor for GameManager
     * @param p The player character
     */
    GameManager(std::shared_ptr<Character> p);
    
    /**
     * @brief Run the main game loop
     * @details Manages the game flow until the game ends
     */
    void run();
    
    /**
     * @brief Run the game in test mode
     * @details Simplified version of the game loop for testing
     */
    void runTestMode();
    
    /**
     * @brief Switch to a different game mode
     * @param mode The new game mode to switch to
     */
    void switchMode(std::shared_ptr<GameMode> mode);
    
    /**
     * @brief Set the victory state
     * @param value Whether the player has won
     */
    void setVictorious(bool value) { isVictorious = value; }
    
    /**
     * @brief Exit the game
     * @details Sets the game running flag to false, ending the game loop
     */
    void exitGame() { isGameRunning = false; }
    
    /**
     * @brief Get the current game mode
     * @return The current active game mode
     */
    std::shared_ptr<GameMode> getCurrentMode() const { return currentMode; }
    
    /**
     * @brief Get the trader character
     * @return The NPC trader character
     */
    std::shared_ptr<Character> getTrader() const { return trader; }
};
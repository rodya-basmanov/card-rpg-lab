/**
 * @file GameMode.h
 * @brief Definition of the abstract GameMode class
 * @details This file defines the base GameMode class that represents
 *          different modes of gameplay in the card RPG
 */
#pragma once

#include <memory>

// Forward declaration
class Character;

/**
 * @class GameMode
 * @brief Abstract base class for all game modes
 * @details Defines the interface for different gameplay modes
 *          such as battle, dungeon crawling, or trading
 */
class GameMode {
public:
    /**
     * @brief Check if the current game mode is finished
     * @return True if the mode is finished, false otherwise
     * @details Default implementation returns false
     */
    virtual bool isFinished() const { return false; }
    
    /**
     * @brief Update the state of the game mode
     * @details Process a single step of the game mode's logic
     */
    virtual void update() {};
    
    /**
     * @brief Start the game mode
     * @details Initialize and begin the game mode
     */
    virtual void start() = 0;
    
    /**
     * @brief Virtual destructor
     */
    virtual ~GameMode() = default;
};
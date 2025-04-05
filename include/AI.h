/**
 * @file AI.h
 * @brief Definition of the base AI class
 * @details This file defines the interface for all AI implementations
 *          that can control characters in the game
 */
#pragma once
#include <memory>

// Forward declarations
class Character;
class Entity;

/**
 * @class AI
 * @brief Abstract base class for all AI controllers
 * @details Defines the interface for AI that can make decisions
 *          for characters during battles and other game modes
 */
class AI {
public:
    /**
     * @brief Makes a decision for the controlled character
     * @param self The character controlled by this AI
     * @param target The target entity (usually an opponent)
     * @details Implementation should decide what action to take
     *          based on game state, character status, and target
     */
    virtual void makeDecision(Character& self, Entity& target) = 0;
    
    /**
     * @brief Virtual destructor
     */
    virtual ~AI() = default;
};
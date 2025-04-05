/**
 * @file EasyAI.h
 * @brief Definition of the EasyAI class for simple AI behavior
 * @details This file defines a basic AI implementation with simple
 *          decision-making for beginner-level opponents
 */
#pragma once
#include "AI.h"
#include "Character.h"

/**
 * @class EasyAI
 * @brief Simple artificial intelligence for basic game decisions
 * @details Implements a straightforward AI that makes predictable decisions,
 *          suitable for tutorial levels or easy opponents
 */
class EasyAI : public AI {
private:
    /** @brief Pointer to the character targeted by this AI */
    std::shared_ptr<Character> target;

public:
    /**
     * @brief Constructor for EasyAI
     * @param t Pointer to the character targeted by this AI
     */
    EasyAI(std::shared_ptr<Character> t);
    
    /**
     * @brief Makes a simple decision for the character
     * @param self The character controlled by the AI
     * @param target The entity being targeted by the AI
     * @details Implements basic decision-making logic, usually
     *          choosing to attack directly without complex strategy
     */
    void makeDecision(Character& self, Entity& target) override;
};
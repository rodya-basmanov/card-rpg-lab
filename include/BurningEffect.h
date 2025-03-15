/**
 * @file BurningEffect.h
 * @brief Definition of the BurningEffect card class
 * @details This file defines the BurningEffect class, a card that applies
 *          a burning status effect causing damage over time
 */
#pragma once
#include "Card.h"
#include "Entity.h"

/**
 * @class BurningEffect
 * @brief Represents a fire-based damage-over-time effect card
 * @details When played, this card applies a burning effect to the target
 *          that deals damage each turn for several turns
 */
class BurningEffect : public Card {
public:
    /**
     * @brief Default constructor for BurningEffect
     * @details Initializes a burning effect card with standard name and description
     */
    BurningEffect();
    
    /**
     * @brief Play this card on a target
     * @param target The entity targeted by this card
     * @details Applies a burning effect that deals 5 damage per turn
     *          for 3 turns (total 15 damage)
     */
    void play(Entity & target) override;
};
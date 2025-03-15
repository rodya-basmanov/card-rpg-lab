/**
 * @file Poison.h
 * @brief Definition of the Poison card class
 * @details This file defines the Poison class, a card that applies
 *          a toxic effect to the target causing damage over time
 */
#pragma once
#include "Card.h"
#include "Entity.h"

/**
 * @class Poison
 * @brief Represents a poison effect card
 * @details When played, this card applies a poison effect to the target
 *          that deals damage over multiple turns
 */
class Poison : public Card {
public:
    /**
     * @brief Default constructor for Poison
     * @details Initializes a poison card with default values
     */
    Poison();
    
    /**
     * @brief Play this card on a target
     * @param target The entity targeted by this card
     * @details Applies a poison effect that deals 5 damage per turn
     *          for a fixed number of turns
     */
    void play(Entity & target) override;
};
/**
 * @file TrapCard.h
 * @brief Definition of the TrapCard class
 * @details This file defines the TrapCard class, a card that
 *          sets a trap that damages entities when triggered
 */
#pragma once
#include "Card.h"
#include "Entity.h"

/**
 * @class TrapCard
 * @brief Represents a trap card that deals damage when triggered
 * @details When played, this card immediately damages the target
 *          and could potentially apply additional effects
 */
class TrapCard : public Card {
public:
    /**
     * @brief Default constructor for TrapCard
     * @details Initializes a trap card with standard name and description
     */
    TrapCard();
    
    /**
     * @brief Play this card on a target
     * @param target The entity targeted by this card
     * @details Inflicts 10 damage to the target when triggered
     */
    void play(Entity& target) override;
    
    /**
     * @brief Get the mana cost of this card
     * @return The mana cost (0)
     * @details Basic trap cards are free to use
     */
    int getManaCost() const override { return 0; }
};
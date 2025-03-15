/**
 * @file Regeneration.h
 * @brief Definition of the Regeneration card class
 * @details This file defines the Regeneration class, a card that
 *          applies a healing effect over time to the target
 */
#pragma once
#include "Card.h"
#include "Entity.h"

/**
 * @class Regeneration
 * @brief Represents a healing-over-time effect card
 * @details When played, this card applies a regeneration effect to the target
 *          that restores health each turn for several turns
 */
class Regeneration : public Card {
public:
    /**
     * @brief Default constructor for Regeneration
     * @details Initializes a regeneration card with standard name and description
     */
    Regeneration();
    
    /**
     * @brief Play this card on a target
     * @param target The entity targeted by this card
     * @details Applies a regeneration effect that heals 10 health per turn
     *          for 3 turns (total 30 health)
     */
    void play(Entity & target) override;
    
    /**
     * @brief Get the mana cost of this card
     * @return The mana cost (15)
     * @details Regeneration has a moderate mana cost due to its
     *          powerful healing effect over time
     */
    int getManaCost() const override { return 15; }
};
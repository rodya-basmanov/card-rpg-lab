/**
 * @file Fireball.h
 * @brief Definition of the Fireball card class
 * @details This file defines the Fireball class, a card that deals
 *          fire damage and applies a burning effect to the target
 */
#pragma once
#include "Card.h"
#include "Entity.h"

/**
 * @class Fireball
 * @brief Represents a fire-based attack card
 * @details When played, this card deals significant damage to the target
 *          and applies a burning effect that deals damage over time
 */
class Fireball : public Card {
private:
    /** @brief Mana cost to play this card */
    int manaCost = 20;
public:
    /**
     * @brief Default constructor for Fireball
     * @details Initializes a fireball card with default values
     */
    Fireball();
    
    /**
     * @brief Play this card on a target
     * @param target The entity targeted by this card
     * @details Deals fire damage and applies a burning effect that
     *          continues to damage the target over multiple turns
     */
    void play(Entity & target) override;
    
    /**
     * @brief Get the mana cost of this card
     * @return The mana cost (20)
     * @details Fireball has a high mana cost due to its powerful
     *          combination of direct damage and damage over time
     */
    int getManaCost() const override { return manaCost; }
};
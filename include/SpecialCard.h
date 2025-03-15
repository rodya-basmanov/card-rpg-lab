/**
 * @file SpecialCard.h
 * @brief Definition of the SpecialCard class
 * @details This file defines the SpecialCard class, a card with
 *          unique effects that don't fit into other card categories
 */
#pragma once
#include "Card.h"
#include "Character.h"

/**
 * @class SpecialCard
 * @brief Represents a special effect card with unique properties
 * @details When played, this card provides special effects like
 *          mana restoration or other utility effects
 */
class SpecialCard : public Card {
public:
    /**
     * @brief Default constructor for SpecialCard
     * @details Initializes a special card with standard name and description
     */
    SpecialCard();
    
    /**
     * @brief Play this card on a target
     * @param target The entity targeted by this card
     * @details Restores mana to the target and potentially
     *          provides other beneficial effects
     */
    void play(Entity& target) override;
};
/**
 * @file SpellCard.h
 * @brief Definition of the SpellCard class
 * @details This file defines the SpellCard class, a card that
 *          applies magical effects to the target
 */
#pragma once
#include "Card.h"
#include "Character.h"

/**
 * @class SpellCard
 * @brief Represents a magical spell card
 * @details When played, this card applies special effects like
 *          slowing or other status modifiers to the target
 */
class SpellCard : public Card {
public:
    /**
     * @brief Default constructor for SpellCard
     * @details Initializes a spell card with standard name and description
     */
    SpellCard();
    
    /**
     * @brief Play this card on a target
     * @param target The entity targeted by this card
     * @details Applies a slowing effect to the target,
     *          reducing their speed for several turns
     */
    void play(Entity& target) override;
    
    /**
     * @brief Get the mana cost of this card
     * @return The mana cost (0)
     * @details This basic spell doesn't require mana, though most
     *          advanced spells would have a cost
     */
    int getManaCost() const override { return 0; }
};
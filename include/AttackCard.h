/**
 * @file AttackCard.h
 * @brief Definition of the AttackCard class
 * @details This file defines the AttackCard class, a basic card
 *          that deals direct damage to a target
 */
#pragma once
#include "Card.h"
#include "Entity.h"

/**
 * @class AttackCard
 * @brief Represents a basic attack card
 * @details When played, this card deals a fixed amount of damage
 *          to the target entity without any special effects
 */
class AttackCard : public Card {
public:
    /**
     * @brief Default constructor for AttackCard
     * @details Initializes an attack card with standard name and description
     */
    AttackCard();
    
    /**
     * @brief Play this card on a target
     * @param target The entity targeted by this card
     * @details Deals 15 points of damage to the target
     */
    void play(Entity& target) override;
    
    /**
     * @brief Get the mana cost of this card
     * @return The mana cost (0)
     * @details Attack cards are basic actions that don't require mana
     */
    int getManaCost() const override { return 0; }
};
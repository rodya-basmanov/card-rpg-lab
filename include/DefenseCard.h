/**
 * @file DefenseCard.h
 * @brief Definition of the DefenseCard class
 * @details This file defines the DefenseCard class, a card that
 *          increases the defense of the target entity
 */
#pragma once
#include "Card.h"
#include "Entity.h"

/**
 * @class DefenseCard
 * @brief Represents a defensive card
 * @details When played, this card boosts the target's defense,
 *          reducing damage from incoming attacks
 */
class DefenseCard : public Card {
public:
    /**
     * @brief Default constructor for DefenseCard
     * @details Initializes a defense card with standard name and description
     */
    DefenseCard();
    
    /**
     * @brief Play this card on a target
     * @param target The entity targeted by this card
     * @details Increases the target's defense by a significant amount
     */
    void play(Entity& target) override;
    
    /**
     * @brief Get the mana cost of this card
     * @return The mana cost (10)
     * @details Defense cards have a moderate mana cost
     */
    int getManaCost() const override { return 10; }
};
/**
 * @file LightningCard.h
 * @brief Definition of the LightningCard class
 * @details This file defines the LightningCard class, a card that
 *          deals random lightning damage to the target
 */
#pragma once
#include "Card.h"
#include "Entity.h"

/**
 * @class LightningCard
 * @brief Represents a lightning-based attack card
 * @details When played, this card deals a random amount of damage
 *          to the target, with the potential for critical strikes
 */
class LightningCard : public Card {
public:
    /**
     * @brief Default constructor for LightningCard
     * @details Initializes a lightning card with standard name and description
     */
    LightningCard();
    
    /**
     * @brief Play this card on a target
     * @param target The entity targeted by this card
     * @details Deals a random amount of damage (10-30) to the target
     *          and has a chance to apply a stun effect
     */
    void play(Entity& target) override;
};
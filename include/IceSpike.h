/**
 * @file IceSpike.h
 * @brief Definition of the IceSpike card class
 * @details This file defines the IceSpike class, a card that deals
 *          ice damage and applies a slowing effect to the target
 */
#pragma once
#include "Card.h"
#include "Entity.h"

/**
 * @class IceSpike
 * @brief Represents an ice-based attack card
 * @details When played, this card deals moderate damage to the target
 *          and applies a slowing effect that reduces the target's speed
 */
class IceSpike : public Card {
public:
    /**
     * @brief Default constructor for IceSpike
     * @details Initializes an ice spike card with default values
     */
    IceSpike();
    
    /**
     * @brief Play this card on a target
     * @param target The entity targeted by this card
     * @details Deals ice damage and applies a slowing effect that
     *          reduces the target's movement speed by 30%
     */
    void play(Entity & target) override;
    
    /**
     * @brief Get the mana cost of this card
     * @return The mana cost (15)
     * @details IceSpike has a moderate mana cost due to its
     *          combination of damage and utility effects
     */
    int getManaCost() const override { return 15; }
};
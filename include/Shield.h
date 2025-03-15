/**
 * @file Shield.h
 * @brief Definition of the Shield card class
 * @details This file defines the Shield class, a card that provides
 *          a defensive buff to the target entity
 */
#pragma once
#include "Card.h"
#include "Entity.h"

/**
 * @class Shield
 * @brief Represents a defensive shield card
 * @details When played, this card increases the target's defense,
 *          providing protection against incoming damage
 */
class Shield : public Card {
public:
    /**
     * @brief Default constructor for Shield
     * @details Initializes a shield card with standard name and description
     */
    Shield();
    
    /**
     * @brief Play this card on a target
     * @param target The entity targeted by this card
     * @details Increases the target's defense by a fixed amount,
     *          making them more resistant to damage
     */
    void play(Entity & target) override;
};
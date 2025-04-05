/**
 * @file Card.h
 * @brief Definition of the base Card class
 * @details This file defines the base Card class that represents
 *          playable cards in the game with various effects
 */
#pragma once
#include <string>
#include "Entity.h"

/**
 * @class Card
 * @brief Abstract base class for all cards in the game
 * @details Defines the interface for cards that can be played
 *          to affect entities in the game
 */
class Card {
protected:
    /** @brief Name of the card */
    std::string name;
    
    /** @brief Description of what the card does */
    std::string description;

public:
    /**
     * @brief Constructor for Card
     * @param name The name of the card
     * @param description The description of what the card does
     */
    Card(const std::string& name, const std::string& description)
        : name(name), description(description) {}

    /**
     * @brief Play this card on a target
     * @param target The entity targeted by this card
     * @details Implementation should define the effect of playing the card
     */
    virtual void play(Entity& target) = 0;
    
    /**
     * @brief Get the name of the card
     * @return The name of the card
     */
    const std::string& getName() const { return name; }
    
    /**
     * @brief Get the description of the card
     * @return The description of the card
     */
    const std::string& getDescription() const { return description; }
    
    /**
     * @brief Get the mana cost of the card
     * @return The amount of mana required to play this card
     * @details Base implementation returns 0, but derived classes should override
     *          this to provide the actual mana cost
     */
    virtual int getManaCost() const { return 0; }

    /**
     * @brief Virtual destructor
     */
    virtual ~Card() = default;
};
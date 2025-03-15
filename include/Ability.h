/**
 * @file Ability.h
 * @brief Definition of the Ability abstract class
 * @details Defines base class for all abilities/skills that characters can use in the game
 */
#pragma once
#include "Entity.h"

// Forward declaration
class Character;

/**
 * @class Ability
 * @brief Abstract base class representing character abilities/skills
 * @details Ability defines the interface for all character abilities that can be
 * activated against targets and consume mana.
 */
class Ability {
protected:
    /** @brief Name of the ability */
    std::string name;
    
    /** @brief Description of what the ability does */
    std::string description;
public:
    /**
     * @brief Constructor for Ability
     * @param name The name of the ability
     * @param description The description of what the ability does
     */
    Ability(const std::string & name, const std::string & description)
        : name(name), description(description) {}

    /**
     * @brief Activates the ability
     * @param user The character using the ability
     * @param target The entity that is targeted by the ability
     * @details This method handles the ability activation including mana cost
     * checking, ability application, and any side effects
     */
    virtual void activate(Character & user, Entity & target) = 0;
    
    /**
     * @brief Gets the mana cost of the ability
     * @return The amount of mana required to use this ability
     */
    virtual int getManaCost() const = 0;
    
    /**
     * @brief Applies the ability's effect to the target
     * @param target The entity affected by the ability
     * @details Implements the primary effect of the ability on the target entity
     */
    virtual void applyEffect(Entity& target) = 0;

    /**
     * @brief Gets the name of the ability
     * @return The name of the ability
     */
    const std::string & getName() const { return name; }
    
    /**
     * @brief Gets the description of the ability
     * @return The description of the ability
     */
    const std::string & getDescription() const { return description; }

    /**
     * @brief Virtual destructor
     */
    virtual ~Ability() = default;
};
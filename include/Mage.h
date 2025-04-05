/**
 * @file Mage.h
 * @brief Definition of the Mage character class
 * @details This file defines the Mage class, a spellcaster character
 *          specialized in magical attacks and elemental abilities
 */
#pragma once
#include "Character.h"
#include "Fireball.h"
#include <string>

/**
 * @class Mage
 * @brief Represents a mage character in the game
 * @details Mages are spellcasters with high mana and magical abilities
 *          who excel at dealing damage from a distance and controlling the battlefield
 */
class Mage : public Character {
private:
    /** @brief The mage's deck of cards */
    std::shared_ptr<Deck> deck;
public:
    /**
     * @brief Constructor for Mage
     * @param name The character's name
     * @param health Initial health points
     * @param mana Initial mana points
     * @param attackPower Initial attack power
     * @param defense Initial defense value
     */
    Mage(const std::string& name, int health, int mana, int attackPower, int defense);
    
    /**
     * @brief Perform a magical attack on a target
     * @param target The entity to attack
     * @details Mages use magical attacks that consume mana but deal significant damage
     */
    void attack(Entity& target) override;
    
    /**
     * @brief Use a special ability on a target
     * @param ability The ability to use
     * @param target The target of the ability
     * @details Mages are particularly powerful with elemental abilities like Fireball
     */
    void useAbility(Ability & ability, Entity & target) override;
    
    /**
     * @brief AI-controlled action for this character
     * @details When controlled by AI, the mage prioritizes using powerful spells
     *          and maintains distance from melee opponents
     */
    void performAIAction() override;
    
    /**
     * @brief Get the mage's deck of cards
     * @return Shared pointer to the mage's deck
     */
    std::shared_ptr<Deck> getDeck() const override { return deck; }
};
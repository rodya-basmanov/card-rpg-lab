/**
 * @file Warrior.h
 * @brief Definition of the Warrior character class
 * @details This file defines the Warrior class, a melee character
 *          specialized in physical attacks and defensive abilities
 */
#pragma once
#include "Character.h"

// Forward declaration
class Character;

/**
 * @class Warrior
 * @brief Represents a warrior character in the game
 * @details Warriors are melee combatants with high health and attack power
 *          who excel at direct combat and defensive maneuvers
 */
class Warrior : public Character {
    
public:
    /**
     * @brief Constructor for Warrior
     * @param name The character's name
     * @param health Initial health points
     * @param mana Initial mana points
     * @param attackPower Initial attack power
     * @param defense Initial defense value
     */
    Warrior(const std::string& name, int health, int mana, int attackPower, int defense);
    
    /**
     * @brief Use a special ability on a target
     * @param ability The ability to use
     * @param target The target of the ability
     * @details Warriors are particularly effective with defensive and strength-enhancing abilities
     */
    void useAbility(Ability & ability, Entity & target) override;
    
    /**
     * @brief Perform a basic attack on a target
     * @param target The entity to attack
     * @details Warriors have powerful melee attacks that deal significant damage
     */
    void attack(Entity& target) override;
    
    /**
     * @brief AI-controlled action for this character
     * @details When controlled by AI, the warrior prioritizes attacking
     *          nearby enemies and uses defensive abilities when health is low
     */
    void performAIAction() override;
    
    /**
     * @brief Get the warrior's deck of cards
     * @return Shared pointer to the warrior's deck
     */
    std::shared_ptr<Deck> getDeck() const override { return deck; }
};
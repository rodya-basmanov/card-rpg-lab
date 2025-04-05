/**
 * @file Archer.h
 * @brief Definition of the Archer character class
 * @details This file defines the Archer class, a ranged character
 *          specialized in critical hits and ice-based abilities
 */
#pragma once
#include "Character.h"
#include "IceSpike.h"

/**
 * @class Archer
 * @brief Represents an archer character in the game
 * @details Archers are ranged characters with high accuracy and
 *          special abilities that can slow enemies with ice-based attacks
 */
class Archer : public Character {
private:
    /** @brief The archer's deck of cards */
    std::shared_ptr<Deck> deck;
public:
    /**
     * @brief Constructor for Archer
     * @param name The character's name
     * @param health Initial health points
     * @param mana Initial mana points
     * @param attackPower Initial attack power
     * @param defense Initial defense value
     */
    Archer(const std::string& name, int health, int mana, int attackPower, int defense);

    /**
     * @brief Perform a basic attack on a target
     * @param target The entity to attack
     * @details Archers perform ranged attacks that have a chance to do critical damage
     */
    void attack(Entity& target) override;
    
    /**
     * @brief Use a special ability on a target
     * @param ability The ability to use
     * @param target The target of the ability
     * @details Archers are particularly skilled with ice-based abilities
     */
    void useAbility(Ability & ability, Entity & target) override;
    
    /**
     * @brief AI-controlled action for this character
     * @details When controlled by AI, the archer prioritizes ranged attacks
     *          and uses slowing abilities to maintain distance
     */
    void performAIAction() override;
    
    /**
     * @brief Get the archer's deck of cards
     * @return Shared pointer to the archer's deck
     */
    std::shared_ptr<Deck> getDeck() const override { return deck; }
};
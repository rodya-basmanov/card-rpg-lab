/**
 * @file Healer.h
 * @brief Definition of the Healer character class
 * @details This file defines the Healer class, a support character
 *          specialized in restoring health and removing negative effects
 */
#pragma once
#include "Character.h"

/**
 * @class Healer
 * @brief Represents a healer character in the game
 * @details Healers are support characters with abilities focused on
 *          healing allies and providing defensive buffs
 */
class Healer : public Character {
public:
    /**
     * @brief Constructor for Healer
     * @param name The character's name
     * @param health Initial health points
     * @param mana Initial mana points
     * @param attackPower Initial attack power
     * @param defense Initial defense value
     */
    Healer(const std::string& name, int health, int mana, int attackPower, int defense);

    /**
     * @brief Perform a basic attack on a target
     * @param target The entity to attack
     * @details Healers have weaker attacks but can apply special effects
     */
    void attack(Entity& target) override;
    
    /**
     * @brief Heal an ally character
     * @param ally The character to heal
     * @details This is the primary ability of healers, restoring health to allies
     */
    void healAllies(Character& ally);
    
    /**
     * @brief Use a special ability on a target
     * @param ability The ability to use
     * @param target The target of the ability
     * @details Healers excel at using regeneration and shield abilities
     */
    void useAbility(Ability& ability, Entity& target) override;
    
    /**
     * @brief Get the healer's deck of cards
     * @return Shared pointer to the healer's deck
     */
    std::shared_ptr<Deck> getDeck() const override;
    
    /**
     * @brief AI-controlled action for this character
     * @details When controlled by AI, the healer prioritizes healing allies
     *          with low health and applying buffs
     */
    void performAIAction() override;
};
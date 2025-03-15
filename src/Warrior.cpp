/**
 * @file Warrior.cpp
 * @brief Implementation of the Warrior class
 * @details Contains the implementations of Warrior-specific functionality,
 *          including construction, special abilities, and deck initialization
 */

#include "Warrior.h"
#include "AttackCard.h"
#include "DefenseCard.h"
#include "Shield.h"
#include <iostream>

/**
 * @brief Constructor for Warrior
 * @param name The name of the warrior
 * @param health Initial health value
 * @param mana Initial mana value
 * @param attackPower The attack power of the warrior
 * @param defense The defense value of the warrior
 * @details Initializes a Warrior character with the specified attributes
 *          and sets up a basic deck with attack, defense, and shield cards.
 */
Warrior::Warrior(const std::string& name, int health, int mana, int attackPower, int defense)
    : Character(name, health, mana, attackPower, defense) {
    deck = std::make_shared<Deck>();
    deck->addCard(std::make_shared<AttackCard>());
    deck->addCard(std::make_shared<DefenseCard>());
    deck->addCard(std::make_shared<Shield>());
}

/**
 * @brief Warrior's implementation of attack
 * @param target The entity to attack
 * @details Warriors have a chance to perform a critical hit,
 *          dealing 50% more damage than a normal attack.
 *          Uses RNG to determine if a critical hit occurs.
 */
void Warrior::attack(Entity& target) {
    if (!target.isAlive()) {
        std::cout << "Target is already defeated!" << std::endl;
        return;
    }
    
    int damage = getAttackPower() - target.getDefense();
    if (damage < 0) damage = 0;
    target.takeDamage(damage);
    std::cout << getName() << " attacks with a sword for " << damage << " damage!" << std::endl;
}

/**
 * @brief Warrior's ability usage method
 * @param ability The ability to use
 * @param target The target for the ability
 * @details Warriors can boost their abilities with rage,
 *          potentially dealing extra damage or gaining enhanced effects.
 */
void Warrior::useAbility(Ability& ability, Entity& target) {
    if (getMana() >= ability.getManaCost()) {
        reduceMana(ability.getManaCost());
        ability.applyEffect(target);
        std::cout << getName() << " uses " << ability.getName() << " on " << target.getName() << "!" << std::endl;
    } else {
        std::cout << "Not enough mana to use " << ability.getName() << "!" << std::endl;
    }
}

/**
 * @brief AI control for Warrior characters
 * @details Defines the AI behavior for warrior NPCs.
 *          Warriors prioritize attacking with their special abilities
 *          when they have enough mana, or perform regular attacks otherwise.
 */
void Warrior::performAIAction() {
    if (auto target = getTarget()) {
        if (target->isAlive()) {
            std::cout << "[DEBUG] " << getName() << " attacks " << target->getName() << std::endl;
            attack(*target);
        } else {
            std::cout << "[DEBUG] " << getName() << " has no valid target!" << std::endl;
        }
    } else {
        std::cout << "[DEBUG] " << getName() << " has no target set!" << std::endl;
    }
}
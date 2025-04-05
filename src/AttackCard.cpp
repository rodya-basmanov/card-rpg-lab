/**
 * @file AttackCard.cpp
 * @brief Implementation of the AttackCard class
 * @details Contains the definitions of all methods declared in AttackCard.h
 */

#include "AttackCard.h"
#include <iostream>

/**
 * @brief Constructor for AttackCard
 * @details Initializes an attack card with a predefined name and description
 */
AttackCard::AttackCard()
    : Card("Attack Card", "Deals 15 damage to the target.") {}

/**
 * @brief Implements the effect of playing an AttackCard
 * @param target The entity targeted by the attack
 * @details Deals 15 damage to the target and displays a message
 */
void AttackCard::play(Entity& target) {
    int damage = 15;
    target.takeDamage(damage);
    std::cout << "Attack Card deals " << damage << " damage to " << target.getName() << "!" << std::endl;
}
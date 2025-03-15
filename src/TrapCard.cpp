/**
 * @file TrapCard.cpp
 * @brief Implementation of the TrapCard class
 * @details Contains the definitions of all methods declared in TrapCard.h
 */

#include "TrapCard.h"
#include <iostream>

/**
 * @brief Constructor for TrapCard
 * @details Initializes a trap card with a predefined name and description
 */
TrapCard::TrapCard()
    : Card("Trap Card", "Deals 10 damage when triggered.") {}

/**
 * @brief Implements the effect of playing a TrapCard
 * @param target The entity targeted by the trap
 * @details Deals 10 damage to the target and displays a message
 */
void TrapCard::play(Entity& target) {
    int damage = 10;
    target.takeDamage(damage);
    std::cout << "Trap Card deals " << damage << " damage to " << target.getName() << "!" << std::endl;
}
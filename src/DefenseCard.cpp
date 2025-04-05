/**
 * @file DefenseCard.cpp
 * @brief Implementation of the DefenseCard class
 * @details Contains the definitions of all methods declared in DefenseCard.h
 */

#include "DefenseCard.h"
#include <iostream>

/**
 * @brief Constructor for DefenseCard
 * @details Initializes a defense card with a predefined name and description
 */
DefenseCard::DefenseCard()
    : Card("Defense Card", "Creates a shield that absorbs 20 damage.") {}

/**
 * @brief Implements the effect of playing a DefenseCard
 * @param target The entity targeted by the defense effect
 * @details Increases the target's defense by 20 points and displays a message
 */
void DefenseCard::play(Entity& target) {
    int shieldAmount = 20;
    target.setDefense(target.getDefense() + shieldAmount);
    std::cout << "Defense Card creates a shield for " << shieldAmount << " damage!" << std::endl;
}
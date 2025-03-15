/**
 * @file LightningCard.cpp
 * @brief Implementation of the LightningCard class
 * @details Contains the definitions of all methods declared in LightningCard.h
 */

#include "LightningCard.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

/**
 * @brief Constructor for LightningCard
 * @details Initializes a lightning card with a predefined name and description
 */
LightningCard::LightningCard()
    : Card("Lightning Card", "Deals random damage between 10 and 30.") {}

/**
 * @brief Implements the effect of playing a LightningCard
 * @param target The entity targeted by the lightning
 * @details Deals a random amount of damage between 10 and 30 to the target
 *          and displays a message with the damage dealt
 */
void LightningCard::play(Entity& target) {
    int damage = 10 + (std::rand() % 21);
    target.takeDamage(damage);
    std::cout << "Lightning Card deals " << damage << " damage to " << target.getName() << "!\n";
}
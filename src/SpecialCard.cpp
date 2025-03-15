/**
 * @file SpecialCard.cpp
 * @brief Implementation of the SpecialCard class
 * @details Contains the definitions of all methods declared in SpecialCard.h
 */

#include "SpecialCard.h"
#include <iostream>

/**
 * @brief Constructor for SpecialCard
 * @details Initializes a special card with a predefined name and description
 */
SpecialCard::SpecialCard()
    : Card("Special Card", "Restores 30 mana to the target.") {}

/**
 * @brief Implements the effect of playing a SpecialCard
 * @param target The entity targeted by the special effect
 * @details Restores 30 mana points to the target and displays a message
 */
void SpecialCard::play(Entity& target) {
    int manaRestore = 30;
    target.increaseMana(manaRestore);
    std::cout << "Special Card restores " << manaRestore << " mana to " << target.getName() << "!" << std::endl;
}
/**
 * @file Shield.cpp
 * @brief Implementation of the Shield class
 * @details Contains the definitions of all methods declared in Shield.h
 */

#include "Shield.h"
#include "Character.h"
#include <iostream>

/**
 * @brief Constructor for Shield
 * @details Initializes a shield card with a predefined name and description
 */
Shield::Shield()
    : Card("Shield", "Blocks 50% incoming damage for 2 turns.") {}

/**
 * @brief Implements the effect of playing a Shield card
 * @param target The entity targeted by the shield effect
 * @details Increases the target's defense by 10 points if it's a Character,
 *          providing protection against incoming damage
 */
void Shield::play(Entity & target) {
    Character* characterTarget = dynamic_cast<Character*>(&target);
    if (characterTarget) {
        characterTarget->setDefense(characterTarget->getDefense() + 10);
        std::cout << "Shield Card increases defense by 10 for " << target.getName() << std::endl;
    }
}
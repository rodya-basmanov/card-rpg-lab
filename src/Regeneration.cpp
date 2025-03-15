/**
 * @file Regeneration.cpp
 * @brief Implementation of the Regeneration class
 * @details Contains the definitions of all methods declared in Regeneration.h
 */

#include "Regeneration.h"
#include "Character.h"
#include <iostream>

/**
 * @brief Constructor for Regeneration
 * @details Initializes a regeneration card with a predefined name and description
 */
Regeneration::Regeneration()
    : Card("Regeneration", "Restores 10 health per turn for 3 turns.") {}

/**
 * @brief Implements the effect of playing a Regeneration card
 * @param target The entity targeted by the regeneration effect
 * @details Applies a regeneration effect to the target if it's a Character,
 *          restoring 10 health points per turn for 3 turns
 */
void Regeneration::play(Entity & target) {
    if (auto* character = dynamic_cast<Character*>(&target)) {
        character->applyEffect(EffectType::REGENERATION, 1.0f, 3, 0, 10);
        std::cout << "Regeneration Card heals " << target.getName() << std::endl;
    }
}
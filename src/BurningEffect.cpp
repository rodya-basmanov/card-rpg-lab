/**
 * @file BurningEffect.cpp
 * @brief Implementation of the BurningEffect class
 * @details Contains the definitions of all methods declared in BurningEffect.h
 */

#include "BurningEffect.h"
#include "Character.h"
#include <iostream>

/**
 * @brief Constructor for BurningEffect
 * @details Initializes a burning effect card with a predefined name and description
 */
BurningEffect::BurningEffect()
    : Card("Burning Effect", "Deals 5 damage per turn for 3 turns.") {}

/**
 * @brief Implements the effect of playing a BurningEffect card
 * @param target The entity targeted by the burning effect
 * @details Applies a burning effect to the target if it's a Character,
 *          dealing 5 damage per turn for 3 turns
 */
void BurningEffect::play(Entity & target) {
    if (auto* character = dynamic_cast<Character*>(&target)) {
        character->applyEffect(EffectType::BURN, 1.0f, 3, 5);
        std::cout << "Burning Effect Card activates on " << target.getName() << std::endl;
    }
}
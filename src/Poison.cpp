/**
 * @file Poison.cpp
 * @brief Implementation of the Poison class
 * @details Contains the definitions of all methods declared in Poison.h
 */

#include "Poison.h"
#include "Character.h"
#include <iostream>

/**
 * @brief Constructor for Poison
 * @details Initializes a poison card with a predefined name and description
 */
Poison::Poison()
    : Card("Poison", "Deals 5 damage per turn for 5 turns.") {}

/**
 * @brief Implements the effect of playing a Poison card
 * @param target The entity targeted by the poison effect
 * @details Applies a poison effect to the target if it's a Character,
 *          dealing 5 damage per turn for 5 turns
 */
void Poison::play(Entity & target) {
    if (auto* character = dynamic_cast<Character*>(&target)) {
        character->applyEffect(EffectType::POISON, 1.0f, 5, 5);
        std::cout << "Poison Card activates on " << target.getName() << std::endl;
    }
}
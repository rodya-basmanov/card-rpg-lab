/**
 * @file SpellCard.cpp
 * @brief Implementation of the SpellCard class
 * @details Contains the definitions of all methods declared in SpellCard.h
 */

#include "SpellCard.h"
#include <iostream>

/**
 * @brief Constructor for SpellCard
 * @details Initializes a spell card with a predefined name and description
 */
SpellCard::SpellCard()
    : Card("Spell Card", "Applies a magical effect to the target.") {}

/**
 * @brief Implements the effect of playing a SpellCard
 * @param target The entity targeted by the spell
 * @details Applies a slowing effect to the target if it's a Character,
 *          reducing its speed by 30% for 3 turns
 */
void SpellCard::play(Entity& target) {
    if (auto* character = dynamic_cast<Character*>(&target)) {
        character->applyEffect(EffectType::SLOW, 0.7f, 3);
        std::cout << "Spell Card applies a magical effect to " << character->getName() << "!" << std::endl;
    } else {
        std::cout << "Target is not a Character!" << std::endl;
    }
}
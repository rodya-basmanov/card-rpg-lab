/**
 * @file IceSpike.cpp
 * @brief Implementation of the IceSpike card class
 * @details Contains the definitions of all methods declared in IceSpike.h
 */

#include "IceSpike.h"
#include "Character.h"
#include <iostream>

/**
 * @brief Constructor for IceSpike
 * @details Initializes an ice spike card with a predefined name and description
 */
IceSpike::IceSpike()
    : Card("Ice Spike", "Slows the enemy by 30% for 2 turns.") {}

/**
 * @brief Implements the effect of playing an IceSpike card
 * @param target The entity targeted by the ice spike
 * @details Applies a slowing effect that reduces the target's speed by 30%
 *          for 2 turns if the target is a Character
 */
void IceSpike::play(Entity & target) {
    if (auto* character = dynamic_cast<Character*>(&target)) {
        character->applyEffect(EffectType::SLOW, 0.7f, 2);
        std::cout << "Ice Spike Card slows " << target.getName() << std::endl;
    }
}
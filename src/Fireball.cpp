/**
 * @file Fireball.cpp
 * @brief Implementation of the Fireball card class
 * @details Contains the definitions of all methods declared in Fireball.h
 */

#include "Fireball.h"
#include "BurningEffect.h"
#include "Character.h"
#include <iostream>

/**
 * @brief Constructor for Fireball
 * @details Initializes a fireball card with a predefined name and description
 */
Fireball::Fireball()
    : Card("Fireball", "Deals 25 damage and applies a burning effect.") {}

/**
 * @brief Implements the effect of playing a Fireball card
 * @param target The entity targeted by the fireball
 * @details Deals 25 damage to the target and applies a burning effect
 *          that continues to damage the target over several turns
 */
void Fireball::play(Entity& target) {
    if (!target.isAlive()) return;
        
    int damage = 25;
    target.takeDamage(damage);
    std::cout << "Fireball deals " << damage << " damage to " << target.getName() << "!" << std::endl;
    
    BurningEffect burningEffect;
    burningEffect.play(target);
}
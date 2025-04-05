/**
 * @file Character.cpp
 * @brief Implementation of the Character class
 * @details Contains the definitions of all methods declared in Character.h
 */

#include "Character.h"
#include "Ability.h"
#include "AI.h"
#include <iostream>
#include <algorithm>

/**
 * @brief Constructor for Character
 * @param name The name of the character
 * @param health Initial health value
 * @param mana Initial mana value
 * @param attackPower The attack power of the character
 * @param defense The defense value of the character
 * @details Initializes a character with the specified attributes
 */
Character::Character(const std::string& name, int health, int mana, int attackPower, int defense)
    : Entity(name, std::min(health, Entity::MAX_HEALTH), 
      std::min(mana, Entity::MAX_MANA)), 
      attackPower(attackPower), 
      defense(defense), 
      kills(0), 
      deck(std::make_shared<Deck>()),
      inventory(std::make_shared<Inventory>()) {}

/**
 * @brief Performs an attack on a target
 * @param target The entity to attack
 * @details Checks if the target is alive, calculates damage based on speed modifiers,
 *          applies damage to the target, and outputs a message about the result.
 *          Grants experience and increases kill count if the target dies.
 */
void Character::attack(Entity& target) {
    if (target.isAlive()) {
        float speedMod = getCurrentSpeedModifier();
        int damage = static_cast<int>(attackPower * speedMod);
        target.takeDamage(damage);
        std::cout << getName() << " attacks for " << damage << " damage!" << std::endl;

        if (!target.isAlive()) {
            gainExp(30);
            incrementKills();
        }
    } else {
        std::cout << getName() << " tries to attack a dead target!" << std::endl;
    }
}

/**
 * @brief Uses an ability on a target
 * @param ability The ability to use
 * @param target The target entity for the ability
 * @details Applies the specified ability to the target if the character has enough mana.
 *          Reduces the character's mana by the ability's cost and displays a message.
 */
void Character::useAbility(Ability& ability, Entity& target) {
    if (ability.getManaCost() <= getMana()) {
        reduceMana(ability.getManaCost());
        ability.activate(*this, target);
        std::cout << getName() << " uses " << ability.getName() << "!" << std::endl;
    } else {
        std::cout << "Not enough mana to use " << ability.getName() << "!" << std::endl;
    }
}

/**
 * @brief Applies an effect to the character
 * @param type The type of effect to apply
 * @param mod The modifier for the effect
 * @param dur The duration of the effect in turns
 * @param dmg The damage per turn caused by the effect
 * @param heal The healing per turn provided by the effect
 * @details Creates and applies an effect of the specified type with the given parameters.
 *          Displays appropriate messages based on the effect type.
 */
void Character::applyEffect(EffectType type, float mod, int dur, int dmg, int heal) {
    activeEffects.emplace_back(type, mod, dur, dmg, heal);
    
    switch(type) {
        case EffectType::SLOW:
            std::cout << getName() << "'s speed reduced to " 
                      << mod*100 << "% for " << dur << " turns!" << std::endl;
            break;
        case EffectType::BURN:
            std::cout << getName() << " is burning for " << dur << " turns!" << std::endl;
            break;
        case EffectType::POISON:
            std::cout << getName() << " is poisoned for " << dur << " turns!" << std::endl;
            break;
        case EffectType::REGENERATION:
            std::cout << getName() << " regenerates for " << dur << " turns!" << std::endl;
            break;
        default:
            break;
    }
}

/**
 * @brief Updates all active effects on the character
 * @details Applies the effects of each active status and decreases their duration.
 *          Removes expired effects and displays appropriate messages.
 *          Handles damage from burns/poison and healing from regeneration.
 */
void Character::updateEffect() {
    for(auto it = activeEffects.begin(); it != activeEffects.end();) {
        it->duration--;
        
        switch(it->type) {
            case EffectType::BURN:
            case EffectType::POISON:
                takeDamage(it->damagePerTurn);
                std::cout << getName() << " takes " 
                          << it->damagePerTurn << " damage from effect!" << std::endl;
                break;
            case EffectType::REGENERATION:
                heal(it->healPerTurn);
                std::cout << getName() << " heals " 
                          << it->healPerTurn << " from regeneration!" << std::endl;
                break;
            default:
                break;
        }
        
        if(it->duration <= 0) {
            it = activeEffects.erase(it);
        } else {
            ++it;
        }
    }
}

/**
 * @brief Performs an automated AI action for the character
 * @details If the character has an AI assigned and has a valid living target,
 *          this method delegates the action to the AI's decision-making logic.
 */
void Character::performAIAction() {
    if(ai && target && target->isAlive()) {
        ai->makeDecision(*this, *target);
    }
}

/**
 * @brief Gets the current speed modifier for the character
 * @return A float representing the combined speed modifier from all active effects
 * @details Calculates the cumulative effect of all SLOW status effects
 *          currently applied to the character. A value of 1.0 means normal speed,
 *          while lower values indicate reduced speed.
 */
float Character::getCurrentSpeedModifier() const {
    float total = 1.0f;
    for(const auto& effect : activeEffects) {
        if(effect.type == EffectType::SLOW) {
            total *= effect.speedModifier;
        }
    }
    return total;
}
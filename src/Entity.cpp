/**
 * @file Entity.cpp
 * @brief Implementation of the Entity class
 * @details Contains the definitions of all methods declared in Entity.h
 */

#include "Entity.h"
#include <algorithm>

/**
 * @brief Constructor for Entity
 * @param name Entity name
 * @param health Initial health points
 * @param mana Initial mana points
 * @param defense Initial defense value
 * @details Initializes an entity with provided values, clamping them to valid ranges
 */
Entity::Entity(const std::string& name, int health, int mana, int defense)
    : name(name),
      health(std::clamp(health, 0, MAX_HEALTH)),
      mana(std::clamp(mana, 0, MAX_MANA)),
      defense(std::max(defense, 0)) {}

/**
 * @brief Heal the entity by a specified amount
 * @param amount Amount of health to restore
 * @details Increases health by the specified amount, up to the maximum
 */
void Entity::heal(int amount) {
    if (amount < 0) return;
    health = std::min(health + amount, MAX_HEALTH);
}

/**
 * @brief Apply damage to the entity
 * @param damage Amount of damage to apply
 * @details Reduces health by the damage amount, after subtracting defense
 */
void Entity::takeDamage(int damage) {
    if (damage < 0) return;
    int actualDamage = std::max(damage - defense, 0);
    health = std::max(health - actualDamage, 0);
}

/**
 * @brief Set the entity's defense value
 * @param def New defense value
 * @details Updates the defense value, ensuring it's not negative
 */
void Entity::setDefense(int def) {
    defense = std::max(def, 0);
}

/**
 * @brief Get the entity's current health
 * @return Current health points
 */
int Entity::getHealth() const {
    return health;
}

/**
 * @brief Get the entity's current mana
 * @return Current mana points
 */
int Entity::getMana() const {
    return mana;
}

/**
 * @brief Reduce the entity's mana
 * @param amount Amount of mana to consume
 * @details Decreases mana by the specified amount, ensuring it stays in valid range
 */
void Entity::reduceMana(int amount) {
    mana = std::clamp(mana - amount, 0, MAX_MANA);
}

/**
 * @brief Restore health to the entity
 * @param amount Amount of health to restore
 * @details Increases health by the specified amount, up to the maximum
 */
void Entity::restoreHealth(int amount) {
    if (amount < 0) return;
    health = std::min(health + amount, MAX_HEALTH);
}
/**
 * @file HealthPotion.h
 * @brief Definition of the HealthPotion item class
 * @details This file defines the HealthPotion class, a consumable
 *          item that restores health to a character
 */
#pragma once
#include "Item.h"

/**
 * @class HealthPotion
 * @brief A consumable item that restores health
 * @details When used, a health potion restores 30 health points to the target
 */
class HealthPotion : public Item {
public:
    /**
     * @brief Constructor for HealthPotion
     * @details Initializes a health potion with standard name and description
     */
    HealthPotion() : Item("Health Potion", "Restores 30 HP") {}

    /**
     * @brief Apply the effects of the health potion to a character
     * @param target The character to heal
     * @details Restores 30 health points to the target and outputs a message
     */
    void apply(Character& target) override {
        target.restoreHealth(30);
        std::cout << target.getName() << " restored 30 HP!\n";
    }
};
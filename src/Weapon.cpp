/**
 * @file Weapon.cpp
 * @brief Implementation of the Weapon item class
 * @details Contains the definitions of all methods declared in Weapon.h
 */

#include "Weapon.h"
#include <iostream>

/**
 * @brief Constructor for Weapon
 * @param name The name of the weapon
 * @param description The description of the weapon
 * @param damage The amount of damage this weapon adds to attacks
 * @details Initializes a weapon item with the specified attributes
 */
Weapon::Weapon(const std::string& name, const std::string& description, int damage)
    : Item(name, description), damage(damage) {}

/**
 * @brief Apply the weapon to a character
 * @param target The character to equip the weapon
 * @details Increases the target character's attack power by the weapon's damage value
 *          and displays a message about the equipment
 */
void Weapon::apply(Character& target) {
    target.setAttackPower(target.getAttackPower() + damage);
    std::cout << target.getName() << " equipped " << name << " and increased attack power by " << damage << "!" << std::endl;
}
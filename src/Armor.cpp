/**
 * @file Armor.cpp
 * @brief Implementation of the Armor item class
 * @details Contains the definitions of all methods declared in Armor.h
 */

#include "Armor.h"
#include <iostream>

/**
 * @brief Constructor for Armor
 * @param name The name of the armor
 * @param description The description of the armor
 * @param defense The amount of defense this armor provides
 * @details Initializes an armor item with the specified attributes
 */
Armor::Armor(const std::string& name, const std::string& description, int defense)
    : Item(name, description), defense(defense) {}

/**
 * @brief Apply the armor to a character
 * @param target The character to equip the armor
 * @details Increases the target character's defense by the armor's defense value
 *          and displays a message about the equipment
 */
void Armor::apply(Character& target) {
    target.setDefense(target.getDefense() + defense);
    std::cout << target.getName() << " equipped " << name << " and increased defense by " << defense << "!" << std::endl;
}
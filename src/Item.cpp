/**
 * @file Item.cpp
 * @brief Implementation of the Item abstract class
 * @details Contains the definitions of all methods declared in Item.h
 */

#include "Item.h"
#include <iostream>

/**
 * @brief Constructor for Item
 * @param name The name of the item
 * @param description The description of what the item does
 * @details Initializes an item with the specified name and description
 */
Item::Item(const std::string& name, const std::string& description)
    : name(name), description(description) {}

/**
 * @brief Base implementation of the apply method
 * @param target The character to apply the item effect to
 * @details This is a default implementation that simply outputs a message.
 *          Derived classes should override this to provide specific effects.
 */
void Item::apply(Character& target) {
    std::cout << "Applying item: " << name << std::endl;
}
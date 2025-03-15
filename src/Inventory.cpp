/**
 * @file Inventory.cpp
 * @brief Implementation of the Inventory class
 * @details Contains the definitions of all methods declared in Inventory.h
 */

#include "Inventory.h"
#include <algorithm>
#include <iostream>

/**
 * @brief Add an item to the inventory
 * @param item Pointer to the item to add
 * @details Adds the specified item to the inventory and displays a message
 */
void Inventory::addItem(Item* item) {
    items.push_back(item);
    std::cout << "Added item: " << item->getName() << std::endl;
}

/**
 * @brief Use an item on a character
 * @param item Pointer to the item to use
 * @param target The character to apply the item effect to
 * @details Applies the effect of the specified item to the target character,
 *          removes the item from the inventory, and displays messages
 */
void Inventory::useItem(Item* item, Character& target) {
    auto it = std::find(items.begin(), items.end(), item);

    if (it != items.end()) {
        (*it)->apply(target);
        items.erase(it);
        std::cout << "Used item: " << item->getName() << std::endl;
    } else {
        std::cout << "Item not found in inventory!" << std::endl;
    }
}

/**
 * @brief Remove an item from the inventory
 * @param item Pointer to the item to remove
 * @details Removes the specified item from the inventory without using it
 *          and displays a message about the result
 */
void Inventory::removeItem(Item* item) {
    auto it = std::find(items.begin(), items.end(), item);
    if (it != items.end()) {
        items.erase(it);
        std::cout << "Removed item: " << item->getName() << "\n";
    } else {
        std::cout << "Item not found in inventory!\n";
    }
}
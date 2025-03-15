/**
 * @file Inventory.h
 * @brief Definition of the Inventory class
 * @details This file defines the Inventory class that manages
 *          collections of items for characters
 */
#pragma once
#include <vector>
#include "Item.h"

// Forward declaration
class Character;

/**
 * @class Inventory
 * @brief Manages a collection of items
 * @details Provides functionality for storing, using, and managing
 *          various items that characters can collect and utilize
 */
class Inventory {
private:
    /** @brief Collection of items in the inventory */
    std::vector<Item*> items;

public:
    /**
     * @brief Add an item to the inventory
     * @param item Pointer to the item to add
     */
    void addItem(Item* item);
    
    /**
     * @brief Use an item on a character
     * @param item Pointer to the item to use
     * @param target The character to apply the item effect to
     * @details Applies the effect of the specified item to the target character
     */
    void useItem(Item* item, Character& target);
    
    /**
     * @brief Get all items in the inventory
     * @return Reference to the vector of items
     */
    const std::vector<Item*>& getItems() const { return items; }
    
    /**
     * @brief Remove an item from the inventory
     * @param item Pointer to the item to remove
     */
    void removeItem(Item* item);
};
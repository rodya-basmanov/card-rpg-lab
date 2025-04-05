/**
 * @file Item.h
 * @brief Definition of the abstract Item class
 * @details This file defines the Item base class for all usable items in the game,
 *          including potions, equipment, and other consumables
 */
#pragma once
#include <string>

// Forward declaration
class Character;

/**
 * @class Item
 * @brief Abstract base class for all items in the game
 * @details Defines the interface for all items that can be used
 *          or equipped by characters
 */
class Item {
protected:
    /** @brief Name of the item */
    std::string name;
    
    /** @brief Description of what the item does */
    std::string description;

public:
    /**
     * @brief Constructor for Item
     * @param name The name of the item
     * @param description The description of what the item does
     */
    Item(const std::string& name, const std::string& description);
    
    /**
     * @brief Apply this item's effect to a character
     * @param target The character targeted by this item
     * @details Implementation should define the effect of using the item
     */
    virtual void apply(Character& target) = 0;
    
    /**
     * @brief Get the name of the item
     * @return The name of the item
     */
    const std::string& getName() const { return name; }
    
    /**
     * @brief Get the description of the item
     * @return The description of the item
     */
    const std::string& getDescription() const { return description; }
    
    /**
     * @brief Virtual destructor
     */
    virtual ~Item() = default;
};
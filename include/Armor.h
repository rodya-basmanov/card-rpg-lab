/**
 * @file Armor.h
 * @brief Definition of the Armor item class
 * @details This file defines the Armor class, an equippable item
 *          that increases the defense of a character
 */
#pragma once
#include "Item.h"
#include "Character.h"

/**
 * @class Armor
 * @brief Represents a defensive equipment item
 * @details When equipped, armor increases the defense stat of a character,
 *          reducing the damage they take from attacks
 */
class Armor : public Item {
private:
    /** @brief The defense value provided by this armor */
    int defense;

public:
    /**
     * @brief Constructor for Armor
     * @param name The name of the armor
     * @param description The description of the armor
     * @param defense The amount of defense this armor provides
     */
    Armor(const std::string& name, const std::string& description, int defense);
    
    /**
     * @brief Apply this armor to a character
     * @param target The character to equip this armor
     * @details Increases the target's defense by the armor's defense value
     */
    void apply(Character& target) override;
    
    /**
     * @brief Get the defense value of this armor
     * @return The defense value
     */
    int getDefense() const { return defense; }
};
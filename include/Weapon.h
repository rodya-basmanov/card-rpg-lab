/**
 * @file Weapon.h
 * @brief Definition of the Weapon item class
 * @details This file defines the Weapon class, an equippable item
 *          that increases the attack power of a character
 */
#pragma once
#include "Item.h"
#include "Character.h"

/**
 * @class Weapon
 * @brief Represents an offensive equipment item
 * @details When equipped, a weapon increases the attack power of a character,
 *          allowing them to deal more damage with attacks
 */
class Weapon : public Item {
private:
    /** @brief The damage bonus provided by this weapon */
    int damage;

public:
    /**
     * @brief Constructor for Weapon
     * @param name The name of the weapon
     * @param description The description of the weapon
     * @param damage The amount of damage this weapon adds to attacks
     */
    Weapon(const std::string& name, const std::string& description, int damage);
    
    /**
     * @brief Apply this weapon to a character
     * @param target The character to equip this weapon
     * @details Increases the target's attack power by the weapon's damage value
     */
    void apply(Character& target) override;
    
    /**
     * @brief Get the damage value of this weapon
     * @return The damage bonus
     */
    int getDamage() const { return damage; }
};
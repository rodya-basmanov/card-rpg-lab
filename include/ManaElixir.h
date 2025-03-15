/**
 * @file ManaElixir.h
 * @brief Definition of the ManaElixir item class
 * @details This file defines the ManaElixir class, a consumable
 *          item that restores mana to a character
 */
#pragma once
#include "Item.h"

/**
 * @class ManaElixir
 * @brief A consumable item that restores mana
 * @details When used, a mana elixir restores 20 mana points to the target
 */
class ManaElixir : public Item {
public:
    /**
     * @brief Constructor for ManaElixir
     * @details Initializes a mana elixir with standard name and description
     */
    ManaElixir() : Item("Mana Elixir", "Restores 20 Mana") {}

    /**
     * @brief Apply the effects of the mana elixir to a character
     * @param target The character to restore mana to
     * @details Restores 20 mana points to the target and outputs a message
     */
    void apply(Character& target) override {
        target.increaseMana(20);
        std::cout << target.getName() << " restored 20 Mana!\n";
    }
};
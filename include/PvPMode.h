/**
 * @file PvPMode.h
 * @brief Definition of the PvPMode game mode
 * @details This file defines the PvPMode class, which implements
 *          player versus player combat mechanics
 */
#pragma once

#include "GameMode.h"
#include "Character.h"

/**
 * @class PvPMode
 * @brief Game mode for player versus player combat
 * @details Manages turn-based combat between two player-controlled characters
 */
class PvPMode : public GameMode {
private:
    /** @brief Pointer to the first player's character */
    std::shared_ptr<Character> player1;
    
    /** @brief Pointer to the second player's character */
    std::shared_ptr<Character> player2;

    /**
     * @brief Process a player's turn
     * @param attacker The character taking their turn
     * @param defender The opponent character
     * @details Handles action selection and execution for a player's turn
     */
    void playerTurn(std::shared_ptr<Character> attacker, std::shared_ptr<Character> defender);

    /**
     * @brief Let the player select an ability
     * @param character The character selecting an ability
     * @return The selected ability
     * @details Displays available abilities and processes player selection
     */
    static std::shared_ptr<Ability> selectAbility(const Character& character);
    
    /**
     * @brief Use an item from the character's inventory
     * @param character The character using an item
     * @details Displays available items and processes player selection
     */
    static void useItemFromInventory(Character& character);

public:
    /**
     * @brief Constructor for PvPMode
     * @param p1 Pointer to the first player's character
     * @param p2 Pointer to the second player's character
     */
    PvPMode(std::shared_ptr<Character> p1, std::shared_ptr<Character> p2);
    
    /**
     * @brief Start the PvP mode
     * @details Initializes the battle and displays introductory information
     */
    void start() override;
};
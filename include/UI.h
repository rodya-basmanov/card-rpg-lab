/**
 * @file UI.h
 * @brief Definition of UI utilities for game display
 * @details This file defines various UI functions and constants
 *          for rendering game elements like health bars, battle animations,
 *          and game state information
 */
#pragma once
#include "Character.h"
#include "Entity.h"
#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <algorithm>

/** @brief ANSI color code for resetting text color */
const std::string COLOR_RESET   = "\033[0m";
/** @brief ANSI color code for red text */
const std::string COLOR_RED     = "\033[31m";
/** @brief ANSI color code for green text */
const std::string COLOR_GREEN   = "\033[32m";
/** @brief ANSI color code for yellow text */
const std::string COLOR_YELLOW  = "\033[33m";
/** @brief ANSI color code for blue text */
const std::string COLOR_BLUE    = "\033[34m";
/** @brief ANSI color code for magenta text */
const std::string COLOR_MAGENTA = "\033[35m";
/** @brief ANSI color code for cyan text */
const std::string COLOR_CYAN    = "\033[36m";

/**
 * @namespace UI
 * @brief Contains all user interface related functions
 * @details Provides functions for rendering game elements and
 *          managing the display of game information
 */
namespace UI {
    /**
     * @brief Clear the console screen
     * @details Uses platform-specific commands to clear the terminal
     */
    void clearScreen();

    /**
     * @brief Create a visual health bar
     * @param current Current health value
     * @param max Maximum health value
     * @param width Width of the health bar in characters
     * @return String representation of the health bar
     * @details Returns a colored bar representing health percentage
     */
    std::string healthBar(int current, int max, int width = 20);

    /**
     * @brief Create a visual mana bar
     * @param current Current mana value
     * @param max Maximum mana value
     * @param width Width of the mana bar in characters
     * @return String representation of the mana bar
     * @details Returns a colored bar representing mana percentage
     */
    std::string manaBar(int current, int max, int width = 15);

    /**
     * @brief Format a list of active effects
     * @param effects Vector of active effects to display
     * @return String representation of the effects list
     * @details Creates a formatted string showing all active status effects
     */
    std::string effectsList(const std::vector<ActiveEffect>& effects);

    /**
     * @brief Display the battle interface
     * @param player The player character
     * @param enemy The enemy entity
     * @details Shows health bars, status effects, and other battle information
     */
    void battleInterface(const Character& player, const Entity& enemy);

    /**
     * @brief Display an attack animation
     * @param attackerName Name of the attacking entity
     * @param abilityName Optional name of the ability being used
     * @details Shows a visual animation for attack actions
     */
    void attackAnimation(const std::string& attackerName, const std::string& abilityName = "");

    /**
     * @brief Display damage numbers
     * @param target Name of the entity receiving damage/healing
     * @param amount Amount of damage or healing
     * @param isHeal Whether this is healing (true) or damage (false)
     * @details Shows damage or healing amounts with appropriate colors
     */
    void displayDamage(const std::string& target, int amount, bool isHeal = false);

    /**
     * @brief Create a mana bar with numeric values
     * @param character The character whose mana to display
     * @param width Width of the mana bar in characters
     * @return String representation of the mana bar with numbers
     * @details Returns a colored bar with numeric values representing mana
     */
    std::string manaBarWithNumbers(const Character& character, int width = 15);

    /**
     * @brief Log an enemy action
     * @param action The action being taken
     * @param details Additional details about the action
     * @details Adds an enemy action to the battle log
     */
    void enemyActionLog(const std::string& action, const std::string& details = "");

    /**
     * @brief Display an enemy attack animation
     * @param attacker Name of the attacking enemy
     * @details Shows a visual animation for enemy attack actions
     */
    void enemyAttackAnimation(const std::string& attacker);

    /** @brief Battle log containing recent actions */
    extern std::vector<std::string> battleLog;
    
    /**
     * @brief Add a message to the battle log
     * @param message The message to add
     * @details Adds a new entry to the battle log, maintaining a maximum size
     */
    void addToLog(const std::string& message);
    
    /**
     * @brief Display the battle log
     * @details Shows the most recent battle log entries
     */
    void displayLog();
}
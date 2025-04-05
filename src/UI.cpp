/**
 * @file UI.cpp
 * @brief Implementation of the UI (User Interface) class
 * @details Contains methods for displaying game information in the console,
 *          including battle interfaces, health/mana bars, animations, and logs
 */

#include "UI.h"
#include <iostream>
#include <chrono>
#include <thread>

std::vector<std::string> UI::battleLog;

/**
 * @brief Adds a message to the battle log
 * @param message The message to add to the log
 * @details Adds the specified message to the battle log and manages the log size
 *          by removing the oldest messages when the log exceeds 5 entries.
 */
void UI::addToLog(const std::string& message) {
    battleLog.push_back(message);
    if (battleLog.size() > 5) battleLog.erase(battleLog.begin());
}

/**
 * @brief Displays the battle log
 * @details Prints the entire battle log to the console,
 *          showing recent battle events and messages.
 */
void UI::displayLog() {
    std::cout << COLOR_CYAN << "=== Battle Log ===" << COLOR_RESET << "\n";
    for (const auto& msg : battleLog) {
        std::cout << "> " << msg << "\n";
    }
}

/**
 * @brief Clears the console screen
 * @details Uses platform-specific commands to clear the console screen,
 *          creating a cleaner interface between game states.
 */
void UI::clearScreen() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
    std::cout << COLOR_RESET << std::endl;
}

/**
 * @brief Creates a text-based health bar
 * @param current Current health value
 * @param max Maximum health value
 * @param width Width of the health bar in characters
 * @return String representation of the health bar
 * @details Generates a visual representation of health as a progress bar,
 *          using the ratio of current to max health to determine the filled portion.
 */
std::string UI::healthBar(int current, int max, int width) {
    float ratio = std::clamp(static_cast<float>(current) / max, 0.0f, 1.0f);
    int filled = static_cast<int>(ratio * width);
    
    std::string bar = "[";
    bar += std::string(filled, '=');
    bar += std::string(width - filled, ' ');
    bar += "] ";
    bar += std::to_string(current) + "/" + std::to_string(max);
    return bar;
}

/**
 * @brief Creates a text-based mana bar
 * @param current Current mana value
 * @param max Maximum mana value
 * @param width Width of the mana bar in characters
 * @return String representation of the mana bar
 * @details Generates a visual representation of mana as a progress bar,
 *          using the ratio of current to max mana to determine the filled portion.
 *          Uses asterisks to represent mana instead of equals signs.
 */
std::string UI::manaBar(int current, int max, int width) {
    float ratio = static_cast<float>(current) / max;
    int filled = static_cast<int>(ratio * width);
    
    std::string bar = "[";
    bar += std::string(filled, '*');
    bar += std::string(width - filled, ' ');
    bar += "]";
    return bar;
}

/**
 * @brief Creates a list of active effects on an entity
 * @param effects Vector of active effects to display
 * @return String representation of the effects list
 * @details Generates a formatted list of all active effects on an entity,
 *          including their types and remaining durations.
 *          Returns an empty string if there are no active effects.
 */
std::string UI::effectsList(const std::vector<ActiveEffect>& effects) {
    if (effects.empty()) return "None";
    
    std::string list;
    for (const auto& effect : effects) {
        list += Character::toString(effect.type) 
               + " (" + std::to_string(effect.duration) + " turns)";
        
        if (effect.damagePerTurn > 0) {
            list += " [Dmg: " + std::to_string(effect.damagePerTurn) + "]";
        }
        if (effect.healPerTurn > 0) {
            list += " [Heal: " + std::to_string(effect.healPerTurn) + "]";
        }
        if (effect.speedModifier != 1.0f) {
            list += " [Speed: " + std::to_string(effect.speedModifier * 100) + "%]";
        }
        list += ", ";
    }
    return list.empty() ? "None" : list.substr(0, list.size() - 2);
}

/**
 * @brief Displays the battle interface
 * @param player The player character
 * @param enemy The enemy entity
 * @details Creates and displays a formatted battle interface showing
 *          health, mana, attack, defense, and active effects for both
 *          the player and enemy. Also displays the battle log.
 */
void UI::battleInterface(const Character& player, const Entity& enemy) {
    clearScreen();
    
    const Character* enemyCharacter = dynamic_cast<const Character*>(&enemy);
    if (!enemyCharacter) {
        std::cerr << "Error: Enemy is not a Character!" << std::endl;
        return;
    }

    std::cout << COLOR_YELLOW << "===== BATTLE =====" << COLOR_RESET << "\n";
    
    std::cout << COLOR_GREEN << "[Player] " << player.getName() 
              << " (Lv." << player.getLevel() << ")\n"
              << "HP: " << healthBar(player.getHealth(), Entity::MAX_HEALTH) 
              << " (" << player.getHealth() << "/" << Entity::MAX_HEALTH << ")\n"
              << "MP: " << manaBar(player.getMana(), Entity::MAX_MANA) 
              << " (" << player.getMana() << "/" << Entity::MAX_MANA << ")\n"
              << "Attack: " << player.getAttackPower() << "\n"
              << "Defense: " << player.getDefense() << "\n"
              << "EXP: " << player.getExperience() << "/" << player.getRequiredExp() << "\n"
              << "Kills: " << player.getKills() << "\n"
              << "Effects: " << effectsList(player.getActiveEffects()) << "\n\n";

    std::cout << COLOR_RED << "[Enemy] " << enemyCharacter->getName() << "\n"
              << "HP: " << healthBar(enemyCharacter->getHealth(), Entity::MAX_HEALTH) 
              << " (" << enemyCharacter->getHealth() << "/" << Entity::MAX_HEALTH << ")\n"
              << "Attack: " << enemyCharacter->getAttackPower() << "\n"
              << "Defense: " << enemyCharacter->getDefense() << "\n"
              << "Effects: " << effectsList(enemyCharacter->getActiveEffects()) << "\n"
              << COLOR_RESET << "\n";

    displayLog();
    std::cout << "\n" << COLOR_YELLOW << "==================" << COLOR_RESET << "\n";
}

/**
 * @brief Displays an attack animation
 * @param attackerName The name of the attacking character
 * @param abilityName The name of the ability being used (optional)
 * @details Creates a simple text-based animation for attacks or ability use,
 *          with a delay between dots to simulate action. Uses colored text
 *          to enhance the visual effect.
 */
void UI::attackAnimation(const std::string& attackerName, const std::string& abilityName) {
    std::cout << COLOR_MAGENTA;
    if (!abilityName.empty()) {
        std::cout << attackerName << " uses " << abilityName << "!\n";
    } else {
        std::cout << attackerName << " attacks!\n";
    }
    
    for (int i = 0; i < 3; ++i) {
        std::cout << ".";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
    std::cout << COLOR_RESET << "\n";
}

/**
 * @brief Displays damage or healing messages
 * @param target The name of the target character
 * @param amount The amount of damage or healing
 * @param isHeal Whether this is healing (true) or damage (false)
 * @details Adds a colored message to the battle log indicating damage taken
 *          or health restored, with appropriate formatting based on the action type.
 */
void UI::displayDamage(const std::string& target, int amount, bool isHeal) {
    if (isHeal) {
        addToLog(COLOR_GREEN + target + " heals " + std::to_string(amount) + " HP!" + COLOR_RESET);
    } else {
        addToLog(COLOR_RED + target + " takes " + std::to_string(amount) + " damage!" + COLOR_RESET);
    }
}

/**
 * @brief Creates a detailed mana bar with numeric values
 * @param character The character whose mana to display
 * @param width Width of the mana bar in characters
 * @return String representation of the mana bar with numeric values
 * @details Similar to manaBar, but includes the current and maximum mana values
 *          at the end of the bar for clearer information display.
 */
std::string UI::manaBarWithNumbers(const Character& character, int width) {
    float manaRatio = static_cast<float>(character.getMana()) / Entity::MAX_MANA;
    int filled = static_cast<int>(width * manaRatio);

    std::string bar = "[";
    bar += std::string(filled, '*') + std::string(width - filled, ' ');
    bar += "] " + std::to_string(character.getMana()) + "/" + std::to_string(Entity::MAX_MANA);
    return bar + "\n";
}

/**
 * @brief Logs enemy actions to the battle log
 * @param action The main action description
 * @param details Additional details about the action (optional)
 * @details Creates a formatted log entry for enemy actions with proper coloring,
 *          and adds it to the battle log for display in the interface.
 */
void UI::enemyActionLog(const std::string& action, const std::string& details) {
    std::string message = COLOR_RED + "[Enemy] " + COLOR_RESET + action;
    if (!details.empty()) message += " (" + details + ")";
    addToLog(message);
}

/**
 * @brief Displays an ASCII art animation for enemy attacks
 * @param attacker The name of the attacking enemy
 * @details Shows a simple ASCII art animation depicting an enemy attack,
 *          with colored text and a short delay for visual effect.
 *          Clears the screen after the animation completes.
 */
void UI::enemyAttackAnimation(const std::string& attacker) {
    std::cout 
        << COLOR_RED << "  >> " << attacker << " attacks!\n"
        << "   \\\\\n"
        << "    \\\\_\\\n"
        << "     (•_•)\n"
        << "     / >💥" << COLOR_RESET;
    std::this_thread::sleep_for(std::chrono::milliseconds(700));
    clearScreen();
}
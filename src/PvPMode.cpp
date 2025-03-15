/**
 * @file PvPMode.cpp
 * @brief Implementation of the PvPMode class
 * @details Contains the implementation of the player versus player game mode
 *          where two player-controlled characters battle against each other
 */

#include "PvPMode.h"
#include "UI.h"
#include <iostream>
#include <limits>
#include <memory>

/**
 * @brief Constructor for PvPMode
 * @param p1 Shared pointer to the first player character
 * @param p2 Shared pointer to the second player character
 * @details Initializes a PvP battle between two player-controlled characters
 */
PvPMode::PvPMode(std::shared_ptr<Character> p1, std::shared_ptr<Character> p2)
    : player1(p1), player2(p2) {}

/**
 * @brief Selects an ability from a character's deck
 * @param character The character whose abilities to select from
 * @return A shared pointer to the selected ability, or nullptr if selection failed
 * @details Displays the available abilities in the character's deck and
 *          allows the player to choose one. Returns the selected ability
 *          or nullptr if the deck is empty or the selection is invalid.
 */
std::shared_ptr<Ability> PvPMode::selectAbility(const Character& character) {
    auto deck = character.getDeck();
    if (!deck || deck->size() == 0) {
        std::cout << "No abilities available!\n";
        return nullptr;
    }

    std::cout << "Choose an ability:\n";
    const auto& cards = deck->getCards();
    for (size_t i = 0; i < cards.size(); ++i) {
        std::cout << i + 1 << ". " << cards[i]->getName() << "\n";
    }

    int choice;
    std::cin >> choice;

    if (choice > 0 && choice <= static_cast<int>(cards.size())) {
        return std::dynamic_pointer_cast<Ability>(cards[choice - 1]);
    } else {
        std::cout << "Invalid choice!\n";
        return nullptr;
    }
}

/**
 * @brief Allows a character to use an item from their inventory
 * @param character The character who will use the item
 * @details Displays a list of available items in the character's inventory,
 *          lets the player select one, applies its effects to the character,
 *          and removes the item from the inventory after use.
 */
void PvPMode::useItemFromInventory(Character& character) {
    auto inventory = character.getInventory();
    if (!inventory || inventory->getItems().empty()) {
        std::cout << "No items available!\n";
        return;
    }

    std::cout << "Choose an item:\n";
    const auto& items = inventory->getItems();
    for (size_t i = 0; i < items.size(); ++i) {
        std::cout << i + 1 << ". " << items[i]->getName() << " - " << items[i]->getDescription() << "\n";
    }

    int choice;
    if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input! Please enter a number.\n";
        return;
    }

    if (choice > 0 && choice <= static_cast<int>(items.size())) {
        Item* selectedItem = items[choice - 1];
        selectedItem->apply(character);
        inventory->removeItem(selectedItem);
        std::cout << "Used item: " << selectedItem->getName() << "\n";
    } else {
        std::cout << "Invalid choice!\n";
    }
}

/**
 * @brief Handles a player's turn in the PvP battle
 * @param attacker The character taking their turn
 * @param defender The opposing character
 * @details Displays the battle interface, presents action options to the player,
 *          and processes the selected action (attack, ability, defend).
 *          Updates both characters' status after the action is completed.
 */
void PvPMode::playerTurn(std::shared_ptr<Character> attacker, std::shared_ptr<Character> defender) {
    UI::clearScreen();
    std::cout << "=== " << attacker->getName() << "'s turn ===\n";
    std::cout << "1. Attack\n2. Ability\n3. Item\n";
    
    int choice;
    std::cin >> choice;
    
    switch (choice) {
        case 1:
            attacker->attack(*defender);
            break;
        case 2:
            if (auto ability = selectAbility(*attacker)) {
                attacker->useAbility(*ability, *defender);
            }
            break;
        case 3:
            useItemFromInventory(*attacker);
            break;
    }
    
    attacker->updateEffect();
    defender->updateEffect();
}

/**
 * @brief Starts the PvP battle
 * @details Initializes the battle between two player characters,
 *          sets up targeting, and manages the battle loop until
 *          one character is defeated. Alternates turns between players
 *          and displays the battle outcome at the end.
 */
void PvPMode::start() {
    std::cout << "PvP Battle started! " << player1->getName() << " vs " << player2->getName() << std::endl;

    player1->setTarget(player2);
    player2->setTarget(player1);

    while (player1->isAlive() && player2->isAlive()) {
        playerTurn(player1, player2);
        if (!player2->isAlive()) break;

        playerTurn(player2, player1);
    }

    if (player1->isAlive()) {
        std::cout << player1->getName() << " wins!" << std::endl;
    } else {
        std::cout << player2->getName() << " wins!" << std::endl;
    }
}
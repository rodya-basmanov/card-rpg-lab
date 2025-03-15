/**
 * @file BattleMode.cpp
 * @brief Implementation of the BattleMode class
 * @details Contains the implementation of battle mechanics between the player and enemy
 */

#include "BattleMode.h"
#include "UI.h"
#include "EasyAI.h"
#include <iostream>

/**
 * @brief Constructor for BattleMode
 * @param p Shared pointer to the player character
 * @param e Shared pointer to the enemy character
 * @details Initializes a battle session between player and enemy characters
 */
BattleMode::BattleMode(std::shared_ptr<Character> p, std::shared_ptr<Character> e)
    : player(p), enemy(e) {}

/**
 * @brief Starts the battle mode
 * @details Prints initial message and begins the battle loop
 */
void BattleMode::start() {
    std::cout << "Battle started! " << player->getName() << " vs " << enemy->getName() << std::endl;

    player->setTarget(enemy);
    enemy->setTarget(player);

    if (!enemy->getAI()) {
        std::cout << "[DEBUG] Setting AI for enemy!" << std::endl;
        enemy->setAI(std::make_shared<EasyAI>(enemy));
    }

    while (player->isAlive() && enemy->isAlive()) {
        bool endTurn = true;

        try {
            UI::battleInterface(*player, *enemy);
        } catch (const std::exception& e) {
            std::cerr << "Error drawing interface: " << e.what() << std::endl;
        }

        BattleAction action = getPlayerChoice();
        switch (action) {
            case BattleAction::ATTACK:
                try {
                    UI::attackAnimation(player->getName());
                } catch (const std::exception& e) {
                    std::cerr << "Error showing animation: " << e.what() << std::endl;
                }
                player->attack(*enemy);
                UI::addToLog(COLOR_GREEN + player->getName() + " attacks " + enemy->getName() + "!" + COLOR_RESET);
                break;

            case BattleAction::ABILITY: {
                auto card = selectAbilityCard(*player);
                if (card && player->getMana() >= card->getManaCost()) {
                    card->play(*enemy);
                    player->reduceMana(card->getManaCost());
                    UI::addToLog(COLOR_CYAN + player->getName() + " uses " + card->getName() + "!" + COLOR_RESET);
                    endTurn = false;
                } else {
                    std::cout << "Can't use this ability!" << std::endl;
                    UI::addToLog(COLOR_RED + "Not enough mana to use " + card->getName() + "!" + COLOR_RESET);
                }
                break;
            }

            case BattleAction::DEFEND:
                player->setDefense(player->getDefense() + 5);
                UI::addToLog(COLOR_BLUE + player->getName() + " increases defense by 5!" + COLOR_RESET);
                break;

            case BattleAction::ITEM:
                useItemFromInventory(*player);
                endTurn = false;
                break;

            default:
                std::cout << "Invalid action! Skipping turn.\n";
                UI::addToLog(COLOR_RED + "Invalid action! Skipping turn." + COLOR_RESET);
                break;
        }

        if (endTurn && enemy->isAlive()) {
            std::cout << "[DEBUG] Enemy's turn!" << std::endl;
            if (enemy->getAI()) {
                enemy->performAIAction();
            } else {
                enemy->attack(*player);
                UI::addToLog(COLOR_RED + enemy->getName() + " attacks " + player->getName() + "!" + COLOR_RESET);
            }
        }

        if (player->isAlive()) {
            player->updateEffect();
        }
        if (enemy->isAlive()) {
            enemy->updateEffect();
        }
    }

    if (!enemy->isAlive()) {
        std::cout << "You win!\n";
        player->gainExp(30);
        player->incrementKills();
        UI::addToLog(COLOR_GREEN + "You gained 30 EXP and defeated " + enemy->getName() + "!" + COLOR_RESET);
        UI::addToLog(COLOR_GREEN + "Total kills: " + std::to_string(player->getKills()) + COLOR_RESET);
    } else if (!player->isAlive()) {
        std::cout << "You lose!\n";
        UI::addToLog(COLOR_RED + "You have been defeated by " + enemy->getName() + "!" + COLOR_RESET);
    } else {
        std::cout << "Battle ended in a draw!\n";
        UI::addToLog(COLOR_YELLOW + "The battle ended in a draw!" + COLOR_RESET);
    }
}

/**
 * @brief Updates the battle state
 * @details Called each game loop to update the state of the battle
 * This is currently a placeholder for future functionality
 */
void BattleMode::update() {}

/**
 * @brief Gets the player's choice of action for their turn
 * @return BattleAction enum representing the player's chosen action
 * @details Displays options and processes player input to determine their action choice
 */
BattleMode::BattleAction BattleMode::getPlayerChoice() const {
    int choice;
    while (true) {
        std::cout << "Choose an action:\n";
        std::cout << "1. Attack\n";
        std::cout << "2. Use Ability\n";
        std::cout << "3. Defend\n";
        std::cout << "4. Use Item\n";

        if (std::cin >> choice) {
            switch (choice) {
                case 1: return BattleAction::ATTACK;
                case 2: return BattleAction::ABILITY;
                case 3: return BattleAction::DEFEND;
                case 4: return BattleAction::ITEM;
                default:
                    std::cout << "Invalid choice! Please enter a number between 1 and 4.\n";
                    break;
            }
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number between 1 and 4.\n";
        }
    }
}

std::shared_ptr<Ability> BattleMode::selectAbility(const Character& character) const {
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

std::shared_ptr<Card> BattleMode::selectAbilityCard(Character& character) {
    auto deck = character.getDeck();
    if (!deck || deck->getCards().empty()) {
        std::cout << "No ability cards available!" << std::endl;
        return nullptr;
    }

    std::cout << "Select an ability card to use:" << std::endl;
    auto cards = deck->getCards();
    for (size_t i = 0; i < cards.size(); ++i) {
        std::cout << i << ". " << cards[i]->getName()
                  << " (Mana: " << cards[i]->getManaCost() << ")" << std::endl;
    }

    int index;
    std::cin >> index;
    if (index >= 0 && index < static_cast<int>(cards.size())) {
        auto selectedCard = cards[index];
        deck->removeCard(selectedCard);
        return selectedCard;
    } else {
        std::cout << "Invalid selection!" << std::endl;
        return nullptr;
    }
}

/**
 * @brief Handles the process of a character using an item from their inventory
 * @param character The character who is using an item
 * @details Displays inventory items, allows selection of an item to use, and applies its effects
 */
void BattleMode::useItemFromInventory(Character& character) {
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
/**
 * @file EasyAI.cpp
 * @brief Implementation of the EasyAI class
 * @details Contains the implementation of a basic AI controller
 *          that makes simple decisions for beginner-level opponents
 */

#include "EasyAI.h"
#include "AttackCard.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

/**
 * @brief Constructor for EasyAI
 * @param t Shared pointer to the target character
 * @details Initializes a basic AI controller with a reference to the target character
 */
EasyAI::EasyAI(std::shared_ptr<Character> t) : target(t) {}

/**
 * @brief Makes a decision for the AI-controlled character
 * @param self Reference to the character controlled by this AI
 * @param target Reference to the target entity
 * @details Implements simple decision-making logic for the easy AI:
 *          - First tries to use cards from the deck if available
 *          - Falls back to basic attack if no cards are available
 *          - Initializes random seed on first call for any randomized decisions
 */
void EasyAI::makeDecision(Character& self, Entity& target) {
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(nullptr));
        seeded = true;
    }

    if (auto deck = self.getDeck()) {
        if (!deck->getCards().empty()) {
            auto card = deck->drawCard();
            if (card) {
                std::cout << "[DEBUG] " << self.getName() << " uses a card!" << std::endl;
                card->play(target);
                return;
            }
        }
    }

    std::cout << "[DEBUG] " << self.getName() << " attacks!" << std::endl;
    self.attack(target);
}
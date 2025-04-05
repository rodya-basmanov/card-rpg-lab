/**
 * @file AdvancedAI.cpp
 * @brief Implementation of the AdvancedAI class
 * @details Contains the implementation of a more sophisticated AI controller
 *          that can make strategic decisions based on game state
 */

#include "AdvancedAI.h"
#include "Fireball.h"
#include "IceSpike.h"
#include "Regeneration.h"
#include "DefenseCard.h"
#include <iostream>

/**
 * @brief Constructor for AdvancedAI
 * @param self Shared pointer to the character controlled by this AI
 * @param target Shared pointer to the target character (typically the player)
 * @param deck Shared pointer to the deck of cards available to the AI
 * @details Initializes an advanced AI controller with references to the controlled character,
 *          its target, and its deck of cards for making strategic decisions.
 */
AdvancedAI::AdvancedAI(std::shared_ptr<Character> self, std::shared_ptr<Character> target, std::shared_ptr<Deck> deck)
    : self(self), target(target), deck(deck) {}

/**
 * @brief Makes a strategic decision for the AI-controlled character
 * @param self Reference to the character controlled by this AI
 * @param target Reference to the target entity
 * @details Evaluates the current game state and makes decisions based on multiple factors:
 *          - Uses healing abilities when health is low
 *          - Uses offensive spells when target has high health
 *          - Uses defensive abilities when necessary
 *          - Falls back to basic attacks when other options aren't viable
 */
void AdvancedAI::makeDecision(Character& self, Entity& target) {
    if (self.getHealth() < 30 && deck->size() > 0) {
        useBestCard();
    } else {
        attackOrDefend();
    }
}

/**
 * @brief Selects and uses the best card from the deck based on the current situation
 * @details This method prioritizes healing cards like Regeneration when available.
 *          If no specific tactical card is found, it draws a random card from the deck
 *          and plays it against the target. The method implements the strategic card
 *          selection logic for the AI.
 */
void AdvancedAI::useBestCard() {
    for (const auto& card : deck->getCards()) {
        if (card->getName() == "Regeneration") {
            card->play(*self);
            return;
        }
    }
    if (!deck->getCards().empty()) {
        auto card = deck->drawCard();
        card->play(*target);
    }
}

/**
 * @brief Decides between attacking or using a defensive strategy
 * @details This method compares the health of the AI-controlled character and its target.
 *          If the AI's health is lower than the target's, it plays a defensive card to 
 *          increase survivability. Otherwise, it performs a direct attack on the target.
 *          This implements the basic combat decision making for the AI.
 */
void AdvancedAI::attackOrDefend() {
    if (self->getHealth() < target->getHealth()) {
        DefenseCard defenseCard;
        defenseCard.play(*self);
    } else {
        self->attack(*target);
    }
}
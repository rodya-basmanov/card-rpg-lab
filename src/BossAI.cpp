/**
 * @file BossAI.cpp
 * @brief Implementation of the BossAI class
 * @details Contains the implementation of an advanced AI controller for boss characters,
 *          with more challenging decision-making and special abilities
 */

#include "BossAI.h"
#include "Fireball.h"
#include "IceSpike.h"
#include "BurningEffect.h"
#include "SpellCard.h"
#include "Regeneration.h"
#include <algorithm>
#include <random>
#include <iostream>

/**
 * @brief Constructor for BossAI
 * @param self Shared pointer to the character controlled by this AI
 * @param target Shared pointer to the target character (typically the player)
 * @param deck Shared pointer to the deck of cards available to the AI
 * @details Initializes a boss AI with references to the controlled character,
 *          its target, and its deck of cards for making strategic decisions
 */
BossAI::BossAI(std::shared_ptr<Character> self, std::shared_ptr<Character> target, std::shared_ptr<Deck> deck)
    : self(self), target(target), deck(deck) {}

/**
 * @brief Decision-making method for the Boss AI
 * @param self Reference to the character controlled by this AI
 * @param target Reference to the target entity
 * @details Main decision-making method that sequentially calls health check
 *          and chooses between attack or ability usage
 */
void BossAI::makeDecision(Character& self, Entity& target) {
    checkHealthAndAct();
    useAbilityOrAttack();
}

/**
 * @brief Checks health level and takes appropriate actions
 * @details If the boss's health falls below 30, attempts to use a regeneration card from the deck.
 *          If no such card is available, outputs a message about its absence
 */
void BossAI::checkHealthAndAct() {
    if (self->isAlive() && self->getHealth() < 30) {
        for (const auto& card : deck->getCards()) {
            if (card->getName() == "Regeneration") {
                card->play(*self);
                deck->removeCard(card);
                return;
            }
        }
        std::cout << "No Regeneration card available!" << std::endl;
    }
}

/**
 * @brief Chooses between using a special ability or a regular attack
 * @details Randomly chooses between a regular attack and using a card from the deck.
 *          If the deck is empty or unable to draw a card, uses Fireball as a fallback option
 */
void BossAI::useAbilityOrAttack() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    int action = dis(gen);

    if (action == 0) {
        self->attack(*target);
        std::cout << "Boss attacks!" << std::endl;
    } else {
        if (deck && !deck->getCards().empty()) {
            auto card = deck->drawCard();
            if (card) {
                card->play(*target);
                std::cout << "Boss uses " << card->getName() << std::endl;
                return;
            }
        }
        Fireball fireball;
        fireball.play(*target);
        std::cout << "Boss uses Fireball as fallback!" << std::endl;
    }
}
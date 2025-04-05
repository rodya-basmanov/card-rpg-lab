/**
 * @file BossAI.h
 * @brief Definition of the BossAI class for boss enemy behavior
 * @details This file defines an advanced AI implementation for boss encounters
 *          with complex decision-making and special abilities
 */
#pragma once
#include "AI.h"
#include "Character.h"
#include "Deck.h"

/**
 * @class BossAI
 * @brief Advanced artificial intelligence for boss enemies
 * @details Implements sophisticated decision-making for challenging boss encounters,
 *          including special ability usage and adaptive combat strategies
 */
class BossAI : public AI {
private:
    /** @brief Pointer to the character targeted by this AI (usually the player) */
    std::shared_ptr<Character> target;
    
    /** @brief Pointer to the deck of cards available to this boss */
    std::shared_ptr<Deck> deck;
    
    /** @brief Pointer to the boss character controlled by this AI */
    std::shared_ptr<Character> self;
    
    /**
     * @brief Decides whether to use a special ability or basic attack
     * @details Makes a strategic choice based on current battle conditions
     */
    void useAbilityOrAttack();
    
    /**
     * @brief Uses a random card from the boss's deck
     * @details Selects and plays a card at random from the available options
     */
    void useRandomCard();
    
    /**
     * @brief Checks the boss's health and takes appropriate action
     * @details May trigger special abilities or healing when health is low
     */
    void checkHealthAndAct();

public:
    /**
     * @brief Constructor for BossAI
     * @param self Pointer to the boss character controlled by this AI
     * @param target Pointer to the character targeted by this AI (usually the player)
     * @param deck Pointer to the deck of cards available to this boss
     */
    BossAI(std::shared_ptr<Character> self, std::shared_ptr<Character> target, std::shared_ptr<Deck> deck);
    
    /**
     * @brief Makes the best decision for the boss in the current game state
     * @param self The boss character controlled by the AI
     * @param target The entity being targeted by the AI
     * @details Implements complex boss behavior including phase-based attack patterns
     */
    void makeDecision(Character& self, Entity& target) override;
};
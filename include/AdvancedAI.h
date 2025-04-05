/**
 * @file AdvancedAI.h
 * @brief Definition of the AdvancedAI class for sophisticated game decision making
 */
#pragma once
#include "AI.h"
#include "Character.h"
#include "Deck.h"

/**
 * @class AdvancedAI
 * @brief Advanced artificial intelligence for making strategic gameplay decisions
 * 
 * AdvancedAI extends the base AI class with more sophisticated decision-making
 * algorithms, taking into account character status, available cards in deck,
 * and optimal attack/defense strategies.
 */
class AdvancedAI : public AI {
private:
    /** @brief Pointer to the character controlled by this AI */
    std::shared_ptr<Character> self;
    
    /** @brief Pointer to the character targeted by this AI */
    std::shared_ptr<Character> target;
    
    /** @brief Pointer to the deck of cards available to this AI */
    std::shared_ptr<Deck> deck;

public:
    /**
     * @brief Constructor for AdvancedAI
     * @param self Pointer to the character controlled by this AI
     * @param target Pointer to the character targeted by this AI
     * @param deck Pointer to the deck of cards available to this AI
     */
    AdvancedAI(std::shared_ptr<Character> self, std::shared_ptr<Character> target, std::shared_ptr<Deck> deck);

    /**
     * @brief Makes the best decision for the character in the current game state
     * @param self The character controlled by the AI
     * @param target The entity being targeted by the AI
     * @override Override of AI's makeDecision method
     */
    void makeDecision(Character& self, Entity& target) override;

private:
    /**
     * @brief Selects and uses the best card from the deck based on current game state
     * 
     * This method analyzes the available cards, character status, and target status
     * to determine the optimal card to play.
     */
    void useBestCard();
    
    /**
     * @brief Decides between attacking or defending based on game state
     * 
     * This method evaluates the health, mana, and status effects of both characters
     * to determine if an offensive or defensive approach is optimal.
     */
    void attackOrDefend();
};
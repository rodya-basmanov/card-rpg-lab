/**
 * @file TradingMode.h
 * @brief Definition of the TradingMode game mode
 * @details This file defines the TradingMode class, which implements
 *          card trading mechanics between the player and NPC traders
 */
#pragma once

#include "GameMode.h"
#include "Character.h"
#include "Deck.h"
#include "Card.h"
#include <memory>

/**
 * @class TradingMode
 * @brief Game mode for trading cards with NPCs
 * @details Manages the exchange of cards between the player and
 *          non-player character traders
 */
class TradingMode : public GameMode {
private:
    /** @brief Pointer to the player character */
    std::shared_ptr<Character> player;
    
    /** @brief Pointer to the trader character */
    std::shared_ptr<Character> trader;

    /**
     * @brief Let a character select a card from their deck
     * @param character The character selecting a card
     * @return The selected card
     * @details Displays the character's deck and processes card selection
     */
    std::shared_ptr<Card> selectCardFromDeck(const std::shared_ptr<Character> & character);

public:
    /**
     * @brief Constructor for TradingMode
     * @param p Pointer to the player character
     * @param trader Pointer to the trader character
     */
    TradingMode(std::shared_ptr<Character> p, std::shared_ptr<Character> trader);
    
    /**
     * @brief Exchange cards between player and trader
     * @param playerCard Card from the player's deck
     * @param traderCard Card from the trader's deck
     * @details Removes the specified cards from their respective decks
     *          and adds them to the opposite deck
     */
    void exchangeCards(std::shared_ptr<Card> playerCard, std::shared_ptr<Card> traderCard);
    
    /**
     * @brief Start the trading mode
     * @details Initializes the trading interface and displays available options
     */
    void start() override;
    
    /**
     * @brief Update the trading state
     * @details Processes player actions in the trading interface
     */
    void update() override;
};
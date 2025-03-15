/**
 * @file Deck.h
 * @brief Definition of the Deck class for card management
 * @details This file defines the Deck class that manages collections
 *          of cards for players and other game entities
 */
#pragma once
#include <vector>
#include <memory>
#include "Card.h"

/**
 * @class Deck
 * @brief Manages a collection of cards
 * @details The Deck class provides functionality for adding, removing,
 *          and drawing cards during gameplay
 */
class Deck {
private:
    /** @brief The collection of cards in this deck */
    std::vector<std::shared_ptr<Card>> cards;

public:
    /**
     * @brief Add a card to the deck
     * @param card The card to add
     */
    void addCard(std::shared_ptr<Card> card);
    
    /**
     * @brief Remove a card from the deck
     * @param card The card to remove
     */
    void removeCard(std::shared_ptr<Card> card);
    
    /**
     * @brief Draw a card from the deck
     * @return The drawn card, or nullptr if the deck is empty
     * @details Removes and returns the top card from the deck
     */
    std::shared_ptr<Card> drawCard();
    
    /**
     * @brief Get all cards in the deck
     * @return Vector containing all cards in the deck
     */
    std::vector<std::shared_ptr<Card>> getCards() const { return cards; }
    
    /**
     * @brief Get the number of cards in the deck
     * @return The number of cards
     */
    size_t size() const { return cards.size(); }
};
/**
 * @file Deck.cpp
 * @brief Implementation of the Deck class
 * @details Contains the definitions of all methods declared in Deck.h
 */

#include "Deck.h"
#include <algorithm>

/**
 * @brief Add a card to the deck
 * @param card The card to be added
 * @details Adds the specified card to the end of the deck
 */
void Deck::addCard(std::shared_ptr<Card> card) {
    cards.push_back(card);
}

/**
 * @brief Draw a card from the deck
 * @return The drawn card, or nullptr if the deck is empty
 * @details Removes and returns the top card from the deck
 */
std::shared_ptr<Card> Deck::drawCard() {
    if (!cards.empty()) {
        std::shared_ptr<Card> card = cards.back();
        cards.pop_back();
        return card;
    }
    return nullptr;
}

/**
 * @brief Remove a specific card from the deck
 * @param card The card to be removed
 * @details Searches for and removes the specified card from the deck
 */
void Deck::removeCard(std::shared_ptr<Card> card) {
    auto it = std::find(cards.begin(), cards.end(), card);
    if (it != cards.end()) {
        cards.erase(it);
    }
}
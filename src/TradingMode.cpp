/**
 * @file TradingMode.cpp
 * @brief Implementation of the TradingMode class
 * @details Contains methods for card trading between the player and a trader character,
 *          allowing players to exchange cards from their decks
 */

#include "TradingMode.h"
#include "Deck.h"
#include "Card.h"
#include "Warrior.h"
#include <iostream>

/**
 * @brief Constructor for TradingMode
 * @param p Shared pointer to the player character
 * @param trader Shared pointer to the trader character
 * @details Initializes a trading session between the player and a trader
 */
TradingMode::TradingMode(std::shared_ptr<Character> p, std::shared_ptr<Character> trader)
    : player(p), trader(trader) {}

/**
 * @brief Starts the trading mode
 * @details Provides a menu for players to trade cards with the trader character.
 *          Allows selection of cards from both decks and facilitates the exchange.
 *          Continues until the player chooses to exit the trading session.
 */
void TradingMode::start() {
    std::cout << "Trading started between " << player->getName() << " and " << trader->getName() << std::endl;
    std::cout << "Trader's deck size: " << trader->getDeck()->getCards().size() << std::endl;
    std::cout << "Trading started between " << player->getName() << " and " << trader->getName() << std::endl;

    std::shared_ptr<Card> playerCard = selectCardFromDeck(player);
    if (!playerCard) {
        std::cout << "Player cancels the trade." << std::endl;
        return;
    }

    std::shared_ptr<Card> traderCard = selectCardFromDeck(trader);
    if (!traderCard) {
        std::cout << "Trader cancels the trade." << std::endl;
        return;
    }

    std::cout << "Trade proposed: " << player->getName() << " offers " << playerCard->getName()
              << " for " << traderCard->getName() << std::endl;
    std::cout << "Accept trade? (y/n): ";
    char choice;
    std::cin >> choice;

    if (choice == 'y') {
        exchangeCards(playerCard, traderCard);
        std::cout << "Trade completed!" << std::endl;
    } else {
        std::cout << "Trade canceled." << std::endl;
    }
}

/**
 * @brief Selects a card from a character's deck
 * @param character The character whose deck to select from
 * @return A shared pointer to the selected card, or nullptr if selection failed
 * @details Displays all cards in the character's deck and allows selection
 *          by choosing a card index. Returns the selected card or nullptr
 *          if the deck is empty or the selection is invalid.
 */
std::shared_ptr<Card> TradingMode::selectCardFromDeck(const std::shared_ptr<Character>& character) {
    std::cout << character->getName() << ", select a card to trade (enter index): ";

    std::shared_ptr<Deck> deck = character->getDeck();
    if (!deck || deck->getCards().empty()) {
        std::cout << "No cards to trade." << std::endl;
        return nullptr;
    }

    std::vector<std::shared_ptr<Card>> cards = deck->getCards();
    std::cout << "Available cards:" << std::endl;
    for (size_t i = 0; i < cards.size(); ++i) {
        std::cout << i << ". " << cards[i]->getName() << std::endl;
    }

    int index;
    std::cin >> index;
    if (index >= 0 && index < static_cast<int>(cards.size())) {
        return cards[index];
    } else {
        std::cout << "Invalid card index." << std::endl;
        return nullptr;
    }
}

/**
 * @brief Exchanges cards between the player and trader
 * @param playerCard The card from the player's deck to trade
 * @param traderCard The card from the trader's deck to trade
 * @details Removes the selected card from each character's deck
 *          and adds the other character's card to their deck.
 *          Displays messages confirming the successful exchange.
 */
void TradingMode::exchangeCards(std::shared_ptr<Card> playerCard, std::shared_ptr<Card> traderCard) {
    player->getDeck()->removeCard(playerCard);
    trader->getDeck()->removeCard(traderCard);

    player->getDeck()->addCard(traderCard);
    trader->getDeck()->addCard(playerCard);
}

/**
 * @brief Updates the trading mode
 * @details Restarts the trading session.
 *          This is a simple implementation that calls the start method.
 */
void TradingMode::update() {
    start();
}
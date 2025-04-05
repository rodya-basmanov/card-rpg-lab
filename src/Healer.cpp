/**
 * @file Healer.cpp
 * @brief Implementation of the Healer class
 * @details Contains the implementations of Healer-specific functionality,
 *          including construction, healing abilities, and deck initialization
 */

#include "Healer.h"
#include "Regeneration.h"
#include "SpecialCard.h"
#include "HealthPotion.h"
#include "Inventory.h"
#include <iostream>

/**
 * @brief Constructor for Healer
 * @param name The name of the healer
 * @param health Initial health value
 * @param mana Initial mana value
 * @param attackPower The attack power of the healer
 * @param defense The defense value of the healer
 * @details Initializes a Healer character with the specified attributes,
 *          sets up a deck with regeneration and special cards,
 *          and populates the inventory with a health potion.
 */
Healer::Healer(const std::string& name, int health, int mana, int attackPower, int defense)
    : Character(name, health, mana, attackPower, defense) {
    deck = std::make_shared<Deck>();
    deck->addCard(std::make_shared<Regeneration>());
    deck->addCard(std::make_shared<SpecialCard>());

    setInventory(std::make_shared<Inventory>());

    auto inventory = getInventory();
    if (inventory) {
        inventory->addItem(new HealthPotion());
    } else {
        std::cerr << "Inventory is not initialized!" << std::endl;
    }
}

/**
 * @brief Healer's implementation of attack
 * @param target The entity to attack
 * @details Healers have weaker attacks but provide support through healing.
 *          Their attacks still deal damage based on their attack power.
 */
void Healer::attack(Entity& target) {
    int damage = getAttackPower();
    target.takeDamage(damage);
    std::cout << getName() << " heals while attacking for " << damage << " damage!" << std::endl;
}

/**
 * @brief Heals an ally character
 * @param ally The ally character to heal
 * @details Restores a fixed amount of health (20) to the specified ally,
 *          displaying a message about the healing performed.
 */
void Healer::healAllies(Character& ally) {
    int healingAmount = 20;
    ally.heal(healingAmount);
    std::cout << getName() << " heals " << ally.getName() << " for " << healingAmount << " points!" << std::endl;
}

/**
 * @brief Healer's ability usage method
 * @param ability The ability to use
 * @param target The target for the ability
 * @details Healers specialize in restoration and support abilities.
 *          This method applies the specified ability to the target if there is enough mana,
 *          reduces the healer's mana accordingly, and displays a message.
 */
void Healer::useAbility(Ability& ability, Entity& target) {
    if (getMana() >= ability.getManaCost()) {
        reduceMana(ability.getManaCost());
        ability.activate(*this, target);
        std::cout << getName() << " uses " << ability.getName() << "!" << std::endl;
    } else {
        std::cout << "Not enough mana to use " << ability.getName() << "!" << std::endl;
    }
}

/**
 * @brief Gets the healer's card deck
 * @return A shared pointer to the deck
 * @details Provides access to the healer's deck of cards,
 *          which typically contains healing and support cards.
 */
std::shared_ptr<Deck> Healer::getDeck() const {
    return deck;
}

/**
 * @brief AI control for Healer characters
 * @details Defines the AI behavior for healer NPCs.
 *          Healers prioritize using cards from their deck if available,
 *          focusing on healing and support abilities.
 *          They resort to basic attacks when other options are unavailable.
 */
void Healer::performAIAction() {
    if (auto target = getTarget()) {
        if (target->isAlive()) {
            if (auto deck = getDeck()) {
                if (!deck->getCards().empty()) {
                    auto card = deck->drawCard();
                    if (card) {
                        std::cout << "[DEBUG] " << getName() << " uses a card!" << std::endl;
                        card->play(*target);
                        return;
                    }
                }
            }

            std::cout << "[DEBUG] " << getName() << " attacks!" << std::endl;
            attack(*target);
        } else {
            std::cout << "[DEBUG] " << getName() << " has no valid target!" << std::endl;
        }
    } else {
        std::cout << "[DEBUG] " << getName() << " has no target set!" << std::endl;
    }
}
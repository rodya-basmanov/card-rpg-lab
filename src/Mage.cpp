/**
 * @file Mage.cpp
 * @brief Implementation of the Mage class
 * @details Contains the implementations of Mage-specific functionality,
 *          including construction, special abilities, spellcasting, and deck initialization
 */

#include "Mage.h"
#include "Fireball.h"
#include "LightningCard.h"
#include "SpellCard.h"
#include <iostream>

/**
 * @brief Constructor for Mage
 * @param name The name of the mage
 * @param health Initial health value
 * @param mana Initial mana value
 * @param attackPower The attack power of the mage
 * @param defense The defense value of the mage
 * @details Initializes a Mage character with the specified attributes
 *          and sets up a basic deck with Fireball, LightningCard, and SpellCard.
 */
Mage::Mage(const std::string& name, int health, int mana, int attackPower, int defense)
    : Character(name, health, mana, attackPower, defense) {
    deck = std::make_shared<Deck>();
    deck->addCard(std::make_shared<Fireball>());
    deck->addCard(std::make_shared<LightningCard>());
    deck->addCard(std::make_shared<SpellCard>());
}

/**
 * @brief Mage's implementation of attack
 * @param target The entity to attack
 * @details Mages have a special attack that uses mana for a fireball
 *          instead of a standard attack if they have enough mana (20+).
 *          Otherwise, they perform a basic staff attack.
 */
void Mage::attack(Entity& target) {
    if (getMana() >= 20) {
        Fireball fireball;
        fireball.play(target);
        reduceMana(20);
    } else {
        int damage = getAttackPower();
        target.takeDamage(damage);
        std::cout << getName() << " hits with a staff for " << damage << " damage!" << std::endl;
    }
}

/**
 * @brief Mage's ability usage method
 * @param ability The ability to use
 * @param target The target for the ability
 * @details Applies magical abilities to the target if the mage has 
 *          sufficient mana. Consumes mana and displays a message
 *          about the ability's usage.
 */
void Mage::useAbility(Ability& ability, Entity& target) {
    if (getMana() >= ability.getManaCost()) {
        reduceMana(ability.getManaCost());
        ability.applyEffect(target);
        std::cout << getName() << " uses " << ability.getName() << " on " << target.getName() << "!" << std::endl;
    } else {
        std::cout << "Not enough mana to use " << ability.getName() << "!" << std::endl;
    }
}

/**
 * @brief AI control for Mage characters
 * @details Defines the AI behavior for mage NPCs.
 *          Mages prioritize using cards from their deck if available,
 *          then casting Fireball if they have enough mana, 
 *          and finally using basic attacks as a last resort.
 */
void Mage::performAIAction() {
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

            if (getMana() >= 20) {
                std::cout << "[DEBUG] " << getName() << " casts Fireball!" << std::endl;
                Fireball fireball;
                fireball.play(*target);
            } else {
                std::cout << "[DEBUG] " << getName() << " attacks!" << std::endl;
                attack(*target);
            }
        } else {
            std::cout << "[DEBUG] " << getName() << " has no valid target!" << std::endl;
        }
    } else {
        std::cout << "[DEBUG] " << getName() << " has no target set!" << std::endl;
    }
}
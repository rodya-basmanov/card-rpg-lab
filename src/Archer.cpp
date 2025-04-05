/**
 * @file Archer.cpp
 * @brief Implementation of the Archer class
 * @details Contains the implementations of Archer-specific functionality,
 *          including construction, special abilities, ranged attacks, and deck initialization
 */

#include "Archer.h"
#include "IceSpike.h"
#include "TrapCard.h"
#include "Poison.h"
#include <iostream>

/**
 * @brief Constructor for Archer
 * @param name The name of the archer
 * @param health Initial health value
 * @param mana Initial mana value
 * @param attackPower The attack power of the archer
 * @param defense The defense value of the archer
 * @details Initializes an Archer character with the specified attributes
 *          and sets up a basic deck with ice spike, trap, and poison cards.
 */
Archer::Archer(const std::string& name, int health, int mana, int attackPower, int defense)
    : Character(name, health, mana, attackPower, defense) {
    deck = std::make_shared<Deck>();
    deck->addCard(std::make_shared<IceSpike>());
    deck->addCard(std::make_shared<TrapCard>());
    deck->addCard(std::make_shared<Poison>());
}

/**
 * @brief Archer's implementation of attack
 * @param target The entity to attack
 * @details Archers specialize in ranged attacks with a bow and arrow.
 *          They can often target weak points for additional damage.
 */
void Archer::attack(Entity& target) {
    int damage = getAttackPower();
    target.takeDamage(damage);
    std::cout << getName() << " shoots an arrow at " << target.getName() << " for " << damage << " damage!" << std::endl;
}

/**
 * @brief Archer's ability usage method
 * @param ability The ability to use
 * @param target The target for the ability
 * @details Archers can use specialized abilities like traps or poisons.
 *          Consumes mana and applies the ability's effect to the target.
 */
void Archer::useAbility(Ability & ability, Entity & target) {
    if (auto* iceSpike = dynamic_cast<IceSpike*>(&ability)) {
        std::cout << getName() << " uses Ice Spike to slow the enemy!" << std::endl;
        
        iceSpike->play(target);
    } else {
        std::cout << "Unknown ability used!" << std::endl;
    }
}

/**
 * @brief AI control for Archer characters
 * @details Defines the AI behavior for archer NPCs.
 *          Archers primarily use ranged attacks, with a focus
 *          on maintaining distance while dealing damage.
 */
void Archer::performAIAction() {
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
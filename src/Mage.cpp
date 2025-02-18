#include "Mage.h"
#include "Fireball.h"
#include <iostream>

Mage::Mage(const std::string& name, int health, int mana, int attackPower, int defense)
    : Character(name, health, mana, attackPower, defense) {}

    void Mage::attack(Entity& target) {
        if (getMana() >= 20) {
            reduceMana(20);
            Fireball fireball;
            Character* characterTarget = dynamic_cast<Character*>(&target);
            if (characterTarget) {
                fireball.activate(*characterTarget);
            } else {
                std::cout << "Target is not a Character!" << std::endl;
            }
        } else {
            std::cout << getName() << " doesn't have enough mana to attack!" << std::endl;
        }
    }
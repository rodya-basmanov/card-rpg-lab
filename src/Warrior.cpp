#include "Warrior.h"
#include <iostream>

Warrior::Warrior(const std::string& name, int health, int mana, int attackPower, int defense)
    : Character(name, health, mana, attackPower, defense) {}

    void Warrior::attack(Entity& target) {
        Character* characterTarget = dynamic_cast<Character*>(&target);
        if (characterTarget) {
            int damage = getAttackPower() - characterTarget->getDefense();
            if (damage < 0) damage = 0;
            target.takeDamage(damage);
            std::cout << getName() << " attacks with a sword for " << damage << " damage!" << std::endl;
        } else {
            std::cout << "Target is not a Character!" << std::endl;
        }
    }
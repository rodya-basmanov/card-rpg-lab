#include "Healer.h"
#include <iostream>

Healer::Healer(const std::string& name, int health, int mana, int attackPower, int defense)
    : Character(name, health, mana, attackPower, defense) {}

void Healer::attack(Entity& target) {
    int damage = getAttackPower();
    target.takeDamage(damage);
    std::cout << getName() << " heals while attacking for " << damage << " damage!" << std::endl;
}

void Healer::healAllies(Character& ally) {
    int healingAmount = 20;
    ally.heal(healingAmount);
    std::cout << getName() << " heals " << ally.getName() << " for " << healingAmount << " points!" << std::endl;
}
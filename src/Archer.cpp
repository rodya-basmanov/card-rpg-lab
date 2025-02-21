#include "Archer.h"
#include "IceSpike.h"
#include <iostream>

Archer::Archer(const std::string& name, int health, int mana, int attackPower, int defense)
    : Character(name, health, mana, attackPower, defense) {}

void Archer::attack(Entity& target) {
    int damage = getAttackPower();
    target.takeDamage(damage);
    std::cout << getName() << " shoots an arrow for " << damage << " damage!" << std::endl;
}

void Archer::useAbility(IceSpike& iceSpike, Character& target) {
    std::cout << getName() << " uses Ice Spike to slow the enemy!" << std::endl;
    iceSpike.activate(target);
}
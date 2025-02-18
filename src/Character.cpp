#include "Character.h"
#include "Ability.h"
#include <iostream>

Character::Character(const std::string& name, int health, int mana, int attackPower, int defense) : Entity(name, health, mana), attackPower(attackPower), defense(defense) {}

void Character::useAbility(Ability& ability) {
    ability.activate(*this);
    std::cout << getName() << " uses the ability!" << std::endl;
};
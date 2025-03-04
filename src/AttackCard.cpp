#include "AttackCard.h"
#include <iostream>

AttackCard::AttackCard()
    : Card("Attack Card", "Deals 15 damage to the target.") {}

void AttackCard::play(Entity& target) {
    int damage = 15;
    target.takeDamage(damage);
    std::cout << "Attack Card deals " << damage << " damage to " << target.getName() << "!" << std::endl;
}
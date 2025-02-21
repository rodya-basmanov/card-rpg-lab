#include "TrapCard.h"
#include <iostream>

TrapCard::TrapCard()
    : Card("Trap Card", "Deals 10 damage when triggered.") {}

void TrapCard::play(Entity& target) {
    int damage = 10;
    target.takeDamage(damage);
    std::cout << "Trap Card deals " << damage << " damage to " << target.getName() << "!" << std::endl;
}
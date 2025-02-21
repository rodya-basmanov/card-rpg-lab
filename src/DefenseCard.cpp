#include "DefenseCard.h"
#include <iostream>

DefenseCard::DefenseCard()
    : Card("Defense Card", "Creates a shield that absorbs 20 damage.") {}

void DefenseCard::play(Entity& target) {
    int shieldAmount = 20;
    target.setDefense(target.getDefense() + shieldAmount);
    std::cout << "Defense Card creates a shield for " << shieldAmount << " damage!" << std::endl;
}
#include "SpecialCard.h"
#include <iostream>

SpecialCard::SpecialCard()
    : Card("Special Card", "Restores 30 mana to the target.") {}

void SpecialCard::play(Entity& target) {
    int manaRestore = 30;
    target.reduceMana(-manaRestore);
    std::cout << "Special Card restores " << manaRestore << " mana to " << target.getName() << "!" << std::endl;
}
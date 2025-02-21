#include "BurningEffect.h"
#include <iostream>

BurningEffect::BurningEffect()
    : Ability("Burning Effect", "Deals 5 damage per turn for 3 turns.") {}

void BurningEffect::activate(Character& target) {
    std::cout << "Burning Effect activates on " << target.getName() << "!" << std::endl;
    target.applyEffect(1.0f, 3);
}
#include "IceSpike.h"
#include <iostream>

IceSpike::IceSpike()
    : Ability("Ice Spike", "Slows the enemy by 30% for 2 turns.") {}

void IceSpike::activate(Character& target) {
    std::cout << "Ice Spike activates on " << target.getName() << "!" << std::endl;
    target.applyEffect(0.7f, 2);
}
#include "Fireball.h"
#include "BurningEffect.h"
#include "Character.h"
#include <iostream>

Fireball::Fireball()
    : Ability("Fireball", "Deals 25 damage and applies a burning effect.") {}

void Fireball::activate(Character& target) {
    int damage = 25;
    target.takeDamage(damage);
    std::cout << "Fireball deals " << damage << " damage to " << target.getName() << "!" << std::endl;
    
    BurningEffect burningEffect;
    burningEffect.activate(target);
}
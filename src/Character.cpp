#include "Character.h"
#include "Ability.h"
#include <iostream>

Character::Character(const std::string& name, int health, int mana, int attackPower, int defense)
    : Entity(name, health, mana), attackPower(attackPower), defense(defense), speedModifier(1.0f), effectDuration(0) {}

void Character::attack(Entity& target) {
    int damage = static_cast<int>(attackPower * speedModifier);
    target.takeDamage(damage);
    std::cout << getName() << " attacks for " << damage << " damage!" << std::endl;
}

void Character::useAbility(Ability& ability) {
    ability.activate(*this);
    std::cout << getName() << " uses the ability!" << std::endl;
}

void Character::applyEffect(float modifier, int duration) {
    speedModifier = modifier;
    effectDuration = duration;
    if (modifier == 1.0f && duration > 0) {
        std::cout << getName() << " is now burning and will take 5 damage per turn for " << duration << " turns!" << std::endl;
    } else {
        std::cout << getName() << "'s speed is now reduced to " << (modifier * 100) << "% for " << duration << " turns!" << std::endl;
    }
}

void Character::updateEffect() {
    if (effectDuration > 0) {
        effectDuration--;

        if (speedModifier == 1.0f && effectDuration >= 0) {
            int burnDamage = 5;
            takeDamage(burnDamage);
            std::cout << getName() << " takes " << burnDamage << " burn damage!" << std::endl;
        }
        
        if (effectDuration == 0) {
            speedModifier = 1.0f;
            std::cout << getName() << "'s speed has returned to normal!" << std::endl;
        }
    }
}
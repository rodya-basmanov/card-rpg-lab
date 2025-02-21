#include "Entity.h"
#include <iostream>

Entity::Entity(const std::string& name, int health, int mana, int defense) : name(name), health(health), mana(mana), defense(defense) {
    if (health > MAX_HEALTH) this->health = MAX_HEALTH; 
    if (mana > MAX_MANA) this->mana = MAX_MANA;
}

void Entity::heal(int amount) {
    health += amount;
    if (health > MAX_HEALTH) health = MAX_HEALTH;
    std::cout << name << " healed for " << amount  << " points!" << std::endl;
}
void Entity::takeDamage(int damage) {
    int finalDamage = damage - defense;
    if (finalDamage < 0) finalDamage = 0;
    health -= finalDamage;
    if (health < 0) health = 0;
    std::cout << name << " took " << finalDamage << " damage!" << std::endl;
}
void Entity::reduceMana(int amount) {
    if (amount > 0) {
        mana -= amount;
        if (mana < 0) mana = 0;
        std::cout << name << " spent " << amount << " mana!" << std::endl;
    } else if (amount < 0) {
        mana -= amount;
        if (mana > MAX_MANA) mana = MAX_MANA;
        std::cout << name << " restored " << -amount << " mana!" << std::endl;
    }
}

int Entity::getHealth() const {
    return health;
}
int Entity::getMana() const {
    return mana;
}
void Entity::setDefense(int def) {
    defense = def;
    std::cout << name << "'s defense is now " << defense << "!" << std::endl;
}
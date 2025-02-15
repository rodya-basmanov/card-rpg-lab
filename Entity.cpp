#include "Entity.h"

Entity::Entity(const std::string& name, int health, int mana) : name(name), health(health), mana(mana) {
    if (health > MAX_HEALTH) this->health = MAX_HEALTH; 
    if (mana > MAX_MANA) this->mana = MAX_MANA;
}

void Entity::heal(int amount) {
    health += amount;
    if (health > MAX_HEALTH) health = MAX_HEALTH;
    std::cout << name << " healed for " << amount  << " points!" << std::endl;
}
void Entity::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
    std::cout << name << " took " << damage << " damage" << std::endl;
}
void Entity::reduceMana(int amount) {
    mana -= amount;
    if (mana < 0) mana = 0;
    std::cout << name << " spent " << amount << " mana" << std::endl;
}

int Entity::getHealth() const {
    return health;
}
int Entity::getMana() const {
    return mana;
}
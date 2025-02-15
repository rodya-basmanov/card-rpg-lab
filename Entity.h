#pragma once 
#include <string>
#include <iostream>

class Entity {
protected:
    std::string name;
    int health;
    int mana;
public:
    static const int MAX_HEALTH = 100;
    static const int MAX_MANA = 100;
    
    Entity(const std::string& name, int health, int mana) : name(name), health(health), mana(mana) {}

    void heal(int amount) {
        health += amount;
        if (health > MAX_HEALTH) health = MAX_HEALTH;
        std::cout << name << " healed for " << amount  << " points!" << std::endl;
    }
    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
        std::cout << name << " took " << damage << " damage" << std::endl;
    }
    void reduceMana(int amount) {
        mana -= amount;
        if (mana < 0) mana = 0;
        std::cout << name << " spent " << amount << " mana" << std::endl;
    }

    int getHealth() const {
        return health;
    }
    int getMana() const {
        return mana;
    }
};
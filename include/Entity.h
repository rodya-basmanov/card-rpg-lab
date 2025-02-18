#pragma once
#include <string>

class Entity {
protected:
    std::string name;
    int health;
    int mana;

public:
    static const int MAX_HEALTH = 100;
    static const int MAX_MANA = 100;

    Entity(const std::string& name, int health, int mana); 
    void heal(int amount);                                 
    void takeDamage(int damage);                           
    void reduceMana(int amount);                           
    int getHealth() const;                                
    int getMana() const;                                  
};
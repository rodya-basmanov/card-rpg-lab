#pragma once
#include <string>

class Entity {
protected:
    std::string name;
    int health;
    int mana;
    int defense;

public:
    static const int MAX_HEALTH = 100;
    static const int MAX_MANA = 100;

    Entity(const std::string& name, int health, int mana, int defense = 0); 
    void heal(int amount);                                 
    void takeDamage(int damage);                           
    void reduceMana(int amount);                           
    int getHealth() const;                                
    int getMana() const;       
    const std::string& getName() const { return name; }  
    int getDefense() const { return defense; }
    
    virtual ~Entity() = default;
};
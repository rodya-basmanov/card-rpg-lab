#pragma once
#include <string>
#include "Entity.h"
#include "Ability.h"

class Ability;

class Character : public Entity {
protected: 
    int attackPower;
    int defense;
public:
    Character(const std::string& name, int health, int mana, int attackPower, int defense);

    virtual void attack(Entity& target) = 0;
    virtual void useAbility(Ability& ability);

    int getAttackPower() const { return attackPower; }
    int getDefense() const { return defense; }

    void setAttackPower(int power) { attackPower = power; }
    void setDefense(int def) { defense = def; }

    virtual ~Character() = default;
};
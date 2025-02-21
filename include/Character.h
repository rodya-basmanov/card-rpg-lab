#pragma once
#include <string>
#include "Entity.h"
#include "Ability.h"

class Ability;

class Character : public Entity {
protected:
    int attackPower;
    int defense;
    float speedModifier;
    int effectDuration;

public:
    Character(const std::string& name, int health, int mana, int attackPower, int defense);
    virtual void attack(Entity& target) = 0;
    virtual void useAbility(Ability& ability);
    virtual void applyEffect(float modifier, int duration);
    virtual void updateEffect();
    int getAttackPower() const { return attackPower; }
    int getDefense() const { return defense; }
    float getSpeedModifier() const { return speedModifier; }
    int getEffectDuration() const { return effectDuration; }
    void setAttackPower(int power) { attackPower = power; }
    void setDefense(int def) { defense = def; }
    virtual ~Character() = default;
};
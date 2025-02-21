#pragma once
#include "Character.h"
#include "IceSpike.h"

class Archer : public Character {
public:
    Archer(const std::string& name, int health, int mana, int attackPower, int defense);

    void attack(Entity& target) override;
    void useAbility(IceSpike& iceSpike, Character& targeta);
};
#pragma once
#include "Character.h"

class Mage : public Character {
public:
    Mage(const std::string& name, int health, int mana, int attackPower, int defense);

    void attack(Entity& target) override;
};
#pragma once
#include "Character.h"

class Warrior : public Character {
public:
    Warrior(const std::string& name, int health, int mana, int attackPower, int defense);

    void attack(Entity& target) override;
};
#pragma once
#include "Character.h"

class Healer : public Character {
public:
    Healer(const std::string& name, int health, int mana, int attackPower, int defense);

    void attack(Entity& target) override;
    void healAllies(Character& ally);
};
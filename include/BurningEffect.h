#pragma once
#include "Ability.h"
#include "Character.h"

class BurningEffect : public Ability {
public:
    BurningEffect();
    void activate(Character& target) override;
};
#pragma once
#include "Ability.h"

class Fireball : public Ability {
public:
    Fireball();

    void activate(Character& target) override;
};
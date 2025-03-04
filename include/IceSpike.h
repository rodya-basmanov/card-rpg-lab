#pragma once
#include "Ability.h"
#include "Character.h"

class IceSpike : public Ability {
public:
    IceSpike();
    void activate(Character& target) override;
};
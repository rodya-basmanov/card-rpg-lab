#pragma once
#include "Card.h"
#include "Character.h"

class SpecialCard : public Card {
public:
    SpecialCard();
    void play(Entity& target) override;
};
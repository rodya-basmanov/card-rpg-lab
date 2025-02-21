#pragma once
#include "Card.h"
#include "Entity.h"

class TrapCard : public Card {
public:
    TrapCard();
    void play(Entity& target) override;
};
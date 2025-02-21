#pragma once
#include "Card.h"
#include "Entity.h"

class AttackCard : public Card {
public:
    AttackCard();
    void play(Entity& target) override;
};
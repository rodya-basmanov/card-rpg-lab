#pragma once
#include "Card.h"
#include "Entity.h"

class DefenseCard : public Card {
public:
    DefenseCard();
    void play(Entity& target) override;
};
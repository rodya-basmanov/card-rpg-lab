#pragma once
#include "Card.h"
#include "Character.h"

class SpellCard : public Card {
public:
    SpellCard();
    void play(Entity& target) override;
};
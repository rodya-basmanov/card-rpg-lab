#include "SpellCard.h"
#include <iostream>

SpellCard::SpellCard()
    : Card("Spell Card", "Applies a magical effect to the target.") {}

void SpellCard::play(Entity& target) {
    Character* characterTarget = dynamic_cast<Character*>(&target);
    if (characterTarget) {
        std::cout << "Spell Card applies a magical effect to " << characterTarget->getName() << "!" << std::endl;
        
        characterTarget->applyEffect(1.0f, 3);
    } else {
        std::cout << "Target is not a Character!" << std::endl;
    }
}
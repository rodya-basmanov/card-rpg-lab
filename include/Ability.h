#pragma once
#include <string>
#include "Character.h"

class Character;

class Ability {
protected:
    std::string name;
    std::string description;
public:
    Ability(const std::string& name, const std::string& description)
        : name(name), description(description) {}

    virtual void activate(Character& target) = 0;

    const std::string& getName() const { return name; }
    const std::string& getDescription() const { return description; }

    virtual ~Ability() = default;
};
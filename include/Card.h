#pragma once
#include <string>
#include "Entity.h"

class Card {
protected:
    std::string name;
    std::string description;

public:
    Card(const std::string& name, const std::string& description)
        : name(name), description(description) {}

    virtual void play(Entity& target) = 0;
    const std::string& getName() const { return name; }
    const std::string& getDescription() const { return description; }

    virtual ~Card() = default;
};
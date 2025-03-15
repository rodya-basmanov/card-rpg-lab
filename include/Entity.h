/**
 * @file Entity.h
 * @brief Definition of the base Entity class for all game objects
 * @details This class represents an abstraction of any game entity
 *          that can have health, mana, defense and active effects
 */
#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <algorithm> // Replaced bits/algorithmfwd.h with standard <algorithm>
#include <vector>

/**
 * @enum EffectType
 * @brief Enumeration of effect types that can be applied to an entity
 */
enum class EffectType { NONE, SLOW, BURN, POISON, REGENERATION };

/**
 * @struct ActiveEffect
 * @brief Structure describing an active effect
 * @details Contains information about the effect type, duration and parameters
 */
struct ActiveEffect {
    /** @brief Effect type */
    EffectType type;
    
    /** @brief Speed modifier (for slowing effects) */
    float speedModifier;
    
    /** @brief Effect duration in turns */
    int duration;
    
    /** @brief Damage per turn (for periodic damage effects) */
    int damagePerTurn;
    
    /** @brief Healing per turn (for periodic healing effects) */
    int healPerTurn;

    /**
     * @brief Effect constructor
     * @param t Effect type
     * @param mod Speed modifier
     * @param dur Duration
     * @param dmg Damage per turn
     * @param heal Healing per turn
     */
    ActiveEffect(EffectType t, float mod, int dur, int dmg = 0, int heal = 0)
        : type(t), speedModifier(mod), duration(dur), damagePerTurn(dmg), healPerTurn(heal) {}
};

/**
 * @class Entity
 * @brief Base class for all entities in the game
 * @details Implements basic functionality for entities such as health, mana, defense and effects
 */
class Entity {
protected:
    /** @brief Entity name */
    std::string name;
    
    /** @brief Current health */
    int health;
    
    /** @brief Current mana */
    int mana;
    
    /** @brief Entity defense */
    int defense;
    
    /** @brief List of active effects on the entity */
    std::vector<ActiveEffect> activeEffects;

public:
    /** @brief Maximum health for all entities */
    static constexpr int MAX_HEALTH = 200;
    
    /** @brief Maximum mana for all entities */
    static constexpr int MAX_MANA = 100;

    /**
     * @brief Get list of active effects
     * @return Constant reference to active effects vector
     */
    const std::vector<ActiveEffect>& getActiveEffects() const { return activeEffects; }

    /**
     * @brief Entity constructor
     * @param name Entity name
     * @param health Initial health
     * @param mana Initial mana
     * @param defense Initial defense
     */
    Entity(const std::string& name, int health, int mana, int defense = 0);
    
    /**
     * @brief Virtual destructor
     */
    virtual ~Entity() = default;

    /**
     * @brief Heal the entity
     * @param amount Amount of health to restore
     */
    virtual void heal(int amount);
    
    /**
     * @brief Take damage
     * @param damage Amount of damage to receive
     */
    virtual void takeDamage(int damage);
    
    /**
     * @brief Set defense value
     * @param def New defense value
     */
    virtual void setDefense(int def);
    
    /**
     * @brief Get current health
     * @return Current health
     */
    virtual int getHealth() const;
    
    /**
     * @brief Get current mana
     * @return Current mana
     */
    virtual int getMana() const;
    
    /**
     * @brief Get entity name
     * @return Entity name
     */
    virtual const std::string& getName() const { return name; }
    
    /**
     * @brief Get entity defense
     * @return Current defense
     */
    virtual int getDefense() const { return defense; }
    
    /**
     * @brief Check if entity is alive
     * @return true if health is greater than 0
     */
    virtual bool isAlive() const { return health > 0; }
    
    /**
     * @brief Update entity effects
     * @details Virtual method that can be overridden in derived classes
     */
    virtual void updateEffect() {}
    
    /**
     * @brief Reduce mana
     * @param amount Amount of mana to reduce
     */
    virtual void reduceMana(int amount);
    
    /**
     * @brief Set mana
     * @param newMana New mana value
     */
    virtual void setMana(int newMana) {
        mana = std::max(0, std::min(newMana, MAX_MANA));
    }
    
    /**
     * @brief Increase mana
     * @param amount Amount of mana to increase
     */
    virtual void increaseMana(int amount) {
        mana = std::min(mana + amount, MAX_MANA);
    }
    
    /**
     * @brief Restore health
     * @param amount Amount of health to restore
     */
    virtual void restoreHealth(int amount);
};

#endif
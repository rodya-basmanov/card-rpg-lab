/**
 * @file Character.h
 * @brief Definition of the base Character class
 * @details This class represents game characters that can use abilities,
 *          have inventory, card deck and can be controlled by AI
 */
#pragma once
#include "Entity.h"
#include "Ability.h"
#include "Deck.h"
#include "Inventory.h"
#include "AI.h"
#include <memory>
#include <vector>
#include <iostream>
#include <iterator>
#include <cmath>

// Forward declarations
class Ability;
class AI;
class Character;

/**
 * @class Character
 * @brief Base class for all game characters
 * @details Character extends the Entity class and adds functionality
 *          specific to game characters
 */
class Character : public Entity {
private:
    /** @brief Character level */
    int level = 1;
    
    /** @brief Character experience */
    int experience = 0;
    
    /** @brief Kill count */
    int kills = 0;
    
    /** @brief Base experience per level */
    static constexpr int BASE_EXP_PER_LEVEL = 100;
    
    /** @brief Experience growth rate per level */
    static constexpr float EXP_GROWTH_RATE = 1.5f;

    /** @brief Character inventory */
    std::shared_ptr<Inventory> inventory;

public:
    /**
     * @brief Get active effects list
     * @return Constant reference to active effects vector
     */
    const std::vector<ActiveEffect>& getActiveEffects() const { return activeEffects; }

    /**
     * @brief Converts effect type to string representation
     * @param type Effect type
     * @return String representation of the effect
     */
    static std::string toString(EffectType type) {
        switch (type) {
            case EffectType::SLOW: return "Slow";
            case EffectType::BURN: return "Burn";
            case EffectType::POISON: return "Poison";
            case EffectType::REGENERATION: return "Regeneration";
            default: return "None";
        }
    }

    /**
     * @brief Get character's inventory
     * @return Pointer to inventory
     */
    std::shared_ptr<Inventory> getInventory() const { return inventory; }
    
    /**
     * @brief Set character's inventory
     * @param inv New inventory
     */
    void setInventory(std::shared_ptr<Inventory> inv) { inventory = inv; }

    /**
     * @brief Get effect duration of specified type
     * @param type Effect type
     * @return Duration of the effect in turns or 0 if effect is absent
     */
    int getEffectDuration(EffectType type) const {
        for (const auto& effect : activeEffects) {
            if (effect.type == type) {
                return effect.duration;
            }
        }
        return 0;
    }

    /**
     * @brief Gain experience
     * @param exp Amount of experience to gain
     */
    void gainExp(int exp) {
        experience += exp;
        checkLevelUp();
    }

    /**
     * @brief Increment kill counter
     */
    void incrementKills() {
        kills++;
    }

    /**
     * @brief Get current character level
     * @return Current level
     */
    int getLevel() const { return level; }
    
    /**
     * @brief Get current experience 
     * @return Current experience
     */
    int getExperience() const { return experience; }
    
    /**
     * @brief Get kill count
     * @return Number of kills
     */
    int getKills() const { return kills; }

    /**
     * @brief Calculate required experience for next level
     * @return Required experience amount
     */
    int getRequiredExp() const {
        return static_cast<int>(BASE_EXP_PER_LEVEL * std::pow(level, EXP_GROWTH_RATE));
    }

protected:
    /** @brief Attack power */
    int attackPower;
    
    /** @brief Defense value */
    int defense;
    
    /** @brief Character's deck */
    std::shared_ptr<Deck> deck;
    
    /** @brief AI controlling the character */
    std::shared_ptr<AI> ai;
    
    /** @brief Character's target */
    std::shared_ptr<Entity> target;

    /** @brief Active effects on the character */
    std::vector<ActiveEffect> activeEffects;

public:
    /**
     * @brief Character constructor
     * @param name Character name
     * @param health Initial health
     * @param mana Initial mana
     * @param attackPower Attack power
     * @param defense Defense value
     */
    Character(const std::string& name, int health, int mana, int attackPower, int defense);
    
    /**
     * @brief Virtual destructor
     */
    virtual ~Character() = default;

    /**
     * @brief Attack target
     * @param target Attack target
     */
    virtual void attack(Entity& target) = 0;
    
    /**
     * @brief Use ability
     * @param ability The ability to use
     * @param target The target
     */
    virtual void useAbility(Ability& ability, Entity& target) = 0;

    /**
     * @brief Apply effect to character
     * @param type Effect type
     * @param speedMod Speed modifier
     * @param duration Duration
     * @param damage Damage per turn
     * @param heal Healing per turn
     */
    void applyEffect(EffectType type, float speedMod, int duration, int damage = 0, int heal = 0);
    
    /**
     * @brief Update all effects
     */
    void updateEffect() override;
    
    /**
     * @brief Get current speed modifier
     * @return Current speed modifier value
     */
    float getCurrentSpeedModifier() const;

    /**
     * @brief Get attack power
     * @return Attack power value
     */
    int getAttackPower() const { return attackPower; }
    
    /**
     * @brief Get defense value
     * @return Defense value
     */
    int getDefense() const { return defense; }
    
    /**
     * @brief Set attack power
     * @param power New attack power value
     */
    void setAttackPower(int power) { attackPower = power; }
    
    /**
     * @brief Set defense
     * @param def New defense value
     */
    void setDefense(int def) { defense = def; }

    /**
     * @brief Get character's deck
     * @return Pointer to deck
     */
    virtual std::shared_ptr<Deck> getDeck() const = 0;
    
    /**
     * @brief Set deck
     * @param d New deck
     */
    void setDeck(std::shared_ptr<Deck> d) { deck = d; }
    
    /**
     * @brief Check if character is alive
     * @return true if character is alive
     */
    bool isAlive() const override { return getHealth() > 0; }
    
    /**
     * @brief Set AI
     * @param a New AI
     */
    void setAI(std::shared_ptr<AI> a) { ai = a; }
    
    /**
     * @brief Get character's AI
     * @return Pointer to AI
     */
    std::shared_ptr<AI> getAI() const { return ai; }
    
    /**
     * @brief Set target
     * @param t New target
     */
    void setTarget(std::shared_ptr<Entity> t) { target = t; }
    
    /**
     * @brief Get character's target
     * @return Pointer to target
     */
    std::shared_ptr<Entity> getTarget() const { return target; }
    
    /**
     * @brief Perform AI action
     */
    virtual void performAIAction() = 0;
    
    /**
     * @brief Restore health
     * @param amount Amount of health to restore
     */
    virtual void restoreHealth(int amount) override {
        Entity::restoreHealth(amount);
    }

private:
    /**
     * @brief Check for level up
     */
    void checkLevelUp() {
        while (experience >= getRequiredExp()) {
            levelUp();
            experience = 0;
        }
    }
    
    /**
     * @brief Level up character
     */
    void levelUp() {
        level++;
        attackPower += 2;
        defense += 1;
        heal(MAX_HEALTH * 0.25);

        std::cout << "\n=== LEVEL UP! ===\n"
                  << "New level: " << level << "\n"
                  << "Attack: +2 (" << attackPower << ")\n"
                  << "Defense: +1 (" << defense << ")\n"
                  << "==================\n\n";
    }
};
/**
 * @file BattleMode.h
 * @brief Definition of the BattleMode game mode
 * @details This file defines the BattleMode class, which implements
 *          combat between two characters in the game
 */
#pragma once
#include "GameMode.h"
#include "Character.h"

/**
 * @class BattleMode
 * @brief Manages combat between two characters
 * @details Handles turn-based combat mechanics, player actions,
 *          and determines the outcome of battles
 */
class BattleMode : public GameMode {
private:
    /** @brief Player character involved in battle */
    std::shared_ptr<Character> player;
    
    /** @brief Enemy character involved in battle */
    std::shared_ptr<Character> enemy;

public:
    /**
     * @enum BattleAction
     * @brief Possible actions during battle
     */
    enum class BattleAction {
        ATTACK,  /**< Basic attack action */
        ABILITY, /**< Use a special ability */
        DEFEND,  /**< Defensive stance */
        ITEM     /**< Use an item */
    };

    /**
     * @brief Constructor for BattleMode
     * @param p Player character
     * @param e Enemy character
     */
    BattleMode(std::shared_ptr<Character> p, std::shared_ptr<Character> e);
    
    /**
     * @brief Start the battle
     * @details Initializes the battle and displays starting information
     */
    void start() override;
    
    /**
     * @brief Update battle state
     * @details Processes a single turn of combat including both player and enemy actions
     */
    void update() override;
    
    /**
     * @brief Check if battle is finished
     * @return True if either the player or enemy is defeated
     */
    bool isFinished() const override {
        return !player->isAlive() || !enemy->isAlive();
    }
    
    /**
     * @brief Get the enemy character
     * @return Shared pointer to the enemy character
     */
    std::shared_ptr<Character> getEnemy() const {
        return enemy;
    }

private:
    /**
     * @brief Get the player's chosen action
     * @return The action selected by the player
     */
    BattleAction getPlayerChoice() const;
    
    /**
     * @brief Let the player select an ability
     * @param character The character selecting an ability
     * @return The selected ability
     */
    std::shared_ptr<Ability> selectAbility(const Character& character) const;
    
    /**
     * @brief Use an item from the character's inventory
     * @param character The character using an item
     */
    void useItemFromInventory(Character& character);
    
    /**
     * @brief Select a card with an ability effect
     * @param character The character selecting a card
     * @return The selected card
     */
    std::shared_ptr<Card> selectAbilityCard(Character& character);
};
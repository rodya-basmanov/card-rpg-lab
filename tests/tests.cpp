/**
 * @file tests.cpp
 * @brief Comprehensive test suite for the card-rpg-lab project
 * @details Contains unit tests for all major components of the game:
 *          - Basic entity and character mechanics
 *          - Character class specializations (Warrior, Mage, Archer, Healer)
 *          - Card system and card effects
 *          - AI decision making
 *          - Game modes and battle systems
 *          - Inventory and item management
 */

#include <gtest/gtest.h>
#include <memory>
#include "Entity.h"
#include "Character.h"
#include "Warrior.h"
#include "Mage.h"
#include "Archer.h"
#include "Healer.h"
#include "Fireball.h"
#include "IceSpike.h"
#include "AttackCard.h"
#include "DefenseCard.h"
#include "SpellCard.h"
#include "TrapCard.h"
#include "SpecialCard.h"
#include "Poison.h"
#include "Regeneration.h"
#include "Shield.h"
#include "BurningEffect.h"
#include "PvPMode.h"
#include "BattleMode.h"
#include "BossAI.h"
#include "AdvancedAI.h"
#include "Deck.h"
#include "DungeonMode.h"
#include "ExplorationMode.h"
#include "TradingMode.h"
#include "LightningCard.h"
#include "Armor.h"
#include "Weapon.h"
#include "Inventory.h"
#include "HealthPotion.h"
#include "UI.h"
#include "GameManager.h"

/**
 * @brief Tests the basic health and mana management of the Entity class
 * @details Verifies that entities correctly:
 *          - Take damage and reduce health
 *          - Heal and increase health
 *          - Handle mana reduction with lower bounds protection
 */
TEST(EntityTest, HealthAndManaManagement) {
    Entity entity("Test", 50, 50);
    
    entity.takeDamage(20);
    EXPECT_EQ(entity.getHealth(), 30);
    
    entity.heal(40);
    EXPECT_EQ(entity.getHealth(), 70);
    
    entity.reduceMana(60);
    EXPECT_EQ(entity.getMana(), 0);
}

/**
 * @brief Tests proper initialization of Character objects
 * @details Ensures that characters are correctly created with the specified attributes:
 *          - Name
 *          - Health points
 *          - Mana points
 *          - Attack power
 *          - Defense value
 */
TEST(CharacterTest, Initialization) {
    Warrior warrior("Warrior", 100, 50, 20, 5);
    EXPECT_EQ(warrior.getName(), "Warrior");
    EXPECT_EQ(warrior.getHealth(), 100);
    EXPECT_EQ(warrior.getMana(), 50);
    EXPECT_EQ(warrior.getAttackPower(), 20);
    EXPECT_EQ(warrior.getDefense(), 5);
}

/**
 * @brief Tests the attack mechanics of the Warrior class
 * @details Verifies that Warriors correctly:
 *          - Calculate and apply damage based on attack power
 *          - Reduce target health through attack method
 */
TEST(WarriorTest, AttackMechanics) {
    Warrior warrior("Warrior", 100, 50, 20, 5);
    Warrior enemy("Enemy", 100, 50, 20, 5);
    warrior.attack(enemy);
    EXPECT_EQ(enemy.getHealth(), 85);
}

/**
 * @brief Tests the Mage's specialized attack with Fireball
 * @details Ensures that the Mage:
 *          - Deals the expected damage with specialty attack
 *          - Consumes the correct amount of mana
 */
TEST(MageTest, FireballAttack) {
    Mage mage("Mage", 100, 50, 15, 5);
    Warrior enemy("Enemy", 100, 50, 20, 5);
    mage.attack(enemy);
    EXPECT_EQ(enemy.getHealth(), 75);
    EXPECT_EQ(mage.getMana(), 30);
}

/**
 * @brief Tests the activation of the Fireball card
 * @details Verifies that the Fireball card correctly applies damage to its target
 */
TEST(FireballTest, Activation) {
    Warrior target("Target", 100, 50, 20, 5);
    Fireball fireball;
    fireball.play(target);
    EXPECT_EQ(target.getHealth(), 75);
}

/**
 * @brief Tests the Archer's basic attack mechanics
 * @details Verifies that Archers correctly apply damage with their standard attacks
 */
TEST(ArcherTest, AttackMechanics) {
    Archer archer("Archer", 100, 50, 15, 5);
    Entity enemy("Enemy", 100, 50);
    archer.attack(enemy);
    EXPECT_EQ(enemy.getHealth(), 85);
}

/**
 * @brief Tests the IceSpike ability when used by an Archer
 * @details Ensures that the IceSpike card:
 *          - Correctly applies speed reduction effect to the target
 *          - Reduces the target's speed by the expected amount (30%)
 */
TEST(ArcherTest, IceSpikeAbility) {
    Archer archer("Archer", 100, 50, 15, 5);
    Warrior enemy("Enemy", 100, 50, 10, 5);

    IceSpike iceSpike;

    iceSpike.play(enemy);

    EXPECT_EQ(enemy.getCurrentSpeedModifier(), 0.7f);
}

/**
 * @brief Tests the damage mechanics of the AttackCard
 * @details Verifies that AttackCard correctly:
 *          - Applies damage to the target entity
 *          - Deals the expected amount of damage (15 points)
 */
TEST(AttackCardTest, DamageMechanics) {
    Entity enemy("Enemy", 100, 50);
    AttackCard attackCard;
    attackCard.play(enemy);
    EXPECT_EQ(enemy.getHealth(), 85);
}

/**
 * @brief Tests the shield mechanics of the DefenseCard
 * @details Ensures that DefenseCard properly applies defensive effects to entities
 */
TEST(DefenseCardTest, ShieldMechanics) {
    Entity enemy("Enemy", 100, 50);
    DefenseCard defenseCard;
    defenseCard.play(enemy);
    EXPECT_EQ(enemy.getDefense(), 20);
}

TEST(TrapCardTest, DamageMechanics) {
    Entity enemy("Enemy", 100, 50);
    TrapCard trapCard;
    trapCard.play(enemy);
    EXPECT_EQ(enemy.getHealth(), 90);
}

TEST(SpellCardTest, MagicalEffect) {
    Warrior target("Target", 100, 50, 10, 5);
    SpellCard spellCard;
    spellCard.play(target);
    EXPECT_EQ(target.getEffectDuration(EffectType::SLOW), 3);
}

TEST(SpecialCardTest, ManaRestore) {
    Warrior target("Target", 100, 50, 10, 5);
    SpecialCard specialCard;
    specialCard.play(target);
    EXPECT_EQ(target.getMana(), 80);
}

TEST(IceSpikeTest, Activation) {
    Warrior target("Target", 100, 50, 10, 5);
    IceSpike iceSpike;
    iceSpike.play(target);
    EXPECT_EQ(target.getCurrentSpeedModifier(), 0.7f);
}

/**
 * @brief Tests IceSpike's slowing effect duration
 */
TEST(IceSpikeTest, SlowEffectDuration) {
    Warrior target("Target", 100, 50, 10, 5);
    IceSpike iceSpike;
    
    iceSpike.play(target);
    
    // Check initial slow effect
    EXPECT_EQ(target.getCurrentSpeedModifier(), 0.7f);
    
    // Duration should be set (typically 3 turns)
    EXPECT_GT(target.getEffectDuration(EffectType::SLOW), 0);
    
    // After updateEffect calls, duration should decrease
    target.updateEffect();
    int newDuration = target.getEffectDuration(EffectType::SLOW);
    EXPECT_LT(newDuration, 3);
}

/**
 * @brief Tests IceSpike's mana cost
 */
TEST(IceSpikeTest, ManaCost) {
    IceSpike iceSpike;
    EXPECT_EQ(iceSpike.getManaCost(), 15);
}

TEST(BurningEffectTest, DamageOverTime) {
    Warrior target("Target", 100, 50, 10, 5);
    BurningEffect burningEffect;
    burningEffect.play(target);
    target.updateEffect();
    EXPECT_EQ(target.getHealth(), 95);
    target.updateEffect();
    EXPECT_EQ(target.getHealth(), 90);
    target.updateEffect();
    EXPECT_EQ(target.getHealth(), 85);
}
TEST(ShieldTest, BlockDamage) {
    Warrior target("Target", 100, 50, 10, 5);
    Shield shield;
    shield.play(target);
    EXPECT_EQ(target.getDefense(), 15);
}

TEST(RegenerationTest, HealOverTime) {
    Warrior target("Target", 50, 50, 10, 5);
    Regeneration regen;
    regen.play(target);
    target.updateEffect();
    EXPECT_EQ(target.getHealth(), 60);
}

TEST(PoisonTest, DamageOverTime) {
    Warrior target("Target", 100, 50, 10, 5);
    Poison poison;
    poison.play(target);
    target.updateEffect();
    EXPECT_EQ(target.getHealth(), 95);
}
TEST(WeaponTest, ApplyWeapon) {
    Warrior warrior("Hero", 100, 50, 20, 5);
    Weapon sword("Sword", "Increases attack power by 10", 10);
    sword.apply(warrior);
    EXPECT_EQ(warrior.getAttackPower(), 30);
}

TEST(ArmorTest, ApplyArmor) {
    Warrior warrior("Hero", 100, 50, 20, 5);
    Armor shield("Shield", "Increases defense by 15", 15);
    shield.apply(warrior);
    EXPECT_EQ(warrior.getDefense(), 20);
}

TEST(InventoryTest, AddAndUseItem) {
    Inventory inventory;
    Weapon sword("Sword", "Increases attack power by 10", 10);
    Warrior warrior("Hero", 100, 50, 20, 5);

    inventory.addItem(&sword);
    inventory.useItem(&sword, warrior);
    EXPECT_EQ(warrior.getAttackPower(), 30);
}

TEST(AdvancedAITest, DefenseStrategy) {
    auto aiChar = std::make_shared<Warrior>("AI", 50, 50, 10, 5);
    auto target = std::make_shared<Warrior>("Target", 100, 50, 20, 5);
    auto deck = std::make_shared<Deck>();
    deck->addCard(std::make_shared<DefenseCard>());
    
    AdvancedAI ai(aiChar, target, deck);
    ai.makeDecision(*aiChar, *target);
    
    EXPECT_GT(aiChar->getDefense(), 5);
}

TEST(LightningCardTest, RandomDamageRange) {
    LightningCard card;
    Entity target("Target", 100, 0);
    
    card.play(target);
    int damage = 100 - target.getHealth();
    EXPECT_TRUE(damage >= 10 && damage <= 30);
}
TEST(ExplorationModeTest, EventGeneration) {
    auto player = std::make_shared<Warrior>("Hero", 100, 0, 20, 10);
    ExplorationMode exploration(player);

    // Устанавливаем фиксированное семя для воспроизводимости результатов теста
    std::srand(12345);
    
    // Сохраняем текущий буфер cin
    std::streambuf* oldCin = std::cin.rdbuf();
    
    try {
        // Подготовим входные данные для всех возможных взаимодействий
        std::stringstream input;
        // Для BattleMode (если выпадет событие с боем)
        input << "1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n"; // Достаточно ввода "1" для нескольких ходов
        std::cin.rdbuf(input.rdbuf());
        
        testing::internal::CaptureStdout();
        exploration.generateRandomEvent();
        std::string output = testing::internal::GetCapturedStdout();
        
        // Проверяем, что вывод содержит ожидаемые строки
        EXPECT_TRUE(output.find("found") != std::string::npos || 
                   output.find("attacks") != std::string::npos);
                   
        // Проверяем, что тест не создал бесконечного цикла
        EXPECT_TRUE(output.size() < 10000); // Разумное ограничение на размер вывода
    }
    catch (...) {
        // Восстанавливаем стандартный ввод независимо от результата
        std::cin.rdbuf(oldCin);
        throw; // Перебрасываем исключение
    }
    
    // Восстанавливаем стандартный ввод
    std::cin.rdbuf(oldCin);
}
TEST(DeckTest, CardManagement) {
    Deck deck;
    auto card = std::make_shared<AttackCard>();
    
    deck.addCard(card);
    EXPECT_EQ(deck.size(), 1);
    
    auto drawn = deck.drawCard();
    EXPECT_EQ(deck.size(), 0);
    EXPECT_NE(drawn, nullptr);
}
TEST(EffectTest, FullEffectCycle) {
    Warrior target("Target", 100, 50, 10, 5);
    Poison poison;
    poison.play(target);
    
    for(int i = 0; i < 5; i++) target.updateEffect();
    
    EXPECT_EQ(target.getHealth(), 75);
    EXPECT_EQ(target.getEffectDuration(EffectType::POISON), 0);
}

/**
 * @brief Tests inventory item management functionality
 * @details Verifies that the inventory system:
 *          - Correctly adds items to inventory
 *          - Properly tracks the number of items
 *          - Maintains references to items of different types (Weapon, Armor)
 */
TEST(InventoryTest, ItemManagement) {
    Inventory inv;
    Weapon sword("Sword", "Sharp blade", 10);
    Armor plate("Plate", "Heavy armor", 15);
    
    inv.addItem(&sword);
    inv.addItem(&plate);
    
    EXPECT_EQ(inv.getItems().size(), 2);
}

/**
 * @brief Tests stacking of multiple effects on a character
 * @details Ensures that:
 *          - Multiple different effects can be applied to a character simultaneously
 *          - Each effect applies its specific modifications (damage from burning, speed reduction from ice)
 *          - Effects are properly tracked and applied during updates
 */
TEST(CharacterTest, EffectStacking) {
    Warrior warrior("Warrior", 100, 0, 10, 5);
    IceSpike ice;
    BurningEffect fire;
    
    ice.play(warrior);
    fire.play(warrior);
    
    warrior.updateEffect();
    EXPECT_EQ(warrior.getHealth(), 95);
    EXPECT_FLOAT_EQ(warrior.getCurrentSpeedModifier(), 0.7f);
}
TEST(EdgeCasesTest, HealthBoundaries) {
    Entity entity("Test", 10, 0);
    entity.takeDamage(150);
    EXPECT_EQ(entity.getHealth(), 0);
    
    entity.heal(200);
    EXPECT_EQ(entity.getHealth(), Entity::MAX_HEALTH);
}

TEST(EdgeCasesTest, ManaOverflow) {
    Entity entity("Test", 100, 90);
    entity.reduceMana(-20);
    EXPECT_EQ(entity.getMana(), Entity::MAX_MANA);
}
TEST(CharacterTest, LevelingSystem) {
    Warrior warrior("Warrior", 100, 50, 20, 5);
    warrior.gainExp(120);
    EXPECT_EQ(warrior.getLevel(), 2);
    EXPECT_EQ(warrior.getAttackPower(), 22);
    EXPECT_EQ(warrior.getDefense(), 6);
}
TEST(EntityTest, HealthBoundaries) {
    Entity entity("Test", 250, 50);
    EXPECT_EQ(entity.getHealth(), Entity::MAX_HEALTH);

    entity.takeDamage(250);
    EXPECT_EQ(entity.getHealth(), 0);

    entity.heal(300);
    EXPECT_EQ(entity.getHealth(), Entity::MAX_HEALTH);
}

TEST(EntityTest, DefenseBoundaries) {
    Entity entity("Test", 100, 50, -10);
    EXPECT_EQ(entity.getDefense(), 0);

    entity.setDefense(-5);
    EXPECT_EQ(entity.getDefense(), 0);
}

TEST(BossAITest, FireballFallback) {
    auto boss = std::make_shared<Mage>("Boss", 100, 0, 20, 10);
    auto player = std::make_shared<Warrior>("Player", 100, 0, 15, 5);
    auto deck = std::make_shared<Deck>();
    
    BossAI ai(boss, player, deck);
    ai.makeDecision(*boss, *player);
    
    EXPECT_LT(player->getHealth(), 100);
}
TEST(HealerTest, HealAlliesMechanics) {
    Healer healer("Priest", 100, 100, 10, 5);
    Warrior ally("Warrior", 50, 0, 20, 5);
    
    healer.healAllies(ally);
    EXPECT_EQ(ally.getHealth(), 70);
}

/**
 * @brief Tests the use of special mana restoration cards by Healer
 * @details Verifies that:
 *          - SpecialCard correctly restores mana to the target
 *          - The amount of mana restored matches expectations (30 points)
 */
TEST(HealerTest, SpecialCardUsage) {
    Healer healer("Priest", 100, 100, 10, 5);
    Entity target("Target", 50, 50);
    SpecialCard card;
    
    card.play(target);
    EXPECT_EQ(target.getMana(), 80);
}

/**
 * @brief Tests error handling when removing non-existent items from inventory
 * @details Ensures that:
 *          - System properly handles attempts to remove items not in inventory
 *          - Appropriate error message is displayed
 *          - No crashes or unexpected behavior occur
 */
TEST(InventoryTest, RemoveNonexistentItem) {
    Inventory inv;
    Weapon sword("Sword", "Desc", 10);
    
    testing::internal::CaptureStdout();
    inv.removeItem(&sword);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_TRUE(output.find("not found") != std::string::npos);
}

/**
 * @brief Tests protection against healing beyond maximum health
 * @details Verifies that:
 *          - Health potions won't heal beyond the maximum health limit
 *          - Entity health is capped at MAX_HEALTH when applying healing
 *          - Overhealing is properly prevented
 */
TEST(HealthPotionTest, OverhealProtection) {
    HealthPotion potion;
    Warrior warrior("Warrior", Entity::MAX_HEALTH - 10, 0, 10, 5);
    
    potion.apply(warrior);
    EXPECT_EQ(warrior.getHealth(), Entity::MAX_HEALTH);
}

/**
 * @brief Tests boss enemy generation in Dungeon Mode
 * @details Verifies that:
 *          - Boss enemies are successfully generated
 *          - The returned boss reference is valid (not null)
 *          - Dungeon mode correctly initializes boss encounters
 */
TEST(DungeonModeTest, BossSpawn) {
    auto player = std::make_shared<Warrior>("Hero", 200, 0, 30, 15);
    DungeonMode dungeon(player);
    
    dungeon.generateBoss();
    EXPECT_NE(dungeon.getBoss(), nullptr);
}

/**
 * @brief Tests stacking of multiple speed modifiers from effects
 * @details Ensures that:
 *          - Multiple speed modifiers correctly stack multiplicatively
 *          - Each effect's modifier is properly applied
 *          - The combined effect produces the expected final speed modifier
 */
TEST(EffectTest, SpeedModifierStacking) {
    Warrior target("Target", 100, 0, 10, 5);
    IceSpike ice;
    SpellCard spell;
    
    ice.play(target);
    spell.play(target);
    
    EXPECT_FLOAT_EQ(target.getCurrentSpeedModifier(), 0.7f * 0.7f);
}

/**
 * @brief Tests protection against damage effects reducing health below zero
 * @details Verifies that:
 *          - Damage over time effects won't reduce health below zero
 *          - Entity health is properly capped at the minimum value of 0
 */
TEST(EffectTest, DamageOverflowProtection) {
    Warrior target("Target", 5, 0, 10, 0);
    Poison poison;
    
    poison.play(target);
    target.updateEffect();
    
    EXPECT_EQ(target.getHealth(), 0);
}

/**
 * @brief Tests player inventory initialization by GameManager
 * @details Verifies that:
 *          - Player characters are initialized with default items
 *          - The inventory contains the expected number of starting items
 */
TEST(GameManagerTest, InventoryInitialization) {
    auto player = std::make_shared<Warrior>("Hero", 100, 0, 20, 10);
    GameManager gm(player);
    
    EXPECT_EQ(player->getInventory()->getItems().size(), 2);
}

/**
 * @brief Tests battle log size limiting functionality
 * @details Ensures that:
 *          - The battle log properly limits its size to avoid excessive memory usage
 *          - Older messages are removed when the log exceeds its maximum size
 *          - The log maintains only the most recent messages
 */
TEST(UITest, BattleLogLimiting) {
    UI::battleLog.clear();
    for (int i = 0; i < 10; i++) {
        UI::addToLog("Message " + std::to_string(i));
    }
    EXPECT_EQ(UI::battleLog.size(), 5);
}
TEST(EffectTest, CombinedEffects) {
    Warrior target("Warrior", 100, 50, 20, 5);
    Fireball fireball;
    IceSpike iceSpike;
    
    fireball.play(target);
    iceSpike.play(target);
    
    EXPECT_EQ(target.getHealth(), 75);
    EXPECT_GT(target.getEffectDuration(EffectType::BURN), 0);
    EXPECT_FLOAT_EQ(target.getCurrentSpeedModifier(), 0.7f);
}
TEST(DeckTest, EmptyDeckHandling) {
    Deck deck;
    auto card = deck.drawCard();
    
    EXPECT_EQ(card, nullptr);
    EXPECT_TRUE(deck.getCards().empty());
}

/**
 * @brief Tests the archer's initialization with correct attributes
 */
TEST(ArcherTest, Initialization) {
    Archer archer("Ranger", 90, 60, 18, 4);
    
    EXPECT_EQ(archer.getName(), "Ranger");
    EXPECT_EQ(archer.getHealth(), 90);
    EXPECT_EQ(archer.getMana(), 60);
    EXPECT_EQ(archer.getAttackPower(), 18);
    EXPECT_EQ(archer.getDefense(), 4);
}

/**
 * @brief Tests the healer's basic attack mechanics
 */
TEST(HealerTest, AttackMechanics) {
    Healer healer("Healer", 100, 100, 10, 5);
    Entity enemy("Enemy", 100, 0);
    
    healer.attack(enemy);
    
    // Healer's attack should be weaker than other classes
    EXPECT_GT(enemy.getHealth(), 85);
}

// Create a simple derived class for testing Card base class
class TestCard : public Card {
public:
    TestCard() : Card("Test Card", "A card for testing") {}
    void play(Entity& target) override {
        target.heal(10);
    }
    int getManaCost() const override { return 5; }
};

/**
 * @brief Tests the basic functionality of the Card base class
 */
TEST(CardTest, BasicFunctionality) {
    TestCard testCard;
    
    // Test basic properties
    EXPECT_EQ(testCard.getName(), "Test Card");
    EXPECT_EQ(testCard.getDescription(), "A card for testing");
    EXPECT_EQ(testCard.getManaCost(), 5);
    
    // Test card effect
    Entity target("Target", 50, 0);
    testCard.play(target);
    EXPECT_EQ(target.getHealth(), 60);
}
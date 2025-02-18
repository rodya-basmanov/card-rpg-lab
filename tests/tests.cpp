#include <gtest/gtest.h>
#include "Entity.h"
#include "Character.h"
#include "Mage.h"
#include "Warrior.h"
#include "Fireball.h"

TEST(EntityTest, HealthAndManaManagement) {
    Entity hero("Hero", 100, 50);

    EXPECT_EQ(hero.getHealth(), 100);
    EXPECT_EQ(hero.getMana(), 50);

    hero.takeDamage(30);
    EXPECT_EQ(hero.getHealth(), 70);

    hero.heal(20);
    EXPECT_EQ(hero.getHealth(), 90);

    hero.reduceMana(40);
    EXPECT_EQ(hero.getMana(), 10);

    hero.heal(50);
    EXPECT_EQ(hero.getHealth(), 100);

    hero.reduceMana(20); 
    EXPECT_EQ(hero.getMana(), 0);
}

TEST(CharacterTest, Initialization) {
    Warrior warrior("Warrior", 100, 50, 20, 5);

    EXPECT_EQ(warrior.getName(), "Warrior");
    EXPECT_EQ(warrior.getHealth(), 100);
    EXPECT_EQ(warrior.getMana(), 50);
    EXPECT_EQ(warrior.getAttackPower(), 20);
    EXPECT_EQ(warrior.getDefense(), 5);
}

TEST(WarriorTest, AttackMechanics) {
    Warrior warrior("Warrior", 100, 50, 20, 5);
    Warrior enemy("Enemy", 100, 50, 20, 5);

    warrior.attack(enemy);
    EXPECT_EQ(enemy.getHealth(), 85);
}

TEST(MageTest, FireballAttack) {
    Mage mage("Mage", 100, 50, 15, 5);
    Warrior enemy("Enemy", 100, 50, 20, 5);

    mage.attack(enemy);
    EXPECT_EQ(enemy.getHealth(), 75);
    EXPECT_EQ(mage.getMana(), 30);
}

TEST(MageTest, ManaManagement) {
    Mage mage("Mage", 100, 10, 15, 5);
    Entity enemy("Enemy", 100, 50);

    mage.attack(enemy);
    EXPECT_EQ(enemy.getHealth(), 100);
    EXPECT_EQ(mage.getMana(), 10);
}

TEST(FireballTest, Activation) {
    Warrior target("Target", 100, 50, 20, 5);
    Fireball fireball;

    fireball.activate(target);
    EXPECT_EQ(target.getHealth(), 75);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
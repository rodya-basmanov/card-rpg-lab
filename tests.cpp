#include <gtest/gtest.h>
#include "Entity.h"

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

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
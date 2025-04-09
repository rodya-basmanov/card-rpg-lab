cmake_minimum_required(VERSION 3.10)

project(CardRPG)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(card-rpg-lab
    src/main.cpp
    src/Entity.cpp
    src/Character.cpp
    src/Warrior.cpp
    src/Mage.cpp
    src/Fireball.cpp
    src/Archer.cpp
    src/Healer.cpp
    src/IceSpike.cpp
    src/AttackCard.cpp
    src/DefenseCard.cpp
    src/SpellCard.cpp
    src/TrapCard.cpp
    src/SpecialCard.cpp
    src/BurningEffect.cpp
    src/Poison.cpp
    src/Regeneration.cpp
    src/Shield.cpp
    src/BattleMode.cpp
    src/BossAI.cpp
    src/AdvancedAI.cpp
    src/Deck.cpp
    src/DungeonMode.cpp
    src/ExplorationMode.cpp
    src/TradingMode.cpp
    src/LightningCard.cpp
    src/Armor.cpp
    src/Weapon.cpp
    src/Inventory.cpp
    src/GameManager.cpp
    src/EasyAI.cpp
    src/GameMode.cpp
    src/Item.cpp
    src/PvPMode.cpp
    src/UI.cpp
)

target_include_directories(card-rpg-lab PUBLIC include)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_library(card-rpg-core STATIC
    src/Entity.cpp
    src/Character.cpp
    src/Warrior.cpp
    src/Mage.cpp
    src/Fireball.cpp
    src/Archer.cpp
    src/Healer.cpp
    src/IceSpike.cpp
    src/AttackCard.cpp
    src/DefenseCard.cpp
    src/SpellCard.cpp
    src/TrapCard.cpp
    src/SpecialCard.cpp
    src/BurningEffect.cpp
    src/Poison.cpp
    src/Regeneration.cpp
    src/Shield.cpp
    src/BattleMode.cpp
    src/BossAI.cpp
    src/AdvancedAI.cpp
    src/Deck.cpp
    src/DungeonMode.cpp
    src/ExplorationMode.cpp
    src/TradingMode.cpp
    src/LightningCard.cpp
    src/Armor.cpp
    src/Weapon.cpp
    src/Inventory.cpp
    src/GameManager.cpp
    src/EasyAI.cpp
    src/GameMode.cpp
    src/Item.cpp
    src/PvPMode.cpp
    src/UI.cpp
)

target_include_directories(card-rpg-core PUBLIC include)

# Main tests executable
add_executable(tests
    tests/tests.cpp
)

target_compile_definitions(tests PRIVATE TESTING)

target_link_libraries(tests
    card-rpg-core
    GTest::GTest
    GTest::Main
    pthread
)

add_custom_target(cleanall
    COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_SOURCE_DIR} ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}
    COMMENT "Removing and recreating build directory"
)
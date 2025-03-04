cmake_minimum_required(VERSION 3.10)

project(CardRPG)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(card-rpg-lab
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
)

target_include_directories(card-rpg-lab PUBLIC include)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(tests
    tests/tests.cpp
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
)

target_include_directories(tests PUBLIC include)

target_link_libraries(card-rpg-lab
    ${GTEST_BOTH_LIBRARIES}
    pthread
)

target_link_libraries(tests
    ${GTEST_BOTH_LIBRARIES}
    pthread
)

add_custom_target(cleanall
    COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_SOURCE_DIR} ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}
    COMMENT "Removing and recreating build directory"
)
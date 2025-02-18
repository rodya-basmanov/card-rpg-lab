cmake_minimum_required(VERSION 3.10)

project(CardRPG)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(card-rpg-lab
    src/Entity.cpp
    tests/tests.cpp
)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

target_link_libraries(card-rpg-lab
    ${GTEST_BOTH_LIBRARIES}
    pthread
)
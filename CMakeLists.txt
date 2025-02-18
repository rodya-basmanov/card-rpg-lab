cmake_minimum_required(VERSION 3.10)

project(CardRPG)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(card-rpg-lab
    src/Entity.cpp
)

target_include_directories(card-rpg-lab PUBLIC include)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(tests
    tests/tests.cpp
    src/Entity.cpp
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
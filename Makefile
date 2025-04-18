CXX = g++
CXXFLAGS = -std=c++17 -Wall -Werror -Wpedantic -I/usr/include -pthread -I$(SRC_DIR)
LDFLAGS = -lgtest -lgtest_main -lpthread
GTEST_LIB_DIR = ~/googletest/googletest/build/lib
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build
TARGET = card-rpg-lab

SRCS = $(SRC_DIR)/Entity.cpp
TEST_SRC = $(TEST_DIR)/tests.cpp

OBJS = $(addprefix $(BUILD_DIR)/, $(notdir $(SRCS:.cpp=.o)))
TEST_OBJ = $(BUILD_DIR)/$(notdir $(TEST_SRC:.cpp=.o))

all: $(TARGET)

$(TARGET): $(OBJS) $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) $(OBJS) $(TEST_OBJ) -o $@ -L$(GTEST_LIB_DIR) $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -f $(OBJS) $(TEST_OBJ) $(TARGET)

cleanall: clean
	rm -rf $(BUILD_DIR)

.PHONY: all clean cleanall
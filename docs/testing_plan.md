# Testing Plan
- **Unit Tests**: Verify mechanics (attack, effects, inventory).
  Example:
  ```cpp
  TEST(CharacterTest, Leveling) {
    Warrior w("Test", 100, 0, 10, 5);
    w.gainExp(150);
    ASSERT_EQ(w.getLevel(), 2);
  }```
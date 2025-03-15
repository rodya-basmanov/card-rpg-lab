# 🎮 Card RPG Lab

<div align="center">

![Version](https://img.shields.io/badge/version-1.0.0-blue)
![C++](https://img.shields.io/badge/C%2B%2B-17-blue)
![License](https://img.shields.io/badge/license-MIT-green)
[![Tests](https://img.shields.io/badge/tests-passing-brightgreen)]()
[![Documentation](https://img.shields.io/badge/docs-Doxygen-orange)]()

**Developer**: Basmanov Rodion (Group B81-mm)  
**Contact**: st135699@student.spbu.ru
</div>

---

## 📖 Project Description

**Card RPG Lab** is a turn-based card role-playing game where players battle AI-controlled enemies using character abilities, effect cards, and items.

### ✨ Key Features

- **Diverse Character Classes**: Warrior, Mage, Archer, Healer with unique abilities and characteristics
- **Advanced Card System**: Attack, defense, special effect, and spell cards
- **Intelligent Opponents**: Multiple AI levels (Easy, Advanced, Boss) with different strategies
- **Status Effects**: Burning, Poison, Regeneration, Slow, and other time-based effects
- **Inventory System**: Items, weapons, armor, and consumables
- **Various Game Modes**: Battle, Dungeon, Exploration, Trading, PvP

---

## 🏗️ Architecture

The project has a modular architecture based on object-oriented programming, consisting of the following main components:

- [System Overview](docs/system_overview.md)
- [Requirements and Use Cases](docs/requirements_use_cases.md)
- [Component Diagram](docs/component_diagram.md)
- [Class Diagram](docs/class_diagram.md)
- [Testing Plan](docs/testing_plan.md)

### 📂 Project Structure

```
card-rpg-lab/
├── include/           # Header files (*.h)
├── src/               # Source code (*.cpp)
├── tests/             # Unit tests
├── docs/              # Project documentation
├── build/             # Build files
├── CMakeLists.txt     # Build configuration
├── Doxyfile           # Doxygen settings
├── Makefile           # Simplified build commands
└── README.md          # This file
```

---

## 🔧 Dependencies and Installation

### Requirements

- **C++17** compatible compiler (GCC, Clang, MSVC)
- **CMake** (version 3.10 or higher)
- **Google Test** (for unit tests)
- **Doxygen** (for documentation generation)

### Building the Project

```bash
# Clone the repository
git clone https://github.com/yourusername/card-rpg-lab.git
cd card-rpg-lab

# Build the project
mkdir -p build && cd build
cmake ..
make
```

---

## 🎮 Gameplay

### Starting the Game

```bash
# From the build directory
./card-rpg-lab
```

### Game Controls

#### Main Menu:
```
1 - Battle
2 - Trading
3 - Dungeon
4 - Exploration
5 - PvP
6 - Exit
```

#### Battle Actions:
```
1 - Attack
2 - Use Card
3 - Defend
4 - Open Inventory
```

---

## 🧪 Testing

The project has complete unit test coverage using the Google Test framework.

```bash
# Run tests
cd build
make test
./tests
```

## 📚 Documentation

The project code is fully documented using Doxygen.

```bash
# Generate documentation
doxygen Doxyfile
```

After running this command, you will find the generated documentation in the `docs/html` directory.

---

## 💻 Developer Guide

### Design Principles

The codebase follows these design principles:
- **Object-oriented architecture** with clear inheritance hierarchies
- **Clean separation of game mechanics** through abstractions
- **Complete unit test coverage**
- **Comprehensive Doxygen documentation**

### Adding a New Character Class

1. Create a new class inheriting from `Character`
2. Implement abstract methods:
   - `attack(Entity& target)`
   - `useAbility(Ability& ability, Entity& target)`
   - `performAIAction()`
   - `getDeck()`
3. Add unique abilities for this class
4. Update the character factory to create the new class
5. Add tests for the new class in `tests/tests.cpp`

### Adding a New Ability

1. Create a new class inheriting from `Ability`
2. Implement abstract methods:
   - `activate(Entity& source, Entity& target)`
   - `getManaCost()`
   - `applyEffect(Entity& target)`
3. Update relevant character classes to use the new ability
4. Add tests for the new ability

### Adding New Cards

1. Create a new class inheriting from the appropriate base card class (`AttackCard`, `DefenseCard`, `SpellCard`)
2. Override methods `play(Entity& target)` and `getManaCost()`
3. Add the card to character decks and/or traders
4. Add tests for the new card

---

## 📋 Development Roadmap

- **Graphical Interface**: Adding visual representation of the game (SDL/SFML)
- **Extended Content**: More cards, effects, characters, items
- **Multiplayer**: Network play via local network or internet
- **Progress Saving**: System for saving and loading game progress
- **Campaign**: Development of a story mode with a sequence of missions

---

## 📄 License

This project is distributed under the MIT license. See the [LICENSE](LICENSE) file for more information.
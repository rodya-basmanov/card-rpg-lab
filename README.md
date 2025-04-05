# Card RPG Game

**LabWork2**  
**Author**: Basmanov Rodion (Group B81-mm)  
**Contacts**: st135699@student.spbu.ru

---

## Description
A turn-based card RPG where players battle AI-controlled enemies using abilities, cards, and items. Key features:
- Multiple character classes (Warrior, Mage, Archer, Healer).
- Deck management with attack/defense cards.
- AI opponents (Easy, Advanced, Boss).
- Status effects (Burn, Poison, Regeneration).
- Inventory system with consumables.

---

## Architecture
- [General Description](docs/system_overview.md)
- [Requirements and Use Cases](docs/requirements_use_cases.md)
- [Component Diagram](docs/component_diagram.md)
- [Class Diagram](docs/class_diagram.md)
- [Testing Plan](docs/testing_plan.md)

---

## Dependencies
- **C++17** compatible compiler
- **CMake** (>= 3.10)
- **Google Test** (for unit tests)

## Build with CMake
cd build
cmake ..
make

---

## How to Run
./card-rpg-lab

---

## Game Controls
Main Menu:
1 - Battle
2 - Trading
3 - Dungeon
4 - Exploration
5 - PvP
6 - Exit

---

## Battle Actions:
1 - Attack
2 - Use Card
3 - Defend
4 - Open Inventory

---

## Testing
cd build
make test
./tests
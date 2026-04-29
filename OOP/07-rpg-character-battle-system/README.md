# RPG Character Battle System

## Description
A simple RPG battle simulator with different character types fighting each other.

## Characters
- **Warrior**: 120 HP, 20 Attack Power
- **Mage**: 80 HP, 15 Attack Power + 10 Magic Damage
- **Archer**: 100 HP, 18 Attack Power, 30% Critical Hit (2x damage)

## How It Works
Three characters (Arthur the Warrior, Merlin the Mage, Robin the Archer) battle each other for 2 rounds. Each round:
1. Warrior attacks Mage
2. Mage attacks Archer
3. Archer attacks Warrior

Status is shown before, after each round, and at the end.

## Key Features
- **Inheritance**: All characters inherit from a base Character class
- **Polymorphism**: Each character type has unique attack behavior
- **Dynamic Memory**: Characters are created and deleted dynamically

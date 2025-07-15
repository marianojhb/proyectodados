# CIEN or Escalera - Dice Game (C Project)

## Overview

This is a command-line dice game implemented in **C** as a final project for the course **Programming I**, part of the **University Technical Degree in Programming** at **UTN (Universidad Tecnológica Nacional), Argentina**, during the **first semester of 2024**.

The game is called **"CIEN" or "Escalera"**, and is designed for **multiple users**, supporting both **single-player** and **two-player** modes. The goal is to reach **100 points** in the fewest number of rounds or to get a **straight (1–6)** in a single roll, which results in an immediate win.

---

## Features

- **Single-player and two-player modes**
- **Support for multiple users with name input**
- **Manual or simulated dice input** (simulation mode for testing)
- **Score tracking across rounds and turns**
- **Winning conditions**:
  - Reach 100 points
  - Roll a straight (1–6) to win instantly
  - Rolling six 6s resets the score to 0
- **High score display** for the current session
- **Tie-breaker logic** (optional):
  - Fewer rounds or fewer dice rolls to determine the winner
- **Round limit mode** (optional):
  - Winner is the player with the highest score after N rounds
- **User-friendly text-based interface**:
  - Displays player names, rounds, current scores, dice values, and combo names
- **Menu system with the following options**:
  - Start a new game (1 or 2 players)
  - Show the highest score
  - Exit the game

---

## Technical Requirements

- Built using **Code::Blocks**
- Written in **C**
- **No global variables**
- Uses **functions**, **vectors (arrays)**, and at least one **`.h` header file** to organize the logic
- The `main()` function only contains the main menu logic
- Each menu option calls one or more external functions
- Compliant with all course constraints (no advanced or external libraries)

---

## Additional Libraries

This project uses [`rlutil.h`](https://github.com/tapio/rlutil), a lightweight console utility library by **Tapio Vierros**, for improving the user interface in console environments:

```c
/*
 * File: rlutil.h
 *
 * About: Description
 * This file provides some useful utilities for console mode
 * roguelike game development with C and C++. It is aimed to
 * be cross-platform (at least Windows and Linux).
 *
 * About: Copyright
 * (C) 2010 Tapio Vierros
 *
 * About: Licensing
 * See <License>
 */
```

It helps manage text color, cursor movement, screen clearing, and other console enhancements in a cross-platform way.

---

> 🎲 This project was developed to reinforce core C programming concepts such as structured logic, modular design, user interaction, and real-time decision-making. It was completed as a team assignment and includes both required and extended features for gameplay and usability.

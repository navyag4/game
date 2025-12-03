# Obstacle Dodging Game - Analysis

## What is this game?
A simple console game where you dodge falling obstacles by moving left and right between 3 lanes.

## How to Play
- **Left Arrow**: Move left
- **Right Arrow**: Move right
- **Goal**: Avoid the obstacles (☺) coming down
- **Player**: You are the ♠ symbol at the bottom

## How the Code Works

### Main Components
1. **Player (♠)**: Can be in 3 positions - left (x=0), middle (x=1), right (x=2)
2. **Obstacle (☺)**: Falls from top, appears randomly in one of 3 lanes
3. **Game Loop**: Continuously checks input → draws screen → checks collision → moves obstacle

### Key Variables
- `x` = Player position (0, 1, or 2)
- `step` = How far down the obstacle is (0 to 10)
- `obstaclePos` = Which lane the obstacle is in (0, 1, or 2)

### How Collision Works
```c
if (step == 10 && x == obstaclePos)
    // You hit the obstacle = Game Over
```

### Important Functions
- `_kbhit()` - Checks if a key was pressed
- `getch()` - Gets which key was pressed (75=Left, 77=Right)
- `clear_screen_fast()` - Refreshes screen without flickering
- `PlaySound()` - Plays background music and crash sound

## Features
- 3 lanes
- Random obstacles
- Background music
- Collision detection
- Red color theme

## What I Learned
- Game loops and how they work
- Keyboard input handling in C
- Screen clearing and drawing
- Collision detection logic
- Playing sounds in C programs

---
**By**: [Navya Gupta]  
**Date**: December 2, 2025

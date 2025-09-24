# Final Project - Memory Matching Game

## Executive Summary
This project is a simple Memory Matching Game built in C++. Players try to match hidden pairs of symbols on a grid. If two chosen symbols match, they stay visible; otherwise, they are hidden again. The game helps improve memory skills while practicing programming concepts. Features include saving best scores to a file and handling invalid input with exception handling. The game runs in the console.

## Purpose, Scope, and Objectives

### Purpose
- Build a fun and interactive console game.
- Help players improve memory.
- Provide practice with C++ programming concepts.

### Scope
- Grid with hidden pairs of symbols.
- Player inputs coordinates to match pairs.
- Matching pairs remain visible.
- Best scores saved in a file.
- Input errors handled safely.

### Objectives
- Create a working memory game in C++.
- Apply arrays, loops, conditions, and functions.
- Implement score saving with file handling.
- Add input validation and error handling.

## Project Description
The memory game displays a board with hidden symbols. Players select two coordinates to reveal symbols:
- If the symbols match, they remain visible.
- If they don’t, they are hidden again.
- The game ends when all pairs are matched or when the player exceeds a limited number of moves.

### Features
1. **Random Symbols** – Symbols placed randomly using `rand()`.
2. **Player Input** – Players enter two positions by coordinates.
3. **Match Checking** – Checks if selected symbols match.
4. **File Saving** – Saves player names and best scores.
5. **Play Again Option** – Option to restart after finishing.
6. **Score Count** – Tracks moves and sets a maximum attempt limit.

### Course Concepts Used
- Arrays  
- Loops  
- Conditions  
- Functions  
- File handling  
- Random numbers  
- Input/Output  

### Assumptions
- Players provide valid input (or errors are handled).

### Constraints
- Console only (no graphics).  
- Only alphabets and numbers as symbols.  
- Single-player game.  

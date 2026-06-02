# Improved Memory Matching Game in C++

This project is an improved version of my original Memory Matching Game created in C++.

The game allows the user to choose a category, select a difficulty level, and match pairs of hidden cards. This version uses a multi-file structure with a header file, separate function implementation, file input, arrays, randomization, and a timer to track the player's total time.

## Improvements from the Original Version

- Organized the project into multiple files
- Added a header file for constants and function prototypes
- Improved the game structure using separate functions
- Added difficulty levels: Easy, Medium, and Hard
- Added a timer to track the player's total time
- Improved category selection
- Used external text files for the card content

## Features

- Category selection: Animals, Fantasy, or Greek Gods
- Difficulty levels:
  - Easy: 4x4 board
  - Medium: 6x6 board
  - Hard: 8x8 board
- Random card shuffling
- File input using `.txt` files
- 2D arrays for the game board
- Input validation
- Timer using `chrono`

## Project Structure

- `cartsmain.cpp` - Main driver file that starts the game
- `carts.cpp` - Contains the game functions
- `carts.h` - Header file with constants and function prototypes
- `_Week13FabianaRojasAnimals.txt` - Animal category words
- `_Week13FabianaRojasFantasy.txt` - Fantasy category words
- `_Week13FabianaRojasGreakGods.txt` - Greek Gods category words

## Technologies Used

- C++
- Header files
- File handling with `fstream`
- Arrays and 2D arrays
- Functions
- Randomization
- `chrono` and `thread`
- Console input and output

## How to Run

Compile the program with:

```bash
g++ cartsmain.cpp carts.cpp -o memory_game

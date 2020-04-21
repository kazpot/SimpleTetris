# Simple Tetris (Capstone Option 2)
This is a simple tetris game written in c++

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Structure
src
├── controller.cpp ... input controller
├── controller.h
├── game.cpp ... game loop and update
├── game.h
├── main.cpp
├── player.cpp ... hold player, block, and arena state
├── player.h
├── renderer.cpp ... draw the current game state
└── renderer.h


## Build

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./Tetris`


## Rubric points
1. The project demonstrates an understanding of C++ functions and control structures.
    * player.cpp
2. The project accepts user input and processes the input.
    * controller.cpp
3. The project uses Object Oriented Programming techniques.
    * game.cpp
4. Classes use appropriate access specifiers for class members.
    * player.h
5. Class constructors utilize member initialization lists.
    * player.cpp
6. Classes encapsulate behavior.
    * player.cpp
7. The project uses destructors appropriately.
    * renderer.h
8. The project uses smart pointers instead of raw pointers.
    * game.h
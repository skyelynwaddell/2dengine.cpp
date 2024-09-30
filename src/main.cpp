//main.cpp

#include <iostream>
#include "game.h"
#include <object.h>

#undef main

int main(int argc, char* argv[]) {
    Game game; // Create a Game object
    game.init(); // Initialize the game
    game.run(); // Start the game loop

    return EXIT_SUCCESS;
}
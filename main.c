#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "game.h"
#include "player.h"

int main(int argc, char **argv)
{
    GameState game;
    unsigned int seed;

    if (argc > 1) {
        seed = (unsigned int)strtoul(argv[1], NULL, 10);
    } else {
        seed = (unsigned int)time(NULL);
    }

    game_init(&game, seed);
    game_run(&game);

    return 0;
}
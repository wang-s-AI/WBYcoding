#ifndef PLAYER_H
#define PLAYER_H

#include "game.h"

void game_init(GameState *game, unsigned int seed);
void game_start_level(GameState *game, int level);

int  player_try_move(GameState *game, int dr, int dc);

void game_run(GameState *game);

#endif
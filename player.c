#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "player.h"
#include "map.h"
#include "package.h"
#include "forklift.h"

void game_init(GameState *game, unsigned int seed)
{
    game->seed  = seed;
    game->score = 0;
    game->lives = INITIAL_LIVES;
    game->status = GAME_RUNNING;

    srand(seed);

    game_start_level(game, 1);
}

void game_start_level(GameState *game, int level)
{
    if (level < 1) level = 1;
    if (level > MAX_LEVELS) level = MAX_LEVELS;
    game->level = level;

    map_load_level(game, level);
    package_init(game);
    forklift_init(game);

    game->status = GAME_RUNNING;
}

int player_try_move(GameState *game, int dr, int dc)
{
    int nr = game->robot.row + dr;
    int nc = game->robot.col + dc;

    if (map_is_wall(game, nr, nc)) return 0;

    game->robot.row = nr;
    game->robot.col = nc;
    return 1;
}

static void do_one_turn(GameState *game)
{
    package_pickup(game);
    package_deliver(game);

    if (package_check_win(game)) {
        if (game->level < MAX_LEVELS) {
            map_render(game);
            printf("\n>>> Level %d cleared! Press Enter to continue...\n",
                   game->level);
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) { }
            if (ch == EOF) {
                game->status = GAME_QUIT;
                return;
            }
            game_start_level(game, game->level + 1);
        } else {
            game->status = GAME_WON;
        }
        return;
    }

    forklift_step_all(game);

    if (forklift_hit_player(game)) {
        game->lives--;
        if (game->lives <= 0) {
            game->status = GAME_LOST;
            return;
        }
        game->carrying = 0;
        game->robot = game->robot_start;
    }
}

void game_run(GameState *game)
{
    int ch;

    while (game->status == GAME_RUNNING) {
        map_render(game);

        ch = getchar();

        if (ch == EOF) {
            game->status = GAME_QUIT;
            break;
        }

        if (ch == '\n' || ch == '\r' || ch == ' ' || ch == '\t')
            continue;

        ch = tolower((unsigned char)ch);

        if (ch == 'q') {
            game->status = GAME_QUIT;
            break;
        }

        int dr = 0, dc = 0;
        switch (ch) {
            case 'w': dr = -1; break;
            case 's': dr =  1; break;
            case 'a': dc = -1; break;
            case 'd': dc =  1; break;
            default:
                printf("Invalid input '%c'. Use W/A/S/D, Q to quit.\n", ch);
                fflush(stdout);
                continue;
        }

        if (!player_try_move(game, dr, dc))
            continue;

        do_one_turn(game);
    }

    map_render(game);

    switch (game->status) {
        case GAME_WON:
            puts("\n=== YOU WIN! All levels cleared. ===");
            break;
        case GAME_LOST:
            puts("\n=== GAME OVER ===");
            break;
        case GAME_QUIT:
            puts("\n=== Quit. Bye. ===");
            break;
        default:
            break;
    }
}
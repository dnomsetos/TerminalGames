#include "game.h"

void game_init(game_t* game) {
    generator_init(&game->generator);
    bird_init(&game->bird);
    game->column_index = 0;
    game->column_start = 20;
    for (int i = 0; i < COLUMNS_COUNT; ++i) {
        column_init(&game->columns[i], &game->generator);
    }
}


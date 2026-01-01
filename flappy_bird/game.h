#pragma once

#include "bird.h"
#include "column.h"
#include "random.h"

#define COLUMNS_COUNT 4
#define DISTANCE_BETWEEN_COLUMNS 20

typedef struct game {
    bird_t bird;
    column_t columns[COLUMNS_COUNT];
    int column_index;
    int column_start;
    generator_t generator;
} game_t;

void game_init(game_t* game);


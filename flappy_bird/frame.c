#include <stdlib.h>

#include "frame.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

static char frame[HEIGHT][WIDTH + 1];

void init_frame() {
    for (int i = 0; i < HEIGHT; ++i) {
        memset(frame[i], ' ', WIDTH);
        frame[i][WIDTH] = '\0';
    }
}

int update_frame(game_t* game) {
    calculate_bird_pos(&game->bird);
    frame[(int)game->bird.old_pos][BIRD_GAP] = ' ';
    for (int i = 0; i < COLUMNS_COUNT; ++i) {
        int index = (i + game->column_index) % COLUMNS_COUNT;
        int left_side = game->column_start + (COLUMN_WIDTH + DISTANCE_BETWEEN_COLUMNS) * i;
        for (int x = MAX(left_side, 0); x < MIN(left_side + COLUMN_WIDTH, WIDTH); ++x) {
            char c = (x - left_side) % 2 == 0 ? '[' : ']';
            for (int y = 0; y < game->columns[index].up_pos; ++y) {
                frame[y][x] = c;
            }
            for (int y = game->columns[index].up_pos + GAP_SIZE; y < HEIGHT; ++y) {
                frame[y][x] = c;
            }
        }
        if (left_side + COLUMN_WIDTH < WIDTH && left_side + COLUMN_WIDTH >= 0) {
            for (int y = 0; y < game->columns[index].up_pos; ++y) {
                frame[y][left_side + COLUMN_WIDTH] = ' ';
            }
            for (int y = game->columns[index].up_pos + GAP_SIZE; y < HEIGHT; ++y) {
                frame[y][left_side + COLUMN_WIDTH] = ' ';
            }
        }
    }
    --game->column_start;
    if (game->column_start == -COLUMN_WIDTH - 2) {
        column_init(&game->columns[game->column_index], &game->generator);
        ++game->column_index;
        game->column_index %= COLUMNS_COUNT;
        game->column_start = 18; 
    }
    if (frame[(int)game->bird.pos][BIRD_GAP] == '[' ||
        frame[(int)game->bird.pos][BIRD_GAP] == ']') {
        return 1;
    }
    frame[(int)game->bird.pos][BIRD_GAP] = 'o';
    game->bird.old_pos = game->bird.pos;
    return 0;
}

void print_frame() {
    for (int i = 0; i < HEIGHT; ++i) {
        mvprintw(i, 0, "%s", frame[i]);
    }
}


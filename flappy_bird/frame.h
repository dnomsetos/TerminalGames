#pragma once

#include <ncurses.h>
#include <stdint.h>
#include <string.h>

#include "game.h"

#define HEIGHT 40
#define WIDTH 140

#define BIRD_GAP 3

void init_frame();

int update_frame(game_t* game);

void print_frame();


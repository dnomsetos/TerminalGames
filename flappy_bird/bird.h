#pragma once

#include <time.h>

#define GRAVITY 30000.0
#define FLAP_SPEED -500.0
#define MAX_SPEED 2000000.0


typedef struct bird {
    double pos;
    double old_pos;
    double speed;
    clock_t last_update;
} bird_t;

void bird_init(bird_t* bird);

void calculate_bird_pos(bird_t* bird);

void bird_update(bird_t* bird);


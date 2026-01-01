#include "bird.h"
#include "frame.h"

void bird_init(bird_t* bird) {
    bird->pos = HEIGHT / 2;
    bird->old_pos = HEIGHT / 2;
    bird->speed = 0;
    bird->last_update = clock();
}

void calculate_bird_pos(bird_t* bird) {
    clock_t current_time = clock();
    double dt = (double)(current_time - bird->last_update) / CLOCKS_PER_SEC;
    bird->last_update = current_time;

    bird->pos += bird->speed * dt + 0.5 * GRAVITY * dt * dt;
    bird->speed += GRAVITY * dt;

    if (bird->speed > MAX_SPEED) {
        bird->speed = MAX_SPEED;
    }
}

void bird_update(bird_t* bird) {
    calculate_bird_pos(bird);
    bird->speed = FLAP_SPEED;
}


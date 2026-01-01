#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct generator {
    FILE* urandom;
} generator_t;

int generator_init(generator_t* generator);

int generator_destroy(generator_t* generator);

unsigned char get_random(generator_t* generator);


#pragma once

#include "random.h"

#define GAP_SIZE 10
#define COLUMN_WIDTH 20

typedef struct column {
    int up_pos;
} column_t;

void column_init(column_t* column, generator_t* generator);


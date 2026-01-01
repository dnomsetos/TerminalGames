#include "column.h"

#define MAX_POS 25
#define MIN_POS 2

void column_init(column_t* column, generator_t* generator) {
    column->up_pos = get_random(generator) % (MAX_POS - MIN_POS + 1) + MIN_POS;
}


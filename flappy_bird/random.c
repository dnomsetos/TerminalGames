#include "random.h"

int generator_init(generator_t* generator) {
    generator->urandom = fopen("/dev/urandom", "rb");
    if (!generator->urandom) {
        perror("fopen");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int generator_destroy(generator_t* generator) {
    if (!fclose(generator->urandom)) {
        perror("fclose");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

unsigned char get_random(generator_t* generator) {
    unsigned char byte;
    if (fread(&byte, 1, 1, generator->urandom) == 1) {
        return byte;
    }
    return get_random(generator);
}


#include <stdbool.h>
#include <ncurses.h>
#include <time.h>

#include "frame.h"
#include "game.h"

int main() {
    initscr();
    init_frame();
    nodelay(stdscr, TRUE);
    game_t game;
    game_init(&game);
    print_frame();
    refresh();
    struct timespec delay;
    delay.tv_sec = 0;
    delay.tv_nsec = 10000000L;
    int gaps_count = 5;

    while(true) {
        if (update_frame(&game)) {
            exit(1);
        }
        print_frame();
        refresh();
        for (int i = 0; i < gaps_count; ++i) {
            char c = getch();
            if (c == ' ') {
                bird_update(&game.bird);
            }
            nanosleep(&delay, NULL);
        }
    }

    endwin();
    return 0;
}


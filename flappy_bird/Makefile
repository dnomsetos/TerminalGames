flappy_bird: main.c frame.c frame.h  random.c random.h bird.c bird.h column.h column.c game.h game.c
	clang main.c frame.c random.c bird.c column.c game.c -o flappy_bird -fsanitize=address,undefined -lncurses
	echo "Build complete"

run: flappy_bird
	chmod +x run.sh
	./run.sh

build_and_run: flappy_bird run


clean:
	rm -f flappy_bird


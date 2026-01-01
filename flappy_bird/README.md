# TerminalGames
В этой директории реализация игры flappy bird с использованием библиотеки ncurses.
## Требования
- `gnome-terminal`
- `ncurses`
## Сборка и запуск проекта
1. Можно воспользоваться таргетом make:
```bash
make build_and_run
```
2. Можно собрать и запустить вручную:
```bash
clang main.c frame.c random.c bird.c column.c game.c -o flappy_bird -fsanitize=address,undefined -lncurses
chmod +x run.sh
./run.sh
```

/*
** EPITECH PROJECT, 2023
** hunter.c
** File description:
** hunter
*/
#include <string.h>

#include "hunter.h"

static int main_game_loop(Position *pos, GameState *game) {
    game->window.video_mode = (sfVideoMode){1920, 1080, 32};
    *pos = (Position){{10, 0}, {670, 900}, {0, 450}, {0.5, 0.5}, {0, 0}};
    initialise_game_state(game, pos);
    sfRenderWindow_setFramerateLimit(game->window.window, 60);

    game->sec = 0;
    game->clock = sfClock_create();
    while (sfRenderWindow_isOpen(game->window.window)) {
        update_game_state(game, pos);
        render_game(game, pos);
    }

    clean_up(game);
    return SUCCESS;
}

int hunter(int ac, char **av) {
    GameState game = {0};
    Position pos = {0};

    if (ac == 2 && !strcmp(av[1], "-h")) {
        printf("\nNight Forest Birds Hunt\n\
        nKill all of the birds on the screen.\n\n");
        return SUCCESS;
    }
    return main_game_loop(&pos, &game);
}

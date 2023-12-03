/*
** EPITECH PROJECT, 2023
** rendering.c
** File description:
** rendering
*/

#include "hunter.h"

void render_game(GameState *game, Position *pos)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(game->clock)) > 0.1) {
        sfSprite_setTexture(game->window.object_sprite,
        game->resources.object_textures[game->sec++ % NUM_OBJECTS], sfTrue);
        sfClock_restart(game->clock);
    }
    sfSprite_setPosition(game->window.object_sprite, pos->object_position);
    sfRenderWindow_clear(game->window.window, sfBlack);
    sfRenderWindow_drawSprite(game->window.window,
    game->window.background_sprite, NULL);
    sfRenderWindow_drawSprite(game->window.window,
    game->window.object_sprite, NULL);
    sfRenderWindow_drawText(game->window.window,
    game->text.title, NULL);
    sfRenderWindow_drawText(game->window.window,
    game->text.footer, NULL);
    sfRenderWindow_display(game->window.window);
}

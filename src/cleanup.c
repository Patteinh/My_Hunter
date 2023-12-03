/*
** EPITECH PROJECT, 2023
** cleanup.c
** File description:
** cleanup
*/

#include "hunter.h"

void clean_up(GameState *game)
{
    sfMusic *music_resources[] = { game->resources.background_music,
    game->resources.fly_sound, game->resources.kill_sound };

    sfSprite_destroy(game->window.object_sprite);
    sfSprite_destroy(game->window.background_sprite);
    for (int i = 0; i < NUM_OBJECTS; i++)
        sfTexture_destroy(game->resources.object_textures[i]);
    for (int i = 0; i < 3; i++)
        sfMusic_destroy(music_resources[i]);
    sfText_destroy(game->text.title);
    sfText_destroy(game->text.footer);
    sfRenderWindow_destroy(game->window.window);
}

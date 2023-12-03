/*
** EPITECH PROJECT, 2023
** initialization.c
** File description:
** initialization
*/

#include <stdbool.h>

#include "hunter.h"

static const char *music_paths[3] =
{
    "assets/music/forest_night.ogg", "assets/music/flying_noise.ogg",
    "assets/music/kill_noise.ogg"
};

static const char *bird_paths[NUM_OBJECTS] = {
    "assets/bird/0.png", "assets/bird/1.png", "assets/bird/2.png",
    "assets/bird/3.png", "assets/bird/4.png", "assets/bird/5.png",
    "assets/bird/6.png", "assets/bird/7.png", "assets/bird/8.png"
};

static bool load_textures(GameState *game)
{
    game->resources.background_texture =
    sfTexture_createFromFile("assets/pic/forest.jpg", NULL);

    for (int i = 0; i < NUM_OBJECTS; i++) {
        game->resources.object_textures[i] =
        sfTexture_createFromFile(bird_paths[i], NULL);
        if (!game->resources.object_textures[i]) {
            while (i--)
                sfTexture_destroy(game->resources.object_textures[i]);
            return false;
        }
    }
    return true;
}

static void load_sounds(GameState *game)
{
    sfMusic **music_resources[] = { &game->resources.background_music,
    &game->resources.fly_sound, &game->resources.kill_sound};

    for (int i = 0; i < 3; i++)
        *music_resources[i] = sfMusic_createFromFile(music_paths[i]);
    for (int i = 0; i < 2; i++) {
        sfMusic_setLoop(*music_resources[i], sfTrue);
        sfMusic_play(*music_resources[i]);
    }
}

static void create_texts(GameState *game, Position *pos)
{
    game->resources.font = sfFont_createFromFile("assets/font/my.otf");
    game->text.title = sfText_create();
    sfText_setString(game->text.title, "Night hunt");
    sfText_setPosition(game->text.title, pos->text_position);
    sfText_setFont(game->text.title, game->resources.font);
    sfText_setCharacterSize(game->text.title, 50);
    game->text.footer = sfText_create();
}

static void create_sprites(GameState *game, Position *pos)
{
    game->window.object_sprite = sfSprite_create();
    game->window.background_sprite = sfSprite_create();
    sfSprite_setTexture(game->window.background_sprite,
    game->resources.background_texture, sfTrue);
    sfSprite_setPosition(game->window.object_sprite, pos->object_position);
    sfSprite_setScale(game->window.object_sprite, pos->scale);
}


void initialise_game_state(GameState *game, Position *pos)
{
    game->window.window = sfRenderWindow_create(game->window.video_mode,
    "Windows XP", sfResize | sfClose, NULL);
    if (!load_textures(game)) return;
    load_sounds(game);
    create_texts(game, pos);
    create_sprites(game, pos);
}

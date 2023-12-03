/*
** EPITECH PROJECT, 2023
** hunter.h
** File description:
** Header file for the Hunter game
*/

#pragma once

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_OBJECTS 9

static const int SUCCESS = 0;

typedef struct GameWindow {
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfSprite *background_sprite;
    sfSprite *object_sprite;
} GameWindow;

typedef struct GameResources {
    sfTexture *background_texture;
    sfTexture *object_textures[NUM_OBJECTS];
    sfFont *font;
    sfMusic *background_music;
    sfMusic *fly_sound;
    sfMusic *kill_sound;
} GameResources;

typedef struct GameText {
    sfText *title;
    sfText *footer;
} GameText;

typedef struct GameState {
    GameWindow window;
    GameResources resources;
    GameText text;
    sfEvent event;
    sfClock *clock;
    int sec;
} GameState;

typedef struct Position {
    sfVector2f text_position;
    sfVector2f footer_position;
    sfVector2f object_position;
    sfVector2f scale;
    sfVector2i mouse_position;
} Position;

int hunter(int argc, char **argv);
void initialise_game_state(GameState *game, Position *pos);
void update_game_state(GameState *game, Position *pos);
void render_game(GameState *game, Position *pos);
void clean_up(GameState *game);

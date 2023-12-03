/*
** EPITECH PROJECT, 2023
** game_logic.c
** File description:
** game_logic
*/

#include "hunter.h"

static void handle_music_kill(GameState *game, Position *pos)
{
    pos->mouse_position = sfMouse_getPositionRenderWindow(game->window.window);
    if (pos->mouse_position.x > pos->object_position.x &&
    pos->mouse_position.x < pos->object_position.x + 300 &&
        pos->mouse_position.y > pos->object_position.y &&
        pos->mouse_position.y < pos->object_position.y + 250) {
        sfMusic_play(game->resources.kill_sound);
        pos->object_position.x = -200;
        pos->object_position.y = rand() % 701;
    }
}

static void handle_events(GameState *game, Position *pos)
{
    while (sfRenderWindow_pollEvent(game->window.window, &game->event)) {
        if (game->event.type == sfEvtClosed ||
        sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(game->window.window);
        else if (game->event.type == sfEvtMouseButtonPressed)
            handle_music_kill(game, pos);
    }
}

static void update_initial_object_position(Position *pos)
{
    if (pos->object_position.x <= 150) {
        pos->object_position.x += 8;
    } else if (pos->object_position.x > 150 &&
    pos->object_position.x < 900) {
        pos->object_position.x += 10;
        pos->object_position.y += rand() % 10;
    } else if (pos->object_position.x >= 900 &&
    pos->object_position.x < 1500) {
        pos->object_position.x += 5;
        pos->object_position.y -= rand() % 30;
    }
}

static void update_later_object_position(Position *pos)
{
    if (pos->object_position.x >= 1500 &&
    pos->object_position.x < 2000) {
        pos->object_position.x += 10;
    } else if (pos->object_position.x >= 2000) {
        pos->object_position.x = -200;
        pos->object_position.y = rand() % 701;
    }
}

void update_game_state(GameState *game, Position *pos)
{
    handle_events(game, pos);
    update_initial_object_position(pos);
    update_later_object_position(pos);
}

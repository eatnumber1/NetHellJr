#ifndef _SCREEN_H_
#define _SCREEN_H_

#include "direc.h"
#include "world.h"

#include <stdint.h>
#include <string.h>
#include <graphics.h>

extern int gd, gm;
extern int RES_X, RES_Y;
extern int GRID_MAX_X, GRID_MAX_Y;
extern int CENTER_X, CENTER_Y;

extern int RAY_LENGTH, RAY_LENGTH_45;

extern int HUD_X, HUD_Y;

void screen_display_world(World *world);
void screen_initialize_graphics();
void screen_kill_graphics();
void screen_tick();
void screen_draw_ray(int startX, int startY, Direction angle, int color);
void screen_draw_dude(int x, int y, char ch, int color);
void screen_draw_health(int hp, int maxhp);
void screen_get_dimensions( size_t *x, size_t *y );
void screen_show_chr( char c );
void screen_debug_pos(int x, int y);
void screen_display_death_message();
void screen_display_start_message();

#endif

/* vim:set ff=dos: */

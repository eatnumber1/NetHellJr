#ifndef _SCREEN_H_
#define _SCREEN_H_

#include "world.h"
#include <graphics.h>

int gd = CGAC1, gm; /* CGAC1 =1 --> 320x200 palette 1; 1 page */
int RES_X = 320, RES_Y = 200;
int GRID_MAX_X = 40, GRID_MAX_Y = 30;
int CENTER_X = 160, CENTER_Y = 100;

int RAY_LENGTH=20, RAY_LENGTH_45=14;

int HUD_X = 20, HUD_Y = 180;

void display_world(World *world);
void initialize_graphics();
void kill_graphics();
void tick();
void draw_ray(int startX, int startY, int angle, int color);
void draw_dude(int x, int y, char ch, int color);
void draw_health(int hp, int maxhp);
#endif

/* vim:set ff=dos: */

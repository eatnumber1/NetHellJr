#include "direc.h"
#include "monst.h"
#include "ray.h"
#include "world.h"
#include "screen.h"

#include <stdint.h>

int gd = CGAC1, gm; /* CGAC1 =1 --> 320x200 palette 1; 1 page */
int RES_X = 320, RES_Y = 200;
int GRID_MAX_X = 39, GRID_MAX_Y = 23;
int CENTER_X = 160, CENTER_Y = 100;

int RAY_LENGTH=20, RAY_LENGTH_45=14;

int HUD_X = 20, HUD_Y = 180;

void screen_display_world(World *world ){
	size_t i;
	Monster *mon;
	Ray *ray;

	cleardevice();
	screen_kill_graphics();
	screen_initialize_graphics();

	screen_draw_health(world->you.hp, world->you.maxhp);

	screen_debug_pos(
		screen_grid_to_coordinate(world->you.pos.x),
		screen_grid_to_coordinate(world->you.pos.y)
		);

	screen_draw_dude(
		screen_grid_to_coordinate(world->you.pos.x),
		screen_grid_to_coordinate(world->you.pos.y),
		world->you.sym,
		CGA_LIGHTGREEN
		);

	for(i=0; i<world->monsters.size; ++i){
		mon = &world->monsters.val[i];
		if(mon->hp > 0){ /* alive */
			screen_draw_dude(
				screen_grid_to_coordinate(mon->pos.x),
				screen_grid_to_coordinate(mon->pos.y),
				mon->sym,
				CGA_WHITE
			);
		}
	}

	for(i=0; i<world->rays.size; ++i){
		ray = &world->rays.val[i];
		if(ray->start.x < 0 || ray->start.y < 0){
		}
		else{
			screen_draw_ray(screen_grid_to_coordinate(ray->start.x),
					  screen_grid_to_coordinate(ray->start.y),
					  ray->angle,
					  CGA_RED
				);
		}
	}
	/*screen_kill_graphics();*/
}

int screen_grid_to_coordinate(int x){
	return x*8+4;
}

void screen_initialize_graphics(){
	initgraph(&gd, &gm, "C:\\TC\\BGI");
}

void screen_kill_graphics(){
	closegraph();
}

void screen_tick(){

}

void screen_draw_health(int hp, int maxhp){
	char status[8];

	sprintf(status, "%d/%d", hp, maxhp);
	settextjustify(LEFT_TEXT,CENTER_TEXT);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 1); /* 8x8 bitmap font */

	if(maxhp/hp>5){
		setcolor(CGA_RED);
	}
	else{
		setcolor(CGA_GREEN);
	}
	outtextxy(HUD_X, HUD_Y, status);	
}

void screen_debug_pos(int x, int y){
	char status[8];

	sprintf(status, "%d %d", x, y);
	settextjustify(LEFT_TEXT,CENTER_TEXT);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 1); /* 8x8 bitmap font */

	outtextxy(HUD_X,160, status);	
}

void screen_draw_ray(int startX, int startY, Direction angle, int color){
	int endX, endY;

	setcolor(color);
	
	switch(angle){
		case DIREC_N:
			endX=startX;
			endY=startY-RAY_LENGTH;
			break;
		case DIREC_NE:
			endX=startX+RAY_LENGTH_45;
			endY=startY-RAY_LENGTH_45;
			break;
		case DIREC_E:
			endX=startX+RAY_LENGTH;
			endY=startY;
			break;
		case DIREC_SE:
			endX=startX+RAY_LENGTH_45;
			endY=startY+RAY_LENGTH_45;
			break;
		case DIREC_S:
			endX=startX;
			endY=startY+RAY_LENGTH;
			break;
		case DIREC_SW:
			endX=startX-RAY_LENGTH_45;
			endY=startY+RAY_LENGTH_45;
			break;
		case DIREC_W:
			endX=startX-RAY_LENGTH;
			endY=startY;
			break;
		case DIREC_NW:
			endX=startX-RAY_LENGTH_45;
			endY=startY-RAY_LENGTH_45;
			break;
	}
	line(startX, startY, endX, endY);
}

void screen_draw_dude(int x, int y, char ch, int color){
	char symbol[2];

	sprintf(symbol, "%c", ch);
	setcolor(color);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 1); /* 8x8 bitmap font */
	outtextxy(x,y,symbol);
}

void screen_show_chr( char c ) {
	(void) c;
}


void screen_get_dimensions( size_t *x, size_t *y ) {
	*x = GRID_MAX_X;
	*y = GRID_MAX_Y;
}

/* vim:set ff=dos: */

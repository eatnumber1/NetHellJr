#include "screen.h"
#include "world.h"

void display_world(World *world ){
	int monster_index;
	draw_health(world->you->hp, world->you->maxhp);
	for(i=0; i<MAX_MONSTERS; ++i){
		Monster mon = world->monsters[monster_index];
		if(mon->hp > 0){ /* alive */
			draw_dude(
				grid_to_coordinate(mon->pos->x),
				grid_to_coordinate(mon->pos->y),
				mon->sym,
				CGA_WHITE
				);
		}
	}
}

int grid_to_coordinate(int x){
	return x*8+4;
}
void main(){
	int i;

	initialize_graphics();
	draw_dude(CENTER_X,CENTER_Y, '@', CGA_RED);
	draw_health(50,64);
	getch();
	cleardevice();
	for(i=0; i<8; ++i){
		draw_ray(CENTER_X, CENTER_Y, i, CGA_GREEN);
		getch();
		cleardevice();
	}
	kill_graphics();
}

void initialize_graphics(){
	initgraph(&gd, &gm, "C:\\TC\\BGI");
}

void kill_graphics(){
	closegraph();
}

void tick(){

}

void draw_health(int hp, int maxhp){
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

void draw_ray(int startX, int startY, int angle, int color){
	int endX, endY;

	setcolor(color);
	
	switch(angle){
		case 0:
			endX=startX;
			endY=startY-RAY_LENGTH;
			break;
		case 1:
			endX=startX+RAY_LENGTH_45;
			endY=startY-RAY_LENGTH_45;
			break;
		case 2:
			endX=startX+RAY_LENGTH;
			endY=startY;
			break;
		case 3:
			endX=startX+RAY_LENGTH_45;
			endY=startY+RAY_LENGTH_45;
			break;
		case 4:
			endX=startX;
			endY=startY+RAY_LENGTH;
			break;
		case 5:
			endX=startX-RAY_LENGTH_45;
			endY=startY+RAY_LENGTH_45;
			break;
		case 6:
			endX=startX-RAY_LENGTH;
			endY=startY;
			break;
		case 7:
			endX=startX-RAY_LENGTH_45;
			endY=startY-RAY_LENGTH_45;
			break;
	}
	line(startX, startY, endX, endY);
}

void draw_dude(int x, int y, char ch, int color){
	char symbol[2];

	sprintf(symbol, "%c", ch);
	setcolor(color);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 1); /* 8x8 bitmap font */
	outtextxy(x,y,symbol);
}

/* vim:set ff=dos: */

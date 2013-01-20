#include "world.h"
#include "screen.h"

#include <stdbool.h>

#include <stdio.h>

void monster_set_position( Monster *mon, mon_pos_t x, mon_pos_t y ) {
	mon->pos.x = x;
	mon->pos.y = y;
}

void monster_move( Monster *m, Direction d ) {
	static size_t max_x, max_y;
	static bool has_dimensions = false;

	if( !has_dimensions ) {
		screen_get_dimensions(&max_x, &max_y);
		has_dimensions = true;
	}

	switch( d ) {
		case DIRECTION_DOWN:
			if( m->pos.y == max_y - 1 ) return;
			m->pos.y += 1;
			break;
		case DIRECTION_UP:
			if( m->pos.y == 0 ) return;
			m->pos.y -= 1;
			break;
		case DIRECTION_RIGHT:
			if( m->pos.x == max_x - 1 ) return;
			m->pos.x += 1;
			break;
		case DIRECTION_LEFT:
			if( m->pos.x == 0 ) return;
			m->pos.x -= 1;
			break;
	}
}

/* vim:set ff=dos: */

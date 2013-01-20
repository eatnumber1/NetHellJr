#include "direc.h"
#include "monst.h"
#include "ray.h"
#include "world.h"
#include "screen.h"

#include <stdbool.h>

void world_init( World *w ) {
	monster_list_init(&w->monsters);
	ray_list_init(&w->rays);
}

static bool is_collision( MonsterList *m, Position *p ) {
	size_t i;

	for( i = 0; i < m->size; i++ ) {
		Position *mp = &m->val[i].pos;
		if( mp->x == p->x && mp->y == p->y ) return true;
	}
	return false;
}

WorldError world_move_monster( World *w, Monster *m, Direction d ) {
	static size_t max_x, max_y;
	static bool has_dimensions = false;
	Position np;

	if( !has_dimensions ) {
		screen_get_dimensions(&max_x, &max_y);
		has_dimensions = true;
	}

	np.x = m->pos.x;
	np.y = m->pos.y;
	switch( d ) {
		case DIREC_S:
			if( np.y == max_y - 1 ) goto collision;
			np.y += 1;
			break;
		case DIREC_N:
			if( np.y == 0 ) goto collision;
			np.y -= 1;
			break;
		case DIREC_E:
			if( np.x == max_x - 1 ) goto collision;
			np.x += 1;
			break;
		case DIREC_W:
			if( np.x == 0 ) goto collision;
			np.x -= 1;
			break;
	}
	if( is_collision(&w->monsters, &np) ) goto collision;
	m->pos.x = np.x;
	m->pos.y = np.y;

	return WORLD_ERR_OK;

collision:
	return WORLD_ERR_COLLIDE;
}

/* vim:set ff=dos: */

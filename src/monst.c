#include "direc.h"

#include "monst.h"
#include "screen.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

void monster_init_you( Monster *m, char sym, uint_fast8_t hp, uint_fast8_t maxhp, pos_t x, pos_t y ) {
	assert(hp <= maxhp);
	m->sym = sym;
	m->hp = hp;
	m->maxhp = maxhp;
	monster_set_position(m, x, y);
}

void monster_init( MonsterList *m, char sym, uint_fast8_t hp, uint_fast8_t maxhp, pos_t x, pos_t y ) {
	monster_init_you(&m->val[m->size++], sym, hp, maxhp, x, y);
}

void monster_set_position( Monster *mon, pos_t x, pos_t y ) {
	mon->pos.x = x;
	mon->pos.y = y;
}

void monster_list_init( MonsterList *m ) {
	m->size = 0;
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

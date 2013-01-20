#include "monst.h"

#include <stdint.h>
#include <assert.h>

void monster_init_you( Monster *m, char sym, uint_fast8_t hp, uint_fast8_t maxhp, pos_t x, pos_t y ) {
	assert(hp <= maxhp);
	m->sym = sym;
	m->hp = hp;
	m->maxhp = maxhp;
	monster_set_position(m, x, y);
}

void monster_init( MonsterList *m, char sym, uint_fast8_t hp, uint_fast8_t maxhp, pos_t x, pos_t y ) {
	assert(m->size != MAX_MONSTERS);
	monster_init_you(&m->val[m->size++], sym, hp, maxhp, x, y);
}

void monster_set_position( Monster *mon, pos_t x, pos_t y ) {
	mon->pos.x = x;
	mon->pos.y = y;
}

void monster_list_init( MonsterList *m ) {
	m->size = 0;
}

/* vim:set ff=dos: */

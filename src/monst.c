#include "monst.h"

#include <stdint.h>
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

void monster_init_you( Monster *m, char sym, uint_fast8_t hp, uint_fast8_t maxhp, pos_t x, pos_t y ) {
	assert(hp <= maxhp);
	m->sym = sym;
	m->hp = hp;
	m->maxhp = maxhp;
	monster_set_position(m, x, y);
}

void monster_init( MonsterList *monsters, char sym, uint_fast8_t hp, uint_fast8_t maxhp, pos_t x, pos_t y ) {
	size_t i = 0;
	Monster *m = NULL;

	if( i == MAX_MONSTERS ) i = 0;
	for( ; i < MAX_MONSTERS; i++ ) {
		if( !monster_is_alive(m = &monsters->val[i]) ) break;
	}
	if( m == NULL ) assert(false);

	monsters->size++;
	monster_init_you(m, sym, hp, maxhp, x, y);
}

void monster_set_position( Monster *mon, pos_t x, pos_t y ) {
	mon->pos.x = x;
	mon->pos.y = y;
}

void monster_list_init( MonsterList *m ) {
	m->size = 0;
	memset(m->val, 0, sizeof(Monster) * MAX_MONSTERS);
}

bool monster_is_alive( Monster *m ) {
	return m->hp > 0;
}

/* vim:set ff=dos: */

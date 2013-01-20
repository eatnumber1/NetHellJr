#ifndef _MONST_H_
#define _MONST_H_

#include "direc.h"

#include <stdint.h>
#include <stdbool.h>

#define MAX_MONSTERS 128

typedef struct {
	char sym;
	uint_fast8_t maxhp, hp;
	Position pos;
} Monster;

typedef struct {
	Monster val[MAX_MONSTERS];
	size_t size;
	Monster *you;
} MonsterList;
/* TODO: MonsterList->size is no longer needed */

void monster_init_you( Monster *m, char sym, uint_fast8_t hp, uint_fast8_t maxhp, pos_t x, pos_t y );
void monster_init( MonsterList *m, char sym, uint_fast8_t hp, uint_fast8_t maxhp, pos_t x, pos_t y );
void monster_set_position( Monster *mon, pos_t x, pos_t y );
void monster_list_init( MonsterList *m, Monster *you );
bool monster_is_alive( Monster *m );

typedef bool (*MonsterIterator)( Monster *, void * );
bool monster_list_foreach( MonsterList *m, MonsterIterator f, void *arg );

#endif
/* vim:set ff=dos: */

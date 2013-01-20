#ifndef _WORLD_H_
#define _WORLD_H_

#include <stdint.h>

#include "input.h"

typedef uint_fast16_t mon_pos_t;

struct _MonsterPosition {
	mon_pos_t x, y;
};

typedef struct {
	char sym;
	uint_fast8_t maxhp, hp;
	struct _MonsterPosition pos;
} Monster;

#define MAX_MONSTERS 128

typedef struct {
	Monster you;
	Monster monsters[MAX_MONSTERS];
	size_t nmonsters;
} World;

typedef enum {
	DIRECTION_UP,
	DIRECTION_DOWN,
	DIRECTION_LEFT,
	DIRECTION_RIGHT
} Direction;

void monster_set_position( Monster *mon, mon_pos_t x, mon_pos_t y );
void monster_move( Monster *m, Direction d );

#endif

/* vim:set ff=dos: */

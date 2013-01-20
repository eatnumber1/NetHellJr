#ifndef _WORLD_H_
#define _WORLD_H_

#include <stdint.h>

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

void monster_set_position( Monster *mon, mon_pos_t x, mon_pos_t y );

#endif

/* vim:set ff=dos: */

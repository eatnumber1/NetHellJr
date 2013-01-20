#ifndef _WORLD_H_
#define _WORLD_H_

#include <stdint.h>

#include "input.h"

typedef uint_fast16_t mon_pos_t;
typedef uint_fast8_t angle_t;

struct _Position {
	mon_pos_t x, y;
};

typedef struct {
	struct _Position start;
	angle_t angle;
} Ray;

typedef struct {
	char sym;
	uint_fast8_t maxhp, hp;
	struct _Position pos;
} Monster;

#define MAX_MONSTERS 128
#define MAX_RAYS 128

typedef struct {
	Monster you;
	Monster monsters[MAX_MONSTERS];
	size_t nmonsters;
	Ray rays[MAX_RAYS];
	size_t nrays;
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

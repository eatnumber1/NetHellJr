#ifndef _WORLD_H_
#define _WORLD_H_

#include "monst.h"
#include "ray.h"

typedef struct {
	Monster you;
	RayList rays;
	MonsterList monsters;
} World;

typedef enum {
	WORLD_ERR_OK,
	WORLD_ERR_COLLIDE
} WorldError;

void world_init( World *w );
WorldError world_move_monster( World *w, Monster *m, Direction d );
Direction world_direction_of( Monster *me, Monster *them );

#endif

/* vim:set ff=dos: */

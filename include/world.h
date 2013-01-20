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

#endif

/* vim:set ff=dos: */

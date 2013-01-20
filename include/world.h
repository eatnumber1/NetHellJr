#ifndef _WORLD_H_
#define _WORLD_H_

#include "monst.h"
#include "ray.h"

typedef struct {
	Monster you;
	RayList rays;
	MonsterList monsters;
} World;

#endif

/* vim:set ff=dos: */
